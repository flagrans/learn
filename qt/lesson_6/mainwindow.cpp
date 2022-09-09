#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "myjson.h"
#include "mysubwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QKeyEvent>
#include <QLabel>
#include <QMdiSubWindow>
#include <QMessageBox>
#include <QPrintDialog>
#include <QPrinter>
#include <QStyle>
#include <QSystemTrayIcon>
#include <QTextEdit>
#include <QTextStream>
#include <QTranslator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {

    MyJson mj = MyJson();

    mj.read("settings.json", mydata);

    ui->setupUi(this);
    setWindowTitle(filename + tr(" - Текстовый редактор"));
    setWindowIcon(QIcon(":/icon.png"));

    QSystemTrayIcon *sysTrayIcon = new QSystemTrayIcon(this);
    sysTrayIcon->setIcon(QIcon(":/icon.png"));
    sysTrayIcon->show();

    modelFS = new QFileSystemModel;

    ui->lineEditCurPath->setText(QDir::currentPath());
    ui->treeView->setModel(modelFS);
    modelFS->setRootPath(QDir::currentPath());
    QStringList filters;
    filters << "*.txt";
    modelFS->setNameFilters(filters);
    modelFS->setNameFilterDisables(false);

    setsStyle();
    initLang(mydata.at(0));

    shortCutSetup();

    connect(ui->mReference, &QAction::triggered, this,
            &MainWindow::on_mReference_trigger);
    connect(ui->mExit, &QAction::triggered, this,
            &MainWindow::on_mExit_trigger);
    connect(ui->mOpen, &QAction::triggered, this,
            &MainWindow::on_mOpen_trigger);
    connect(ui->mOpenReadOnly, &QAction::triggered, this,
            &MainWindow::on_mOpenReadOnly);
    connect(ui->mSaveAs, &QAction::triggered, this,
            &MainWindow::on_mSaveAs_trigger);
    connect(ui->mSave, &QAction::triggered, this,
            &MainWindow::on_mSave_trigger);
    //!  connect(ui->textEdit, &QTextEdit::textChanged, this,
    //!          &MainWindow::on_textEdit_textChange);
    connect(ui->mSettings, &QAction::triggered, this,
            &MainWindow::on_mSettings_trigger);
    connect(ui->mPrint, &QAction::triggered, this,
            &MainWindow::on_mPrint_trigger);
    connect(ui->minSub, &QAction::triggered, this,
            &MainWindow::on_minSub_trigger);
    connect(ui->cascadeSub, &QAction::triggered, this,
            &MainWindow::on_cascadeSub_trigger);
    connect(ui->maxSub, &QAction::triggered, this,
            &MainWindow::on_maxSub_trigger);
    connect(ui->tileSub, &QAction::triggered, this,
            &MainWindow::on_tileSub_trigger);

    // connect(qApp, &QCoreApplication::aboutToQuit, this,
    // &MainWindow::on_quit);
}

MainWindow::~MainWindow() {
    //!    if (this->isChange)
    //!        on_quit();
    //!    s->hide();
    //! Крашит приложение при выходе, опять же надо оптимизировать под
    //! многооконность
    delete ui;
}

void MainWindow::on_mExit_trigger() { QApplication::quit(); }

void MainWindow::on_mReference_trigger() {
    QString data;
    QString fileName(":/help.txt");

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        data = tr("Файл справки отсутствует.");
    } else {
        data = file.readAll();
    }
    file.close();
    QMessageBox::about(this, tr("Справка"), data);
}

void MainWindow::on_mOpen_trigger() {
    if (!open_file()) {
        return;
    }
    qobject_cast<MySubWindow *>(ui->mdiArea->activeSubWindow()->widget())
        ->setReadOnly(false);
    // ui->mSave->setDisabled(false); // Пока не знаю как переделавть под
    // многооконность
}

void MainWindow::on_mOpenReadOnly() {
    if (!open_file()) {
        return;
    }
    qobject_cast<MySubWindow *>(ui->mdiArea->activeSubWindow()->widget())
        ->setReadOnly(true);
    // ui->mSave->setDisabled(true); // Пока не знаю как переделавть под
    // многооконность
}

void MainWindow::on_mSaveAs_trigger() {
    filename = QFileDialog::getSaveFileName(this, tr("Сохранить как..."),
                                            filename, "Text files (*.txt)");

    save_file();
}

