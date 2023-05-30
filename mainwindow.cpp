#include "mainwindow.h"
#include <QPushButton>
#include <QMessageBox>
#include <QTime>
#include <QFileDialog>
#include <QDir>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QSizePolicy>

BackgroundWidget::BackgroundWidget(const QPixmap& pixmap, QWidget* parent)
    : QWidget(parent), backgroundPixmap(pixmap)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);

    QLabel* backgroundLabel = new QLabel(this);
    backgroundLabel->setPixmap(backgroundPixmap);
    backgroundLabel->setScaledContents(true);
    layout->addWidget(backgroundLabel);
}

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setWindowTitle("Генератор случайных чисел");
    setFixedSize(300, 200);

    QString imagePath = "D:/Coding/QT_PP/radommap/1.png"; // Замените путь к фотографии на свой
    QPixmap backgroundPixmap(imagePath);

    BackgroundWidget* backgroundWidget = new BackgroundWidget(backgroundPixmap, this);
    setCentralWidget(backgroundWidget);

    QPushButton* button = new QPushButton("Сгенерировать случайное число", backgroundWidget);
    button->setGeometry(50, 50, 200, 30);

    connect(button, &QPushButton::clicked, [=]() {
        QTime time = QTime::currentTime();
        qsrand(static_cast<uint>(time.msec()));

        int randomNumber = qrand() % 100 + 1;
        QMessageBox::information(this, "Случайное число", "Сгенерировано случайное число: " + QString::number(randomNumber));
    });

    QHBoxLayout* mainLayout = new QHBoxLayout(backgroundWidget);
    mainLayout->addWidget(button);
    mainLayout->setAlignment(Qt::AlignCenter);
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
