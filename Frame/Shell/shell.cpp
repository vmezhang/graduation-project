// =====================================================================================
// 
//       Filename:  shell.cpp
//
//    Description:  shell窗口的实现
//
//        Version:  1.0
//        Created:  2014年12月10日 09时36分13秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  ZhangRui, v.me-zr@live.cn
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include "testShell.h"
#include <QLineEdit>
#include <QTextBlock>
#include <QDebug>

ShellEdit::ShellEdit(QWidget *parent) : QPlainTextEdit(parent)
{
    // 设置只读模式
    setReadOnly(true);
    // 加入>>>提示句
    appendPlainText(">>> ");
    // 设置QPlainTextEdit属性
    setStyleSheet("QPlainTextEdit{background:black;font:bold;color:#E0EEEE}");

    edit = new QLineEdit(this->viewport());
    // 设置edit属性
    edit->setStyleSheet("QLineEdit{background:black;font:bold;color:#E0EEEE;border-width:0;border-style:outset}");
    // 触发enter信号
    connect(edit, SIGNAL(returnPressed()), SLOT(onEditFinished()));
}

void ShellEdit::resizeEvent(QResizeEvent *e)
{
    updateEditPosition();
}

QString ShellEdit::runCommand(const QString &cmd)
{

   //调用系统中的命令
    QString cmd2;
    cmd2 = cmd + ">cmd.txt";
    int ret;
    ret = system(cmd2.toLatin1().data());
    qDebug("%d", ret);
    if (ret != 0) {
        return QString("%1:命令不存在").arg(cmd);
    }
    QString qcmd;
    QFile cmdfile("cmd.txt");
    cmdfile.open(QFile::ReadWrite);
    qcmd = cmdfile.readAll();
    return qcmd;

    // 添加自定义系统调用
    // return readShell(cmd);

}


void ShellEdit::onEditFinished()
{
    QString cmd = edit->text();
    // 如果输入为空则光标跳到下一行
    if (cmd.isEmpty()) {
        moveCursor(QTextCursor::End);
        edit->setStyleSheet("QLineEdit{background:black;font:bold;color:#E0EEEE;border-width:0;border-style:outset}");
        edit->clear();

        appendPlainText(">>> ");
        updateEditPosition();

        edit->show();
        edit->setFocus();
        return;
    }
    // 解析输入的命令，并使光标跳到下一行
    moveCursor(QTextCursor::End);
    insertPlainText(cmd);
    edit->setStyleSheet("QLineEdit{background:black;font:bold;color:#E0EEEE;border-width:0;border-style:outset}");
    edit->clear();

    appendPlainText(runCommand(cmd));
    appendPlainText(">>> ");
    updateEditPosition();

    edit->show();
    edit->setFocus();
}

void ShellEdit::updateEditPosition()
{
    resize(size());
    // 构造一个矩形,并返回当前光标
    QRect rect = cursorRect();
    edit->setStyleSheet("QLineEdit{background:black;font:bold;color:#E0EEEE;border-width:0;border-style:outset}");
    edit->resize(viewport()->size().width(), edit->size().height());
    // 将edit放在矩形的右上角位置
    edit->move(rect.topRight());
}

void ShellEdit::closeEvent(QCloseEvent *event)
{
    event->accept();
}
