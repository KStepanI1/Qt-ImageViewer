#include "mainwindow.h"
#include "cutdialog.h"
#include "ui_mainwindow.h"
#include "mono.h"
#include <QPixmap>
#include <QFileDialog>
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include <QColorDialog>
#include <iostream>

#include <quantizationmethod.h>
#include <kmeansmethod.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    methods[0] = new KMeansMethod();
    methods[ui->methodComboBox->currentIndex()]->setColorNum(6);

    ui->btnColor_1->setParent(this);
    btns.push_back(ui->btnColor_1);
    color = ui->btnColor_1->palette().color(QPalette::Window);
    connect(ui->btnColor_1,&QPushButton::clicked,this,&MainWindow::on_colorChanged1);

    ui->btnColor_2->setParent(this);
    btns.push_back(ui->btnColor_2);
    color = ui->btnColor_2->palette().color(QPalette::Window);
    connect(ui->btnColor_2,&QPushButton::clicked,this,&MainWindow::on_colorChanged2);

    ui->btnColor_3->setParent(this);
    btns.push_back(ui->btnColor_3);
    color = ui->btnColor_3->palette().color(QPalette::Window);
    connect(ui->btnColor_3,&QPushButton::clicked,this,&MainWindow::on_colorChanged3);

    ui->btnColor_4->setParent(this);
    btns.push_back(ui->btnColor_4);
    color = ui->btnColor_4->palette().color(QPalette::Window);
    connect(ui->btnColor_4,&QPushButton::clicked,this,&MainWindow::on_colorChanged4);

    ui->btnColor_5->setParent(this);
    btns.push_back(ui->btnColor_5);
    color = ui->btnColor_5->palette().color(QPalette::Window);
    connect(ui->btnColor_5,&QPushButton::clicked,this,&MainWindow::on_colorChanged5);

    ui->btnColor_6->setParent(this);
    btns.push_back(ui->btnColor_6);
    color = ui->btnColor_6->palette().color(QPalette::Window);
    connect(ui->btnColor_6,&QPushButton::clicked,this,&MainWindow::on_colorChanged6);


    ui -> valuelabel -> setText(QString::number(ui->slider->value()));
    w = ui->imageDisplayLabel->width();
    h = ui->imageDisplayLabel->height();
}


void MainWindow::on_colorChanged1()
{
    QPalette palette = ui->btnColor_1->palette();
    QColor oldColor = ui->btnColor_1->palette().color(QPalette::Window);
    QColor newColor;
    newColor = QColorDialog::getColor(color,this,"Изменение цвета");
    if(newColor.isValid())
    {
        int r = newColor.red();
        int g = newColor.green();
        int b = newColor.blue();
        color = QColor(r,g,b);
        ui->btnColor_1->setStyleSheet(QString("background-color:rgb(%1,%2,%3)").
                                    arg(r).arg(g).arg(b));
        updatePixelColors(oldColor, newColor);
    }
}

void MainWindow::on_colorChanged2()
{
    QPalette palette = ui->btnColor_2->palette();
    QColor oldColor = ui->btnColor_2->palette().color(QPalette::Window);
    QColor newColor;
    newColor = QColorDialog::getColor(color,this,"Изменение цвета");
    if(newColor.isValid())
    {
        int r = newColor.red();
        int g = newColor.green();
        int b = newColor.blue();
        color = QColor(r,g,b);
        ui->btnColor_2->setStyleSheet(QString("background-color:rgb(%1,%2,%3)").
                                    arg(r).arg(g).arg(b));
        updatePixelColors(oldColor, newColor);
    }
}

void MainWindow::on_colorChanged3()
{
    QPalette palette = ui->btnColor_3->palette();
    QColor oldColor = ui->btnColor_3->palette().color(QPalette::Window);
    QColor newColor;
    newColor = QColorDialog::getColor(color,this,"Изменение цвета");
    if(newColor.isValid())
    {
        int r = newColor.red();
        int g = newColor.green();
        int b = newColor.blue();
        color = QColor(r,g,b);
        ui->btnColor_3->setStyleSheet(QString("background-color:rgb(%1,%2,%3)").
                                    arg(r).arg(g).arg(b));
        updatePixelColors(oldColor, newColor);
    }
}

void MainWindow::on_colorChanged4()
{
    QPalette palette = ui->btnColor_4->palette();
    QColor oldColor = ui->btnColor_4->palette().color(QPalette::Window);
    QColor newColor;
    newColor = QColorDialog::getColor(color,this,"Изменение цвета");
    if(newColor.isValid())
    {
        int r = newColor.red();
        int g = newColor.green();
        int b = newColor.blue();
        color = QColor(r,g,b);
        ui->btnColor_4->setStyleSheet(QString("background-color:rgb(%1,%2,%3)").
                                    arg(r).arg(g).arg(b));
        updatePixelColors(oldColor, newColor);
    }
}

void MainWindow::on_colorChanged5()
{
    QPalette palette = ui->btnColor_5->palette();
    QColor oldColor = ui->btnColor_5->palette().color(QPalette::Window);
    QColor newColor;
    newColor = QColorDialog::getColor(color,this,"Изменение цвета");
    if(newColor.isValid())
    {
        int r = newColor.red();
        int g = newColor.green();
        int b = newColor.blue();
        color = QColor(r,g,b);
        ui->btnColor_5->setStyleSheet(QString("background-color:rgb(%1,%2,%3)").
                                    arg(r).arg(g).arg(b));
        updatePixelColors(oldColor, newColor);
    }
}

