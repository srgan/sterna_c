#include "profakturi.h"
#include "ui_profakturi.h"

ProFakturi::ProFakturi(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::ProFakturi)
    ,m_ProFakturiLista(0)
    ,m_ProFakturiVnes(0)
    ,m_ProFakturiKorekcija(0)

{
    ui->setupUi(this);
    pressF4();
}

ProFakturi::~ProFakturi()
{
    if (ui){
        delete ui;
    }
}

void ProFakturi::pressF2()
{
    if (!m_ProFakturiLista) {
        return;
    }
    disconnect(m_ProFakturiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_ProFakturiLista = deleteMyWidget<ProFakturiLista>(m_ProFakturiLista);
    m_ProFakturiVnes = showMyWidget<ProFakturiVnes, ProFakturi>(m_ProFakturiVnes, this);
    m_ProFakturiVnes->setCategoryWidget(this);
    connect(m_ProFakturiVnes,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromVnes()));
    connect(m_ProFakturiVnes,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));
    connect(m_ProFakturiVnes,SIGNAL(signalGetKomintent(QString, QWidget*)),this,SLOT(procSentGetKomintent(QString, QWidget*)));
}

void ProFakturi::pressF3()
{
    if (m_ProFakturiLista){
        m_strID = m_ProFakturiLista->getSelectedID();
    }else{
        return;
    }
    disconnect(m_ProFakturiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_ProFakturiLista = deleteMyWidget<ProFakturiLista>(m_ProFakturiLista);
    m_ProFakturiKorekcija = showMyWidget<ProFakturiKorekcija, ProFakturi>(m_ProFakturiKorekcija, this);
    m_ProFakturiKorekcija->setCategoryWidget(this);
    connect(m_ProFakturiKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    connect(m_ProFakturiKorekcija,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));
    connect(m_ProFakturiKorekcija,SIGNAL(signalGetKomintent(QString, QWidget*)),this,SLOT(procSentGetKomintent(QString, QWidget*)));
    m_ProFakturiKorekcija->initProc(m_strID);
}

void ProFakturi::pressF4()
{
    m_ProFakturiLista = showMyWidget<ProFakturiLista, ProFakturi>(m_ProFakturiLista, this);
    m_ProFakturiLista->setCategoryWidget(this);
    connect(m_ProFakturiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    connect(m_ProFakturiLista,SIGNAL(signalpressF2()),this,SLOT(pressF2FromLista()));
    connect(m_ProFakturiLista,SIGNAL(signalpressF3()),this,SLOT(pressF3FromLista()));
}

void ProFakturi::pressEscape()
{

}
void ProFakturi::closeAllForm()
{
}

void ProFakturi::pressF2FromLista()
{
    pressF2();
}
void ProFakturi::pressF3FromLista()
{
    pressF3();
}

void ProFakturi::pressEscapeFromLista()
{
    disconnect(m_ProFakturiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_ProFakturiLista = deleteMyWidget<ProFakturiLista>(m_ProFakturiLista);
    setFocus();
    emit signCloseMyWidget();
}
void ProFakturi::pressEscapeFromVnes()
{
    m_ProFakturiVnes = deleteMyWidget<ProFakturiVnes>(m_ProFakturiVnes);
    pressF4();
}
void ProFakturi::pressEscapeFromKorekcija()
{
    disconnect(m_ProFakturiKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    m_ProFakturiKorekcija = deleteMyWidget<ProFakturiKorekcija>(m_ProFakturiKorekcija);
    pressF4();
}

void ProFakturi::procSentGetArtikal(QString text, QWidget* p)
{
    emit signArtikal(text, p);
}

void ProFakturi::procSentGetKomintent(QString text, QWidget* p)
{
    emit signKomintent(text, p);
}



