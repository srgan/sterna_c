#include "smetki.h"
#include "ui_smetki.h"

Smetki::Smetki(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::Smetki)
    ,m_SmetkiLista(0)
    ,m_SmetkiVnes(0)
    ,m_SmetkiKorekcija(0)

{
    ui->setupUi(this);
    pressF4();
}

Smetki::~Smetki()
{
    if (ui){
        delete ui;
    }
}

void Smetki::pressF2()
{
    if (!m_SmetkiLista) {
        return;
    }
    disconnect(m_SmetkiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_SmetkiLista = deleteMyWidget<SmetkiLista>(m_SmetkiLista);
    m_SmetkiVnes = showMyWidget<SmetkiVnes, Smetki>(m_SmetkiVnes, this);
    m_SmetkiVnes->setCategoryWidget(this);
    connect(m_SmetkiVnes,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromVnes()));
    connect(m_SmetkiVnes,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));

}

void Smetki::pressF3()
{
    if (m_SmetkiLista){
        m_strID = m_SmetkiLista->getSelectedID();
    }else{
        return;
    }
    disconnect(m_SmetkiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_SmetkiLista = deleteMyWidget<SmetkiLista>(m_SmetkiLista);
    m_SmetkiKorekcija = showMyWidget<SmetkiKorekcija, Smetki>(m_SmetkiKorekcija, this);
    m_SmetkiKorekcija->setCategoryWidget(this);
    connect(m_SmetkiKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    connect(m_SmetkiKorekcija,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));


    m_SmetkiKorekcija->initProc(m_strID);
}

void Smetki::pressF4()
{
    m_SmetkiLista = showMyWidget<SmetkiLista, Smetki>(m_SmetkiLista, this);
    m_SmetkiLista->setCategoryWidget(this);
    connect(m_SmetkiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    connect(m_SmetkiLista,SIGNAL(signalpressF2()),this,SLOT(pressF2FromLista()));
    connect(m_SmetkiLista,SIGNAL(signalpressF3()),this,SLOT(pressF3FromLista()));
}

void Smetki::pressEscape()
{

}
void Smetki::closeAllForm()
{
}

void Smetki::pressF2FromLista()
{
    pressF2();
}
void Smetki::pressF3FromLista()
{
    pressF3();
}

void Smetki::pressEscapeFromLista()
{
    disconnect(m_SmetkiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_SmetkiLista = deleteMyWidget<SmetkiLista>(m_SmetkiLista);
    setFocus();
    emit signCloseMyWidget();
}

void Smetki::pressEscapeFromVnes()
{
    m_SmetkiVnes = deleteMyWidget<SmetkiVnes>(m_SmetkiVnes);
    pressF4();
}

void Smetki::pressEscapeFromKorekcija()
{
    disconnect(m_SmetkiKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    m_SmetkiKorekcija = deleteMyWidget<SmetkiKorekcija>(m_SmetkiKorekcija);
    pressF4();
}

void Smetki::procSentGetArtikal(QString text, QWidget* p)
{
    emit signArtikal(text, p);
}



