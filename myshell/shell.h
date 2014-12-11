// =====================================================================================
// 
//       Filename:  shell.h
//
//    Description:  shell窗口类
//
//        Version:  1.0
//        Created:  2014年12月10日 09时36分01秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  ZhangRui, v.me-zr@live.cn
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#ifndef SHELL_H
#define SHELL_H

#include <QPlainTextEdit>

class QLineEdit;

class ShellEdit : public QPlainTextEdit {
    Q_OBJECT
public:
    explicit ShellEdit(QWidget *parent = 0);
    // 命令行解析函数
    virtual QString runCommand(const QString& cmd);

protected:
    // 重写鼠标事件
    void resizeEvent(QResizeEvent *e);

private slots:
    // 输入enter键的响应槽
    void onEditFinished();

private:
    // 使光标移动到当前位置
    void updateEditPosition();
    QLineEdit *edit;
};

#endif  // SHELL_H
