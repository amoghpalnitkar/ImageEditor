#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    //*****************
    void a2();
    void open();
    void close();
    void quit();
private slots:
    void open1();
   // void save();
    void open2();
    void open3();
    void valueChangedSlot(int x);
    void valueChangedSlot_2(int);
    //private:

    //QTextEdit *txtEdit;

    //QAction *openAction;
    //QAction *saveAction;
    //QAction *exitAction;

    //QMenu *fileMenu;

   //*****************
public:

    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
