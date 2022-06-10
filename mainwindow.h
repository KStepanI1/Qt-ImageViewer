#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mono.h"
#include "cutdialog.h"
#include <QMainWindow>
#include <QLabel>
#include <QDialog>
#include <QStandardItemModel>
#include <color.h>
#include <quantizationmethod.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString path;


private slots:
    void on_action_triggered();

    void on_action_3_triggered();

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_updateColors_clicked();

    void on_action_2_triggered();

    void on_slider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QLabel  *imageLabel;
    Mono *mono_window;
    CutDialog *cut_window;
    QStandardItemModel *m;
    QImage image;
    QuantizationMethod *methods[1];
    QString imagePath;
    QColor color;
    std::vector<QPushButton*> btns;

    int w,h;

    void on_colorChanged1();
    void on_colorChanged2();
    void on_colorChanged3();
    void on_colorChanged4();
    void on_colorChanged5();
    void on_colorChanged6();
    void updatePixelColors(QColor oldColor, QColor newColor);
    void updateColors(QList<Color> colors);
signals:
void signal(const QPixmap *pix);

public slots:
void slotMono(QImage img);
void slotCut(QImage img);

};

#endif // MAINWINDOW_H
