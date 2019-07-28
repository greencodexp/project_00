/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Jul 21 21:42:46 2019
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
#include <QtGui/QHBoxLayout>
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
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QTableWidget *ctl_tableFCC;
    QComboBox *ctl_cbSendMSGTypeFCC;
    QPushButton *ctl_btnSendMSG;
    QGroupBox *groupBox_2;
    QTableWidget *ctl_tableRFC;
    QComboBox *ctl_cbSendMSGTypeRFC;
    QPushButton *ctl_btnSendMSG_2;
    QWidget *tab_2;
    QGroupBox *groupBox_3;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *ctl_IP_BCC;
    QLineEdit *ctl_portBCC;
    QGroupBox *groupBox_6;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *ctl_IP_FCC;
    QLineEdit *ctl_portFCC;
    QGroupBox *groupBox_7;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *ctl_IP_RFC;
    QLineEdit *ctl_portRFC;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1165, 558);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 1131, 451));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 1101, 371));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 222, 223);"));
        ctl_tableFCC = new QTableWidget(groupBox);
        ctl_tableFCC->setObjectName(QString::fromUtf8("ctl_tableFCC"));
        ctl_tableFCC->setGeometry(QRect(20, 40, 511, 281));
        ctl_cbSendMSGTypeFCC = new QComboBox(groupBox);
        ctl_cbSendMSGTypeFCC->setObjectName(QString::fromUtf8("ctl_cbSendMSGTypeFCC"));
        ctl_cbSendMSGTypeFCC->setGeometry(QRect(120, 330, 241, 23));
        ctl_btnSendMSG = new QPushButton(groupBox);
        ctl_btnSendMSG->setObjectName(QString::fromUtf8("ctl_btnSendMSG"));
        ctl_btnSendMSG->setGeometry(QRect(20, 330, 75, 23));

        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 222, 223);"));
        ctl_tableRFC = new QTableWidget(groupBox_2);
        ctl_tableRFC->setObjectName(QString::fromUtf8("ctl_tableRFC"));
        ctl_tableRFC->setGeometry(QRect(10, 40, 511, 281));
        ctl_cbSendMSGTypeRFC = new QComboBox(groupBox_2);
        ctl_cbSendMSGTypeRFC->setObjectName(QString::fromUtf8("ctl_cbSendMSGTypeRFC"));
        ctl_cbSendMSGTypeRFC->setGeometry(QRect(110, 330, 241, 23));
        ctl_btnSendMSG_2 = new QPushButton(groupBox_2);
        ctl_btnSendMSG_2->setObjectName(QString::fromUtf8("ctl_btnSendMSG_2"));
        ctl_btnSendMSG_2->setGeometry(QRect(10, 330, 80, 23));

        horizontalLayout->addWidget(groupBox_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(150, 50, 231, 121));
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 222, 223);"));
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
        groupBox_6 = new QGroupBox(tab_2);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(460, 50, 231, 121));
        groupBox_6->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 222, 223);"));
        label_3 = new QLabel(groupBox_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 30, 59, 15));
        label_4 = new QLabel(groupBox_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 80, 59, 15));
        ctl_IP_FCC = new QLineEdit(groupBox_6);
        ctl_IP_FCC->setObjectName(QString::fromUtf8("ctl_IP_FCC"));
        ctl_IP_FCC->setGeometry(QRect(100, 30, 113, 23));
        ctl_portFCC = new QLineEdit(groupBox_6);
        ctl_portFCC->setObjectName(QString::fromUtf8("ctl_portFCC"));
        ctl_portFCC->setGeometry(QRect(100, 70, 81, 23));
        groupBox_7 = new QGroupBox(tab_2);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(760, 50, 231, 121));
        groupBox_7->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 222, 223);"));
        label_5 = new QLabel(groupBox_7);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 30, 59, 15));
        label_6 = new QLabel(groupBox_7);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 80, 59, 15));
        ctl_IP_RFC = new QLineEdit(groupBox_7);
        ctl_IP_RFC->setObjectName(QString::fromUtf8("ctl_IP_RFC"));
        ctl_IP_RFC->setGeometry(QRect(100, 30, 113, 23));
        ctl_portRFC = new QLineEdit(groupBox_7);
        ctl_portRFC->setObjectName(QString::fromUtf8("ctl_portRFC"));
        ctl_portRFC->setGeometry(QRect(100, 70, 81, 23));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1165, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BCC_B6000", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "FCC", 0, QApplication::UnicodeUTF8));
        ctl_btnSendMSG->setText(QApplication::translate("MainWindow", "Send", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "RFC", 0, QApplication::UnicodeUTF8));
        ctl_btnSendMSG_2->setText(QApplication::translate("MainWindow", "Send", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Transmission", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "BCC_B6000", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "IP", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Port", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "FCC", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "IP", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Port", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "RFC", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "IP", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Port", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Config", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
