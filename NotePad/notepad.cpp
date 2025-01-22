#include "notepad.h"
#include "ui_notepad.h"

Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notepad)
{
    ui->setupUi(this);

    connect(ui->actionNew, &QAction::triggered, this, &Notepad::newDocument);
        connect(ui->actionOpen, &QAction::triggered, this, &Notepad::open);
        connect(ui->actionSave, &QAction::triggered, this, &Notepad::save);
        connect(ui->actionSave_as, &QAction::triggered, this, &Notepad::saveAs);
        connect(ui->actionExit, &QAction::triggered, this, &QWidget::close);

    #if QT_CONFIG(clipboard)
        connect(ui->textEdit, &QTextEdit::copyAvailable, ui->actionCopy, &QAction::setEnabled);
        connect(ui->actionCopy, &QAction::triggered, ui->textEdit, &QTextEdit::copy);
    #endif

        connect(ui->textEdit, &QTextEdit::undoAvailable, ui->actionUndo, &QAction::setEnabled);
        connect(ui->actionUndo, &QAction::triggered, ui->textEdit, &QTextEdit::undo);

        connect(ui->actionFont, &QAction::triggered, this, &Notepad::selectFont);
        connect(ui->actionUnderline, &QAction::triggered, this, &Notepad::setFontUnderline);
        connect(ui->actionAbout, &QAction::triggered, this, &Notepad::about);

    #if !QT_CONFIG(clipboard)
        ui->actionCut->setEnabled(false);
    #endif
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::newDocument()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}

void Notepad::open()
{


}

void Notepad::save()
{

}



















































