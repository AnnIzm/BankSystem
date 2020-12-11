#include "authorisewindow.h"
#include "credit.h"
#include "file.h"
#include <QList>
#include <QApplication>
#include "creditthread.h"
#include "depositthread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AuthoriseWindow *w = new AuthoriseWindow;
    w->show();
    CreditThread creditThread;
    creditThread.start();
    DepositThread depositThread;
    depositThread.start();
    return a.exec();
}
