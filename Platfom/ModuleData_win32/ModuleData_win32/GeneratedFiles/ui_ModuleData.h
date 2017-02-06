/********************************************************************************
** Form generated from reading UI file 'ModuleData.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AModuleDataClass
{
public:
    QAction *actionExit;
    QAction *actionMarking;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuWindows;
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
        centralWidget = new QWidget(AModuleDataClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        AModuleDataClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AModuleDataClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1058, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuWindows = new QMenu(menuBar);
        menuWindows->setObjectName(QStringLiteral("menuWindows"));
        AModuleDataClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AModuleDataClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        AModuleDataClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AModuleDataClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        AModuleDataClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuWindows->menuAction());
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionMarking);

        retranslateUi(AModuleDataClass);
        QObject::connect(actionExit, SIGNAL(triggered()), AModuleDataClass, SLOT(close()));

        QMetaObject::connectSlotsByName(AModuleDataClass);
    } // setupUi

    void retranslateUi(QMainWindow *AModuleDataClass)
    {
        AModuleDataClass->setWindowTitle(QApplication::translate("AModuleDataClass", "AModuleData", 0));
        actionExit->setText(QApplication::translate("AModuleDataClass", "&Exit", 0));
        actionMarking->setText(QApplication::translate("AModuleDataClass", "&Marking...", 0));
        menuFile->setTitle(QApplication::translate("AModuleDataClass", "File", 0));
        menuEdit->setTitle(QApplication::translate("AModuleDataClass", "Edit", 0));
        menuWindows->setTitle(QApplication::translate("AModuleDataClass", "Windows", 0));
    } // retranslateUi

};

namespace Ui {
    class AModuleDataClass: public Ui_AModuleDataClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODULEDATA_H
