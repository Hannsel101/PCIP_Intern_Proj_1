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
    QVBoxLayout *verticalLayout_2;
    QPushButton *process_Button;
    QSpacerItem *verticalSpacer_2;
    QLabel *fileStatusHeader;
    QLabel *inputFile_Confirm;
    QLabel *outputFile_Confirm;
    QLabel *logFile_Confirm;
    QSpacerItem *verticalSpacer_3;
    QLabel *processingInformationHeader;
    QLabel *recordsProcessed;
    QSpacerItem *verticalSpacer;
    QLabel *log_Label;
    QLineEdit *Input_LineEdit;
    QLabel *output_Label;
    QLabel *Input_Label;
    QPushButton *OutputSearch_Button;
    QLineEdit *output_LineEdit;
    QPushButton *InputSearch_Button;
    QLineEdit *log_LineEdit;
    QPushButton *LogSearch_Button;
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
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        process_Button = new QPushButton(centralwidget);
        process_Button->setObjectName(QString::fromUtf8("process_Button"));

        verticalLayout_2->addWidget(process_Button);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        fileStatusHeader = new QLabel(centralwidget);
        fileStatusHeader->setObjectName(QString::fromUtf8("fileStatusHeader"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        fileStatusHeader->setFont(font);
        fileStatusHeader->setFrameShape(QFrame::NoFrame);
        fileStatusHeader->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        fileStatusHeader->setIndent(100);

        verticalLayout_2->addWidget(fileStatusHeader);

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

        logFile_Confirm = new QLabel(centralwidget);
        logFile_Confirm->setObjectName(QString::fromUtf8("logFile_Confirm"));

        verticalLayout_2->addWidget(logFile_Confirm);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_3);

        processingInformationHeader = new QLabel(centralwidget);
        processingInformationHeader->setObjectName(QString::fromUtf8("processingInformationHeader"));
        processingInformationHeader->setFont(font);
        processingInformationHeader->setIndent(100);

        verticalLayout_2->addWidget(processingInformationHeader);

        recordsProcessed = new QLabel(centralwidget);
        recordsProcessed->setObjectName(QString::fromUtf8("recordsProcessed"));

        verticalLayout_2->addWidget(recordsProcessed);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_2, 3, 0, 1, 4);

        log_Label = new QLabel(centralwidget);
        log_Label->setObjectName(QString::fromUtf8("log_Label"));

        gridLayout->addWidget(log_Label, 2, 0, 1, 1);

        Input_LineEdit = new QLineEdit(centralwidget);
        Input_LineEdit->setObjectName(QString::fromUtf8("Input_LineEdit"));

        gridLayout->addWidget(Input_LineEdit, 0, 1, 1, 1);

        output_Label = new QLabel(centralwidget);
        output_Label->setObjectName(QString::fromUtf8("output_Label"));

        gridLayout->addWidget(output_Label, 1, 0, 1, 1);

        Input_Label = new QLabel(centralwidget);
        Input_Label->setObjectName(QString::fromUtf8("Input_Label"));

        gridLayout->addWidget(Input_Label, 0, 0, 1, 1);

        OutputSearch_Button = new QPushButton(centralwidget);
        OutputSearch_Button->setObjectName(QString::fromUtf8("OutputSearch_Button"));
        OutputSearch_Button->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(OutputSearch_Button, 1, 2, 1, 1);

        output_LineEdit = new QLineEdit(centralwidget);
        output_LineEdit->setObjectName(QString::fromUtf8("output_LineEdit"));

        gridLayout->addWidget(output_LineEdit, 1, 1, 1, 1);

        InputSearch_Button = new QPushButton(centralwidget);
        InputSearch_Button->setObjectName(QString::fromUtf8("InputSearch_Button"));
        InputSearch_Button->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(InputSearch_Button, 0, 2, 1, 1);

        log_LineEdit = new QLineEdit(centralwidget);
        log_LineEdit->setObjectName(QString::fromUtf8("log_LineEdit"));

        gridLayout->addWidget(log_LineEdit, 2, 1, 1, 1);

        LogSearch_Button = new QPushButton(centralwidget);
        LogSearch_Button->setObjectName(QString::fromUtf8("LogSearch_Button"));
        LogSearch_Button->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(LogSearch_Button, 2, 2, 1, 1);

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
        process_Button->setText(QCoreApplication::translate("MainWindow", "Start Processing", nullptr));
        fileStatusHeader->setText(QCoreApplication::translate("MainWindow", "File Selection Status", nullptr));
        inputFile_Confirm->setText(QCoreApplication::translate("MainWindow", "Input file status", nullptr));
        outputFile_Confirm->setText(QCoreApplication::translate("MainWindow", "output file status", nullptr));
        logFile_Confirm->setText(QCoreApplication::translate("MainWindow", "log file status", nullptr));
        processingInformationHeader->setText(QCoreApplication::translate("MainWindow", "Processing Information", nullptr));
        recordsProcessed->setText(QCoreApplication::translate("MainWindow", "Records Processed: 0", nullptr));
        log_Label->setText(QCoreApplication::translate("MainWindow", "Log File", nullptr));
        Input_LineEdit->setInputMask(QString());
        Input_LineEdit->setText(QString());
        Input_LineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Example: C:/user/input.NOB", nullptr));
        output_Label->setText(QCoreApplication::translate("MainWindow", "Output File", nullptr));
        Input_Label->setText(QCoreApplication::translate("MainWindow", "Input File", nullptr));
        OutputSearch_Button->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        output_LineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Example: C:/user/output.txt", nullptr));
        InputSearch_Button->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        log_LineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Example: C:/user/log.txt", nullptr));
        LogSearch_Button->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
