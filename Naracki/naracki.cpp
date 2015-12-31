#include "naracki.h"
#include "ui_naracki.h"

Naracki::Naracki(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::Naracki)
    ,m_NarackiLista(0)
    ,m_NarackiVnes(0)
    ,m_NarackiKorekcija(0)

{
    ui->setupUi(this);
    pressF4();
}

Naracki::~Naracki()
{
    if (ui){
        delete ui;
    }
}

void Naracki::pressF2()
{
    if (!m_NarackiLista) {
        return;
    }
    disconnect(m_NarackiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_NarackiLista = deleteMyWidget<NarackiLista>(m_NarackiLista);
    m_NarackiVnes = showMyWidget<NarackiVnes, Naracki>(m_NarackiVnes, this);
    m_NarackiVnes->setCategoryWidget(this);
    connect(m_NarackiVnes,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromVnes()));
    connect(m_NarackiVnes,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));
    connect(m_NarackiVnes,SIGNAL(signalGetKomintent(QString, QWidget*)),this,SLOT(procSentGetKomintent(QString, QWidget*)));
}

void Naracki::pressF3()
{
    if (m_NarackiLista){
        m_strID = m_NarackiLista->getSelectedID();
    }else{
        return;
    }
    disconnect(m_NarackiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_NarackiLista = deleteMyWidget<NarackiLista>(m_NarackiLista);
    m_NarackiKorekcija = showMyWidget<NarackiKorekcija, Naracki>(m_NarackiKorekcija, this);
    m_NarackiKorekcija->setCategoryWidget(this);
    connect(m_NarackiKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    connect(m_NarackiKorekcija,SIGNAL(signalGetArtikal(QString, QWidget*)),this,SLOT(procSentGetArtikal(QString, QWidget*)));
    connect(m_NarackiKorekcija,SIGNAL(signalGetKomintent(QString, QWidget*)),this,SLOT(procSentGetKomintent(QString, QWidget*)));
    m_NarackiKorekcija->initProc(m_strID);
}

void Naracki::pressF4()
{
    m_NarackiLista = showMyWidget<NarackiLista, Naracki>(m_NarackiLista, this);
    m_NarackiLista->setCategoryWidget(this);
    connect(m_NarackiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    connect(m_NarackiLista,SIGNAL(signalpressF2()),this,SLOT(pressF2FromLista()));
    connect(m_NarackiLista,SIGNAL(signalpressF3()),this,SLOT(pressF3FromLista()));
}

void Naracki::pressEscape()
{

}
void Naracki::closeAllForm()
{
}

void Naracki::pressF2FromLista()
{
    pressF2();
}
void Naracki::pressF3FromLista()
{
    pressF3();
}

void Naracki::pressEscapeFromLista()
{
    disconnect(m_NarackiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_NarackiLista = deleteMyWidget<NarackiLista>(m_NarackiLista);
    setFocus();
    emit signCloseMyWidget();
}
void Naracki::pressEscapeFromVnes()
{
    m_NarackiVnes = deleteMyWidget<NarackiVnes>(m_NarackiVnes);
    pressF4();
}
void Naracki::pressEscapeFromKorekcija()
{
    disconnect(m_NarackiKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    m_NarackiKorekcija = deleteMyWidget<NarackiKorekcija>(m_NarackiKorekcija);
    pressF4();
}

void Naracki::procSentGetArtikal(QString text, QWidget* p)
{
    emit signArtikal(text, p);
}

void Naracki::procSentGetKomintent(QString text, QWidget* p)
{
    emit signKomintent(text, p);
}



