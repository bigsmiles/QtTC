/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Apr 14 10:37:58 2014
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *tip;
    QTextEdit *text;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *CHI;
    QRadioButton *ECE;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *KNN;
    QRadioButton *Bayes;
    QPushButton *Run;
    QMenuBar *menuBar;
    QToolBar *toolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(676, 503);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(9999999, 9999999));
        MainWindow->setBaseSize(QSize(600, 600));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tip = new QLabel(centralWidget);
        tip->setObjectName(QString::fromUtf8("tip"));
        tip->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(10);
        sizePolicy1.setVerticalStretch(10);
        sizePolicy1.setHeightForWidth(tip->sizePolicy().hasHeightForWidth());
        tip->setSizePolicy(sizePolicy1);
        tip->setMaximumSize(QSize(500, 20));

        verticalLayout_2->addWidget(tip);

        text = new QTextEdit(centralWidget);
        text->setObjectName(QString::fromUtf8("text"));
        text->setMaximumSize(QSize(16777215, 300));

        verticalLayout_2->addWidget(text);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        CHI = new QRadioButton(groupBox);
        CHI->setObjectName(QString::fromUtf8("CHI"));

        verticalLayout->addWidget(CHI);

        ECE = new QRadioButton(groupBox);
        ECE->setObjectName(QString::fromUtf8("ECE"));

        verticalLayout->addWidget(ECE);


        horizontalLayout_5->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        KNN = new QRadioButton(groupBox_2);
        KNN->setObjectName(QString::fromUtf8("KNN"));

        verticalLayout_3->addWidget(KNN);

        Bayes = new QRadioButton(groupBox_2);
        Bayes->setObjectName(QString::fromUtf8("Bayes"));

        verticalLayout_3->addWidget(Bayes);


        horizontalLayout_5->addWidget(groupBox_2);

        Run = new QPushButton(centralWidget);
        Run->setObjectName(QString::fromUtf8("Run"));
        Run->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_5->addWidget(Run);

        horizontalLayout_5->setStretch(0, 3);
        horizontalLayout_5->setStretch(1, 3);
        horizontalLayout_5->setStretch(2, 3);

        verticalLayout_2->addLayout(horizontalLayout_5);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 3);
        verticalLayout_2->setStretch(2, 1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 676, 23));
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setEnabled(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        tip->setText(QApplication::translate("MainWindow", "\350\276\223\345\205\245\351\234\200\350\246\201\345\210\206\347\261\273\347\232\204\346\226\207\346\234\254", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "\347\211\271\345\276\201\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8));
        CHI->setText(QApplication::translate("MainWindow", "CHI", 0, QApplication::UnicodeUTF8));
        ECE->setText(QApplication::translate("MainWindow", "ECE", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\345\210\206\347\261\273\346\226\271\346\263\225", 0, QApplication::UnicodeUTF8));
        KNN->setText(QApplication::translate("MainWindow", "KNN", 0, QApplication::UnicodeUTF8));
        Bayes->setText(QApplication::translate("MainWindow", "Bayes", 0, QApplication::UnicodeUTF8));
        Run->setText(QApplication::translate("MainWindow", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
