#ifndef SETTINGS_H
#define SETTINGS_H

#include <QLabel>
#include <QWidget>

namespace Ui {
class Settings;
}

class Settings : public QWidget {
    Q_OBJECT

public:
    Settings(QWidget *parent = nullptr, QVector<QString> *md = nullptr);
    ~Settings();

protected:
    void closeEvent(QCloseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

public:
    QString hotOpen;
    QString hotSave;
    QString hotSettings;
    QString hotHelp;
    QString hotExit;

signals:
    void changeLang();
    void changeStyle();
    void saveSett();

private slots:
    void on_mSettings_Save_trigger();
    void on_mSettings_Cancel_trigger();
    void press(QLabel *);
    void switchLang(const QString &lang);

private:
    Ui::Settings *ui;
    QLabel *m_focused = nullptr;
    QVector<QString> *mk;
};

#endif // SETTINGS_H
