/********************************************************************************
** Form generated from reading UI file 'spritepreview.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPRITEPREVIEW_H
#define UI_SPRITEPREVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <preview_displayer.h>

QT_BEGIN_NAMESPACE

class Ui_SpritePreview
{
public:
    QSpinBox *spinBox;
    QLabel *label_2;
    PreviewDisplayer *previewDisplayer;

    void setupUi(QDialog *SpritePreview)
    {
        if (SpritePreview->objectName().isEmpty())
            SpritePreview->setObjectName(QString::fromUtf8("SpritePreview"));
        SpritePreview->resize(440, 525);
        spinBox = new QSpinBox(SpritePreview);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(150, 440, 171, 61));
        spinBox->setMaximum(60);
        spinBox->setSingleStep(10);
        label_2 = new QLabel(SpritePreview);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 450, 71, 41));
        QFont font;
        font.setPointSize(24);
        label_2->setFont(font);
        label_2->setScaledContents(false);
        previewDisplayer = new PreviewDisplayer(SpritePreview);
        previewDisplayer->setObjectName(QString::fromUtf8("previewDisplayer"));
        previewDisplayer->setGeometry(QRect(10, 10, 411, 411));

        retranslateUi(SpritePreview);

        QMetaObject::connectSlotsByName(SpritePreview);
    } // setupUi

    void retranslateUi(QDialog *SpritePreview)
    {
        SpritePreview->setWindowTitle(QCoreApplication::translate("SpritePreview", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("SpritePreview", "FPS:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SpritePreview: public Ui_SpritePreview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRITEPREVIEW_H
