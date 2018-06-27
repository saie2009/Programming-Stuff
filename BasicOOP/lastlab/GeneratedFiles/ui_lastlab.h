/********************************************************************************
** Form generated from reading UI file 'lastlab.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LASTLAB_H
#define UI_LASTLAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lastlabClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *lastlabClass)
    {
        if (lastlabClass->objectName().isEmpty())
            lastlabClass->setObjectName(QStringLiteral("lastlabClass"));
        lastlabClass->resize(600, 400);
        menuBar = new QMenuBar(lastlabClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        lastlabClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(lastlabClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        lastlabClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(lastlabClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lastlabClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(lastlabClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        lastlabClass->setStatusBar(statusBar);

        retranslateUi(lastlabClass);

        QMetaObject::connectSlotsByName(lastlabClass);
    } // setupUi

    void retranslateUi(QMainWindow *lastlabClass)
    {
        lastlabClass->setWindowTitle(QApplication::translate("lastlabClass", "lastlab", 0));
    } // retranslateUi

};

namespace Ui {
    class lastlabClass: public Ui_lastlabClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LASTLAB_H