void MainWindow::on_mSave_trigger() { save_file(); }

void MainWindow::on_textEdit_textChange() {
    isChange = true;
    setWindowTitle("* " + filename + tr(" - Текстовый редактор"));
}

void MainWindow::save_file() {

    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        return;
    }
    QTextStream out(&file);
    out << qobject_cast<MySubWindow *>(ui->mdiArea->activeSubWindow()->widget())
               ->toPlainText();
    file.close();

    setWindowTitle(filename + tr(" - Текстовый редактор"));
}

bool MainWindow::open_file() {
    filename = QFileDialog::getOpenFileName(this, tr("Выберите текстовый файл"),
                                            "", "Text files (*.txt)");
    if (isReopen(filename)) {
        return true;
    } else {
        addOpenWin(filename);
        openFileWithTree();
    }
    return true;
}

void MainWindow::on_quit() {
    int ret = QMessageBox::warning(this, tr("Текстовый редактор"),
                                   tr("Документ был изменен.\n"
                                      "Сохранить изменения?"),
                                   QMessageBox::Save | QMessageBox::Cancel,
                                   QMessageBox::Save);
    if (ret == QMessageBox::Save) {
        save_file();
    }
}

void MainWindow::switchLang() {
    ui->retranslateUi(this);
    setWindowTitle(filename + tr(" - Текстовый редактор"));
}

void MainWindow::shortCutSetup() {
    ui->mOpen->setShortcut(QKeySequence(mydata.at(2)));
    ui->mOpenReadOnly->setShortcut(QKeySequence(mydata.at(3)));
    ui->mSave->setShortcut(QKeySequence(mydata.at(4)));
    ui->mSettings->setShortcut(QKeySequence(mydata.at(5)));
    ui->mReference->setShortcut(QKeySequence(mydata.at(6)));
    ui->mExit->setShortcut(QKeySequence(mydata.at(7)));
    ui->mPrint->setShortcut(QKeySequence(mydata.at(8)));
}

void MainWindow::on_mSettings_trigger() {

    s = new Settings(nullptr, &mydata);
    s->setWindowIcon(QIcon(":/icon.png"));
    if (mydata.at(0) == "en") {
        s->setWindowTitle(tr("Settings"));
    } else {
        s->setWindowTitle(tr("Настройки"));
    }
    s->setWindowFlags(Qt::WindowCloseButtonHint);
    s->setWindowModality(Qt::ApplicationModal);
    s->setAttribute(Qt::WA_DeleteOnClose);
    connect(s, &Settings::changeLang, this, &MainWindow::switchLang);
    connect(s, &Settings::saveSett, this, &MainWindow::saveSettings);
    connect(s, &Settings::changeStyle, this, &MainWindow::setsStyle);
    s->show();
}

void MainWindow::saveSettings() {
    MyJson mj = MyJson();
    mj.save("settings.json", mydata);
    shortCutSetup();
}

void MainWindow::setsStyle() {
    QFile qss(":/" + mydata.at(1) + ".qss");
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();

    if (mydata.at(1) == "grey") {
        ui->mOpen->setIcon(QIcon(":/open2.png"));
        ui->mOpenReadOnly->setIcon(QIcon(":/openro2.png"));
        ui->mSave->setIcon(QIcon(":/save2.png"));
        ui->mSaveAs->setIcon(QIcon(":/saveas2.png"));
        ui->mExit->setIcon(QIcon(":/exit2.png"));
        ui->mSettings->setIcon(QIcon(":/settings2.png"));
        ui->mReference->setIcon(QIcon(":/about2.png"));
        ui->mPrint->setIcon(QIcon(":/print2.png"));
        setWindowIcon(QIcon(":/icon2.png"));

    } else {
        ui->mOpen->setIcon(QIcon(":/open.png"));
        ui->mOpenReadOnly->setIcon(QIcon(":/openro.png"));
        ui->mSave->setIcon(QIcon(":/save.png"));
        ui->mSaveAs->setIcon(QIcon(":/saveas.png"));
        ui->mExit->setIcon(QIcon(":/exit.png"));
        ui->mSettings->setIcon(QIcon(":/settings.png"));
        ui->mReference->setIcon(QIcon(":/about.png"));
        ui->mPrint->setIcon(QIcon(":/print.png"));
        setWindowIcon(QIcon(":/icon.png"));
    }
}

