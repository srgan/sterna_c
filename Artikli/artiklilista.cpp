#include "artiklilista.h"
#include "ui_artiklilista.h"



ArtikliLista::ArtikliLista(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::ArtikliLista)
{
    ui->setupUi(this);
    hlp = new QHelperC(this);
    m_row = 0;
    Singleton *s = Singleton::Instance();
    QRect rMain = s->getMainRect();
    ui->gridLayout->setGeometry(rMain);
    setLayout(ui->gridLayout);

    connect(hlp, SIGNAL(signalResultArtikli(QStringList &)), this, SLOT(getResultEX(QStringList &)));
    setFixedSize(QSize(rMain.width()-10, rMain.height()-40));
    numOffset = 0;
    QString vOffset = QString::number(numOffset);
    QString vLimit = "50";
    QString vSName = "%";
    QString vSearchBy = "artikal";
    model = new QStandardItemModel(0,0);
    header = new QHeaderView(Qt::Horizontal, this);
    getTableColumnWidths(COL);
    pressReturn();
    on_LE_prebaraj_textChanged("%%");

}

ArtikliLista::~ArtikliLista()
{
    delete ui;
    delete model;
    delete header;
}


void ArtikliLista::pressF2()
{
    emit signalpressF2();
}
void ArtikliLista::pressF3()
{
    emit signalpressF3();
}
void ArtikliLista::pressEscape()
{
    emit signalpressEscape();
}

void ArtikliLista::seTableSelectedRow(int m_row)
{
    ui->tableView->selectRow(m_row);
}
QString ArtikliLista::getSearchString()
{
    return ui->LE_prebaraj->text();
}
void ArtikliLista::setSearchString(QString& searchText)
{
    ui->LE_prebaraj->setText(searchText);
}


void ArtikliLista::getResultEX(QStringList& tlist)
{
    int r = tlist.count();
    int c = COL;
    model->clear();
    model->setRowCount(r);
    model->setColumnCount(c);
    model->setHeaderData( 0, Qt::Horizontal, trUtf8("Id."));
    model->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
    model->setHeaderData( 2, Qt::Horizontal, trUtf8("Артикал"));
    model->setHeaderData( 3, Qt::Horizontal, trUtf8("Едм"));
    model->setHeaderData( 4, Qt::Horizontal, trUtf8("Реф"));
    model->setHeaderData( 5, Qt::Horizontal, trUtf8("Кат.број"));
    model->setHeaderData( 6, Qt::Horizontal, trUtf8("Ддв"));
    model->setHeaderData( 7, Qt::Horizontal, trUtf8("Производител"));
    model->setHeaderData( 8, Qt::Horizontal, trUtf8("Категорија"));

    ui->tableView->setModel(model);

    ui->tableView->setHorizontalHeader(header);
    header->show();
    int row = 0;

    for(int ii = 0; ii < tlist.count();ii++)
    {
        QStringList itemRecord = tlist.at(ii).split("#;#");
        for (int i = 0; i < c; i++)
        {
            QStandardItem *item = new QStandardItem(itemRecord.at(i));
            item->setTextAlignment(Qt::AlignLeft);
            item->setEditable(false);
            ui->tableView->setRowHeight(row, 18);
            ui->tableView->setColumnWidth(i, colWidth[i]);
            item->setEditable(false);
            model->setItem(row, i, item);
        }
        itemRecord.clear();
        row++;
    }
    QItemSelectionModel *sm = ui->tableView->selectionModel();
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(selectionChanged(QModelIndex,QModelIndex)));
    connect(header, SIGNAL(sectionResized(int, int, int)), this, SLOT(procSectionResized(int, int, int)));
    tlist.clear();
    ui->tableView->show();
}


void ArtikliLista::procSectionResized(int a, int b, int c)
{
    colWidth[a] = c;
}



