#include <QRegularExpression>
#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "global.h"

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);

    ui->password_edit->setEchoMode(QLineEdit::Password);
    ui->confirm_edit->setEchoMode(QLineEdit::Password);

    // 添加样式设置
    ui->tip_label->setProperty("state", "normal");
    repolish(ui->tip_label);

    // 验证码逻辑
    connect(ui->verification_code_btn, &QPushButton::clicked, this, &RegisterDialog::sendVerificationCode);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::sendVerificationCode(){
    // 验证邮箱地址
    auto email = ui->email_edit->text();
    static QRegularExpression regex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    bool match = regex.match(email).hasMatch();

    if(!match){
        return showTip(tr("请输入正确的邮箱地址！"));
    }

    // todo:发送http请求获取验证码

}

void RegisterDialog::showTip(QString str){
    ui->tip_label->setText(str);
    ui->tip_label->setProperty("state", "error");
    repolish(ui->tip_label);
}
