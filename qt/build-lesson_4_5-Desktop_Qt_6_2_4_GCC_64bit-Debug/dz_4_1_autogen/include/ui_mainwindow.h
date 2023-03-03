/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *mSave;
    QAction *mOpen;
    QAction *mSaveAs;
    QAction *mExit;
    QAction *mReference;
    QAction *mOpenReadOnly;
    QAction *mSettings;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelCurPath;
    QLineEdit *lineEditCurPath;
    QHBoxLayout *horizontalLayout_2;
    QTreeView *treeView;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *mFile;
    QMenu *mHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        mSave = new QAction(MainWindow);
        mSave->setObjectName(QString::fromUtf8("mSave"));
        mOpen = new QAction(MainWindow);
        mOpen->setObjectName(QString::fromUtf8("mOpen"));
        mSaveAs = new QAction(MainWindow);
        mSaveAs->setObjectName(QString::fromUtf8("mSaveAs"));
        mExit = new QAction(MainWindow);
        mExit->setObjectName(QString::fromUtf8("mExit"));
        mReference = new QAction(MainWindow);
        mReference->setObjectName(QString::fromUtf8("mReference"));
        mOpenReadOnly = new QAction(MainWindow);
        mOpenReadOnly->setObjectName(QString::fromUtf8("mOpenReadOnly"));
        mSettings = new QAction(MainWindow);
        mSettings->setObjectName(QString::fromUtf8("mSettings"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelCurPath = new QLabel(centralwidget);
        labelCurPath->setObjectName(QString::fromUtf8("labelCurPath"));

        horizontalLayout_3->addWidget(labelCurPath);

        lineEditCurPath = new QLineEdit(centralwidget);
        lineEditCurPath->setObjectName(QString::fromUtf8("lineEditCurPath"));
        lineEditCurPath->setEnabled(true);
        lineEditCurPath->setMouseTracking(false);
        lineEditCurPath->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEditCurPath);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        treeView = new QTreeView(centralwidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        treeView->setFont(font);
        treeView->header()->setVisible(true);

        horizontalLayout_2->addWidget(treeView);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        sizePolicy.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(12);
        textEdit->setFont(font1);
        textEdit->setMouseTracking(true);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        horizontalLayout_2->addWidget(textEdit);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 3);

        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menubar->setMouseTracking(false);
        mFile = new QMenu(menubar);
        mFile->setObjectName(QString::fromUtf8("mFile"));
        mHelp = new QMenu(menubar);
        mHelp->setObjectName(QString::fromUtf8("mHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(mFile->menuAction());
        menubar->addAction(mHelp->menuAction());
        mFile->addAction(mOpen);
        mFile->addAction(mOpenReadOnly);
        mFile->addAction(mSave);
        mFile->addAction(mSaveAs);
        mFile->addSeparator();
        mFile->addAction(mExit);
        mHelp->addAction(mReference);
        mHelp->addAction(mSettings);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\201\321\202\320\276\320\262\321\213\320\271 \321\200\320\265\320\264\320\260\320\272\321\202\320\276\321\200", nullptr));
        mSave->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
#if QT_CONFIG(statustip)
        mSave->setStatusTip(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
#endif // QT_CONFIG(statustip)
        mOpen->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
#if QT_CONFIG(tooltip)
        mOpen->setToolTip(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        mOpen->setStatusTip(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\202\320\265\320\272\321\201\321\202\320\276\320\262\321\213\320\271 \321\204\320\260\320\271\320\273", nullptr));
#endif // QT_CONFIG(statustip)
        mSaveAs->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272...", nullptr));
#if QT_CONFIG(statustip)
        mSaveAs->setStatusTip(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\204\320\260\320\271\320\273 \320\277\320\276\320\264 \320\264\321\200\321\203\320\263\320\270\320\274 \320\270\320\274\320\265\320\275\320\265\320\274", nullptr));
#endif // QT_CONFIG(statustip)
        mExit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
#if QT_CONFIG(statustip)
        mExit->setStatusTip(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264 \320\270\320\267 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217", nullptr));
#endif // QT_CONFIG(statustip)
        mReference->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
#if QT_CONFIG(statustip)
        mReference->setStatusTip(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260 \320\277\320\276 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        mReference->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        mOpenReadOnly->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\202\320\276\320\273\321\214\320\272\320\276 \320\264\320\273\321\217 \321\207\321\202\320\265\320\275\320\270\321\217", nullptr));
#if QT_CONFIG(statustip)
        mOpenReadOnly->setStatusTip(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273 \321\202\320\276\320\273\321\214\320\272\320\276 \320\264\320\273\321\217 \321\207\321\202\320\265\320\275\320\270\321\217", nullptr));
#endif // QT_CONFIG(statustip)
        mSettings->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
#if QT_CONFIG(statustip)
        mSettings->setStatusTip(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", nullptr));
#endif // QT_CONFIG(statustip)
        labelCurPath->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271 \320\277\321\203\321\202\321\214:", nullptr));
        mFile->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        mHelp->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
