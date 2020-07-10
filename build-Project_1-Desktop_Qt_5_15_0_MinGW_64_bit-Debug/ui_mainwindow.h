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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *SelectFile_Button;
    QLineEdit *output_LineEdit;
    QPushButton *SelectFile2_Button;
    QLineEdit *Input_LineEdit;
    QLabel *Input_Label;
    QPushButton *InputSearch_Button;
    QLabel *label;
    QPushButton *OutputSearch_Button;
    QVBoxLayout *verticalLayout_2;
    QFrame *line;
    QLabel *inputFile_Confirm;
    QLabel *outputFile_Confirm;
    QSpacerItem *verticalSpacer;
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
        SelectFile_Button = new QPushButton(centralwidget);
        SelectFile_Button->setObjectName(QString::fromUtf8("SelectFile_Button"));

        gridLayout->addWidget(SelectFile_Button, 0, 3, 1, 1);

        output_LineEdit = new QLineEdit(centralwidget);
        output_LineEdit->setObjectName(QString::fromUtf8("output_LineEdit"));

        gridLayout->addWidget(output_LineEdit, 1, 1, 1, 1);

        SelectFile2_Button = new QPushButton(centralwidget);
        SelectFile2_Button->setObjectName(QString::fromUtf8("SelectFile2_Button"));

        gridLayout->addWidget(SelectFile2_Button, 1, 3, 1, 1);

        Input_LineEdit = new QLineEdit(centralwidget);
        Input_LineEdit->setObjectName(QString::fromUtf8("Input_LineEdit"));

        gridLayout->addWidget(Input_LineEdit, 0, 1, 1, 1);

        Input_Label = new QLabel(centralwidget);
        Input_Label->setObjectName(QString::fromUtf8("Input_Label"));

        gridLayout->addWidget(Input_Label, 0, 0, 1, 1);

        InputSearch_Button = new QPushButton(centralwidget);
        InputSearch_Button->setObjectName(QString::fromUtf8("InputSearch_Button"));
        InputSearch_Button->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(InputSearch_Button, 0, 2, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        OutputSearch_Button = new QPushButton(centralwidget);
        OutputSearch_Button->setObjectName(QString::fromUtf8("OutputSearch_Button"));
        OutputSearch_Button->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(OutputSearch_Button, 1, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(0, 10));
        line->setBaseSize(QSize(0, 15));
        QFont font;
        font.setPointSize(10);
        line->setFont(font);
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(15);
        line->setMidLineWidth(10);
        line->setFrameShape(QFrame::HLine);

        verticalLayout_2->addWidget(line);

        inputFile_Confirm = new QLabel(centralwidget);
        inputFile_Confirm->setObjectName(QString::fromUtf8("inputFile_Confirm"));
        inputFile_Confirm->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(inputFile_Confirm->sizePolicy().hasHeightForWidth());
        inputFile_Confirm->setSizePolicy(sizePolicy);
        inputFile_Confirm->setMinimumSize(QSize(0, 13));
        inputFile_Confirm->setMaximumSize(QSize(16777215, 20));
        inputFile_Confirm->setFrameShape(QFrame::NoFrame);
        inputFile_Confirm->setScaledContents(true);
        inputFile_Confirm->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        inputFile_Confirm->setMargin(0);
        inputFile_Confirm->setIndent(0);

        verticalLayout_2->addWidget(inputFile_Confirm);

        outputFile_Confirm = new QLabel(centralwidget);
        outputFile_Confirm->setObjectName(QString::fromUtf8("outputFile_Confirm"));
        outputFile_Confirm->setMinimumSize(QSize(0, 13));
        outputFile_Confirm->setMaximumSize(QSize(16777215, 20));

        verticalLayout_2->addWidget(outputFile_Confirm, 0, Qt::AlignTop);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_2, 2, 0, 1, 4);

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
        SelectFile_Button->setText(QCoreApplication::translate("MainWindow", "Select File", nullptr));
        output_LineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Example: C:/user/file.txt", nullptr));
        SelectFile2_Button->setText(QCoreApplication::translate("MainWindow", "Select File", nullptr));
        Input_LineEdit->setInputMask(QString());
        Input_LineEdit->setText(QString());
        Input_LineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Example: C:/user/file.txt", nullptr));
        Input_Label->setText(QCoreApplication::translate("MainWindow", "Input File", nullptr));
        InputSearch_Button->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Output File", nullptr));
        OutputSearch_Button->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        inputFile_Confirm->setText(QCoreApplication::translate("MainWindow", "Input File: ", nullptr));
        outputFile_Confirm->setText(QCoreApplication::translate("MainWindow", "- No output file selected", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
