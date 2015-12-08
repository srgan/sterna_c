#include "priemnicikorekcija.h"
#include "ui_priemnicikorekcija.h"

PriemniciKorekcija::PriemniciKorekcija(BaseForm *parent) :
    BaseForm(parent),
    statusWait(false),
    hlp(0),
    ui(new Ui::PriemniciKorekcija)
{
    ui->setupUi(this);
    hlp = new QHelperC(this);
    Singleton *s = Singleton::Instance();
    QRect rMain = s->getMainRect();
    ui->gridLayout->setGeometry(rMain);
    setLayout(ui->gridLayout);
    setFixedSize(QSize(rMain.width()-10, rMain.height()-40));

    ui->comboBox_2->installEventFilter(this);

    ui->dateTimeEdit->installEventFilter(this);
    ui->dateTimeEdit_2->installEventFilter(this);
    ui->dateTimeEdit_3->installEventFilter(this);
    ui->dateTimeEdit_4->installEventFilter(this);

    ui->lineEdit->installEventFilter(this);
    ui->lineEdit_2->installEventFilter(this);
    ui->lineEdit_3->installEventFilter(this);
    ui->lineEdit_4->installEventFilter(this);
    ui->lineEdit_5->installEventFilter(this);
    ui->lineEdit_6->installEventFilter(this);
    ui->lineEdit_7->installEventFilter(this);
    ui->lineEdit_8->installEventFilter(this);
    ui->lineEdit_9->installEventFilter(this);
    ui->lineEdit_10->installEventFilter(this);
    ui->lineEdit_11->installEventFilter(this);
    ui->lineEdit_12->installEventFilter(this);
    ui->lineEdit_13->installEventFilter(this);
    ui->lineEdit_14->installEventFilter(this);
    ui->lineEdit_15->installEventFilter(this);
    ui->lineEdit_16->installEventFilter(this);
    ui->lineEdit_17->installEventFilter(this);
    ui->lineEdit_18->installEventFilter(this);
    ui->lineEdit_19->installEventFilter(this);
    ui->lineEdit_20->installEventFilter(this);
    ui->lineEdit_21->installEventFilter(this);
    ui->lineEdit_22->installEventFilter(this);
    ui->lineEdit_23->installEventFilter(this);
    ui->lineEdit_24->installEventFilter(this);
    ui->lineEdit_25->installEventFilter(this);
    ui->lineEdit_26->installEventFilter(this);
    ui->lineEdit_27->installEventFilter(this);


    ui->pushButton_3->installEventFilter(this);
    ui->pushButton_4->installEventFilter(this);
    ui->pushButton_5->installEventFilter(this);
    ui->pushButton_6->installEventFilter(this);

    connect(this, SIGNAL(finishKorekcija()),this, SLOT(procFinishKorekcija()));
    connect(hlp, SIGNAL(signalResultPriemnici(QStringList &)), this, SLOT(getResultEX(QStringList &)));
    connect(hlp, SIGNAL(signalResultUpdateArticle(QStringList &)), this, SLOT(getResultEXUpdate22(QStringList &)));
    pressEnter();
}

PriemniciKorekcija::~PriemniciKorekcija()
{
    delete ui;
    delete hlp;
}
void PriemniciKorekcija::pressEscape()
{
    emit signalpressEscape();
}

void PriemniciKorekcija::initProc(QString m_searchID)
{
    statusWait = true;
//    ui->pushButton->setEnabled(false);
    QString vLimit = "1";
    QString vOffset = "0";
    QString vSName = m_searchID;
    QString vSearchBy = "sifra";
    hlp->getallKomintenti(vOffset, vLimit, vSName);
}
void PriemniciKorekcija::getResultEX(QStringList& tlist)
{
    for(int ii = 0; ii < tlist.count();ii++)
    {
        QStringList itemRecord = tlist.at(ii).split("#;#");
        m_id_artikal = itemRecord.at(0);
        ui->lineEdit_2->setText(itemRecord.at(1));
        ui->lineEdit_3->setText(itemRecord.at(2));
        ui->lineEdit_4->setText(itemRecord.at(3));
        ui->lineEdit_5->setText(itemRecord.at(4));
        ui->lineEdit_6->setText(itemRecord.at(5));
    }
//    ui->pushButton->setEnabled(true);
    statusWait = false;
}
//getResultEXUpdate
void PriemniciKorekcija::on_pushButton_released()
{
    statusWait = true;
//    ui->pushButton->setEnabled(false);
    QString blankText = "";
    QString blankDdv = "18";
    QString a1 = ui->lineEdit_2->text();
    QString a2 = ui->lineEdit_3->text();
    QString a3 = ui->lineEdit_4->text();
    QString a4 = ui->lineEdit_5->text();
    QString a5 = ui->lineEdit_6->text();
    hlp->getUpdateArticle(a1,a2,a3,a4,a5,blankDdv, blankText, blankText );
}

