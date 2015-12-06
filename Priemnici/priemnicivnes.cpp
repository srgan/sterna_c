#include "priemnicivnes.h"
#include "ui_priemnicivnes.h"

PriemniciVnes::PriemniciVnes(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::PriemniciVnes)
{
    ui->setupUi(this);
    ui->lineEdit->installEventFilter(this);
    ui->lineEdit_2->installEventFilter(this);
    ui->lineEdit_3->installEventFilter(this);
    ui->lineEdit_4->installEventFilter(this);
    ui->lineEdit_5->installEventFilter(this);
    ui->dateTimeEdit->installEventFilter(this);
    Singleton *s = Singleton::Instance();
    QRect rMain = s->getMainRect();
    ui->gridLayout->setGeometry(rMain);
    setLayout(ui->gridLayout);
    setFixedSize(QSize(rMain.width()-10, rMain.height()-40));
}

PriemniciVnes::~PriemniciVnes()
{
    if (ui){
        delete ui;
    }

}
void PriemniciVnes::pressEscape()
{
    emit signalpressEscape();
}

void PriemniciVnes::pressEnter()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}
void PriemniciVnes::pressReturn()
{
    if(ui->pushButton_4->hasFocus())
    {

    }
    else
    {
        QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
        QCoreApplication::postEvent(this, event);
    }

}



bool PriemniciVnes::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::FocusIn)
    {
        if (object == ui->lineEdit)
        {
            ui->lineEdit->setStyleSheet("background-color: yellow");
        }
        if (object == ui->lineEdit_2)
        {
            ui->lineEdit_2->setStyleSheet("background-color: yellow");
        }
        if (object == ui->lineEdit_3)
        {
            ui->lineEdit_3->setStyleSheet("background-color: yellow");
        }
        if (object == ui->lineEdit_4)
        {
            ui->lineEdit_4->setStyleSheet("background-color: yellow");
        }
        if (object == ui->lineEdit_5)
        {
            ui->lineEdit_5->setStyleSheet("background-color: yellow");
        }
        if (object == ui->dateTimeEdit)
        {
            ui->dateTimeEdit->setStyleSheet("background-color: yellow");
        }

    }
    if (event->type() == QEvent::FocusOut)
    {
        if (object == ui->lineEdit)
        {
            ui->lineEdit->setStyleSheet("background-color: none");
        }
        if (object == ui->lineEdit_2)
        {
            ui->lineEdit_2->setStyleSheet("background-color: none");
        }
        if (object == ui->lineEdit_3)
        {
            ui->lineEdit_3->setStyleSheet("background-color: none");
        }
        if (object == ui->lineEdit_4)
        {
            ui->lineEdit_4->setStyleSheet("background-color: none");
        }
        if (object == ui->lineEdit_5)
        {
            ui->lineEdit_5->setStyleSheet("background-color: none");
        }
        if (object == ui->dateTimeEdit)
        {
            ui->dateTimeEdit->setStyleSheet("background-color: none");
        }
    }

    return false;
}
