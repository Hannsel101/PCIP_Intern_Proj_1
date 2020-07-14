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
#include <QtWidgets/QHBoxLayout>
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
    QSpacerItem *verticalSpacer_3;
    QFrame *line_4;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLabel *label_6;
    QLineEdit *lineEdit_2;
    QLabel *label_7;
    QLineEdit *lineEdit_3;
    QLabel *label_8;
    QPushButton *antennaPosition_Button;
    QSpacerItem *verticalSpacer;
    QFrame *line;
    QLabel *processingInformationHeader;
    QLabel *label_2;
    QLabel *endTime;
    QLabel *recordsProcessed;
    QLabel *label;
    QFrame *line_2;
    QSpacerItem *verticalSpacer_2;
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
        MainWindow->resize(316, 483);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setBaseSize(QSize(600, 0));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
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
        process_Button->setMinimumSize(QSize(0, 30));
        process_Button->setMaximumSize(QSize(100, 16777215));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        process_Button->setFont(font);

        verticalLayout_2->addWidget(process_Button, 0, Qt::AlignHCenter);

        verticalSpacer_3 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_3);

        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShadow(QFrame::Sunken);
        line_4->setFrameShape(QFrame::HLine);

        verticalLayout_2->addWidget(line_4);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        label_9->setFont(font1);
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_9);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 10, -1, -1);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(110, 16777215));
        QFont font2;
        font2.setPointSize(10);
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_4);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(5, 16777215));
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_5);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 25));
        lineEdit->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_4->addWidget(lineEdit);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMaximumSize(QSize(5, 16777215));
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_6);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(0, 25));
        lineEdit_2->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_4->addWidget(lineEdit_2);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMaximumSize(QSize(5, 16777215));
        label_7->setFont(font2);
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_7);

        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setMinimumSize(QSize(0, 25));
        lineEdit_3->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_4->addWidget(lineEdit_3);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMaximumSize(QSize(5, 16777215));
        label_8->setFont(font2);
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_8);


        verticalLayout_2->addLayout(horizontalLayout_4);

        antennaPosition_Button = new QPushButton(centralwidget);
        antennaPosition_Button->setObjectName(QString::fromUtf8("antennaPosition_Button"));
        antennaPosition_Button->setMinimumSize(QSize(100, 30));
        antennaPosition_Button->setMaximumSize(QSize(100, 16777215));
        antennaPosition_Button->setBaseSize(QSize(0, 0));
        antennaPosition_Button->setFont(font2);

        verticalLayout_2->addWidget(antennaPosition_Button, 0, Qt::AlignHCenter);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        processingInformationHeader = new QLabel(centralwidget);
        processingInformationHeader->setObjectName(QString::fromUtf8("processingInformationHeader"));
        processingInformationHeader->setFont(font1);
        processingInformationHeader->setAlignment(Qt::AlignCenter);
        processingInformationHeader->setIndent(100);

        verticalLayout_2->addWidget(processingInformationHeader);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);

        verticalLayout_2->addWidget(label_2);

        endTime = new QLabel(centralwidget);
        endTime->setObjectName(QString::fromUtf8("endTime"));
        endTime->setFont(font2);

        verticalLayout_2->addWidget(endTime);

        recordsProcessed = new QLabel(centralwidget);
        recordsProcessed->setObjectName(QString::fromUtf8("recordsProcessed"));
        recordsProcessed->setFont(font2);

        verticalLayout_2->addWidget(recordsProcessed);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font2);

        verticalLayout_2->addWidget(label);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout_2, 3, 0, 1, 4);

        log_Label = new QLabel(centralwidget);
        log_Label->setObjectName(QString::fromUtf8("log_Label"));
        log_Label->setFont(font2);

        gridLayout->addWidget(log_Label, 2, 0, 1, 1);

        Input_LineEdit = new QLineEdit(centralwidget);
        Input_LineEdit->setObjectName(QString::fromUtf8("Input_LineEdit"));
        Input_LineEdit->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(Input_LineEdit, 0, 1, 1, 1);

        output_Label = new QLabel(centralwidget);
        output_Label->setObjectName(QString::fromUtf8("output_Label"));
        output_Label->setFont(font2);

        gridLayout->addWidget(output_Label, 1, 0, 1, 1);

        Input_Label = new QLabel(centralwidget);
        Input_Label->setObjectName(QString::fromUtf8("Input_Label"));
        Input_Label->setMinimumSize(QSize(0, 0));
        Input_Label->setFont(font2);

        gridLayout->addWidget(Input_Label, 0, 0, 1, 1);

        OutputSearch_Button = new QPushButton(centralwidget);
        OutputSearch_Button->setObjectName(QString::fromUtf8("OutputSearch_Button"));
        OutputSearch_Button->setMinimumSize(QSize(40, 30));
        OutputSearch_Button->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(OutputSearch_Button, 1, 2, 1, 1);

        output_LineEdit = new QLineEdit(centralwidget);
        output_LineEdit->setObjectName(QString::fromUtf8("output_LineEdit"));
        output_LineEdit->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(output_LineEdit, 1, 1, 1, 1);

        InputSearch_Button = new QPushButton(centralwidget);
        InputSearch_Button->setObjectName(QString::fromUtf8("InputSearch_Button"));
        InputSearch_Button->setMinimumSize(QSize(40, 30));
        InputSearch_Button->setMaximumSize(QSize(30, 16777215));
        InputSearch_Button->setStyleSheet(QString::fromUtf8(""));
        InputSearch_Button->setFlat(false);

        gridLayout->addWidget(InputSearch_Button, 0, 2, 1, 1);

        log_LineEdit = new QLineEdit(centralwidget);
        log_LineEdit->setObjectName(QString::fromUtf8("log_LineEdit"));
        log_LineEdit->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(log_LineEdit, 2, 1, 1, 1);

        LogSearch_Button = new QPushButton(centralwidget);
        LogSearch_Button->setObjectName(QString::fromUtf8("LogSearch_Button"));
        LogSearch_Button->setMinimumSize(QSize(40, 30));
        LogSearch_Button->setMaximumSize(QSize(30, 16777215));

        gridLayout->addWidget(LogSearch_Button, 2, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 316, 21));
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
        label_9->setText(QCoreApplication::translate("MainWindow", "GPS Antenna Position", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "ECEF Coordinates:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "E", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", ",", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "F", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", ",", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("MainWindow", "G", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        antennaPosition_Button->setText(QCoreApplication::translate("MainWindow", "Load Position", nullptr));
        processingInformationHeader->setText(QCoreApplication::translate("MainWindow", "Processing Information", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Start Time:", nullptr));
        endTime->setText(QCoreApplication::translate("MainWindow", "End Time: ", nullptr));
        recordsProcessed->setText(QCoreApplication::translate("MainWindow", "Records Processed: ", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "% Records with RSS over 0.5m: ", nullptr));
        log_Label->setText(QCoreApplication::translate("MainWindow", "Log File", nullptr));
        Input_LineEdit->setInputMask(QString());
        Input_LineEdit->setText(QString());
        Input_LineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Example: C:/user/input.NOB", nullptr));
        output_Label->setText(QCoreApplication::translate("MainWindow", "Output File", nullptr));
        Input_Label->setText(QCoreApplication::translate("MainWindow", "Input File", nullptr));
        OutputSearch_Button->setText(QString());
        output_LineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Example: C:/user/output.txt", nullptr));
        InputSearch_Button->setText(QString());
        log_LineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Example: C:/user/log.txt", nullptr));
        LogSearch_Button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
