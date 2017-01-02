/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *subButton;
    QLabel *infoLabel;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_4;
    QPushButton *genOpenButton;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QPushButton *generateButton;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *openButton;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QTextBrowser *listBrowser;
    QProgressBar *progressBar;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(475, 701);
        verticalLayout_6 = new QVBoxLayout(Form);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit = new QLineEdit(Form);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        subButton = new QPushButton(Form);
        subButton->setObjectName(QString::fromUtf8("subButton"));

        horizontalLayout->addWidget(subButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_6->addLayout(verticalLayout);

        infoLabel = new QLabel(Form);
        infoLabel->setObjectName(QString::fromUtf8("infoLabel"));

        verticalLayout_6->addWidget(infoLabel);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        frame_2 = new QFrame(Form);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        genOpenButton = new QPushButton(frame_2);
        genOpenButton->setObjectName(QString::fromUtf8("genOpenButton"));

        verticalLayout_4->addWidget(genOpenButton);


        verticalLayout_5->addWidget(frame_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_5->addLayout(horizontalLayout_2);

        frame = new QFrame(Form);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setAutoFillBackground(false);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        generateButton = new QPushButton(frame);
        generateButton->setObjectName(QString::fromUtf8("generateButton"));

        verticalLayout_3->addWidget(generateButton);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(horizontalLayout_3);

        openButton = new QPushButton(frame);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        openButton->setCheckable(false);
        openButton->setDefault(false);

        verticalLayout_3->addWidget(openButton);


        verticalLayout_5->addWidget(frame);


        horizontalLayout_4->addLayout(verticalLayout_5);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);


        verticalLayout_6->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        groupBox = new QGroupBox(Form);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_7 = new QVBoxLayout(groupBox);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);

        verticalLayout_2->addWidget(label_3);

        listBrowser = new QTextBrowser(groupBox);
        listBrowser->setObjectName(QString::fromUtf8("listBrowser"));
        listBrowser->setOpenLinks(true);

        verticalLayout_2->addWidget(listBrowser);


        verticalLayout_7->addLayout(verticalLayout_2);

        progressBar = new QProgressBar(groupBox);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(100);
        progressBar->setOrientation(Qt::Horizontal);
        progressBar->setInvertedAppearance(false);

        verticalLayout_7->addWidget(progressBar);


        verticalLayout_6->addWidget(groupBox);

        groupBox->raise();
        infoLabel->raise();
        QWidget::setTabOrder(lineEdit, subButton);
        QWidget::setTabOrder(subButton, genOpenButton);
        QWidget::setTabOrder(genOpenButton, generateButton);
        QWidget::setTabOrder(generateButton, openButton);
        QWidget::setTabOrder(openButton, listBrowser);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "YouTube Subscriber", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineEdit->setToolTip(QApplication::translate("Form", "Example: https://www.youtube.com/watch?v=2hIy1JrPjAo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lineEdit->setPlaceholderText(QApplication::translate("Form", "Youtube Video/Channel URL", 0, QApplication::UnicodeUTF8));
        subButton->setText(QApplication::translate("Form", "Subscribe", 0, QApplication::UnicodeUTF8));
        infoLabel->setText(QString());
        genOpenButton->setText(QApplication::translate("Form", "[ Generate + OPEN ] Updated HTML", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form", "OR", 0, QApplication::UnicodeUTF8));
        generateButton->setText(QApplication::translate("Form", "Generate Updated HTML", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Form", " and then ", 0, QApplication::UnicodeUTF8));
        openButton->setText(QApplication::translate("Form", "Open HTML", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label_3->setText(QApplication::translate("Form", "Your Subscription List:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        listBrowser->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        listBrowser->setDocumentTitle(QString());
        progressBar->setFormat(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
