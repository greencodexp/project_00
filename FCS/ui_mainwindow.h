/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Jul 6 22:32:08 2019
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QComboBox *ctl_cbMSGType;
    QPushButton *ctl_btnSend;
    QTableWidget *ctl_tableFCS;
    QPushButton *ctl_btnAutoTest;
    QWidget *tab_2;
    QGroupBox *groupBox_6;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *ctl_IP_FCS;
    QLineEdit *ctl_portFCS;
    QPushButton *ctl_btnApplyFCSConf;
    QPushButton *ctl_btnCancelFCSConf;
    QGroupBox *groupBox_3;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *ctl_IP_BCC;
    QLineEdit *ctl_portBCC;
    QPushButton *ctl_btnApplyBCCConf;
    QPushButton *ctl_btnCancelBCCConf;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(671, 611);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 30, 631, 511));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        ctl_cbMSGType = new QComboBox(tab);
        ctl_cbMSGType->setObjectName(QString::fromUtf8("ctl_cbMSGType"));
        ctl_cbMSGType->setGeometry(QRect(100, 450, 151, 23));
        ctl_btnSend = new QPushButton(tab);
        ctl_btnSend->setObjectName(QString::fromUtf8("ctl_btnSend"));
        ctl_btnSend->setGeometry(QRect(10, 450, 80, 23));
        ctl_tableFCS = new QTableWidget(tab);
        ctl_tableFCS->setObjectName(QString::fromUtf8("ctl_tableFCS"));
        ctl_tableFCS->setGeometry(QRect(10, 20, 601, 421));
        ctl_btnAutoTest = new QPushButton(tab);
        ctl_btnAutoTest->setObjectName(QString::fromUtf8("ctl_btnAutoTest"));
        ctl_btnAutoTest->setGeometry(QRect(280, 450, 80, 23));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupBox_6 = new QGroupBox(tab_2);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 30, 311, 161));
        label_3 = new QLabel(groupBox_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 30, 59, 15));
        label_4 = new QLabel(groupBox_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 80, 59, 15));
        ctl_IP_FCS = new QLineEdit(groupBox_6);
        ctl_IP_FCS->setObjectName(QString::fromUtf8("ctl_IP_FCS"));
        ctl_IP_FCS->setGeometry(QRect(100, 30, 113, 23));
        ctl_portFCS = new QLineEdit(groupBox_6);
        ctl_portFCS->setObjectName(QString::fromUtf8("ctl_portFCS"));
        ctl_portFCS->setGeometry(QRect(100, 70, 81, 23));
        ctl_btnApplyFCSConf = new QPushButton(groupBox_6);
        ctl_btnApplyFCSConf->setObjectName(QString::fromUtf8("ctl_btnApplyFCSConf"));
        ctl_btnApplyFCSConf->setGeometry(QRect(40, 120, 80, 23));
        ctl_btnCancelFCSConf = new QPushButton(groupBox_6);
        ctl_btnCancelFCSConf->setObjectName(QString::fromUtf8("ctl_btnCancelFCSConf"));
        ctl_btnCancelFCSConf->setGeometry(QRect(170, 120, 80, 23));
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(360, 30, 231, 161));
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 59, 15));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 80, 59, 15));
        ctl_IP_BCC = new QLineEdit(groupBox_3);
        ctl_IP_BCC->setObjectName(QString::fromUtf8("ctl_IP_BCC"));
        ctl_IP_BCC->setGeometry(QRect(100, 30, 113, 23));
        ctl_portBCC = new QLineEdit(groupBox_3);
        ctl_portBCC->setObjectName(QString::fromUtf8("ctl_portBCC"));
        ctl_portBCC->setGeometry(QRect(100, 70, 81, 23));
        ctl_btnApplyBCCConf = new QPushButton(groupBox_3);
        ctl_btnApplyBCCConf->setObjectName(QString::fromUtf8("ctl_btnApplyBCCConf"));
        ctl_btnApplyBCCConf->setGeometry(QRect(20, 120, 80, 23));
        ctl_btnCancelBCCConf = new QPushButton(groupBox_3);
        ctl_btnCancelBCCConf->setObjectName(QString::fromUtf8("ctl_btnCancelBCCConf"));
        ctl_btnCancelBCCConf->setGeometry(QRect(120, 120, 80, 23));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 671, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        ctl_btnSend->setText(QApplication::translate("MainWindow", "Send", 0, QApplication::UnicodeUTF8));
        ctl_btnAutoTest->setText(QApplication::translate("MainWindow", "Auto", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Transmission", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "FCS", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "IP", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Port", 0, QApplication::UnicodeUTF8));
        ctl_btnApplyFCSConf->setText(QApplication::translate("MainWindow", "Apply", 0, QApplication::UnicodeUTF8));
        ctl_btnCancelFCSConf->setText(QApplication::translate("MainWindow", "Cancel", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "BCC_B6000", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "IP", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Port", 0, QApplication::UnicodeUTF8));
        ctl_btnApplyBCCConf->setText(QApplication::translate("MainWindow", "Apply", 0, QApplication::UnicodeUTF8));
        ctl_btnCancelBCCConf->setText(QApplication::translate("MainWindow", "Cancel", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Config", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