void MainWindow::initLang(const QString &lang) {
    QTranslator translator;
    bool b = translator.load("TextEdit_" + lang + "_" + lang.toUpper());
    qApp->installTranslator(&translator);
    ui->retranslateUi(this);
}

bool MainWindow::openFileWithTree() {
    QString data;

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        return false;
    }
    data = file.readAll();

    file.close();
    qobject_cast<MySubWindow *>(ui->mdiArea->activeSubWindow()->widget())
        ->setText(data);
    setWindowTitle(filename + tr(" - Текстовый редактор"));
    return true;
}

void MainWindow::on_treeView_clicked(const QModelIndex &index) {

    ui->lineEditCurPath->setText(modelFS->filePath(index));
}

void MainWindow::on_treeView_doubleClicked(const QModelIndex &index) {
    if (!modelFS->isDir(index)) {
        filename = modelFS->filePath(index);
        if (isReopen(filename)) {
            return;
        } else {
            addOpenWin(filename);
            openFileWithTree();
        }
    }
}

void MainWindow::on_mPrint_trigger() {
    QPrinter printer;
    QPrintDialog dlg(&printer, qobject_cast<MySubWindow *>(
                                   ui->mdiArea->currentSubWindow()->widget()));
    dlg.setWindowTitle(tr("Печать"));
    if (dlg.exec() != QDialog::Accepted)
        return;
    QTextEdit *curTE =
        qobject_cast<MySubWindow *>(ui->mdiArea->currentSubWindow()->widget());
    curTE->print(&printer);
}

void MainWindow::addOpenWin(const QString &fn) {
    QAction *testAction = new QAction();
    testAction->setText(getFileName(fn));
    ui->openWindows->addAction(testAction);
    MySubWindow *textE = new MySubWindow(fn, testAction);
    textE->setAttribute(Qt::WA_DeleteOnClose);
    textE->setWindowTitle(getFileName(fn));
    ui->mdiArea->addSubWindow(textE);
    textE->showMaximized();
    connect(textE, &MySubWindow::destroyed, this, [=]() {
        ui->openWindows->removeAction(textE->getAction());
        rebuildOpenWindows();
    });
    connect(textE->getAction(), &QAction::triggered, this, [=]() {
        on_changeActive_trigger(textE->getFN());
        rebuildOpenWindows();
    });
    rebuildOpenWindows();
}

QString MainWindow::getFileName(const QString &fn) {
    QFileInfo fileinfo(filename);
    return fileinfo.fileName();
}

void MainWindow::rebuildOpenWindows() {
    for (auto temp : ui->mdiArea->subWindowList()) {
        qobject_cast<MySubWindow *>(temp->widget())
            ->getAction()
            ->setIcon(QIcon());
    }
    qobject_cast<MySubWindow *>(ui->mdiArea->activeSubWindow()->widget())
        ->getAction()
        ->setIcon(QIcon(":/win.png"));
}

void MainWindow::on_minSub_trigger() {
    ui->mdiArea->currentSubWindow()->widget()->showMinimized();
    for (auto temp : ui->mdiArea->subWindowList()) {
        temp->widget()->showMinimized();
    }
}

void MainWindow::on_maxSub_trigger() {
    for (auto temp : ui->mdiArea->subWindowList()) {
        temp->widget()->showMaximized();
    }
}

void MainWindow::on_cascadeSub_trigger() {
    on_maxSub_trigger();
    ui->mdiArea->cascadeSubWindows();
}

void MainWindow::on_tileSub_trigger() {
    on_maxSub_trigger();
    ui->mdiArea->tileSubWindows();
}

bool MainWindow::isReopen(const QString &fn) {
    for (auto temp : ui->mdiArea->subWindowList()) {
        if (qobject_cast<MySubWindow *>(temp->widget())->getFN() == fn) {
            ui->mdiArea->setActiveSubWindow(temp);
            rebuildOpenWindows();
            return true;
        }
    }
    return false;
}

void MainWindow::on_changeActive_trigger(const QString &fn) {
    for (auto temp : ui->mdiArea->subWindowList()) {
        if (qobject_cast<MySubWindow *>(temp->widget())->getFN() == fn) {
            ui->mdiArea->setActiveSubWindow(temp);
            rebuildOpenWindows();
        }
    }
    rebuildOpenWindows();
}
