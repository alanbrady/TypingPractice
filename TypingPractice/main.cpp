#include <QtGui/QApplication>
#include "typingpractice.h"
#include "typingreceiver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TypingPractice w;
    //TypingReceiver w;
    w.show();
    return a.exec();
}

/*
#include "textmanager.h"
#include <QString>
#include <QDebug>

int main(int argc, char *argv[]) {
    TextManager tm;

    tm.addText("This is a sentence.  This is another.  This is ");
    tm.addText("yet another.");
    //tm.setMode(TextManager::RandomMode);

    qDebug() << QString(tm.getNextLine().c_str());
    qDebug() << QString(tm.getNextLine().c_str());
    qDebug() << QString(tm.getNextLine().c_str());

    return 0;
}
*/
