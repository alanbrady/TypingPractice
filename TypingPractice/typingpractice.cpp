#include "typingpractice.h"
#include <QFileDialog>
#include "ui_typingpractice.h"
#include "filereader.h"

#include <QtCore>

TypingPractice::TypingPractice(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TypingPractice)
{
    ui->setupUi(this);

    receiver = new TypingReceiver();
    ui->gridMain->addWidget(receiver, 0, 0, 1, -1, Qt::AlignCenter);

    ui->statusBar->showMessage("Select a text file to begin.");

    connect(receiver, SIGNAL(statusChanged(TypingReceiver::Status)), this, SLOT(receiverChanged(TypingReceiver::Status)));
    connect(receiver, SIGNAL(needAnotherString()), this, SLOT(giveReceiverString()));
}

TypingPractice::~TypingPractice()
{
    delete ui;
}

void TypingPractice::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void TypingPractice::startPractice() {
    //this->receiver->setString("This is the first string.");
    this->receiver->setStatus(TypingReceiver::Started);
}

void TypingPractice::pausePractice() {
    this->receiver->setStatus(TypingReceiver::Paused);
}

void TypingPractice::stopPractice() {
    this->receiver->setStatus(TypingReceiver::Stopped);
}

void TypingPractice::receiverChanged(TypingReceiver::Status status) {
    if (status == TypingReceiver::Started)
        ui->statusBar->showMessage("Practice Started");
    else if (status == TypingReceiver::Paused)
        ui->statusBar->showMessage("Practice Pause");
    else if (status == TypingReceiver::Stopped)
        ui->statusBar->showMessage("Practice Stopped");
}

void TypingPractice::giveReceiverString() {
    //this->receiver->setString("  This is another test string.");
    this->receiver->setString(this->tm.getNextLine().c_str());
}

void TypingPractice::getFileDialog() {
    QString file = QFileDialog::getOpenFileName(this, "Select file to practice", "", "Text files (*.txt)");
    ui->fileLabel->setText(file);
    FileReader fr(&this->tm);
    if (fr.readTextFile(file.toStdString())) {
        this->enableControls(true);
    } else {
        ui->fileLabel->setText("File cannnot be opened");
    }
}

void TypingPractice::enableControls(bool enabled) {
    ui->buttonStart->setEnabled(enabled);
    ui->buttonPause->setEnabled(enabled);
    ui->buttonStop->setEnabled(enabled);
}
