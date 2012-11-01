/********************************************************************************
** Form generated from reading UI file 'typingpractice.ui'
**
** Created: Wed Mar 17 11:31:04 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TYPINGPRACTICE_H
#define UI_TYPINGPRACTICE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TypingPractice
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridMain;
    QSpacerItem *verticalSpacer;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonStart;
    QPushButton *buttonPause;
    QPushButton *buttonStop;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *buttonFile;
    QLabel *fileLabel;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TypingPractice)
    {
        if (TypingPractice->objectName().isEmpty())
            TypingPractice->setObjectName(QString::fromUtf8("TypingPractice"));
        TypingPractice->setWindowModality(Qt::WindowModal);
        TypingPractice->resize(600, 400);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TypingPractice->sizePolicy().hasHeightForWidth());
        TypingPractice->setSizePolicy(sizePolicy);
        TypingPractice->setMinimumSize(QSize(600, 400));
        TypingPractice->setMaximumSize(QSize(600, 400));
        centralWidget = new QWidget(TypingPractice);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 9, 581, 341));
        gridMain = new QGridLayout(gridLayoutWidget);
        gridMain->setSpacing(6);
        gridMain->setContentsMargins(11, 11, 11, 11);
        gridMain->setObjectName(QString::fromUtf8("gridMain"));
        gridMain->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridMain->addItem(verticalSpacer, 0, 0, 1, 1);

        line = new QFrame(gridLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridMain->addWidget(line, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonStart = new QPushButton(gridLayoutWidget);
        buttonStart->setObjectName(QString::fromUtf8("buttonStart"));
        buttonStart->setEnabled(false);

        horizontalLayout->addWidget(buttonStart);

        buttonPause = new QPushButton(gridLayoutWidget);
        buttonPause->setObjectName(QString::fromUtf8("buttonPause"));
        buttonPause->setEnabled(false);

        horizontalLayout->addWidget(buttonPause);

        buttonStop = new QPushButton(gridLayoutWidget);
        buttonStop->setObjectName(QString::fromUtf8("buttonStop"));
        buttonStop->setEnabled(false);

        horizontalLayout->addWidget(buttonStop);


        gridMain->addLayout(horizontalLayout, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        buttonFile = new QPushButton(gridLayoutWidget);
        buttonFile->setObjectName(QString::fromUtf8("buttonFile"));
        sizePolicy.setHeightForWidth(buttonFile->sizePolicy().hasHeightForWidth());
        buttonFile->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(buttonFile);

        fileLabel = new QLabel(gridLayoutWidget);
        fileLabel->setObjectName(QString::fromUtf8("fileLabel"));
        QFont font;
        font.setItalic(true);
        fileLabel->setFont(font);

        horizontalLayout_4->addWidget(fileLabel);


        gridMain->addLayout(horizontalLayout_4, 2, 0, 1, 1);

        TypingPractice->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TypingPractice);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        TypingPractice->setMenuBar(menuBar);
        statusBar = new QStatusBar(TypingPractice);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setEnabled(true);
        statusBar->setAutoFillBackground(false);
        TypingPractice->setStatusBar(statusBar);

        retranslateUi(TypingPractice);
        QObject::connect(buttonPause, SIGNAL(clicked()), TypingPractice, SLOT(pausePractice()));
        QObject::connect(buttonStop, SIGNAL(clicked()), TypingPractice, SLOT(stopPractice()));
        QObject::connect(buttonStart, SIGNAL(clicked()), TypingPractice, SLOT(startPractice()));
        QObject::connect(buttonFile, SIGNAL(clicked()), TypingPractice, SLOT(getFileDialog()));

        QMetaObject::connectSlotsByName(TypingPractice);
    } // setupUi

    void retranslateUi(QMainWindow *TypingPractice)
    {
        TypingPractice->setWindowTitle(QApplication::translate("TypingPractice", "Typing Practice", 0, QApplication::UnicodeUTF8));
        buttonStart->setText(QApplication::translate("TypingPractice", "Start", 0, QApplication::UnicodeUTF8));
        buttonPause->setText(QApplication::translate("TypingPractice", "Pause", 0, QApplication::UnicodeUTF8));
        buttonStop->setText(QApplication::translate("TypingPractice", "Stop", 0, QApplication::UnicodeUTF8));
        buttonFile->setText(QApplication::translate("TypingPractice", "File", 0, QApplication::UnicodeUTF8));
        fileLabel->setText(QApplication::translate("TypingPractice", "No File Selected", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TypingPractice: public Ui_TypingPractice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TYPINGPRACTICE_H