void PriemniciKorekcija::getResultEXUpdate22(QStringList& tlist)
{
    statusWait = false;
    QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setWindowTitle(trUtf8("Information"));
    msgBox->setText(trUtf8("Податокот е успешно корегиран"));
    msgBox->setStandardButtons(QMessageBox::Yes);
    msgBox->setDefaultButton(QMessageBox::Yes);
    msgBox->exec();
    delete msgBox;
    setFocus();
//    ui->pushButton->setEnabled(true);
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Escape, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}

void PriemniciKorekcija::pressEnter()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}
void PriemniciKorekcija::pressReturn()
{
    if(ui->pushButton_4->hasFocus())
    {
        on_pushButton_released();
    }
    else if(ui->lineEdit->hasFocus())
    {
        emit signalGetKomintent("", (QWidget*)this);
    }
    else if(ui->lineEdit_2->hasFocus())
    {
        emit signalGetArtikal("", (QWidget*)this);
    }
    else
    {
        QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);

        QCoreApplication::postEvent(this, event);
    }
}

void PriemniciKorekcija::on_pushButton_5_clicked()
{
    emit signalGetArtikal("", this);
}


void PriemniciKorekcija::setFocusArtikal(QString t)
{
    ui->lineEdit_2->setFocus();
    ui->lineEdit_2->selectAll();
    ui->lineEdit_2->setText(t);
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}

void PriemniciKorekcija::setFocusKomintent(QString t)
{
    ui->lineEdit->setFocus();
    ui->lineEdit->selectAll();
    ui->lineEdit->setText(t);
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}

