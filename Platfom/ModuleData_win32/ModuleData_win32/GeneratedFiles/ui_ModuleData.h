/********************************************************************************
** Form generated from reading UI file 'ModuleData.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODULEDATA_H
#define UI_MODULEDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AModuleDataClass
{
public:
    QAction *actionExit;
    QAction *actionMarking;
    QAction *actionRandomGenerator;
    QAction *actionManualControl;
    QAction *actionComPort;
    QAction *actionDataView;
    QAction *actionChartNew;
    QAction *actionDelete;
    QAction *actionChartClose;
    QAction *actionChartPlay;
    QAction *actionChartPause;
    QAction *actionChartStop;
    QAction *actionDataDelete;
    QAction *actionDataSelect;
    QAction *actionChartData;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuChart;
    QMenu *menuWindows;
    QMenu *menuData;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AModuleDataClass)
    {
        if (AModuleDataClass->objectName().isEmpty())
            AModuleDataClass->setObjectName(QStringLiteral("AModuleDataClass"));
        AModuleDataClass->resize(1058, 745);
        actionExit = new QAction(AModuleDataClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionMarking = new QAction(AModuleDataClass);
        actionMarking->setObjectName(QStringLiteral("actionMarking"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icons/Icons/bookmark.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMarking->setIcon(icon);
        actionRandomGenerator = new QAction(AModuleDataClass);
        actionRandomGenerator->setObjectName(QStringLiteral("actionRandomGenerator"));
        actionManualControl = new QAction(AModuleDataClass);
        actionManualControl->setObjectName(QStringLiteral("actionManualControl"));
        actionComPort = new QAction(AModuleDataClass);
        actionComPort->setObjectName(QStringLiteral("actionComPort"));
        actionDataView = new QAction(AModuleDataClass);
        actionDataView->setObjectName(QStringLiteral("actionDataView"));
        actionChartNew = new QAction(AModuleDataClass);
        actionChartNew->setObjectName(QStringLiteral("actionChartNew"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Icons/Icons/chart_bar.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChartNew->setIcon(icon1);
        actionDelete = new QAction(AModuleDataClass);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        actionChartClose = new QAction(AModuleDataClass);
        actionChartClose->setObjectName(QStringLiteral("actionChartClose"));
        actionChartPlay = new QAction(AModuleDataClass);
        actionChartPlay->setObjectName(QStringLiteral("actionChartPlay"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Icons/Icons/playback_play.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChartPlay->setIcon(icon2);
        actionChartPause = new QAction(AModuleDataClass);
        actionChartPause->setObjectName(QStringLiteral("actionChartPause"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Icons/Icons/playback_pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChartPause->setIcon(icon3);
        actionChartStop = new QAction(AModuleDataClass);
        actionChartStop->setObjectName(QStringLiteral("actionChartStop"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Icons/Icons/playback_stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChartStop->setIcon(icon4);
        actionDataDelete = new QAction(AModuleDataClass);
        actionDataDelete->setObjectName(QStringLiteral("actionDataDelete"));
        actionDataSelect = new QAction(AModuleDataClass);
        actionDataSelect->setObjectName(QStringLiteral("actionDataSelect"));
        actionChartData = new QAction(AModuleDataClass);
        actionChartData->setObjectName(QStringLiteral("actionChartData"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Icons/Icons/db.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChartData->setIcon(icon5);
        centralWidget = new QWidget(AModuleDataClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));

        verticalLayout->addWidget(tabWidget);

        AModuleDataClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AModuleDataClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1058, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuChart = new QMenu(menuBar);
        menuChart->setObjectName(QStringLiteral("menuChart"));
        menuWindows = new QMenu(menuBar);
        menuWindows->setObjectName(QStringLiteral("menuWindows"));
        menuData = new QMenu(menuBar);
        menuData->setObjectName(QStringLiteral("menuData"));
        AModuleDataClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AModuleDataClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        AModuleDataClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AModuleDataClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        AModuleDataClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuChart->menuAction());
        menuBar->addAction(menuData->menuAction());
        menuBar->addAction(menuWindows->menuAction());
        menuFile->addAction(actionExit);
        menuChart->addAction(actionMarking);
        menuChart->addSeparator();
        menuChart->addAction(actionChartNew);
        menuChart->addAction(actionChartClose);
        menuChart->addSeparator();
        menuChart->addAction(actionChartPlay);
        menuChart->addAction(actionChartPause);
        menuChart->addAction(actionChartStop);
        menuChart->addSeparator();
        menuChart->addAction(actionChartData);

        retranslateUi(AModuleDataClass);
        QObject::connect(actionExit, SIGNAL(triggered()), AModuleDataClass, SLOT(close()));

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(AModuleDataClass);
    } // setupUi

    void retranslateUi(QMainWindow *AModuleDataClass)
    {
        AModuleDataClass->setWindowTitle(QApplication::translate("AModuleDataClass", "AModuleData", Q_NULLPTR));
        actionExit->setText(QApplication::translate("AModuleDataClass", "&Exit", Q_NULLPTR));
        actionMarking->setText(QApplication::translate("AModuleDataClass", "&Marking\342\200\246", Q_NULLPTR));
        actionRandomGenerator->setText(QApplication::translate("AModuleDataClass", "Random generator\342\200\246", Q_NULLPTR));
        actionManualControl->setText(QApplication::translate("AModuleDataClass", "Manual control\342\200\246", Q_NULLPTR));
        actionComPort->setText(QApplication::translate("AModuleDataClass", "Com port\342\200\246", Q_NULLPTR));
        actionDataView->setText(QApplication::translate("AModuleDataClass", "View", Q_NULLPTR));
        actionChartNew->setText(QApplication::translate("AModuleDataClass", "New", Q_NULLPTR));
        actionDelete->setText(QApplication::translate("AModuleDataClass", "Delete", Q_NULLPTR));
        actionChartClose->setText(QApplication::translate("AModuleDataClass", "Close\342\200\246", Q_NULLPTR));
        actionChartPlay->setText(QApplication::translate("AModuleDataClass", "Play", Q_NULLPTR));
        actionChartPause->setText(QApplication::translate("AModuleDataClass", "Pause", Q_NULLPTR));
        actionChartStop->setText(QApplication::translate("AModuleDataClass", "Stop", Q_NULLPTR));
        actionDataDelete->setText(QApplication::translate("AModuleDataClass", "Delete", Q_NULLPTR));
        actionDataSelect->setText(QApplication::translate("AModuleDataClass", "Select", Q_NULLPTR));
        actionChartData->setText(QApplication::translate("AModuleDataClass", "Data...", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("AModuleDataClass", "FILE", Q_NULLPTR));
        menuChart->setTitle(QApplication::translate("AModuleDataClass", "CHART", Q_NULLPTR));
        menuWindows->setTitle(QApplication::translate("AModuleDataClass", "WINDOWS", Q_NULLPTR));
        menuData->setTitle(QApplication::translate("AModuleDataClass", "DATA", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AModuleDataClass: public Ui_AModuleDataClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODULEDATA_H
