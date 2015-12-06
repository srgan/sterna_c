#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "xx.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    ,m_artikliModul(0)
    ,m_komintentiModul(0)
    ,m_priemnicaModul(0)
    ,m_fakturaModul(0)
{
    ui->setupUi(this);
    m_artikliModul_description = trUtf8("Артикли");
    m_komintentiModul_description = trUtf8("Коминтенти");
    m_priemnicaModul_description = trUtf8("Приемници");
    m_fakturaModul_description = trUtf8("Фактура");
    dock = new QDockWidget(this);
    m_left = new Left(dock);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createDockWindows()
{
    dock->setWindowTitle(tr("Navigate"));
    dock->setFixedWidth(210);
    dock->setFixedHeight(500);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dock->setWidget(m_left);
    addDockWidget(Qt::LeftDockWidgetArea, dock);
    ui->centralWidget->showMaximized();
    QDesktopWidget *desk = new QDesktopWidget();
    QRect screenRect = desk->screenGeometry();
    delete desk;
    int  mLeftW = m_left->width();
    rMain = QRect(0, 0, screenRect.width() - mLeftW, screenRect.height() - 100);
    Singleton *s = Singleton::Instance();
    s->setMainRect(rMain);

}

void MainWindow::on_actionClose_triggered()
{
    if (m_left)
    {
        m_left->setFocus();
        m_left->getSelection();
    }
    closeMyWidget();
}


void MainWindow::updateNavigator(QWidget* a, QWidget* b)
{
    b->setFocus();
    on_actionClose_triggered();
    a->setFocus();
    m_left->updateSelection(a);
}

void MainWindow::closeMyWidget()
{
    if (qobject_cast<Artikli*>(qApp->focusWidget()))
    {
        deleteMyWidget<Artikli>((Artikli*)qApp->focusWidget());
        m_artikliModul = NULL;
    }
    if (qobject_cast<Komintenti*>(qApp->focusWidget()))
    {
        deleteMyWidget<Komintenti>((Komintenti*)qApp->focusWidget());
        m_komintentiModul = NULL;
    }
    if (qobject_cast<Priemnici*>(qApp->focusWidget()))
    {
        deleteMyWidget<Priemnici>((Priemnici*)qApp->focusWidget());
        m_priemnicaModul = NULL;
    }
    if (qobject_cast<Fakturi*>(qApp->focusWidget()))
    {
        deleteMyWidget<Fakturi>((Fakturi*)qApp->focusWidget());
        m_fakturaModul = NULL;
    }
}
//---------------------------------------------------------------------------------------------------

void MainWindow::on_actionArtikal_triggered()
{
    QString text = "";
    procCreateModulArtikal(text, NULL);
}

//---------------------------------------------------------------------------------------------------

void MainWindow::on_actionKomintent_triggered()
{
    QString text = "";
    procCreateModulKomintent(text, NULL);
}

//---------------------------------------------------------------------------------------------------

void MainWindow::on_actionPriemnica_triggered()
{
    QString text = "";
    procCreateModulPriemnica(text, NULL);
}

//---------------------------------------------------------------------------------------------------

void MainWindow::on_actionFaktura_triggered()
{
    QString text = "";
    procCreateModulFaktura(text, NULL);
}

//---------------------------------------------------------------------------------------------------

void MainWindow::procCreateModulArtikal(QString, QWidget *p)
{
    m_artikliModul = showMyWidget<Artikli, BaseForm, QWidget>(m_artikliModul, m_artikliModul_description, (BaseForm*)ui->centralWidget, p);
}

void MainWindow::procCreateModulKomintent(QString, QWidget *p)
{
    m_komintentiModul = showMyWidget<Komintenti, BaseForm, QWidget>(m_komintentiModul, m_komintentiModul_description, (BaseForm*)ui->centralWidget, p);
}
void MainWindow::procCreateModulPriemnica(QString, QWidget *p)
{
    m_priemnicaModul = showMyWidget<Priemnici, BaseForm, QWidget>(m_priemnicaModul, m_priemnicaModul_description, (BaseForm*)ui->centralWidget, p);
    connect(m_priemnicaModul, SIGNAL(signArtikal(QString, QWidget*)), this, SLOT(procCreateModulArtikal(QString, QWidget*)));
    connect(m_priemnicaModul, SIGNAL(signKomintent(QString, QWidget*)), this, SLOT(procCreateModulKomintent(QString, QWidget*)));
}
void MainWindow::procCreateModulFaktura(QString, QWidget *p)
{
    m_fakturaModul = showMyWidget<Fakturi, BaseForm, QWidget>(m_fakturaModul, m_fakturaModul_description, (BaseForm*)ui->centralWidget, NULL);
    connect(m_priemnicaModul, SIGNAL(signArtikal(QString, QWidget*)), this, SLOT(procCreateModulArtikal(QString, QWidget*)));
    connect(m_priemnicaModul, SIGNAL(signKomintent(QString, QWidget*)), this, SLOT(procCreateModulKomintent(QString, QWidget*)));
}

