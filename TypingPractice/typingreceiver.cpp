#include "typingreceiver.h"
#include <math.h>

#include <QtCore>

#define DEF_FONT_SIZE 16
#define DEF_FONT_FAM "Arial"
#define DEF_FONT_WEIGHT 55
#define DEF_WIDTH 580

TypingReceiver::TypingReceiver(QWidget *parent) :
    QWidget(parent)
{
    this->font.setFamily(DEF_FONT_FAM);
    this->font.setPointSize(DEF_FONT_SIZE);
    this->font.setWeight(DEF_FONT_WEIGHT);

    metrics = new QFontMetrics(this->font);

    this->avgCharWidth = metrics->averageCharWidth();
    this->setMinimumSize(DEF_WIDTH, metrics->height()+15);
    this->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    this->pPos = 0;
    this->displayString = "";
    this->remainderString = "";
    this->setStatus(TypingReceiver::Stopped);

}

void TypingReceiver::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QRect widgetRect = this->rect();

    painter.setBrush(Qt::SolidPattern);
    painter.fillRect(widgetRect, QColor(255, 255, 255));
    painter.setBrush(Qt::NoBrush);
    widgetRect.setHeight(widgetRect.height()-1);
    widgetRect.setWidth(widgetRect.width()-1);
    painter.drawRect(widgetRect);

    painter.setFont(this->font);
    painter.drawText(2, metrics->height()+10, displayString);

    this->drawPointer(&painter);
}

void TypingReceiver::keyPressEvent(QKeyEvent *event) {
    QChar testChar = event->text()[0];
    if (testChar == this->displayString[pPos]) {
        pPos++;
        if (pPos < displayString.size()) {
            this->update();
        } else {
            pPos = 0;
            this->currentString = "";
            this->loadUpString();
        }
    }
}

TypingReceiver::~TypingReceiver() {
    delete metrics;
}

void TypingReceiver::drawPointer(QPainter *painter) {
    if (!this->displayString.isEmpty()) {
        QString tempString = displayString;
        tempString.remove(pPos, tempString.size());

        if (pPos-1 >= 0)
            if (tempString[pPos-1].isSpace())
                tempString.replace(pPos-1, 1, '-');

        QRect textRect = metrics->boundingRect(tempString);
        QChar posChar = displayString[pPos];
        if (posChar.isSpace())
            posChar = '-';
        float charWidth = metrics->boundingRect(posChar).width();

        QTransform trans;
        trans.translate(textRect.width()+(charWidth/2.0)+3, 3);
        painter->setTransform(trans);
        painter->setBrush(QBrush(QColor(197, 40, 3), Qt::SolidPattern));

        QPointF points[3] = {
            QPointF(-4.0, 0.5),
            QPointF(4.0, 0.5),
            QPointF(0.0, 8.0)
        };
        painter->drawPolygon(points, 3);
    }
}

void TypingReceiver::setStatus(TypingReceiver::Status newStatus) {
    if (this->status != newStatus) {
        this->status = newStatus;
        if (this->status == TypingReceiver::Started)
            this->grabKeyboard();
            if (displayString.isEmpty())
                emit needAnotherString();
        else
            this->releaseKeyboard();

        if (this->status == TypingReceiver::Stopped) {
            this->pPos = 0;
            this->displayString = "";
            this->remainderString = "";
            this->update();
        }
        emit statusChanged(this->status);
    }
}

TypingReceiver::Status TypingReceiver::getStatus() {
    return this->status;
}

void TypingReceiver::setString(QString iString) {
    if (this->status == this->Started) {
        this->currentString = iString;
        this->loadUpString();
    } else {
        this->remainderString = iString;
    }
}

void TypingReceiver::loadUpString() {
    this->currentString = this->remainderString + this->currentString;
    this->remainderString.clear();

    int difWidth = metrics->boundingRect(this->currentString).width() - this->rect().width();
    if (difWidth < 0) {
        this->remainderString = this->currentString;
        emit needAnotherString();
        return;
    } else {
        int indexR = ceil(difWidth/this->avgCharWidth);
        int indexL;
        QString testString;
        int strSize = this->currentString.size();
        int dif;

        do {
            indexL = strSize - indexR;
            testString = this->currentString.left(indexL);
            indexR++;
            dif = this->rect().width() - metrics->boundingRect(testString).width();
        } while(dif < 10);

        indexR--;
        this->displayString = this->currentString.left(indexL);
        this->remainderString = this->currentString.right(indexR);

        qDebug() << displayString << ":" << remainderString;
        this->update();
    }

}
