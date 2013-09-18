#include "mainwindow.h"
#include <QLocale>
#include "qtextedit.h"
#include "qaction.h"
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QTextEdit>
#include <QLineEdit>
#include <QMessageBox>
#include <QTextBrowser>
#include <QFile>
#include <QTextStream>
#include <QGraphicsView>
#include <QBitmap>
#include <QPixmap>
#include <QPicture>
#include <QPainter>
#include <QPaintDevice>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QColor>
#include <QWidget>
#include <QFileDialog>
#include "ui_mainwindow.h"

QString line = "abc";
QString line11;
int xcoor,ycoor;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QString line;
    line = "           -----Image Editor-----";
    QLineEdit(line,0);
    ui->menuMyFiles->addSeparator();
    //connect(ui->actionQuit_2, SIGNAL(triggered()),qApp,SLOT(quit()));
    int x;
    //QString line9 = "  ";
    //QString line10 = "     Created by - Amogh Palnitkar";
    //QString line11 = "                        - Arvind Telharkar";
    //QString line12 = "                        - Vishakha Damle";
    //this->ui->textBrowser->append(line);
   // this->ui->textBrowser->append(line);
    //line = line + this->ui->lineEdit->text();
    //for(x=0;x<20;x++)
        //this->ui->textBrowser->append(line9);
    //this->ui->textBrowser->append(line10);
    //this->ui->textBrowser->append(line11);
    //this->ui->textBrowser->append(line12);
    //this->ui->textBrowser->show();
    bool ii;
    ii = FALSE;

   // connect(this->ui->actionQuit,SIGNAL(triggered()),this,SLOT(save()));
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(valueChangedSlot(int)));
    //connect(this->ui->actionSave,SIGNAL(triggered()),this,SLOT(open3()));
    connect(ui->verticalSlider,SIGNAL(valueChanged(int)),this,SLOT(valueChangedSlot_2(int)));
    connect(this->ui->pushButton_2,SIGNAL(clicked()),this,SLOT(open1()));
   // connect(this->ui->pushButton,SIGNAL(clicked()),this,SLOT(open3()));
    connect(this->ui->actionOpen,SIGNAL(triggered()),this,SLOT(open2()));
    if (ii){
       line = line + this->ui->textBrowser->tr("Open ..");

        this->ui->textBrowser->show();
    };
    if (!(ii)){
        line = line + this->ui->textBrowser->tr("Not Open ..");

        this->ui->textBrowser->show();
    };

}

void MainWindow :: open2()   //Gives the image
{

    QFileDialog di;
    line = di.getOpenFileName(this,tr("Open File"),"C:",tr("Images(*.tiff *.tif)"));


    QFile file(line);
    if (!file.open(QIODevice::ReadWrite))
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }

        QGraphicsScene* scene = new QGraphicsScene();
        QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap(line));
        scene->addItem(item);
        this->ui->graphicsView->setScene(scene);
        this->ui->graphicsView->show();
}

void MainWindow :: open3()   //Gives the image
{

   // QFileDialog di;
    //line11 = di.getOpenFileName(this,tr("Open File"),"C:",tr("Images(*.tiff *.tif)"));


    QFile file(line11);
    if (!file.open(QIODevice::ReadWrite))
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }

        QGraphicsScene* scene = new QGraphicsScene();
        QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap(line11));
        scene->addItem(item);
        this->ui->graphicsView->setScene(scene);
        this->ui->graphicsView->show();
}

