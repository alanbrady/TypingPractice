#ifndef TYPINGRECEIVER_H
#define TYPINGRECEIVER_H

#include <QWidget>
#include <QFont>
#include <QPainter>
#include <QFontMetrics>
#include <QString>
#include <QKeyEvent>

class TypingReceiver : public QWidget
{
Q_OBJECT
public:
    explicit TypingReceiver(QWidget *parent = 0);
    ~TypingReceiver();

    enum Status { Stopped = 0, Started, Paused };

    void setStatus(Status newStatus);
    Status getStatus();

    void setString(QString iString);

signals:
    void statusChanged(TypingReceiver::Status);
    void needAnotherString();

public slots:

protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent* event);

private:
    QFont font;
    float avgCharWidth;
    QFontMetrics* metrics;
    int pPos;
    QString currentString;
    QString displayString;
    QString remainderString;
    Status status;

    void drawPointer(QPainter* painter);
    void loadUpString();
};

#endif // TYPINGRECEIVER_H
