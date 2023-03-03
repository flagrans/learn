/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QGroupBox *mSetGroupLang;
    QRadioButton *mSetRus;
    QRadioButton *mSetEng;
    QGroupBox *mSetGroupHotkey;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *l_open;
    QPushButton *p_open;
    QLabel *l_save;
    QPushButton *p_save;
    QPushButton *p_settings;
    QLabel *l_settings;
    QPushButton *p_help;
    QLabel *l_help;
    QPushButton *p_exit;
    QLabel *l_exit;
    QLabel *l_open_ro;
    QPushButton *p_open_ro;
    QLabel *label_6;
    QPushButton *mSetSave;
    QPushButton *mSetCancel;
    QGroupBox *mSetGroupTheme;
    QRadioButton *mSetWhite;
    QRadioButton *mSetGrey;

    void setupUi(QWidget *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(290, 345);
        mSetGroupLang = new QGroupBox(Settings);
        mSetGroupLang->setObjectName(QString::fromUtf8("mSetGroupLang"));
        mSetGroupLang->setGeometry(QRect(10, 10, 270, 51));
        mSetRus = new QRadioButton(mSetGroupLang);
        mSetRus->setObjectName(QString::fromUtf8("mSetRus"));
        mSetRus->setGeometry(QRect(38, 20, 91, 22));
        mSetRus->setChecked(true);
        mSetEng = new QRadioButton(mSetGroupLang);
        mSetEng->setObjectName(QString::fromUtf8("mSetEng"));
        mSetEng->setGeometry(QRect(148, 20, 91, 22));
        mSetGroupHotkey = new QGroupBox(Settings);
        mSetGroupHotkey->setObjectName(QString::fromUtf8("mSetGroupHotkey"));
        mSetGroupHotkey->setGeometry(QRect(10, 122, 270, 181));
        label_1 = new QLabel(mSetGroupHotkey);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(10, 25, 70, 16));
        label_2 = new QLabel(mSetGroupHotkey);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 73, 70, 16));
        label_3 = new QLabel(mSetGroupHotkey);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 98, 70, 16));
        label_4 = new QLabel(mSetGroupHotkey);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 123, 70, 16));
        label_5 = new QLabel(mSetGroupHotkey);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 148, 70, 16));
        l_open = new QLabel(mSetGroupHotkey);
        l_open->setObjectName(QString::fromUtf8("l_open"));
        l_open->setGeometry(QRect(130, 25, 111, 16));
        p_open = new QPushButton(mSetGroupHotkey);
        p_open->setObjectName(QString::fromUtf8("p_open"));
        p_open->setGeometry(QRect(245, 22, 21, 20));
        l_save = new QLabel(mSetGroupHotkey);
        l_save->setObjectName(QString::fromUtf8("l_save"));
        l_save->setGeometry(QRect(130, 73, 111, 16));
        p_save = new QPushButton(mSetGroupHotkey);
        p_save->setObjectName(QString::fromUtf8("p_save"));
        p_save->setGeometry(QRect(245, 70, 21, 20));
        p_settings = new QPushButton(mSetGroupHotkey);
        p_settings->setObjectName(QString::fromUtf8("p_settings"));
        p_settings->setGeometry(QRect(245, 95, 21, 20));
        l_settings = new QLabel(mSetGroupHotkey);
        l_settings->setObjectName(QString::fromUtf8("l_settings"));
        l_settings->setGeometry(QRect(130, 98, 111, 16));
        p_help = new QPushButton(mSetGroupHotkey);
        p_help->setObjectName(QString::fromUtf8("p_help"));
        p_help->setGeometry(QRect(245, 120, 21, 20));
        l_help = new QLabel(mSetGroupHotkey);
        l_help->setObjectName(QString::fromUtf8("l_help"));
        l_help->setGeometry(QRect(130, 123, 111, 16));
        p_exit = new QPushButton(mSetGroupHotkey);
        p_exit->setObjectName(QString::fromUtf8("p_exit"));
        p_exit->setGeometry(QRect(245, 145, 21, 20));
        l_exit = new QLabel(mSetGroupHotkey);
        l_exit->setObjectName(QString::fromUtf8("l_exit"));
        l_exit->setGeometry(QRect(130, 148, 111, 16));
        l_open_ro = new QLabel(mSetGroupHotkey);
        l_open_ro->setObjectName(QString::fromUtf8("l_open_ro"));
        l_open_ro->setGeometry(QRect(130, 50, 111, 16));
        p_open_ro = new QPushButton(mSetGroupHotkey);
        p_open_ro->setObjectName(QString::fromUtf8("p_open_ro"));
        p_open_ro->setGeometry(QRect(245, 47, 21, 20));
        label_6 = new QLabel(mSetGroupHotkey);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 50, 120, 16));
        mSetSave = new QPushButton(Settings);
        mSetSave->setObjectName(QString::fromUtf8("mSetSave"));
        mSetSave->setGeometry(QRect(110, 315, 80, 24));
        mSetCancel = new QPushButton(Settings);
        mSetCancel->setObjectName(QString::fromUtf8("mSetCancel"));
        mSetCancel->setGeometry(QRect(200, 315, 80, 24));
        mSetGroupTheme = new QGroupBox(Settings);
        mSetGroupTheme->setObjectName(QString::fromUtf8("mSetGroupTheme"));
        mSetGroupTheme->setGeometry(QRect(10, 65, 270, 51));
        mSetWhite = new QRadioButton(mSetGroupTheme);
        mSetWhite->setObjectName(QString::fromUtf8("mSetWhite"));
        mSetWhite->setGeometry(QRect(38, 20, 91, 22));
        mSetWhite->setChecked(true);
        mSetGrey = new QRadioButton(mSetGroupTheme);
        mSetGrey->setObjectName(QString::fromUtf8("mSetGrey"));
        mSetGrey->setGeometry(QRect(148, 20, 91, 22));

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QWidget *Settings)
    {
        Settings->setWindowTitle(QString());
        mSetGroupLang->setTitle(QCoreApplication::translate("Settings", "\320\257\320\267\321\213\320\272 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", nullptr));
        mSetRus->setText(QCoreApplication::translate("Settings", "\320\240\321\203\321\201\321\201\320\272\320\270\320\271", nullptr));
        mSetEng->setText(QCoreApplication::translate("Settings", "\320\220\320\275\320\263\320\273\320\270\320\271\321\201\320\272\320\270\320\271", nullptr));
        mSetGroupHotkey->setTitle(QCoreApplication::translate("Settings", "\320\223\320\276\321\200\321\217\321\207\320\270\320\265 \320\272\320\273\320\260\320\262\320\270\321\210\320\270", nullptr));
        label_1->setText(QCoreApplication::translate("Settings", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214:", nullptr));
        label_2->setText(QCoreApplication::translate("Settings", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214:", nullptr));
        label_3->setText(QCoreApplication::translate("Settings", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270:", nullptr));
        label_4->setText(QCoreApplication::translate("Settings", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260:", nullptr));
        label_5->setText(QCoreApplication::translate("Settings", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        p_open->setText(QCoreApplication::translate("Settings", "...", nullptr));
        p_save->setText(QCoreApplication::translate("Settings", "...", nullptr));
        p_settings->setText(QCoreApplication::translate("Settings", "...", nullptr));
        p_help->setText(QCoreApplication::translate("Settings", "...", nullptr));
        p_exit->setText(QCoreApplication::translate("Settings", "...", nullptr));
        p_open_ro->setText(QCoreApplication::translate("Settings", "...", nullptr));
        label_6->setText(QCoreApplication::translate("Settings", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\264\320\273\321\217 \321\207\321\202\320\265\320\275\320\270\321\217:", nullptr));
        mSetSave->setText(QCoreApplication::translate("Settings", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        mSetCancel->setText(QCoreApplication::translate("Settings", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        mSetGroupTheme->setTitle(QCoreApplication::translate("Settings", "\320\242\320\265\320\274\320\260 \320\276\321\204\320\276\321\200\320\274\320\273\320\265\320\275\320\270\321\217", nullptr));
        mSetWhite->setText(QCoreApplication::translate("Settings", "\320\241\320\262\320\265\321\202\320\273\320\260\321\217", nullptr));
        mSetGrey->setText(QCoreApplication::translate("Settings", "\320\242\320\265\320\274\320\275\320\260\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
