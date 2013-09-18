#include <QtGui/QApplication>
#include <QTextEdit>
#include <QMessageBox>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  // working
      //QTextEdit textEdit;
      //textEdit.show();
 // working ends
    MainWindow w;
    w.show();
    QMessageBox messageBox;
    //messageBox.setWindowTitle(tr("Notepad"));
    messageBox.setText("Do you really want to quit?");
    return a.exec();
}