void MainWindow::on_colorChanged6()
{
    QPalette palette = ui->btnColor_6->palette();
    QColor oldColor = palette.color(QPalette::Window);
    QColor newColor;
    newColor = QColorDialog::getColor(color,this,"Изменение цвета");
    if(newColor.isValid())
    {
        int r = newColor.red();
        int g = newColor.green();
        int b = newColor.blue();
        color = QColor(r,g,b);
        ui->btnColor_6->setStyleSheet(QString("background-color:rgb(%1,%2,%3)").
                                    arg(r).arg(g).arg(b));
        updatePixelColors(oldColor, newColor);
    }
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_slider_valueChanged(int value)
{
    ui -> valuelabel -> setText(QString::number(ui->slider->value()));
    double factor = ui->slider->value()/100.0;
    ui->imageDisplayLabel->setFixedSize(w*factor,h*factor);
}

void MainWindow::updateColors(QList<Color> colors)
{

    int i = 0;
    for (const Color &color : colors) {
       int r = color.getColor().red();
       int g = color.getColor().green();
       int b = color.getColor().blue();
       btns[i]->setStyleSheet(QString("background-color:rgb(%1,%2,%3)").
                                           arg(r).arg(g).arg(b));
       i++;
    }
}

void MainWindow::on_action_triggered()
{
    path = QFileDialog::getOpenFileName(this, tr("Image Files (*.png *.jpg *.bmp)"));
    if (!image.load(path))
    {
        return;
    }
    ui->pathLineEdit->setText(path);
    ui->imageDisplayLabel->setScaledContents( true );
    ui->imageDisplayLabel->setPixmap(QPixmap(path).scaled(600, 800, Qt::KeepAspectRatio));

    methods[ui->methodComboBox->currentIndex()]->setImage(ui->imageDisplayLabel->pixmap(Qt::ReturnByValue).toImage().scaled(100, 100, Qt::KeepAspectRatioByExpanding));
    methods[ui->methodComboBox->currentIndex()]->generateColors();
    updateColors(methods[ui->methodComboBox->currentIndex()]->getColors());
}

void MainWindow::on_action_3_triggered()
{
    this->close();
}

void MainWindow::on_updateColors_clicked()
{
    if (!image.load(path))
    {
        return;
    }
    ui->imageDisplayLabel->setPixmap(QPixmap(path).scaled(600, 800, Qt::KeepAspectRatio));
    methods[ui->methodComboBox->currentIndex()]->setImage(ui->imageDisplayLabel->pixmap(Qt::ReturnByValue).toImage().scaled(100, 100, Qt::KeepAspectRatioByExpanding));
    methods[ui->methodComboBox->currentIndex()]->generateColors();
    updateColors(methods[ui->methodComboBox->currentIndex()]->getColors());
}

void MainWindow::on_pushButton_clicked()
{
    mono_window = new Mono(this);
    mono_window->show();
    connect(this, &MainWindow::signal, mono_window, &Mono::slot);
    emit signal(ui->imageDisplayLabel->pixmap());
    connect(mono_window, &Mono::signalMono, this, &MainWindow::slotMono);
}

void MainWindow::on_pushButton_2_clicked()
{
    cut_window = new CutDialog(this);
    cut_window->show();
    connect(this, &MainWindow::signal, cut_window, &CutDialog::slot);
    emit signal(ui->imageDisplayLabel->pixmap());
    connect(cut_window, &CutDialog::signalCut, this, &MainWindow::slotCut);
}

void MainWindow::slotMono(QImage img)
{
  QPixmap pix = QPixmap::fromImage(img);
  ui->imageDisplayLabel->setPixmap(QPixmap(pix).scaled(600, 800, Qt::KeepAspectRatio));
  methods[ui->methodComboBox->currentIndex()]->setImage(ui->imageDisplayLabel->pixmap(Qt::ReturnByValue).toImage().scaled(100, 100, Qt::KeepAspectRatioByExpanding));
  methods[ui->methodComboBox->currentIndex()]->generateColors();
  updateColors(methods[ui->methodComboBox->currentIndex()]->getColors());
}

void MainWindow::slotCut(QImage img)
{
  QPixmap pix = QPixmap::fromImage(img);
  ui->imageDisplayLabel->setPixmap(QPixmap(pix).scaled(600, 800, Qt::KeepAspectRatio));
  methods[ui->methodComboBox->currentIndex()]->setImage(ui->imageDisplayLabel->pixmap(Qt::ReturnByValue).toImage().scaled(100, 100, Qt::KeepAspectRatioByExpanding));
  methods[ui->methodComboBox->currentIndex()]->generateColors();
  updateColors(methods[ui->methodComboBox->currentIndex()]->getColors());
}

void MainWindow::on_action_2_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                       "Выбрать изображение", "",
                        "Изображения (*.jpeg  *.jpg *.png)");
    ui->imageDisplayLabel->pixmap(Qt::ReturnByValue).save(fileName);
}

void MainWindow::updatePixelColors(QColor oldColor, QColor newColor)
{
    QImage img = ui->imageDisplayLabel->pixmap()->toImage();
    for(int x = 0; x < img.width(); x++){
        for(int y = 0; y < img.height(); y++){
            QColor color = img.pixelColor(x,y);
            if (abs(color.green() - oldColor.green()) < 10 && abs(color.red() - oldColor.red()) < 10 && abs(color.blue() - oldColor.blue()) < 10) {
               img.setPixelColor(x,y,newColor);
            }
        }
    }
    ui->imageDisplayLabel->setPixmap(QPixmap::fromImage(img));
}