void MainWindow::open1()    //Displays Meta-Data
{

    QFileDialog di;
        if(line == "abc")
        {
             QMessageBox::critical(this, tr("Error"), tr("File not open!"));
            return;
           }
  QFile file(line);
  if (!file.open(QIODevice::ReadOnly)) {
      QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
      return;
  }
 // QString line11 ="C://Untitled123.tif";
   //  QFile file1(line11);
  /*QTextStream stream1 ( &file1 );

          if (!file1.open(QIODevice::WriteOnly)) {
              QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
              return;
          }*/

  int i = 0,j=0,k;
  char ch,ch1,ch2;
  int t_id;
  int type;
  int data_count;
  double data;
  int flag=0;
  int str,off,height,width;
  QLocale con;

              QTextStream stream ( &file );

     stream>>ch;

                      if(ch == 73)
                      {

                          QString line1 = "Big Endian";

                          this->ui->textBrowser->append(line1);
                            this->ui->textBrowser->show();
                      }
                      stream>>ch;

                      stream>>ch;

                      stream>>ch;


                      stream>>ch2;

                      stream>>ch1;

                       i=ch1;

                       if(i<0)
                           i=i+256;
                      int hex=i*256;

                       i=ch2;

                      if(i<0)
                      {
                              i=i+256;
                      }
                      hex=hex+i;

                        stream.seek(hex);
                        stream>>ch;

                      i=ch;

                      QString line1 = "No. of tags : ";
                      QString goo   = con.toString(i);

                        this->ui->textBrowser->append(line1);
                        this->ui->textBrowser->append(goo);
                        this->ui->textBrowser->show();
                      stream>>ch;

                      for(k=1;k<=12;k++)
                      {
                          stream>>ch;
                      }
                        while( !stream.atEnd() )
                               {
                                      stream>>ch;
                                      if(ch==00 && flag==0)
                                        {

                                                stream>>ch1;

                                                if(ch1== 01)   //0100-tag
                                                {

                                                          flag=1;
                                                        int i;

                                                        t_id=101;
                                                        stream>>ch;
                                                        type=ch;
                                                        stream>>ch;
                                                        stream>>ch;
                                                        data_count=ch;
                                                        stream>>ch;
                                                        if(data_count==1)
                                                        {
                                                                //offset=type;
                                                                printf("DC=1");		//check
                                                        }

                                                        for(i=1;i<=3;i++)
                                                        {
                                                              stream>>ch2;	//go to offset
                                                        }
                                                            stream>>ch1;
                                                            i=ch1;
                                                           int hex=i*256;
                                                            i=ch2;
                                                           if(i<0)
                                                           {
                                                                   i=i+256;
                                                           }
                                                           hex=hex+i;
                                                           width=hex;

                                                           QString line1 = "Width of the Image : ";
                                                           QString goo   = con.toString(hex);

                                                             this->ui->textBrowser->append(line1);
                                                             this->ui->textBrowser->append(goo);
                                                             this->ui->textBrowser->show();
                                                            data=ch ;
                                                        //break;
                                                }//end if ch1
                                         }//end if ch2
                                    if(ch==01)
                                      {

                                              stream>>ch1;

                                              if(ch1== 01)   //0101-tag
                                              {

                                                      int i;

                                                      t_id=101;
                                                      stream>>ch;
                                                      type=ch;
                                                      stream>>ch;
                                                      stream>>ch;
                                                      data_count=ch;
                                                      stream>>ch;


                                                      for(i=1;i<=3;i++)
                                                      {
                                                            stream>>ch2;	//go to offset
                                                      }


                                                          stream>>ch1;
                                                          i=ch1;

                                                         int hex=i*256;
                                                          i=ch2;
                                                         if(i<0)
                                                         {
                                                                 i=i+256;
                                                         }
                                                         hex=hex+i;
                                                         height=hex;

                                                         QString line1 = "Height of the Image : ";

                                                         QString goo   = con.toString(hex);

                                                           this->ui->textBrowser->append(line1);
                                                           this->ui->textBrowser->append(goo);
                                                           this->ui->textBrowser->show();
                                                          data=ch ;
                                                      //break;
                                              }//end if ch1
                                       }//end if ch2

                                    if(ch==03)
                                      {

                                              stream>>ch1;

                                              if(ch1== 01)   //0103-tag
                                              {


                                                      int i;

                                                      t_id=101;
                                                      stream>>ch;
                                                      type=ch;
                                                      stream>>ch;
                                                      stream>>ch;
                                                      data_count=ch;
                                                      stream>>ch;


                                                      for(i=1;i<=3;i++)
                                                      {
                                                            stream>>ch2;	//go to offset
                                                      }
                                                          stream>>ch1;
                                                          i=ch1;
                                                         int hex=i*256;
                                                          i=ch2;
                                                         if(i<0)
                                                         {
                                                                 i=i+256;
                                                         }
                                                         hex=hex+i;
                                                        QString goo;
                                                        if(hex == 1)
                                                            goo = "No Compression";
                                                                    else if(hex == 5)
                                                            goo = "LZW Compression";

                                                         QString line1 = "Compression of the Image : ";
                                                           this->ui->textBrowser->append(line1);
                                                           this->ui->textBrowser->append(goo);
                                                           this->ui->textBrowser->show();
                                                          data=ch ;
                                                      //break;
                                              }//end if ch1
                                       }//end if ch2

                                    if(ch==17)
                                      {

                                              stream>>ch1;

                                              if(ch1== 01)   //0101-tag
                                              {
                                                  printf("Read");

                                                      int i,offset;

                                                      t_id=ch;
                                                      stream>>ch;
                                                      type=ch;
                                                      stream>>ch;
                                                      stream>>ch;
                                                      data_count=ch;
                                                      stream>>ch;



                                                      offset=type*data_count;


                                                      for(i=1;i<=3;i++)
                                                      {
                                                            stream>>ch2;	//go to offset
                                                      }
                                                          stream>>ch1;
                                                          i=ch1;
                                                         int hex=i*256;
                                                          i=ch2;
                                                         if(i<0)
                                                         {
                                                                 i=i+256;
                                                         }
                                                         hex=hex+i;
                                                         off=hex;

                                                        // QString line1 = "Strips : ";
                                                        //  QString goo   = con.toString(hex);

                                                         //  this->ui->textBrowser->append(line1);
                                                          // this->ui->textBrowser->append(goo);
                                                           //this->ui->textBrowser->show();
                                                          data=ch ;
                                                     // break;
                                              }//end if ch1
                                       }//end if ch2
                                    if(ch==22)
                                      {

                                              stream>>ch1;

                                              if(ch1== 01)   //0101-tag
                                              {
                                                  printf("Read");

                                                      int i,offset;

                                                      t_id=ch;
                                                      stream>>ch;
                                                      type=ch;
                                                      stream>>ch;
                                                      stream>>ch;
                                                      data_count=ch;
                                                      stream>>ch;
                                                      if(data_count==1)
                                                      {
                                                              offset=type;
                                                              printf("DC=1");		//check
                                                      }
                                                      else
                                                      {
                                                              printf("DC=%d",data_count);
                                                              offset=type*data_count;

                                                      }

                                                      for(i=1;i<=3;i++)
                                                      {
                                                            stream>>ch2;	//go to offset
                                                      }
                                                          stream>>ch1;
                                                          i=ch1;
                                                         int hex=i*256;
                                                          i=ch2;
                                                         if(i<0)
                                                         {
                                                                 i=i+256;
                                                         }
                                                         hex=hex+i;

                                                         QString line1 = "Rows per Strip : ";
                                                          QString goo   = con.toString(hex);

                                                           this->ui->textBrowser->append(line1);
                                                           this->ui->textBrowser->append(goo);
                                                           this->ui->textBrowser->show();
                                                          data=ch ;
                                                     // break;
                                              }//end if ch1
                                       }//end if ch2
                                    if(ch==23)
                                      {

                                              stream>>ch1;

                                              if(ch1== 01)   //0101-tag
                                              {
                                                       printf("      \nHELP!!");

                                                      int i,offset;

                                                      t_id=ch;
                                                      stream>>ch;
                                                      type=ch;
                                                      stream>>ch;
                                                      stream>>ch;
                                                      data_count=ch;
                                                      stream>>ch;
                                                      if(data_count==1)
                                                      {
                                                              offset=type;
                                                              printf("DC=1");		//check
                                                      }
                                                      else
                                                      {
                                                              printf("DC=%d",data_count);
                                                              offset=type*data_count;

                                                      }

                                                      for(i=1;i<=3;i++)
                                                      {
                                                            stream>>ch2;	//go to offset
                                                      }
                                                          stream>>ch1;
                                                          i=ch1;
                                                          if(i<0)
                                                              i=i+256;
                                                         int hex=i*256;
                                                          i=ch2;
                                                         if(i<0)
                                                         {
                                                                 i=i+256;
                                                         }
                                                         hex=hex+i;
                                                         stream>>ch1;
                                                         i=ch1;
                                                         if(i<0)
                                                             i=i+256;
                                                         i=i*65536;
                                                         hex=hex+i;
                                                         str=hex;

                                                         QString line1 = "Strip Byte Count : ";
                                                         QString goo   = con.toString(hex);

                                                           this->ui->textBrowser->append(line1);
                                                           this->ui->textBrowser->append(goo);
                                                           this->ui->textBrowser->show();
                                                          data=ch ;

                                                      break;
                                              }//end if ch1

                                    }
                                    //end if ch2

                               }//end while
                        printf("      \nHELP!!");
                        QString line11;

                      //line11="C:\\temp12345.TIF";

 line11 = QFileDialog::getSaveFileName(this,tr("Save File"),"C:",tr("Images(*.tif *.tiff)"));

 QFile file1(line11);
 if (!file1.open(QIODevice::ReadWrite)) {
     QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
     return;
 }


QTextStream stream1 ( &file1 );
QString goo1,goo2;
 stream.seek(0);
 stream1.seek(0);
 int flag1=0,flag2=0,flagx=0,flagy=0;
                         QChar ch10;
 //QChar ch15;
                        // int ch5;
// ch15=height;
char ch15 = height-ycoor;
printf("\n%d",ch15);
 int temp=ch15;
if(ch15<0)
{

    temp=temp+256;
    ch15=temp;
    printf("%d",temp);
    printf("asdfg");
}
printf("\n%d",ch15);

                                while(!stream.atEnd())
                                {

                                        stream>>ch10;
                                         stream1<<ch10 ;
                                         if(ch10==254 && flagy==0)
                                         {
                                          flagx=1;
                                         flagy=1;
                                         printf("flaggeddddddddddddd");
                                                 for(i=1;i<=10;i++)
                                                 {
                                                     stream>>ch10;
                                                      stream1<<ch10 ;
                                                 }

                                         }


                                   if(ch10==01 && flag2==0 && flagx==1)
                                        {

                                       stream>>ch10;
                                        stream1<<ch10 ;
                                       if(ch10== 01)   //0100-tag
                                       {flag2=1;

                                         printf("changeoooooooooo1111111111");

                                               for(i=1;i<=6;i++)
                                               {
                                                     stream>>ch10;
                                                        stream1<<ch10 ;	//go to offset
                                               }
                                               if(temp<255)
                                               {
                                                 stream>>ch10;
                                                stream1<<ch15 ;

                                                for(i=1;i<=3;i++)
                                                {
                                                      stream>>ch10;
                                                         stream1<<ch10 ;	//go to offset
                                                }
                                               }
                                                else
                                               {
                                                   QString goo   = con.toString(ch15);
                                                   goo1=goo.left(1);
                                                   goo2=goo.right(1);
                                                   stream>>ch10;
                                                  stream1<<temp ;
                                                  stream>>ch10;
                                                 stream1<<temp;
                                               }
                                               for(i=1;i<=2;i++)
                                               {
                                                     stream>>ch10;
                                                        stream1<<ch10 ;	//go to offset
                                               }
                                                flagx=0;
                                                        //break;
                                                }//end if ch1
                                         }//end if ch2

                         }

                      file.close();
}




void MainWindow :: valueChangedSlot(int x)
{

    xcoor=x;
    printf("%d\n",xcoor);

}

void MainWindow :: valueChangedSlot_2(int y)
{
    ycoor = y;
    printf("%d\n",ycoor);
    ycoor = ycoor;
}

/*void MainWindow :: save()
{
    line11 = QFileDialog::getSaveFileName(this,tr("Save File"),"C:",tr("Images(*.tif *.tiff)"));
}*/


MainWindow::~MainWindow()
{
    delete ui;
}
