#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>

namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();

private:
    Ui::RegisterDialog *ui;

    void showTip(QString str);
public slots:
    void sendVerificationCode();
};

#endif // REGISTERDIALOG_H
