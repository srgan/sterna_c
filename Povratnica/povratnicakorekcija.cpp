#include "povratnicakorekcija.h"
#include "ui_povratnicakorekcija.h"

PovratniciKorekcija::PovratniciKorekcija(BaseForm *parent) :
    BaseForm(parent),
    statusWait(false),
    hlp(0),
    ui(new Ui::PovratniciKorekcija)
{
    ui->setupUi(this);
    hlp = new QHelperC(this);
    Singleton *s = Singleton::Instance();
    QRect rMain = s->getMainRect();
    ui->gridLayout->setGeometry(rMain);
    setLayout(ui->gridLayout);
    setFixedSize(QSize(rMain.width()-10, rMain.height()-40));
    connect(this, SIGNAL(finishKorekcija()),this, SLOT(procFinishKorekcija()));
    connect(hlp, SIGNAL(signalResultPovratnici(QStringList &)), this, SLOT(getResultEX(QStringList &)));
    connect(hlp, SIGNAL(signalResultUpdateArticle(QStringList &)), this, SLOT(getResultEXUpdate22(QStringList &)));
}

PovratniciKorekcija::~PovratniciKorekcija()
{
    delete ui;
    delete hlp;
}
void PovratniciKorekcija::pressEscape()
{
    emit signalpressEscape();
}

void PovratniciKorekcija::initProc(QString m_searchID)
{
    statusWait = true;
//    ui->pushButton->setEnabled(false);
    QString vLimit = "1";
    QString vOffset = "0";
    QString vSName = m_searchID;
    QString vSearchBy = "sifra";
    hlp->getallArtikli(vOffset, vLimit, vSName, vSearchBy);
}
void PovratniciKorekcija::getResultEX(QStringList& tlist)
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
void PovratniciKorekcija::on_pushButton_released()
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

void PovratniciKorekcija::getResultEXUpdate22(QStringList& tlist)
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

void PovratniciKorekcija::setFocusArtikal(QString t)
{
    ui->lineEdit_2->setFocus();
    ui->lineEdit_2->selectAll();
    ui->lineEdit_2->setText(t);
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}

void PovratniciKorekcija::setFocusKomintent(QString t)
{
    ui->lineEdit->setFocus();
    ui->lineEdit->selectAll();
    ui->lineEdit->setText(t);
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}

void PovratniciKorekcija::pressReturn()
{
    if(ui->pushButton_4->hasFocus())
    {
        //on_pushButton_released();
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
