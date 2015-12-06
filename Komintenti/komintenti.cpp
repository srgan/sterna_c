#include "komintenti.h"
#include "ui_komintenti.h"

Komintenti::Komintenti(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::Komintenti)
    ,m_KomintentiLista(0)
    ,m_KomintentiVnes(0)
    ,m_KomintentiKorekcija(0)

{
    ui->setupUi(this);
    pressF4();
}

Komintenti::~Komintenti()
{
    if (ui){
        delete ui;
    }
}

void Komintenti::pressF2()
{
    if (!m_KomintentiLista) {
        return;
    }
    disconnect(m_KomintentiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_KomintentiLista = deleteMyWidget<KomintentiLista>(m_KomintentiLista);
    m_KomintentiVnes = showMyWidget<KomintentiVnes, Komintenti>(m_KomintentiVnes, this);
    m_KomintentiVnes->setCategoryWidget(this);
    connect(m_KomintentiVnes,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromVnes()));
}

void Komintenti::pressF3()
{
    if (m_KomintentiLista){
        m_strID = m_KomintentiLista->getSelectedID();
    }else{
        return;
    }
    disconnect(m_KomintentiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_KomintentiLista = deleteMyWidget<KomintentiLista>(m_KomintentiLista);
    m_KomintentiKorekcija = showMyWidget<KomintentiKorekcija, Komintenti>(m_KomintentiKorekcija, this);
    m_KomintentiKorekcija->setCategoryWidget(this);
    connect(m_KomintentiKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));


    m_KomintentiKorekcija->initProc(m_strID);
}

void Komintenti::pressF4()
{
    m_KomintentiLista = showMyWidget<KomintentiLista, Komintenti>(m_KomintentiLista, this);
    m_KomintentiLista->setCategoryWidget(this);
    connect(m_KomintentiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    connect(m_KomintentiLista,SIGNAL(signalpressF2()),this,SLOT(pressF2FromLista()));
    connect(m_KomintentiLista,SIGNAL(signalpressF3()),this,SLOT(pressF3FromLista()));
}

void Komintenti::pressEscape()
{

}
void Komintenti::closeAllForm()
{
}

void Komintenti::pressF2FromLista()
{
    pressF2();
}
void Komintenti::pressF3FromLista()
{
    pressF3();
}

void Komintenti::pressEscapeFromLista()
{
    disconnect(m_KomintentiLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_KomintentiLista = deleteMyWidget<KomintentiLista>(m_KomintentiLista);
    setFocus();
    emit signCloseMyWidget();
}
void Komintenti::pressEscapeFromVnes()
{
    m_KomintentiVnes = deleteMyWidget<KomintentiVnes>(m_KomintentiVnes);
    pressF4();
}
void Komintenti::pressEscapeFromKorekcija()
{
    disconnect(m_KomintentiKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    m_KomintentiKorekcija = deleteMyWidget<KomintentiKorekcija>(m_KomintentiKorekcija);
    pressF4();
}