bool PriemniciKorekcija::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::FocusIn)
    {
        if (object == ui->comboBox_2)
        {
            ui->comboBox_2->setStyleSheet("background-color: yellow");
        }
        if (object == ui->dateTimeEdit)
        {
            ui->dateTimeEdit->setStyleSheet("background-color: yellow");
        }
        if (object == ui->dateTimeEdit_2)
        {
            ui->dateTimeEdit_2->setStyleSheet("background-color: yellow");
        }
        if (object == ui->dateTimeEdit_3)
        {
            ui->dateTimeEdit_3->setStyleSheet("background-color: yellow");
        }
        if (object == ui->dateTimeEdit_4)
        {
            ui->dateTimeEdit_4->setStyleSheet("background-color: yellow");
        }



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
        if (object == ui->lineEdit_6)
        {
            ui->lineEdit_6->setStyleSheet("background-color: yellow");
        }
        if (object == ui->lineEdit_7)
        {
            ui->lineEdit_7->setStyleSheet("background-color: yellow");
        }
        if (object == ui->lineEdit_8)
        {
            ui->lineEdit_8->setStyleSheet("background-color: yellow");
        }
        if (object == ui->lineEdit_9)
        {
            ui->lineEdit_9->setStyleSheet("background-color: yellow");
        }
        if (object == ui->lineEdit_10)
        {
            ui->lineEdit_10->setStyleSheet("background-color: yellow");
        }
        if (object == ui->lineEdit_11)
        {
            ui->lineEdit_11->setStyleSheet("background-color: yellow");
        }
        if (object == ui->lineEdit_12)
        {
            ui->lineEdit_12->setStyleSheet("background-color: yellow");
        }
        if (object == ui->lineEdit_13)
        {
            ui->lineEdit_13->setStyleSheet("background-color: yellow");
        }
        if (object == ui->lineEdit_14)
        {
            ui->lineEdit_14->setStyleSheet("background-color: yellow");
        }
        if (object == ui->lineEdit_15)
        {
            ui->lineEdit_15->setStyleSheet("background-color: yellow");
        }
        if (object == ui->lineEdit_16)
        {
            ui->lineEdit_16->setStyleSheet("background-color: yellow");
        }
        if (object == ui->lineEdit_17)
        {
            ui->lineEdit_17->setStyleSheet("background-color: yellow");
        }
        if (object == ui->lineEdit_18)
        {
            ui->lineEdit_18->setStyleSheet("background-color: yellow");
        }
        if (object == ui->lineEdit_19)
        {
            ui->lineEdit_19->setStyleSheet("background-color: yellow");
        }
        if (object == ui->lineEdit_20)
        {
            ui->lineEdit_20->setStyleSheet("background-color: yellow");
        }
        if (object == ui->lineEdit_21)
        {
            ui->lineEdit_21->setStyleSheet("background-color: yellow");
        }
        if (object == ui->lineEdit_22)
        {
            ui->lineEdit_22->setStyleSheet("background-color: yellow");
        }
        if (object == ui->lineEdit_23)
        {
            ui->lineEdit_23->setStyleSheet("background-color: yellow");
        }
        if (object == ui->lineEdit_24)
        {
            ui->lineEdit_24->setStyleSheet("background-color: yellow");
        }
        if (object == ui->lineEdit_25)
        {
            ui->lineEdit_25->setStyleSheet("background-color: yellow");
        }
        if (object == ui->lineEdit_26)
        {
            ui->lineEdit_26->setStyleSheet("background-color: yellow");
        }
        if (object == ui->lineEdit_27)
        {
            ui->lineEdit_27->setStyleSheet("background-color: yellow");
        }
        if (object == ui->pushButton_3)
        {
            ui->pushButton_3->setStyleSheet("background-color: yellow");
        }
        if (object == ui->pushButton_4)
        {
            ui->pushButton_4->setStyleSheet("background-color: yellow");
        }
        if (object == ui->pushButton_5)
        {
            ui->pushButton_5->setStyleSheet("background-color: yellow");
        }
        if (object == ui->pushButton_6)
        {
            ui->pushButton_6->setStyleSheet("background-color: yellow");
        }
        if (object == ui->textEdit)
        {
            ui->textEdit->setStyleSheet("background-color: yellow");
        }

    }
    if (event->type() == QEvent::FocusOut)
    {
        if (object == ui->comboBox_2)
        {
            ui->comboBox_2->setStyleSheet("background-color: none");
        }
        if (object == ui->dateTimeEdit)
        {
            ui->dateTimeEdit->setStyleSheet("background-color: none");
        }
        if (object == ui->dateTimeEdit_2)
        {
            ui->dateTimeEdit_2->setStyleSheet("background-color: none");
        }
        if (object == ui->dateTimeEdit_3)
        {
            ui->dateTimeEdit_3->setStyleSheet("background-color: none");
        }
        if (object == ui->dateTimeEdit_4)
        {
            ui->dateTimeEdit_4->setStyleSheet("background-color: none");
        }



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
        if (object == ui->lineEdit_6)
        {
            ui->lineEdit_6->setStyleSheet("background-color: none");
        }
        if (object == ui->lineEdit_7)
        {
            ui->lineEdit_7->setStyleSheet("background-color: none");
        }
        if (object == ui->lineEdit_8)
        {
            ui->lineEdit_8->setStyleSheet("background-color: none");
        }
        if (object == ui->lineEdit_9)
        {
            ui->lineEdit_9->setStyleSheet("background-color: none");
        }
        if (object == ui->lineEdit_10)
        {
            ui->lineEdit_10->setStyleSheet("background-color: none");
        }
        if (object == ui->lineEdit_11)
        {
            ui->lineEdit_11->setStyleSheet("background-color: none");
        }
        if (object == ui->lineEdit_12)
        {
            ui->lineEdit_12->setStyleSheet("background-color: none");
        }
        if (object == ui->lineEdit_13)
        {
            ui->lineEdit_13->setStyleSheet("background-color: none");
        }
        if (object == ui->lineEdit_14)
        {
            ui->lineEdit_14->setStyleSheet("background-color: none");
        }
        if (object == ui->lineEdit_15)
        {
            ui->lineEdit_15->setStyleSheet("background-color: none");
        }
        if (object == ui->lineEdit_16)
        {
            ui->lineEdit_16->setStyleSheet("background-color: none");
        }
        if (object == ui->lineEdit_17)
        {
            ui->lineEdit_17->setStyleSheet("background-color: none");
        }
        if (object == ui->lineEdit_18)
        {
            ui->lineEdit_18->setStyleSheet("background-color: none");
        }
        if (object == ui->lineEdit_19)
        {
            ui->lineEdit_19->setStyleSheet("background-color: none");
        }
        if (object == ui->lineEdit_20)
        {
            ui->lineEdit_20->setStyleSheet("background-color: none");
        }
        if (object == ui->lineEdit_21)
        {
            ui->lineEdit_21->setStyleSheet("background-color: none");
        }
        if (object == ui->lineEdit_22)
        {
            ui->lineEdit_22->setStyleSheet("background-color: none");
        }
        if (object == ui->lineEdit_23)
        {
            ui->lineEdit_23->setStyleSheet("background-color: none");
        }
        if (object == ui->lineEdit_24)
        {
            ui->lineEdit_24->setStyleSheet("background-color: none");
        }
        if (object == ui->lineEdit_25)
        {
            ui->lineEdit_25->setStyleSheet("background-color: none");
        }
        if (object == ui->lineEdit_26)
        {
            ui->lineEdit_26->setStyleSheet("background-color: none");
        }
        if (object == ui->lineEdit_27)
        {
            ui->lineEdit_27->setStyleSheet("background-color: none");
        }
        if (object == ui->pushButton_3)
        {
            ui->pushButton_3->setStyleSheet("background-color: none");
        }
        if (object == ui->pushButton_4)
        {
            ui->pushButton_4->setStyleSheet("background-color: none");
        }
        if (object == ui->pushButton_5)
        {
            ui->pushButton_5->setStyleSheet("background-color: none");
        }
        if (object == ui->pushButton_6)
        {
            ui->pushButton_6->setStyleSheet("background-color: none");
        }
        if (object == ui->textEdit)
        {
            ui->textEdit->setStyleSheet("background-color: none");
        }

    }

    return false;
}
