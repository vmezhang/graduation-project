/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon May 11 19:13:31 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONITOR_H
#define UI_MONITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_monitor
{
public:
    QAction *actionStart;
    QAction *actionSave_as;
    QAction *actionExit;
    QAction *actionGroup;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_4;
    QLabel *ker_ver_lb;
    QLabel *ker_ver_contex;
    QLabel *hostname_lb;
    QLabel *hostname_contex;
    QLabel *process_lb;
    QLabel *process_contex;
    QWidget *tab_2;
    QTableWidget *tableWidget_2;
    QWidget *tab_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *lcdNumber_2;
    QLCDNumber *lcdNumber_3;
    QLCDNumber *lcdNumber_1;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(700, 388);
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionGroup = new QAction(MainWindow);
        actionGroup->setObjectName(QString::fromUtf8("actionGroup"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, -1, 711, 331));
        QFont font;
        font.setFamily(QString::fromUtf8("Sans Serif"));
        font.setPointSize(12);
        tabWidget->setFont(font);
        tabWidget->setMouseTracking(false);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(true);
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        ker_ver_lb = new QLabel(tab_4);
        ker_ver_lb->setObjectName(QString::fromUtf8("ker_ver_lb"));
        ker_ver_lb->setGeometry(QRect(20, 80, 151, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("CM Roman Asian"));
        font1.setPointSize(12);
        ker_ver_lb->setFont(font1);
        ker_ver_contex = new QLabel(tab_4);
        ker_ver_contex->setObjectName(QString::fromUtf8("ker_ver_contex"));
        ker_ver_contex->setGeometry(QRect(200, 80, 221, 31));
        ker_ver_contex->setFont(font1);
        ker_ver_contex->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        hostname_lb = new QLabel(tab_4);
        hostname_lb->setObjectName(QString::fromUtf8("hostname_lb"));
        hostname_lb->setGeometry(QRect(20, 40, 151, 31));
        hostname_lb->setFont(font1);
        hostname_contex = new QLabel(tab_4);
        hostname_contex->setObjectName(QString::fromUtf8("hostname_contex"));
        hostname_contex->setGeometry(QRect(200, 40, 221, 31));
        hostname_contex->setFont(font1);
        hostname_contex->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        process_lb = new QLabel(tab_4);
        process_lb->setObjectName(QString::fromUtf8("process_lb"));
        process_lb->setGeometry(QRect(20, 130, 131, 21));
        process_lb->setFont(font1);
        process_contex = new QLabel(tab_4);
        process_contex->setObjectName(QString::fromUtf8("process_contex"));
        process_contex->setGeometry(QRect(200, 130, 471, 21));
        process_contex->setFont(font1);
        process_contex->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        tabWidget->addTab(tab_4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tableWidget_2 = new QTableWidget(tab_2);
        if (tableWidget_2->columnCount() < 6)
            tableWidget_2->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (tableWidget_2->rowCount() < 2)
            tableWidget_2->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget_2->setItem(0, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget_2->setItem(1, 0, __qtablewidgetitem9);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(10, 20, 681, 201));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget_2->sizePolicy().hasHeightForWidth());
        tableWidget_2->setSizePolicy(sizePolicy);
        tableWidget_2->setTextElideMode(Qt::ElideMiddle);
        tableWidget_2->horizontalHeader()->setStretchLastSection(true);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        label = new QLabel(tab_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 60, 150, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("CM Roman"));
        font2.setPointSize(20);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(260, 60, 150, 20));
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(440, 60, 150, 20));
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(tab_3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 100, 531, 111));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lcdNumber_2 = new QLCDNumber(layoutWidget);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setFrameShape(QFrame::StyledPanel);
        lcdNumber_2->setFrameShadow(QFrame::Plain);

        horizontalLayout->addWidget(lcdNumber_2);

        lcdNumber_3 = new QLCDNumber(layoutWidget);
        lcdNumber_3->setObjectName(QString::fromUtf8("lcdNumber_3"));
        lcdNumber_3->setFrameShape(QFrame::StyledPanel);
        lcdNumber_3->setFrameShadow(QFrame::Plain);

        horizontalLayout->addWidget(lcdNumber_3);

        lcdNumber_1 = new QLCDNumber(layoutWidget);
        lcdNumber_1->setObjectName(QString::fromUtf8("lcdNumber_1"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("CM Roman"));
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        lcdNumber_1->setFont(font3);
        lcdNumber_1->setCursor(QCursor(Qt::ArrowCursor));
        lcdNumber_1->setAutoFillBackground(false);
        lcdNumber_1->setFrameShape(QFrame::StyledPanel);
        lcdNumber_1->setFrameShadow(QFrame::Plain);
        lcdNumber_1->setSmallDecimalPoint(false);

        horizontalLayout->addWidget(lcdNumber_1);

        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 28));
        menuBar->setDefaultUp(false);
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMovable(true);
        mainToolBar->setToolButtonStyle(Qt::ToolButtonFollowStyle);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(tableWidget_2, tabWidget);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(activated()), MainWindow, SLOT(close()));
        QObject::connect(actionGroup, SIGNAL(activated()), MainWindow, SLOT(show()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "System In View", 0, QApplication::UnicodeUTF8));
        actionStart->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionGroup->setText(QApplication::translate("MainWindow", "Group", 0, QApplication::UnicodeUTF8));
        ker_ver_lb->setText(QApplication::translate("MainWindow", "Kernel Version:", 0, QApplication::UnicodeUTF8));
        ker_ver_contex->setText(QString());
        hostname_lb->setText(QApplication::translate("MainWindow", "Host Name:", 0, QApplication::UnicodeUTF8));
        hostname_contex->setText(QString());
        process_lb->setText(QApplication::translate("MainWindow", "Processor:", 0, QApplication::UnicodeUTF8));
        process_contex->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "BasicInfo", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "MemTotal", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "MemFree", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Buffers", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Cached", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "SwapTotal", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "SwapFree", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_2->verticalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Capacity(KB)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_2->verticalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Capacity(MB)", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = tableWidget_2->isSortingEnabled();
        tableWidget_2->setSortingEnabled(false);
        tableWidget_2->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "MemInfo", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "1  Minute", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "5  Minutes", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "15  Minutes", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "LoadAvg", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class monitor: public Ui_monitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
