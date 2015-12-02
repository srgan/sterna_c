#include "artiklivnes.h"
#include "ui_artiklivnes.h"

ArtikliVnes::ArtikliVnes(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::ArtikliVnes)
    ,hlp(0)

{
    ui->setupUi(this);
    ui->lineEdit_2->setFocus();
    Singleton *s = Singleton::Instance();
    QRect rMain = s->getMainRect();
    ui->gridLayout->setGeometry(rMain);
    setLayout(ui->gridLayout);
    setFixedSize(QSize(rMain.width()-20, rMain.height()-40));
    hlp = new QHelperC(this);
    connect(hlp, SIGNAL(signalResultInsertArticle(QStringList &)), this, SLOT(getResultEX(QStringList &)));
}

ArtikliVnes::~ArtikliVnes()
{
    delete hlp;
    delete ui;
}
void ArtikliVnes::pressEscape()
{
    emit signalpressEscape();
}



void ArtikliVnes::getResultEX(QStringList& tlist)
{
    QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setWindowTitle(trUtf8("Information"));
    msgBox->setText(trUtf8("Податокот е успешно внесен"));
    msgBox->setStandardButtons(QMessageBox::Yes);
    msgBox->setDefaultButton(QMessageBox::Yes);
    msgBox->exec();
    delete msgBox;
    setFocus();
    ui->pushButton->setEnabled(true);
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Escape, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);

}


void ArtikliVnes::on_pushButton_clicked()
{

    QString blankText = "";
    QString blankDdv = "18";
    QString a1 = ui->lineEdit_2->text();
    QString a2 = ui->lineEdit_3->text();
    QString a3 = ui->lineEdit_4->text();
    QString a4 = ui->lineEdit_5->text();
    QString a5 = ui->lineEdit_6->text();

    hlp->getInsertArticle(a1,a2,a3,a4,a5,blankDdv, blankText, blankText );
}
