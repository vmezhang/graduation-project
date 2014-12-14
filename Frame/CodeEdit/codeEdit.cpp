// =====================================================================================
// 
//       Filename:  codeEdit.cpp
//
//    Description:  编辑实现
//
//        Version:  1.0
//        Created:  2014年12月14日 10时29分00秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  ZhangRui, v.me-zr@live.cn
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>
#include "codeEdit.h"
#include "codeWindow.h"

CodePad::CodePad(QWidget *parent):
        QPlainTextEdit(parent)
{
    //![line number members]
    lineNumberArea = new LineNumberArea(this);
    connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));
    connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateLineNumberArea(QRect,int)));
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));

    updateLineNumberAreaWidth(0);
    highlightCurrentLine();
    //![line number members]

    //![highlighter]
    highlighter = new Highlighter(this->document());
    //![highlighter]

    //![getWindow]
    wnd = (CodeWindow *)parent;
    this->codec = wnd->codec;
    setup();
    //![getWindow]

    //![editor members]
    fileName.clear();
    tabName.clear();
    isChanged = false;
    //![editor members]
}

CodePad::~CodePad()
{
}

//![extraAreaWidth]
int CodePad::lineNumberAreaWidth()
{
    if (!lineNumberEnable)
        return 0;

    int digits = 3;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    int space = fontMetrics().width(QLatin1Char('9')) * digits;

    return space;
}
//![extraAreaWidth]

//![slotUpdateExtraAreaWidth]
void CodePad::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}
//![slotUpdateExtraAreaWidth]

//![slotUpdateRequest]
void CodePad::updateLineNumberArea(const QRect &rect, int dy)
{
    if (!lineNumberEnable)
        return ;

    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        updateLineNumberAreaWidth(0);
}
//![slotUpdateRequest]

//![resizeEvent]
void CodePad::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);

    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}
//![resizeEvent]

//![cursorPositionChanged]
void CodePad::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;

        if (currentLineEnable)
            selection.format.setBackground(QColor(Qt::yellow).lighter(180));
        else
            selection.format.setBackground(QColor(Qt::transparent));
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }

    setExtraSelections(extraSelections);
}
//![cursorPositionChanged]

//![extraAreaPaintEvent]
void CodePad::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    if (!lineNumberEnable)
        return ;

    //![extraAreaPaintEvent_0]
    QPainter painter(lineNumberArea);
    //painter.fillRect(event->rect(), Qt::lightGray);
    //![extraAreaPaintEvent_0]

    //![extraAreaPaintEvent_1]
    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom = top + (int) blockBoundingRect(block).height();
    //![extraAreaPaintEvent_1]

    //![extraAreaPaintEvent_2]
    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            if (textCursor().blockNumber() == blockNumber) {
                painter.setPen(Qt::black);
            } else {
                painter.setPen(Qt::darkGray);
            }
            painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
                             Qt::AlignRight, number+tr(" "));
        }

        block = block.next();
        top = bottom;
        bottom = top + (int) blockBoundingRect(block).height();
        ++blockNumber;
    }
    //![extraAreaPaintEvent_2]
}
//![extraAreaPaintEvent]

//![editor members]

void CodePad::setup()
{
    this->lineNumberEnable = wnd->lineNumberEnable;
    this->highlighter->setEnable(wnd->highlightEnable);
    this->currentLineEnable = wnd->currentLineEnable;
    this->setFont(wnd->font);
    this->setWordWrapMode(wnd->wrapMode);
    // refresh
    blockSignals(true);
    updateLineNumberAreaWidth(0);
    highlightCurrentLine();
    highlighter->rehighlight();
    update();
    blockSignals(false);
}

//![open files]
int CodePad::open(const QString &fileName)
{
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QFile::ReadWrite)) {
            QMessageBox::warning(this, tr("CodeEdit"),
                                 tr("Cannot read file %1:\n%2")
                                 .arg(fileName)
                                 .arg(file.errorString()));
            return -2;
        }
        encodedData = file.readAll();
        file.close();
        updateTextEdit();

        this->fileName = fileName;
        this->tabName = QFileInfo(fileName).fileName();
        this->isChanged = false;
        return 0;
    } else {
        return -1;
    }
}
//![open files]

//![save files as]
int CodePad::saveAs(const QString &fileName)
{
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, tr("CodeEdit"),
                                 tr("Cannot write file %1:\n%2")
                                 .arg(fileName)
                                 .arg(file.errorString()));
            return -2;
        }

        QTextStream out(&file);
        out.setCodec(QTextCodec::codecForMib(this->codec));
        out << this->toPlainText();
        file.close();
        this->fileName = fileName;
        this->tabName = QFileInfo(fileName).fileName();
        this->isChanged = false;
        return 0;
    } else {
        return -1;
    }
}
//![save files as]

//![save files]
int CodePad::save()
{
   return saveAs(this->fileName);
}
//![save files]

void CodePad::updateTextEdit()
{
    QTextCodec *codec = QTextCodec::codecForMib(this->codec);

    QTextStream in(&encodedData);
    in.setAutoDetectUnicode(false);
    in.setCodec(codec);
    decodedStr = in.readAll();

    this->setPlainText(decodedStr);
}
//![editor members]

