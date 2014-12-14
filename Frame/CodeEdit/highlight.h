// =====================================================================================
// 
//       Filename:  highlight.h
//
//    Description:  代码高亮类
//
//        Version:  1.0
//        Created:  2014年12月14日 10时29分16秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  ZhangRui, v.me-zr@live.cn
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#ifndef HIGHLIGHT_H
#define HIGHLIGHT_H

#include <QSyntaxHighlighter>

#include <QHash>
#include <QTextCharFormat>

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE

//! [0]
class Highlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    Highlighter(QTextDocument *parent = 0);

protected:
    void highlightBlock(const QString &text);

private:
    struct HighlightingRule
    {
        QRegExp pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    struct StringHighlight
    {
        int index;
        int length;
    };
    QVector<StringHighlight> stringHighlights;

    QRegExp commentStartExpression;
    QRegExp commentEndExpression;

    QTextCharFormat keywordFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;
    QTextCharFormat expressionFormat;
    QTextCharFormat numberFormat;
    QTextCharFormat preProcessorCommandFormat;
    QTextCharFormat stringFormat;
public:
    bool isEnable() { return enable; }
    void setEnable(bool enable) { this->enable = enable; }
private:
    bool enable;
};
//! [0]

#endif // HIGHLIGHT_H

