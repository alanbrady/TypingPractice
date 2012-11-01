#ifndef TYPINGPRACTICE_H
#define TYPINGPRACTICE_H

#include <QMainWindow>
#include "textmanager.h"
#include "typingreceiver.h"

namespace Ui {
    class TypingPractice;
}

class TypingPractice : public QMainWindow {
    Q_OBJECT
public:
    TypingPractice(QWidget *parent = 0);
    ~TypingPractice();

public slots:
    void startPractice();
    void pausePractice();
    void stopPractice();
    void receiverChanged(TypingReceiver::Status status);
    void giveReceiverString();
    void getFileDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::TypingPractice *ui;
    TextManager tm;
    TypingReceiver *receiver;

    void enableControls(bool enabled);
};

#endif // TYPINGPRACTICE_H
