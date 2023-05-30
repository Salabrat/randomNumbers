#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Применение стилей Qt
    QApplication::setStyle("Fusion");

    // Настройка цветовой схемы
    QPalette palette;
    palette.setColor(QPalette::Window, QColor("#f0f0f0")); // Цвет фона окна
    palette.setColor(QPalette::WindowText, QColor("#44444")); // Цвет текста
    palette.setColor(QPalette::Button, QColor("#dddddd")); // Цвет кнопок
    palette.setColor(QPalette::ButtonText, QColor("#333333")); // Цвет текста кнопок
    a.setPalette(palette);

    MainWindow w;
    w.show();

    return a.exec();
}
