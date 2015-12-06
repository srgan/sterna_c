#include "fakturikorekcija.h"
#include "ui_fakturikorekcija.h"

FakturiKorekcija::FakturiKorekcija(BaseForm *parent) :
    BaseForm(parent),
    statusWait(false),
    hlp(0),
    ui(new Ui::FakturiKorekcija)
{
    ui->setupUi(this);
    hlp = new QHelperC(this);
    Singleton *s = Singleton::Instance();
    QRect rMain = s->getMainRect();
    ui->gridLayout->setGeometry(rMain);
    setLayout(ui->gridLayout);
    setFixedSize(QSize(rMain.width()-10, rMain.height()-40));
    connect(this, SIGNAL(finishKorekcija()),this, SLOT(procFinishKorekcija()));
    connect(hlp, SIGNAL(signalResultFakturi(QStringList &)), this, SLOT(getResultEX(QStringList &)));
    connect(hlp, SIGNAL(signalResultUpdateArticle(QStringList &)), this, SLOT(getResultEXUpdate22(QStringList &)));
}

FakturiKorekcija::~FakturiKorekcija()
{
    delete ui;
    delete hlp;
}
void FakturiKorekcija::pressEscape()
{
    emit signalpressEscape();
}

void FakturiKorekcija::initProc(QString m_searchID)
{
    statusWait = true;
    ui->pushButton->setEnabled(false);
    QString vLimit = "1";
    QString vOffset = "0";
    QString vSName = m_searchID;
    QString vSearchBy = "sifra";
    hlp->getallArtikli(vOffset, vLimit, vSName, vSearchBy);
}
void FakturiKorekcija::getResultEX(QStringList& tlist)
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
    ui->pushButton->setEnabled(true);
    statusWait = false;
}
//getResultEXUpdate
void FakturiKorekcija::on_pushButton_released()
{
    statusWait = true;
    ui->pushButton->setEnabled(false);
    QString blankText = "";
    QString blankDdv = "18";
    QString a1 = ui->lineEdit_2->text();
    QString a2 = ui->lineEdit_3->text();
    QString a3 = ui->lineEdit_4->text();
    QString a4 = ui->lineEdit_5->text();
    QString a5 = ui->lineEdit_6->text();
    hlp->getUpdateArticle(a1,a2,a3,a4,a5,blankDdv, blankText, blankText );
}

void FakturiKorekcija::getResultEXUpdate22(QStringList& tlist)
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
    ui->pushButton->setEnabled(true);
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Escape, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}