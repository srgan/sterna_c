#include "ispratnici.h"
#include "ui_ispratnici.h"

Ispratnici::Ispratnici(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::Ispratnici)
    ,m_IspratniciLista(0)
    ,m_IspratniciVnes(0)
    ,m_IspratniciKorekcija(0)

{
    ui->setupUi(this);
    pressF4();
}

Ispratnici::~Ispratnici()
{
    if (ui){
        delete ui;
    }
}

void Ispratnici::pressF2()
{
    if (!m_IspratniciLista) {
        return;
    }
    disconnect(m_IspratniciLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_IspratniciLista = deleteMyWidget<IspratniciLista>(m_IspratniciLista);
    m_IspratniciVnes = showMyWidget<IspratniciVnes, Ispratnici>(m_IspratniciVnes, this);
    m_IspratniciVnes->setCategoryWidget(this);
    connect(m_IspratniciVnes,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromVnes()));
    connect(m_IspratniciVnes,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));
    connect(m_IspratniciVnes,SIGNAL(signalGetKomintent(QString, QWidget*)),this,SLOT(procSentGetKomintent(QString, QWidget*)));
}

void Ispratnici::pressF3()
{
    if (m_IspratniciLista){
        m_strID = m_IspratniciLista->getSelectedID();
    }else{
        return;
    }
    disconnect(m_IspratniciLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_IspratniciLista = deleteMyWidget<IspratniciLista>(m_IspratniciLista);
    m_IspratniciKorekcija = showMyWidget<IspratniciKorekcija, Ispratnici>(m_IspratniciKorekcija, this);
    m_IspratniciKorekcija->setCategoryWidget(this);
    connect(m_IspratniciKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    connect(m_IspratniciKorekcija,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));
    connect(m_IspratniciKorekcija,SIGNAL(signalGetKomintent(QString, QWidget*)),this,SLOT(procSentGetKomintent(QString, QWidget*)));

    m_IspratniciKorekcija->initProc(m_strID);
}

void Ispratnici::pressF4()
{
    m_IspratniciLista = showMyWidget<IspratniciLista, Ispratnici>(m_IspratniciLista, this);
    m_IspratniciLista->setCategoryWidget(this);
    connect(m_IspratniciLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    connect(m_IspratniciLista,SIGNAL(signalpressF2()),this,SLOT(pressF2FromLista()));
    connect(m_IspratniciLista,SIGNAL(signalpressF3()),this,SLOT(pressF3FromLista()));

}

void Ispratnici::pressEscape()
{

}
void Ispratnici::closeAllForm()
{
}

void Ispratnici::pressF2FromLista()
{
    pressF2();
}
void Ispratnici::pressF3FromLista()
{
    pressF3();
}

void Ispratnici::pressEscapeFromLista()
{
    disconnect(m_IspratniciLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_IspratniciLista = deleteMyWidget<IspratniciLista>(m_IspratniciLista);
    setFocus();
    emit signCloseMyWidget();
}
void Ispratnici::pressEscapeFromVnes()
{
    m_IspratniciVnes = deleteMyWidget<IspratniciVnes>(m_IspratniciVnes);
    pressF4();
}
void Ispratnici::pressEscapeFromKorekcija()
{
    disconnect(m_IspratniciKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    m_IspratniciKorekcija = deleteMyWidget<IspratniciKorekcija>(m_IspratniciKorekcija);
    pressF4();
}

void Ispratnici::procSentGetArtikal(QString text, QWidget* p)
{
    emit signArtikal(text, p);
}

void Ispratnici::procSentGetKomintent(QString text, QWidget* p)
{
    emit signKomintent(text, p);
}


