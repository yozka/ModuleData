/********************************************************************************
** Form generated from reading UI file 'ModuleData.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
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
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuChart;
    QMenu *menuWindows;
    QMenu *menuData;
    QMenu *menuCreate;
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
        actionDelete = new QAction(AModuleDataClass);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
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
        menuBar->setGeometry(QRect(0, 0, 1058, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuChart = new QMenu(menuBar);
        menuChart->setObjectName(QStringLiteral("menuChart"));
        menuWindows = new QMenu(menuBar);
        menuWindows->setObjectName(QStringLiteral("menuWindows"));
        menuData = new QMenu(menuBar);
        menuData->setObjectName(QStringLiteral("menuData"));
        menuCreate = new QMenu(menuData);
        menuCreate->setObjectName(QStringLiteral("menuCreate"));
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
        menuData->addAction(menuCreate->menuAction());
        menuData->addAction(actionDataView);
        menuCreate->addAction(actionRandomGenerator);
        menuCreate->addAction(actionManualControl);
        menuCreate->addAction(actionComPort);

        retranslateUi(AModuleDataClass);
        QObject::connect(actionExit, SIGNAL(triggered()), AModuleDataClass, SLOT(close()));

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(AModuleDataClass);
    } // setupUi

    void retranslateUi(QMainWindow *AModuleDataClass)
    {
        AModuleDataClass->setWindowTitle(QApplication::translate("AModuleDataClass", "AModuleData", 0));
        actionExit->setText(QApplication::translate("AModuleDataClass", "&Exit", 0));
        actionMarking->setText(QApplication::translate("AModuleDataClass", "&Marking\342\200\246", 0));
        actionRandomGenerator->setText(QApplication::translate("AModuleDataClass", "Random generator\342\200\246", 0));
        actionManualControl->setText(QApplication::translate("AModuleDataClass", "Manual control\342\200\246", 0));
        actionComPort->setText(QApplication::translate("AModuleDataClass", "Com port\342\200\246", 0));
        actionDataView->setText(QApplication::translate("AModuleDataClass", "View", 0));
        actionChartNew->setText(QApplication::translate("AModuleDataClass", "New", 0));
        actionDelete->setText(QApplication::translate("AModuleDataClass", "Delete", 0));
        menuFile->setTitle(QApplication::translate("AModuleDataClass", "FILE", 0));
        menuChart->setTitle(QApplication::translate("AModuleDataClass", "CHART", 0));
        menuWindows->setTitle(QApplication::translate("AModuleDataClass", "WINDOWS", 0));
        menuData->setTitle(QApplication::translate("AModuleDataClass", "DATA", 0));
        menuCreate->setTitle(QApplication::translate("AModuleDataClass", "Create", 0));
    } // retranslateUi

};

namespace Ui {
    class AModuleDataClass: public Ui_AModuleDataClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODULEDATA_H
