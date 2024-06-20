/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "pixel_editor.h"

QT_BEGIN_NAMESPACE

class Ui_Main_Window
{
public:
    QAction *actionNew;
    QAction *actionSave;
    QAction *actionLoad;
    QAction *actionClose;
    QWidget *centralwidget;
    QPushButton *previousFrame;
    QPushButton *nextFrame;
    QPushButton *newFrame;
    QPushButton *previewSprite;
    QGroupBox *groupBox;
    QToolButton *colorPickerButton;
    QToolButton *eraseButton;
    PixelEditor *pixelEditor;
    QCheckBox *actualSizeCheckBox;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Main_Window)
    {
        if (Main_Window->objectName().isEmpty())
            Main_Window->setObjectName(QString::fromUtf8("Main_Window"));
        Main_Window->resize(800, 600);
        actionNew = new QAction(Main_Window);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionNew->setCheckable(false);
        actionNew->setChecked(false);
        actionSave = new QAction(Main_Window);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionLoad = new QAction(Main_Window);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionClose = new QAction(Main_Window);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        centralwidget = new QWidget(Main_Window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        previousFrame = new QPushButton(centralwidget);
        previousFrame->setObjectName(QString::fromUtf8("previousFrame"));
        previousFrame->setGeometry(QRect(10, 10, 100, 51));
        QFont font;
        font.setPointSize(8);
        font.setKerning(true);
        previousFrame->setFont(font);
        previousFrame->setLayoutDirection(Qt::LeftToRight);
        nextFrame = new QPushButton(centralwidget);
        nextFrame->setObjectName(QString::fromUtf8("nextFrame"));
        nextFrame->setGeometry(QRect(120, 10, 100, 50));
        QFont font1;
        font1.setPointSize(8);
        nextFrame->setFont(font1);
        newFrame = new QPushButton(centralwidget);
        newFrame->setObjectName(QString::fromUtf8("newFrame"));
        newFrame->setGeometry(QRect(60, 70, 110, 51));
        previewSprite = new QPushButton(centralwidget);
        previewSprite->setObjectName(QString::fromUtf8("previewSprite"));
        previewSprite->setGeometry(QRect(30, 310, 170, 70));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 140, 210, 150));
        colorPickerButton = new QToolButton(groupBox);
        colorPickerButton->setObjectName(QString::fromUtf8("colorPickerButton"));
        colorPickerButton->setGeometry(QRect(10, 20, 91, 111));
        colorPickerButton->setCursor(QCursor(Qt::ArrowCursor));
        eraseButton = new QToolButton(groupBox);
        eraseButton->setObjectName(QString::fromUtf8("eraseButton"));
        eraseButton->setGeometry(QRect(110, 20, 91, 111));
        pixelEditor = new PixelEditor(centralwidget);
        pixelEditor->setObjectName(QString::fromUtf8("pixelEditor"));
        pixelEditor->setGeometry(QRect(250, 20, 500, 500));
        actualSizeCheckBox = new QCheckBox(centralwidget);
        actualSizeCheckBox->setObjectName(QString::fromUtf8("actualSizeCheckBox"));
        actualSizeCheckBox->setGeometry(QRect(50, 400, 141, 20));
        Main_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Main_Window);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        Main_Window->setMenuBar(menubar);
        statusbar = new QStatusBar(Main_Window);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Main_Window->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionClose);

        retranslateUi(Main_Window);

        QMetaObject::connectSlotsByName(Main_Window);
    } // setupUi

    void retranslateUi(QMainWindow *Main_Window)
    {
        Main_Window->setWindowTitle(QCoreApplication::translate("Main_Window", "Sprite_Editor", nullptr));
        actionNew->setText(QCoreApplication::translate("Main_Window", "New", nullptr));
        actionSave->setText(QCoreApplication::translate("Main_Window", "Save", nullptr));
        actionLoad->setText(QCoreApplication::translate("Main_Window", "Load", nullptr));
        actionClose->setText(QCoreApplication::translate("Main_Window", "Close", nullptr));
        previousFrame->setText(QCoreApplication::translate("Main_Window", "Previous Frame", nullptr));
        nextFrame->setText(QCoreApplication::translate("Main_Window", "Next Frame", nullptr));
        newFrame->setText(QCoreApplication::translate("Main_Window", "New Frame", nullptr));
        previewSprite->setText(QCoreApplication::translate("Main_Window", "Preview Sprite", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Main_Window", "Tools", nullptr));
        colorPickerButton->setText(QCoreApplication::translate("Main_Window", "Brush Color", nullptr));
        eraseButton->setText(QCoreApplication::translate("Main_Window", "Erase", nullptr));
        actualSizeCheckBox->setText(QCoreApplication::translate("Main_Window", "Preview Actual Size?", nullptr));
        menuFile->setTitle(QCoreApplication::translate("Main_Window", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Main_Window: public Ui_Main_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
