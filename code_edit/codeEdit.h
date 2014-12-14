// =====================================================================================
// 
//       Filename:  codeEdit.h
//
//    Description:  编辑类声明
//
//        Version:  1.0
//        Created:  2014年12月14日 10时28分54秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  ZhangRui, v.me-zr@live.cn
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#ifndef CODEEDIT_H
#define CODEEDIT_H

#include <QPlainTextEdit>
#include <QObject>
#include "highlight.h"

QT_BEGIN_NAMESPACE
class QPaintEvent;
class QResizeEvent;
class QSize;
class QWidget;
class MainWindow;
QT_END_NAMESPACE

class LineNumberArea;

//![codeeditordefinition]
class CodePad : public QPlainTextEdit
{
    Q_OBJECT

public:
    CodePad(QWidget *parent = 0);
    ~CodePad();

    //![line number members]
public:
    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();

protected:
    void resizeEvent(QResizeEvent *event);

private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &, int dy);

public:
    QWidget *lineNumberArea;
    int numWidth;
    bool lineNumberEnable;
    bool currentLineEnable;
    //![line number members]

    //![highlighter]
public:
    Highlighter *highlighter;
    //![highlighter]

    //![editor members]
public:
    int open(const QString &fileName);
    int saveAs(const QString &fileName);
    int save();

    QString getTabName() const { return tabName; }
    void setTabName(const QString &tabName) { this->tabName = tabName; }
    QString getFileName() const { return fileName; }
    bool getChanged() { return isChanged; }
    void setChanged(bool change) { isChanged = change; }

    void setCodec(int codec) { this->codec = codec; }
    int getCodec() { return codec; }

private:
    QString fileName;
    QString tabName;
    bool isChanged;

public slots:
    void updateTextEdit();

public:
    int codec;
private:
    QByteArray encodedData;
    QString decodedStr;
public:
    void setup();
private:
    MainWindow *wnd;
    //![editor members]
};
//![codeeditordefinition]

//![extraarea]
class LineNumberArea : public QWidget
{
public:
    LineNumberArea(CodePad *editor) : QWidget(editor) {
        codeEditor = editor;
    }

    QSize sizeHint() const {
        return QSize(codeEditor->lineNumberAreaWidth(), 0);
    }

protected:
    void paintEvent(QPaintEvent *event) {
        codeEditor->lineNumberAreaPaintEvent(event);
    }

private:
    CodePad *codeEditor;
};
//![extraarea]

#endif // CODEEDIT_H
