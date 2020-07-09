/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *SelectFile2_Button;
    QPushButton *OutputFile_Button;
    QPushButton *SelectFile_Button;
    QLabel *Input_Label;
    QPushButton *InputSearch_Button;
    QLineEdit *lineEdit;
    QLineEdit *Input_LineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 484);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(-1, 0, -1, -1);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        SelectFile2_Button = new QPushButton(centralwidget);
        SelectFile2_Button->setObjectName(QString::fromUtf8("SelectFile2_Button"));

        gridLayout->addWidget(SelectFile2_Button, 1, 3, 1, 1);

        OutputFile_Button = new QPushButton(centralwidget);
        OutputFile_Button->setObjectName(QString::fromUtf8("OutputFile_Button"));
        OutputFile_Button->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(OutputFile_Button, 1, 2, 1, 1);

        SelectFile_Button = new QPushButton(centralwidget);
        SelectFile_Button->setObjectName(QString::fromUtf8("SelectFile_Button"));

        gridLayout->addWidget(SelectFile_Button, 0, 3, 1, 1);

        Input_Label = new QLabel(centralwidget);
        Input_Label->setObjectName(QString::fromUtf8("Input_Label"));

        gridLayout->addWidget(Input_Label, 0, 0, 1, 1);

        InputSearch_Button = new QPushButton(centralwidget);
        InputSearch_Button->setObjectName(QString::fromUtf8("InputSearch_Button"));
        InputSearch_Button->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(InputSearch_Button, 0, 2, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        Input_LineEdit = new QLineEdit(centralwidget);
        Input_LineEdit->setObjectName(QString::fromUtf8("Input_LineEdit"));

        gridLayout->addWidget(Input_LineEdit, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Output File", nullptr));
        SelectFile2_Button->setText(QCoreApplication::translate("MainWindow", "Select File", nullptr));
        OutputFile_Button->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        SelectFile_Button->setText(QCoreApplication::translate("MainWindow", "Select File", nullptr));
        Input_Label->setText(QCoreApplication::translate("MainWindow", "Input File", nullptr));
        InputSearch_Button->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Example: C:/user/file.txt", nullptr));
        Input_LineEdit->setInputMask(QString());
        Input_LineEdit->setText(QString());
        Input_LineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Example: C:/user/file.txt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
