#include "fakturi.h"
#include "ui_fakturi.h"

Fakturi::Fakturi(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::Fakturi)
    ,m_FakturiLista(0)
    ,m_FakturiVnes(0)
    ,m_FakturiKorekcija(0)

{
    ui->setupUi(this);
    pressF4();
}

Fakturi::~Fakturi()
{
    if (ui){
        delete ui;
    }
}

void Fakturi::pressF2()
{
    if (!m_FakturiLista) {
        return;
    }
    disconnect(m_FakturiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_FakturiLista = deleteMyWidget<FakturiLista>(m_FakturiLista);
    m_FakturiVnes = showMyWidget<FakturiVnes, Fakturi>(m_FakturiVnes, this);
    m_FakturiVnes->setCategoryWidget(this);
    connect(m_FakturiVnes,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromVnes()));
    connect(m_FakturiVnes,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));
    connect(m_FakturiVnes,SIGNAL(signalGetKomintent(QString, QWidget*)),this,SLOT(procSentGetKomintent(QString, QWidget*)));
}

void Fakturi::pressF3()
{
    if (m_FakturiLista){
        m_strID = m_FakturiLista->getSelectedID();
    }else{
        return;
    }
    disconnect(m_FakturiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_FakturiLista = deleteMyWidget<FakturiLista>(m_FakturiLista);
    m_FakturiKorekcija = showMyWidget<FakturiKorekcija, Fakturi>(m_FakturiKorekcija, this);
    m_FakturiKorekcija->setCategoryWidget(this);
    connect(m_FakturiKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    connect(m_FakturiKorekcija,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));
    connect(m_FakturiKorekcija,SIGNAL(signalGetKomintent(QString, QWidget*)),this,SLOT(procSentGetKomintent(QString, QWidget*)));
    m_FakturiKorekcija->initProc(m_strID);
}

void Fakturi::pressF4()
{
    m_FakturiLista = showMyWidget<FakturiLista, Fakturi>(m_FakturiLista, this);
    m_FakturiLista->setCategoryWidget(this);
    connect(m_FakturiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    connect(m_FakturiLista,SIGNAL(signalpressF2()),this,SLOT(pressF2FromLista()));
    connect(m_FakturiLista,SIGNAL(signalpressF3()),this,SLOT(pressF3FromLista()));
}

void Fakturi::pressEscape()
{

}
void Fakturi::closeAllForm()
{
}

void Fakturi::pressF2FromLista()
{
    pressF2();
}
void Fakturi::pressF3FromLista()
{
    pressF3();
}

void Fakturi::pressEscapeFromLista()
{
    disconnect(m_FakturiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_FakturiLista = deleteMyWidget<FakturiLista>(m_FakturiLista);
    setFocus();
    emit signCloseMyWidget();
}
void Fakturi::pressEscapeFromVnes()
{
    m_FakturiVnes = deleteMyWidget<FakturiVnes>(m_FakturiVnes);
    pressF4();
}
void Fakturi::pressEscapeFromKorekcija()
{
    disconnect(m_FakturiKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    m_FakturiKorekcija = deleteMyWidget<FakturiKorekcija>(m_FakturiKorekcija);
    pressF4();
}

void Fakturi::procSentGetArtikal(QString text, QWidget* p)
{
    emit signArtikal(text, p);
}

void Fakturi::procSentGetKomintent(QString text, QWidget* p)
{
    emit signKomintent(text, p);
}



