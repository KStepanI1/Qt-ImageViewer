#include "cutdialog.h"
#include "ClipScene.h"
#include "ui_cutdialog.h"

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QGraphicsView>

CutDialog::CutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CutDialog)
{
    ui->setupUi(this);

    m_gridLayout = new QGridLayout(this);
    m_graphicsView = new QGraphicsView(this);
    m_gridLayout->addWidget(m_graphicsView), 0, 0;
    m_pushButton = new QPushButton("Сохранить", this);
    m_clippedLabel = new QLabel(this);
    m_gridLayout->addWidget(m_pushButton, 1, 0);
    m_gridLayout->addWidget(m_clippedLabel, 0, 1);
    m_clipScene = new ClipScene(this);
    m_graphicsView->setScene(m_clipScene);

    connect(m_pushButton, &QPushButton::clicked, this, &CutDialog::onSaveClicked);
    connect(m_clipScene, &ClipScene::clippedImage, this, &CutDialog::onClippedImage);

    resize(640, 480);
}

void CutDialog::onSaveClicked()
{
    const QPixmap *pix = m_clippedLabel->pixmap();
    QImage img = pix->toImage();
    emit signalCut(img);
    this->close();
}

void CutDialog::slot(const QPixmap *pix)
{
    m_clipScene->setImage(pix->toImage());
}



void CutDialog::onClippedImage(const QPixmap& pixmap)
{
    m_clippedLabel->setPixmap(pixmap);
}

CutDialog::~CutDialog()
{
    delete ui;
}
