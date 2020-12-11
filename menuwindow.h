#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include "authorisewindow.h"
#include <QMainWindow>

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QString login = nullptr);
    ~MenuWindow();

private slots:
    void on_exit_clicked();

    void on_add_clicked();

    void on_get_clicked();

    void on_credit_clicked();

    void on_deposit_clicked();

    void changed();

private:
    Ui::MenuWindow *ui;
    QString login;
};

#endif // MENUWINDOW_H
