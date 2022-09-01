#include "mainwindow.h"

#include <QApplication>
#include <QScreen>

constexpr int WIDTH = 800;
constexpr int HEIGHT = 600;
constexpr int MIN_WIDTH = 250;
constexpr int MIN_HEIGHT = 150;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    QScreen *screen = QApplication::screens().at(0);
    QSize size = screen->availableSize();
    w.setGeometry((size.width() - WIDTH) / 2, (size.height() - HEIGHT) / 2,
                  WIDTH, HEIGHT);
    w.setWindowTitle("ДЗ №7: задания 2,3");
    w.setMinimumSize(MIN_WIDTH, MIN_HEIGHT);
    w.show();
    return a.exec();
}
