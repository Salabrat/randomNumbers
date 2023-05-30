#include "mainwindow.h"
#include <QPushButton>
#include <QMessageBox>
#include <QTime>
#include <QFileDialog>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Генератор случайных чисел");
    setFixedSize(300, 200);

    QPushButton *button = new QPushButton("Сгенерировать случайное число", this);
    button->setGeometry(50, 50, 200, 30);

    connect(button, &QPushButton::clicked, [=]() {
        QTime time = QTime::currentTime();
        qsrand(static_cast<uint>(time.msec()));

        int randomNumber = qrand() % 100 + 1;
        QMessageBox::information(this, "Случайное число", "Сгенерировано случайное число: " + QString::number(randomNumber));

        backgroundPixmap.load("D:/Coding/QT_PP/radommap/1.jpg"); // Замените путь к фотографии на свой

        QPalette palette;
        palette.setBrush(QPalette::Window, backgroundPixmap);
        setPalette(palette);

    });
}

void MainWindow::setPhotoDirectory()
{
    QString directory = QFileDialog::getExistingDirectory(this, "Выберите каталог с фотографиями", QDir::homePath());
    if (!directory.isEmpty()) {
        // Здесь вы можете выполнять дополнительные действия с выбранным каталогом, если необходимо
        // Например, загрузить список фотографий из каталога и т.д.
        // ...
    }
}

MainWindow::~MainWindow()
{
}
