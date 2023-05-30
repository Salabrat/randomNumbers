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
    });

    setCentralWidget(button);
}

MainWindow::~MainWindow()
{
}
