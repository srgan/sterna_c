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
    ,m_ispratnicaModul(0)
    ,m_smetkaModul(0)
    ,m_profakturaModul(0)
    ,m_povratnicaModul(0)
    ,m_narackaModul(0)
{
    ui->setupUi(this);
    m_artikliModul_description = trUtf8("Артикли");
    m_komintentiModul_description = trUtf8("Коминтенти");
    m_priemnicaModul_description = trUtf8("Приемници");
    m_fakturaModul_description = trUtf8("Фактура");
    m_ispratnicaModul_description = trUtf8("Испратница");
    m_smetkaModul_description = trUtf8("Сметка");
    m_profakturaModul_description = trUtf8("Про-Фактура");
    m_povratnicaModul_description = trUtf8("Повратница");
    m_narackaModul_description = trUtf8("Нарачка");


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
    if (qobject_cast<Ispratnici*>(qApp->focusWidget()))
    {
        deleteMyWidget<Ispratnici>((Ispratnici*)qApp->focusWidget());
        m_ispratnicaModul = NULL;
    }
    if (qobject_cast<Smetki*>(qApp->focusWidget()))
    {
        deleteMyWidget<Smetki>((Smetki*)qApp->focusWidget());
        m_smetkaModul = NULL;
    }
    if (qobject_cast<ProFakturi*>(qApp->focusWidget()))
    {
        deleteMyWidget<ProFakturi>((ProFakturi*)qApp->focusWidget());
        m_profakturaModul = NULL;
    }
    if (qobject_cast<Povratnici*>(qApp->focusWidget()))
    {
        deleteMyWidget<ProFakturi>((ProFakturi*)qApp->focusWidget());
        m_povratnicaModul = NULL;
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
    connect(m_artikliModul, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
}

void MainWindow::procCreateModulKomintent(QString, QWidget *p)
{
    m_komintentiModul = showMyWidget<Komintenti, BaseForm, QWidget>(m_komintentiModul, m_komintentiModul_description, (BaseForm*)ui->centralWidget, p);
    connect(m_komintentiModul, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
}
void MainWindow::procCreateModulPriemnica(QString, QWidget *p)
{
    m_priemnicaModul = showMyWidget<Priemnici, BaseForm, QWidget>(m_priemnicaModul, m_priemnicaModul_description, (BaseForm*)ui->centralWidget, p);
    connect(m_priemnicaModul, SIGNAL(signArtikal(QString, QWidget*)), this, SLOT(procCreateModulArtikal(QString, QWidget*)));
    connect(m_priemnicaModul, SIGNAL(signKomintent(QString, QWidget*)), this, SLOT(procCreateModulKomintent(QString, QWidget*)));
    connect(m_priemnicaModul, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
}
void MainWindow::procCreateModulFaktura(QString, QWidget *p)
{
    m_fakturaModul = showMyWidget<Fakturi, BaseForm, QWidget>(m_fakturaModul, m_fakturaModul_description, (BaseForm*)ui->centralWidget, p);
    connect(m_fakturaModul, SIGNAL(signArtikal(QString, QWidget*)), this, SLOT(procCreateModulArtikal(QString, QWidget*)));
    connect(m_fakturaModul, SIGNAL(signKomintent(QString, QWidget*)), this, SLOT(procCreateModulKomintent(QString, QWidget*)));
    connect(m_fakturaModul, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));

}

void MainWindow::procCreateModulIspratnica(QString, QWidget *p)
{
    m_ispratnicaModul = showMyWidget<Ispratnici, BaseForm, QWidget>(m_ispratnicaModul, m_ispratnicaModul_description, (BaseForm*)ui->centralWidget, p);
    connect(m_ispratnicaModul, SIGNAL(signArtikal(QString, QWidget*)), this, SLOT(procCreateModulArtikal(QString, QWidget*)));
    connect(m_ispratnicaModul, SIGNAL(signKomintent(QString, QWidget*)), this, SLOT(procCreateModulKomintent(QString, QWidget*)));
    connect(m_ispratnicaModul, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
}

void MainWindow::procCreateModulSmetka(QString, QWidget *p)
{
    m_smetkaModul = showMyWidget<Smetki, BaseForm, QWidget>(m_smetkaModul, m_smetkaModul_description, (BaseForm*)ui->centralWidget, p);
    connect(m_smetkaModul, SIGNAL(signArtikal(QString, QWidget*)), this, SLOT(procCreateModulArtikal(QString, QWidget*)));
    connect(m_smetkaModul, SIGNAL(signKomintent(QString, QWidget*)), this, SLOT(procCreateModulKomintent(QString, QWidget*)));
    connect(m_smetkaModul, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
}


void MainWindow::procCreateModulProFaktura(QString, QWidget *p)
{
    m_profakturaModul = showMyWidget<ProFakturi, BaseForm, QWidget>(m_profakturaModul, m_profakturaModul_description, (BaseForm*)ui->centralWidget, p);
    connect(m_profakturaModul, SIGNAL(signArtikal(QString, QWidget*)), this, SLOT(procCreateModulArtikal(QString, QWidget*)));
    connect(m_profakturaModul, SIGNAL(signKomintent(QString, QWidget*)), this, SLOT(procCreateModulKomintent(QString, QWidget*)));
    connect(m_profakturaModul, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));

}

void MainWindow::procCreateModulPovratnica(QString, QWidget *p)
{
    m_povratnicaModul = showMyWidget<Povratnici, BaseForm, QWidget>(m_povratnicaModul, m_povratnicaModul_description, (BaseForm*)ui->centralWidget, p);
    connect(m_povratnicaModul, SIGNAL(signArtikal(QString, QWidget*)), this, SLOT(procCreateModulArtikal(QString, QWidget*)));
    connect(m_povratnicaModul, SIGNAL(signKomintent(QString, QWidget*)), this, SLOT(procCreateModulKomintent(QString, QWidget*)));
    connect(m_povratnicaModul, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));

}


void MainWindow::procCreateModulNaracka(QString, QWidget *p)
{
    m_narackaModul = showMyWidget<Naracki, BaseForm, QWidget>(m_narackaModul, m_narackaModul_description, (BaseForm*)ui->centralWidget, p);
    connect(m_narackaModul, SIGNAL(signArtikal(QString, QWidget*)), this, SLOT(procCreateModulArtikal(QString, QWidget*)));
    connect(m_narackaModul, SIGNAL(signKomintent(QString, QWidget*)), this, SLOT(procCreateModulKomintent(QString, QWidget*)));
    connect(m_narackaModul, SIGNAL(eupdateNanigator(QWidget*, QWidget*)), this, SLOT(updateNavigator(QWidget*, QWidget*)));
}

void MainWindow::on_actionIspretnicia_triggered()
{
    QString text = "";
    procCreateModulIspratnica(text, NULL);
}

void MainWindow::on_actionSmetka_triggered()
{
    QString text = "";
    procCreateModulSmetka(text, NULL);
}

void MainWindow::on_actionProFaktura_triggered()
{
    QString text = "";
    procCreateModulProFaktura(text, NULL);
}

void MainWindow::on_actionPovratnica_triggered()
{
    QString text = "";
    procCreateModulPovratnica(text, NULL);
}

void MainWindow::on_actionNaracka_triggered()
{
    QString text = "";
    procCreateModulNaracka(text, NULL);
}
