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
    QVBoxLayout *verticalLayout_2;
    QFrame *line_4;
    QLabel *label_9;
    QLineEdit *E_Input;
    QLineEdit *F_Input;
    QLineEdit *G_Input;
    QPushButton *antennaPosition_Button;
    QSpacerItem *verticalSpacer;
    QFrame *line_3;
    QPushButton *process_Button;
    QFrame *line;
    QLabel *processingInformationHeader;
    QLabel *startTime;
    QLabel *endTime;
    QLabel *recordsProcessed;
    QLabel *percentRSS;
    QFrame *line_2;
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
        MainWindow->resize(316, 490);
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
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShadow(QFrame::Sunken);
        line_4->setFrameShape(QFrame::HLine);

        verticalLayout_2->addWidget(line_4);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_9);

        E_Input = new QLineEdit(centralwidget);
        E_Input->setObjectName(QString::fromUtf8("E_Input"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(E_Input->sizePolicy().hasHeightForWidth());
        E_Input->setSizePolicy(sizePolicy1);
        E_Input->setMinimumSize(QSize(0, 25));
        E_Input->setMaximumSize(QSize(1000, 16777215));
        E_Input->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(E_Input);

        F_Input = new QLineEdit(centralwidget);
        F_Input->setObjectName(QString::fromUtf8("F_Input"));
        F_Input->setMinimumSize(QSize(0, 25));
        F_Input->setMaximumSize(QSize(1000, 16777215));
        F_Input->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(F_Input);

        G_Input = new QLineEdit(centralwidget);
        G_Input->setObjectName(QString::fromUtf8("G_Input"));
        G_Input->setMinimumSize(QSize(0, 25));
        G_Input->setMaximumSize(QSize(1000, 16777215));
        G_Input->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(G_Input);

        antennaPosition_Button = new QPushButton(centralwidget);
        antennaPosition_Button->setObjectName(QString::fromUtf8("antennaPosition_Button"));
        antennaPosition_Button->setMinimumSize(QSize(100, 30));
        antennaPosition_Button->setMaximumSize(QSize(100, 16777215));
        antennaPosition_Button->setBaseSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(10);
        antennaPosition_Button->setFont(font1);

        verticalLayout_2->addWidget(antennaPosition_Button, 0, Qt::AlignHCenter);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        process_Button = new QPushButton(centralwidget);
        process_Button->setObjectName(QString::fromUtf8("process_Button"));
        process_Button->setMinimumSize(QSize(0, 30));
        process_Button->setMaximumSize(QSize(100, 16777215));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        process_Button->setFont(font2);

        verticalLayout_2->addWidget(process_Button, 0, Qt::AlignHCenter);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        processingInformationHeader = new QLabel(centralwidget);
        processingInformationHeader->setObjectName(QString::fromUtf8("processingInformationHeader"));
        processingInformationHeader->setFont(font);
        processingInformationHeader->setAlignment(Qt::AlignCenter);
        processingInformationHeader->setIndent(100);

        verticalLayout_2->addWidget(processingInformationHeader);

        startTime = new QLabel(centralwidget);
        startTime->setObjectName(QString::fromUtf8("startTime"));
        startTime->setFont(font1);

        verticalLayout_2->addWidget(startTime);

        endTime = new QLabel(centralwidget);
        endTime->setObjectName(QString::fromUtf8("endTime"));
        endTime->setFont(font1);

        verticalLayout_2->addWidget(endTime);

        recordsProcessed = new QLabel(centralwidget);
        recordsProcessed->setObjectName(QString::fromUtf8("recordsProcessed"));
        recordsProcessed->setFont(font1);

        verticalLayout_2->addWidget(recordsProcessed);

        percentRSS = new QLabel(centralwidget);
        percentRSS->setObjectName(QString::fromUtf8("percentRSS"));
        percentRSS->setFont(font1);

        verticalLayout_2->addWidget(percentRSS);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);


        gridLayout->addLayout(verticalLayout_2, 3, 0, 1, 4);

        log_Label = new QLabel(centralwidget);
        log_Label->setObjectName(QString::fromUtf8("log_Label"));
        log_Label->setFont(font1);

        gridLayout->addWidget(log_Label, 2, 0, 1, 1);

        Input_LineEdit = new QLineEdit(centralwidget);
        Input_LineEdit->setObjectName(QString::fromUtf8("Input_LineEdit"));
        Input_LineEdit->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(Input_LineEdit, 0, 1, 1, 1);

        output_Label = new QLabel(centralwidget);
        output_Label->setObjectName(QString::fromUtf8("output_Label"));
        output_Label->setFont(font1);

        gridLayout->addWidget(output_Label, 1, 0, 1, 1);

        Input_Label = new QLabel(centralwidget);
        Input_Label->setObjectName(QString::fromUtf8("Input_Label"));
        Input_Label->setMinimumSize(QSize(0, 0));
        Input_Label->setFont(font1);

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
        menubar->setGeometry(QRect(0, 0, 316, 20));
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
        label_9->setText(QCoreApplication::translate("MainWindow", "GPS Antenna Position", nullptr));
        E_Input->setPlaceholderText(QCoreApplication::translate("MainWindow", "E", nullptr));
        F_Input->setPlaceholderText(QCoreApplication::translate("MainWindow", "F", nullptr));
        G_Input->setPlaceholderText(QCoreApplication::translate("MainWindow", "G", nullptr));
        antennaPosition_Button->setText(QCoreApplication::translate("MainWindow", "Load Position", nullptr));
        process_Button->setText(QCoreApplication::translate("MainWindow", "Start Processing", nullptr));
        processingInformationHeader->setText(QCoreApplication::translate("MainWindow", "Processing Information", nullptr));
        startTime->setText(QCoreApplication::translate("MainWindow", "Start Time:", nullptr));
        endTime->setText(QCoreApplication::translate("MainWindow", "End Time: ", nullptr));
        recordsProcessed->setText(QCoreApplication::translate("MainWindow", "Records Processed: ", nullptr));
        percentRSS->setText(QCoreApplication::translate("MainWindow", "% Records with RSS over 0.5m: ", nullptr));
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
