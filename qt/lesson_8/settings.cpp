#include "settings.h"
#include "ui_settings.h"

#include <QDebug>
#include <QKeyEvent>
#include <QTranslator>

Settings::Settings(QWidget *parent, QVector<QString> *md)
    : QWidget(parent), ui(new Ui::Settings) {
    ui->setupUi(this);

    mk = md;

    ui->l_open->setText(md->at(2));
    ui->l_open_ro->setText(md->at(3));
    ui->l_save->setText(md->at(4));
    ui->l_settings->setText(md->at(5));
    ui->l_help->setText(md->at(6));
    ui->l_exit->setText(md->at(7));
    ui->l_print->setText(md->at(8));
    ui->l_paste_date->setText(md->at(9));

    if (md->at(0) == "en") {
        ui->mSetEng->setChecked(true);
        switchLang("en_EN");
    } else {
        ui->mSetRus->setChecked(true);
        switchLang("ru_RU");
    }

    if (md->at(1) == "grey") {
        ui->mSetGrey->setChecked(true);
    } else {
        ui->mSetWhite->setChecked(true);
    }

    connect(ui->mSetSave, &QPushButton::clicked, this,
            &Settings::on_mSettings_Save_trigger);
    connect(ui->mSetCancel, &QPushButton::clicked, this,
            &Settings::on_mSettings_Cancel_trigger);

    connect(ui->p_open, &QPushButton::clicked, this,
            [=]() { this->press(ui->l_open); });
    connect(ui->p_open_ro, &QPushButton::clicked, this,
            [=]() { this->press(ui->l_open_ro); });
    connect(ui->p_save, &QPushButton::clicked, this,
            [=]() { this->press(ui->l_save); });
    connect(ui->p_settings, &QPushButton::clicked, this,
            [=]() { this->press(ui->l_settings); });
    connect(ui->p_help, &QPushButton::clicked, this,
            [=]() { this->press(ui->l_help); });
    connect(ui->p_exit, &QPushButton::clicked, this,
            [=]() { this->press(ui->l_exit); });
    connect(ui->p_print, &QPushButton::clicked, this,
            [=]() { this->press(ui->l_print); });
    connect(ui->p_paste_date, &QPushButton::clicked, this,
            [=]() { this->press(ui->l_paste_date); });
}

Settings::~Settings() { delete ui; }

void Settings::closeEvent(QCloseEvent *event) {
    qDebug() << "Exit";
    on_mSettings_Cancel_trigger();
}

void Settings::on_mSettings_Save_trigger() {

    if (ui->l_open->text() != tr("Задайте клавишу..."))
        mk->replace(2, ui->l_open->text());
    if (ui->l_open_ro->text() != tr("Задайте клавишу..."))
        mk->replace(3, ui->l_open_ro->text());
    if (ui->l_save->text() != tr("Задайте клавишу..."))
        mk->replace(4, ui->l_save->text());
    if (ui->l_settings->text() != tr("Задайте клавишу..."))
        mk->replace(5, ui->l_settings->text());
    if (ui->l_help->text() != tr("Задайте клавишу..."))
        mk->replace(6, ui->l_help->text());
    if (ui->l_exit->text() != tr("Задайте клавишу..."))
        mk->replace(7, ui->l_exit->text());
    if (ui->l_print->text() != tr("Задайте клавишу..."))
        mk->replace(8, ui->l_print->text());
    if (ui->l_paste_date->text() != tr("Задайте клавишу..."))
        mk->replace(9, ui->l_paste_date->text());

    if (ui->mSetEng->isChecked()) {
        if (mk->at(0) == "ru") {
            mk->replace(0, "en");
            switchLang("en_EN");
        }
    } else {
        if (mk->at(0) == "en") {
            mk->replace(0, "ru");
            switchLang("ru_RU");
        }
    }

    if (ui->mSetGrey->isChecked() && mk->at(1) == "white") {
        mk->replace(1, "grey");
        emit changeStyle();
    }
    if (ui->mSetWhite->isChecked() && mk->at(1) == "grey") {
        mk->replace(1, "white");
        emit changeStyle();
    }
    emit saveSett();
    close();
}

void Settings::on_mSettings_Cancel_trigger() { close(); }

void Settings::press(QLabel *l) {
    m_focused = l;
    l->setText(tr("Задайте клавишу..."));
}

void Settings::keyPressEvent(QKeyEvent *event) {
    if ((event->key() != Qt::Key_Shift) && (event->key() != Qt::Key_Control) &&
        (event->key() != Qt::Key_Alt)) {
        QKeySequence tt = QKeySequence(event->key() | event->modifiers());
        if (m_focused != nullptr) {
            m_focused->setText(tt.toString());
            qDebug() << tt.toString();
            m_focused = nullptr;
        }
    }
}

void Settings::switchLang(const QString &lang) {
    QTranslator translator;
    bool b = translator.load("TextEdit_" + lang);
    qApp->installTranslator(&translator);
    emit changeLang();
    ui->retranslateUi(this);
    setWindowTitle(tr("Настройки"));
}
