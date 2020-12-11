#ifndef AUTHORISEWINDOW_H
#define AUTHORISEWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QList>
#include "file.h"
#include "account.h"
#include "menuwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class AuthoriseWindow;
}
QT_END_NAMESPACE

class AuthoriseWindow : public QMainWindow
{
    Q_OBJECT

public:
    AuthoriseWindow(QWidget *parent = nullptr);
    ~AuthoriseWindow();

private slots:
    void on_authorization_clicked();

    void on_exit_clicked();

private:
    Ui::AuthoriseWindow *ui;
};
#endif // AUTHORISEWINDOW_H
