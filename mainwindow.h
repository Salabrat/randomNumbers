#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QWidget>

class BackgroundWidget : public QWidget
{
public:
    BackgroundWidget(const QPixmap& pixmap, QWidget* parent = nullptr);

private:
    QPixmap backgroundPixmap;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void setPhotoDirectory();

private:
    QPixmap backgroundPixmap;
};

#endif // MAINWINDOW_H
