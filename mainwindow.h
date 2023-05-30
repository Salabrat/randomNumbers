#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPixmap backgroundPixmap;

private slots:
    void setPhotoDirectory();


};

#endif // MAINWINDOW_H
