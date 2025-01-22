#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CreateConnections();

    ui->newTaskLineEdit->setPlaceholderText("Write task here");
    ui->newDateText->setText(QDateTime::currentDateTime().toString());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CreateConnections()
{
    connect(ui->addNewTaskButton, SIGNAL(clicked()), this, SLOT(OnAddNewTask()));
}

void MainWindow::OnAddNewTask()
{
    QString taskName = ui->newTaskLineEdit->text();
    QString taskDate = QDate::currentDate().toString();

    CreateNewTask(taskName, taskDate);
}

void MainWindow::CreateNewTask(QString const& taskName, QString const& taskDate)
{

    QFrame *taskFrame = new QFrame();
    taskFrame->setFrameStyle(QFrame::StyledPanel);
    taskFrame->setObjectName("TaskName");

    QHBoxLayout *newTask = new QHBoxLayout(taskFrame);

    QVBoxLayout *taskDetails = new QVBoxLayout();

    QLabel *titleLabel = new QLabel(tr("Task #%1").arg(ui->mainLayout->count()));
    taskDetails->addWidget(titleLabel);

    QLabel *taskLabel = new QLabel(taskName);
    taskDetails->addWidget(taskLabel);
    taskLabel->setObjectName("TaskLabel");

    QLabel *dateLabel = new QLabel(taskDate);
    taskDetails->addWidget(dateLabel);

    newTask->addLayout(taskDetails);

    QSpacerItem *spacer = new QSpacerItem(10, 10, QSizePolicy::Policy::Expanding);
    newTask->insertSpacerItem(1, spacer);

    QPushButton *deleteButton = new QPushButton("Delete");

    newTask->insertWidget(2, deleteButton);
    deleteButton->setObjectName("DeleteButton");

    deleteButton->setProperty("CurrentTask", QVariant(QVariant::fromValue<QFrame*>(taskFrame)));

    ui->mainLayout->insertWidget(ui->mainLayout->count() - 1, taskFrame);

    connect(deleteButton, SIGNAL(clicked()), this, SLOT(OnDeleteTask()));

}

void MainWindow::OnDeleteTask()
{
    QPushButton *senderButton = (QPushButton*)sender();

    QVariant toDelete = senderButton->property("CurrentTask");

    QFrame *taskFrame = qvariant_cast<QFrame*>(toDelete);

    taskFrame->deleteLater();
    delete taskFrame;

}








