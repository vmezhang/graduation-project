// =====================================================================================
// 
//       Filename:  highlight.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  2014年12月14日 10时29分26秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  ZhangRui, v.me-zr@live.cn
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>

#include "highlight.h"

//! [structer]
Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    stringFormat.setForeground(Qt::darkCyan);
    keywordFormat.setForeground(Qt::darkYellow);
//    keywordFormat.setFontWeight(QFont::Bold);
//    classFormat.setForeground(Qt::darkMagenta);
//    classFormat.setFontWeight(QFont::Bold);
//    functionFormat.setForeground(Qt::blue);
//    functionFormat.setFontItalic(true);
    expressionFormat.setForeground(Qt::darkMagenta);
//    expressionFormat.setFontWeight(QFont::Bold);
    numberFormat.setForeground(Qt::red);
    preProcessorCommandFormat.setForeground(Qt::darkYellow);
    singleLineCommentFormat.setForeground(Qt::darkGreen);
    multiLineCommentFormat.setForeground(Qt::darkGreen);

//! [Q started class]
    rule.format = classFormat;
    rule.pattern = QRegExp("\\bQ[A-Za-z][A-Za-z0-9]+\\b");
    rule.pattern.setMinimal(false);
    highlightingRules.append(rule);
//! [Q started class]

////! [functions]
//    rule.format = functionFormat;
//    rule.pattern = QRegExp("\\b[A-Za-z0-9_]+(?=\\()");
//    rule.pattern.setMinimal(false);
//    highlightingRules.append(rule);
////! [functions]

//! [expression]
    rule.format = expressionFormat;
    rule.pattern = QRegExp("[\\+\\-\\*/=,.:;?%&|^!<>()\\[\\]{}]");
    rule.pattern.setMinimal(false);
    highlightingRules.append(rule);
//! [expression]

//! [numberFormat]
    rule.format = numberFormat;
    rule.pattern = QRegExp("([.]|\\b)[0-9][A-Za-z0-9.]*");
    rule.pattern.setMinimal(false);
    highlightingRules.append(rule);
//! [numberFormat]

//! [keywords]
    QStringList keywordPatterns;
    keywordPatterns << "\\bint\\b" << "\\bchar\\b" << "\\bbool\\b"
            << "\\bfloat\\b" << "\\bdouble\\b" << "\\bshort\\b" << "\\blong\\b"
            << "\\bif\\b" << "\\belse\\b" << "\\bswitch\\b" << "\\bcase\\b" << "\\bdefault\\b"
            << "\\bfor\\b" << "\\bwhile\\b" << "\\bdo\\b"
            << "\\bcontinue\\b" << "\\bbreak\\b"
            << "\\bvoid\\b" << "\\breturn\\b" << "\\bconst\\b" << "\\bgoto\\b"
            << "\\bvolatile\\b" << "\\bstatic\\b" << "\\bunsigned\\b" << "\\bsigned\\b"
            << "\\benum\\b" << "\\bstruct\\b" << "\\bunion\\b"
            << "\\bauto\\b" << "\\bregister\\b" << "\\bextern\\b"
            << "\\bsizeof\\b" << "\\btypedef\\b" << "\\bclass\\b" << "\\bnew\\b" << "\\bdelete\\b"
            << "\\bpublic\\b" << "\\bprivate\\b" << "\\bprotected\\b"
            << "\\bthis\\b" << "\\btry\\b"<< "\\bcatch\\b" << "\\bthrow\\b"
            << "\\btrue\\b" << "\\bfalse\\b"
            << "\\basm\\b" << "\\bexplicit\\b" << "\\bexport\\b" << "\\btypename\\b"
            << "\\bfriend\\b" << "\\binline\\b" << "\\bmutable\\b" << "\\boperator\\b" << "\\btemplate\\b"
            << "\\btypeid\\b" << "\\bvirtual\\b" << "\\bwarch_t\\b" << "\\busing\\b" << "\\bnamespace\\b"
            << "\\bconst_cast\\b" << "\\bdynamic_cast\\b" << "\\breinterpret_cast\\b" << "\\bstatic_cast\\b";

    foreach (const QString &pattern, keywordPatterns) {
        rule.format = keywordFormat;
        rule.pattern = QRegExp(pattern);
        rule.pattern.setMinimal(false);
        highlightingRules.append(rule);
    }
//! [keywords]

//! [preProcessorCommand]
    rule.format = preProcessorCommandFormat;
    rule.pattern = QRegExp("(#[^\\n]+)|(#\\n)");
    rule.pattern.setMinimal(false);
    highlightingRules.append(rule);
//! [preProcessorCommand]


//! [// comments]
    rule.format = singleLineCommentFormat;
    rule.pattern = QRegExp("//[^\n]*");
    rule.pattern.setMinimal(false);
    highlightingRules.append(rule);
//! [// comments]

//! [/* */ comments]
    commentStartExpression = QRegExp("/\\*");
    commentEndExpression = QRegExp("\\*/");
//! [/* */ comments]
}
//! [structer]

//! [custom highlight]
void Highlighter::highlightBlock(const QString &text)
{
    if (!enable)
        return;

    //! [strings]
    stringHighlights.clear();
    StringHighlight hightlight;

    QRegExp stringRegExp = QRegExp("\".*[^\\\\]\"|\"\"");
    stringRegExp.setMinimal(true);
    int index = stringRegExp.indexIn(text);
    while (index >= 0) {
        int length = stringRegExp.matchedLength();

        hightlight.index = index;
        hightlight.length = length;
        stringHighlights.append(hightlight);

        setFormat(index, length, stringFormat);
        index = stringRegExp.indexIn(text, index + length);
    }

    stringRegExp = QRegExp("'.*[^\\\\]'|''");
    stringRegExp.setMinimal(true);
    index = stringRegExp.indexIn(text);
    while (index >= 0) {
        int length = stringRegExp.matchedLength();

        hightlight.index = index;
        hightlight.length = length;
        stringHighlights.append(hightlight);

        setFormat(index, length, stringFormat);
        index = stringRegExp.indexIn(text, index + length);
    }
    //! [strings]

    bool inString = false;

    //! [key words highlight]
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);

        while (index >= 0) {
            foreach(const StringHighlight &hl, stringHighlights) {
                if(index > hl.index && index < hl.index+hl.length) {
                    inString = true;
                    break;
                }
            }
            int length = expression.matchedLength();

            if(!inString) {
                setFormat(index, length, rule.format);
            } else {
                inString = false;
            }

            index = expression.indexIn(text, index + length);
        }
    }
    //! [key words highlight]

    //! [/* */ comments highlight]
    setCurrentBlockState(0);

    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = commentStartExpression.indexIn(text);

    while (startIndex >= 0) {
        foreach(const StringHighlight &hl, stringHighlights) {
            if(startIndex > hl.index && startIndex < hl.index+hl.length) {
                inString = true;
                break;
            }
        }
        if(inString) {
            startIndex = commentStartExpression.indexIn(text, startIndex + 2);
            inString = false;
            continue;
        }
        int endIndex = commentEndExpression.indexIn(text, startIndex);
        int commentLength;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + commentEndExpression.matchedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
    }
    //! [/* */ comments highlight]
}
//! [custom highlight]


