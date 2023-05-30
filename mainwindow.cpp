#include "mainwindow.h"
#include <QPushButton>
#include <QMessageBox>
#include <QTime>

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
    });
}

MainWindow::~MainWindow()
{
}