void ArtikliLista::selectionChanged(QModelIndex modelX,QModelIndex modelY)
{
    model->setHeaderData( 0, Qt::Horizontal, trUtf8("Id."));
    model->setHeaderData( 1, Qt::Horizontal, trUtf8("Шифра"));
    model->setHeaderData( 2, Qt::Horizontal, trUtf8("Артикал"));
    model->setHeaderData( 3, Qt::Horizontal, trUtf8("Едм"));
    model->setHeaderData( 4, Qt::Horizontal, trUtf8("Реф"));
    model->setHeaderData( 5, Qt::Horizontal, trUtf8("Кат.број"));
    model->setHeaderData( 6, Qt::Horizontal, trUtf8("Ддв"));
    model->setHeaderData( 7, Qt::Horizontal, trUtf8("Производител"));
    model->setHeaderData( 8, Qt::Horizontal, trUtf8("Категорија"));

    int i = modelX.row();
    m_row = modelX.row();
    ui->le_id->setText(model->item(i, 0)->text());
    ui->le_sifra->setText(model->item(i, 1)->text());
    ui->le_artikal_naziv->setText(model->item(i, 2)->text());
    ui->le_edm->setText(model->item(i, 3)->text());
    ui->le_referenca->setText(model->item(i, 4)->text());
    ui->le_kataloski_broj->setText(model->item(i, 5)->text());
    ui->le_ddv->setText(model->item(i, 6)->text());
    m_selectedID = model->item(i, 1)->text();
    int stop = 0;
}

void ArtikliLista::on_pushButton_5_clicked()
{
    numOffset -= 50;
    QString vLimit = "50";
    QString vOffset = QString::number(numOffset);
    QString vSName = ui->LE_prebaraj->text() + "%";
    QString vSearchBy = "artikal";
    hlp->getallArtikli(vOffset, vLimit, vSName, vSearchBy);
}

void ArtikliLista::on_pushButton_6_clicked()
{
    numOffset += 50;
    QString vLimit = "50";
    QString vOffset = QString::number(numOffset);
    QString vSName = ui->LE_prebaraj->text() + "%";
    QString vSearchBy = "artikal";
    hlp->getallArtikli(vOffset, vLimit, vSName, vSearchBy);
}

void ArtikliLista::on_LE_prebaraj_textChanged(const QString &arg1)
{
    numOffset = 0;
    QString vLimit = "50";
    QString vOffset = QString::number(numOffset);
    QString vSName = ui->LE_prebaraj->text() + "%";
    QString vSearchBy = "artikal";
    hlp->getallArtikli(vOffset, vLimit, vSName, vSearchBy);
}

void ArtikliLista::setTableColumnWidths(int ccolumn)
{
    Singleton *s = Singleton::Instance();
    QStringList tempWidth;
    for (int i = 0; i < ccolumn; i++)
    {
        tempWidth << QString::number(ui->tableView->columnWidth(i), 10);
    }
    s->setArtikliColumnWidth(tempWidth);
}

void ArtikliLista::getTableColumnWidths(int ccolumn)
{
    QLocale loc;
    Singleton *s = Singleton::Instance();
    QStringList sss = s->getArtikliColumnWidth();
    if (sss.count() == ccolumn)
    {
        for (int i1 = 0; i1 < ccolumn; i1++)
        {
            colWidth[i1] = loc.toInt(sss.at(i1));
        }
    }
    else
    {
        for (int i1 = 0; i1 < ccolumn; i1++)
        {
            colWidth[i1] = 100;
        }
    }
}


void ArtikliLista::on_pb_vnesi_nov_clicked()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_F2, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}

void ArtikliLista::on_pb_koregiraj_postoecki_clicked()
{
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_F3, Qt::NoModifier);
    QCoreApplication::postEvent(this, event);
}

void ArtikliLista::pressReturn()
{
    if(ui->tableView->hasFocus())
    {
        emit signalReturnResult( ui->le_artikal_naziv->text());
    }
    else
    {
        QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
        QCoreApplication::postEvent(this, event);
    }
}
