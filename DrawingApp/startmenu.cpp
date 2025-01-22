#include "startmenu.h"
#include "ui_startmenu.h"

StartMenu::StartMenu(QWidget *parent) : QWidget(parent)
  , ui(new Ui::StartMenu), drawing{new MainWindow(this)}, timer {new QTimer(this)}, i {-1}
{
    ui->setupUi(this);

    if (!timer->isActive())
        timer->start();

    timer->setInterval(2000);
    ui->imageLabel->resize(276, 379);
    ui->imageLabel->setAlignment(Qt::AlignCenter);

    connect(timer, &QTimer::timeout, this, &StartMenu::SetImage);
    connect(ui->exitButton, &QPushButton::clicked, this, &StartMenu::close);
    connect(ui->newButton, &QPushButton::clicked, this, &StartMenu::OpenNewDrawingWindow);

    GetImages();
    SetImage();
}

StartMenu::~StartMenu()
{
    delete ui;
    delete timer;
    delete drawing;
}

void StartMenu::GetImages()
{
    dir_name = QDir::currentPath() + "/Images/";
    QDir dir(dir_name);
    if (!dir.exists())
        dir.mkdir(dir_name);

    QStringList filters;
    filters << "*.jpg" << "*.jpeg"
            << "*.gif" << "*.png";
    files = dir.entryList(filters);
}

void StartMenu::SetImage()
{
    QPixmap pic(dir_name + files[++i % files.count()]);
    ui->imageLabel->setPixmap(pic.scaled(ui->imageLabel->contentsRect().size(), Qt::KeepAspectRatio));
}

void StartMenu::OpenNewDrawingWindow()
{
    if (!drawing->isVisible())
        drawing->show();

    if(drawing->isVisible())
        this->hide();
}













