#include "mainwindow.h"
#include <QPushButton>
#include <QMessageBox>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton *button = new QPushButton("Сгенерировать случайное число", this);
    connect(button, &QPushButton::clicked, [=]() {
        QTime time = QTime::currentTime();
        qsrand(static_cast<uint>(time.msec()));

        int randomNumber = qrand() % 1912111 + 1;
        QMessageBox::information(this, "Случайное число", "Сгенерировано случайное число: " + QString::number(randomNumber));
    });

    setCentralWidget(button);
}

MainWindow::~MainWindow()
{
}
