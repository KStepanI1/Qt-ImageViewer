#include "mono.h"
#include "ui_mono.h"
#include "mainwindow.h"

Mono::Mono(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mono)
{
    ui->setupUi(this);
    this->setWindowTitle("Монохромное изображение");

}


Mono::~Mono()
{
    delete ui;
}

void Mono::slot(const QPixmap *pix)
{
    original = pix->toImage();
    view = QImage(original);
    ui->label->setPixmap(QPixmap::fromImage(view));
    ui->label->setScaledContents(true);

}

void Mono::set_color(int a, int b, int c)
{
    view = QImage(original);
    for(int x = 0; x < view.width(); x++){
        for(int y = 0; y < view.height(); y++){
            QColor color = view.pixelColor(x,y);
            qreal red = color.redF();
            qreal blue = color.blueF();
            qreal green = color.greenF();
            qreal gray = a*red+b*blue+c*green;
            if (a*b*c == 1) gray = (red+blue+green)/3;
            color.setRedF(a*gray);
            color.setBlueF(b*gray);
            color.setGreenF(c*gray);
            view.setPixelColor(x,y,color);
        }
    }
    ui->label->setPixmap(QPixmap::fromImage(view));
    ui->label->setScaledContents(true);
}

void Mono::set_saturation(qreal s)
{
    const QPixmap *pix = ui->label->pixmap();
    QImage img = pix->toImage();
    for(int x = 0; x < img.width(); x++){
        for(int y = 0; y < img.height(); y++){
            QColor color = img.pixelColor(x,y);
            qreal ns = color.hslSaturationF() + s;
            if(ns > 1) ns = 1;
            else if(ns < 0) ns = 0;
            color.setHslF(color.hslHueF(),ns,color.lightnessF());
            img.setPixelColor(x,y,color);
        }
    }

        ui->label->setPixmap(QPixmap::fromImage(img));
        ui->label->setScaledContents(true);
}

void Mono::on_pushButton_clicked()
{
    set_saturation(-0.1);
}


void Mono::on_pushButton_2_clicked()
{

   set_saturation(0.1);
}


void Mono::on_pushButton_3_clicked()

{
    set_color(1,1,1);
}


void Mono::on_pushButton_4_clicked()
{
  set_color(1,0,0);
}


void Mono::on_pushButton_5_clicked()
{
    set_color(0,1,0);
}


void Mono::on_pushButton_6_clicked()
{
    set_color(0,0,1);
}


void Mono::on_pushButton_7_clicked()
{

    ui->label->setPixmap(QPixmap::fromImage(original));
    ui->label->setScaledContents(true);
}



void Mono::on_pushButton_8_clicked()
{
  const QPixmap *pix = ui->label->pixmap();
  QImage img = pix->toImage();
  emit signalMono(img);
  this->close();
}


void Mono::on_pushButton_9_clicked()
{
       set_color(1, 0, 1);
       set_saturation(-0.5);
}

