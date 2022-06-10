#ifndef MONO_H
#define MONO_H

#include <QDialog>
#include <QImage>
#include <QColor>
#include <QLabel>
#include <QPixmap>

namespace Ui {
class Mono;
}

class Mono : public QDialog
{
    Q_OBJECT

public:
    explicit Mono(QWidget *parent = nullptr);
    ~Mono();


private:
    Ui::Mono *ui;
    QImage original;
    QImage view;
    QString file;

public slots:
void slot(const QPixmap *pix);

private slots:
void set_color(int a,int b,int c);
void set_saturation(qreal s);
void on_pushButton_clicked();
void on_pushButton_2_clicked();
void on_pushButton_3_clicked();
void on_pushButton_4_clicked();
void on_pushButton_5_clicked();
void on_pushButton_6_clicked();
void on_pushButton_7_clicked();
void on_pushButton_8_clicked();
void on_pushButton_9_clicked();

signals:
void signalMono(QImage img);
};



#endif // MONO_H
