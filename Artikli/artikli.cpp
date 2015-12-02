#include "artikli.h"
#include "ui_artikli.h"

Artikli::Artikli(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::Artikli)
    ,m_ArtikliLista(0)
    ,m_ArtikliVnes(0)
    ,m_ArtikliKorekcija(0)

{
    ui->setupUi(this);
    pressF4();
}

Artikli::~Artikli()
{
    if (ui){
        delete ui;
    }
}

void Artikli::pressF2()
{
    if (!m_ArtikliLista) {
        return;
    }
    disconnect(m_ArtikliLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_ArtikliLista = deleteMyWidget<ArtikliLista>(m_ArtikliLista);
    m_ArtikliVnes = showMyWidget<ArtikliVnes, Artikli>(m_ArtikliVnes, this);
    m_ArtikliVnes->setCategoryWidget(this);
    connect(m_ArtikliVnes,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromVnes()));
}

void Artikli::pressF3()
{
    if (m_ArtikliLista){
        m_strID = m_ArtikliLista->getSelectedID();
    }else{
        return;
    }
    disconnect(m_ArtikliLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_ArtikliLista = deleteMyWidget<ArtikliLista>(m_ArtikliLista);
    m_ArtikliKorekcija = showMyWidget<ArtikliKorekcija, Artikli>(m_ArtikliKorekcija, this);
    m_ArtikliKorekcija->setCategoryWidget(this);
    connect(m_ArtikliKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));


    m_ArtikliKorekcija->initProc(m_strID);
}

void Artikli::pressF4()
{
    m_ArtikliLista = showMyWidget<ArtikliLista, Artikli>(m_ArtikliLista, this);
    m_ArtikliLista->setCategoryWidget(this);
    connect(m_ArtikliLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    connect(m_ArtikliLista,SIGNAL(signalpressF2()),this,SLOT(pressF2FromLista()));
    connect(m_ArtikliLista,SIGNAL(signalpressF3()),this,SLOT(pressF3FromLista()));
}

void Artikli::pressEscape()
{

}
void Artikli::closeAllForm()
{
}

void Artikli::pressF2FromLista()
{
    pressF2();
}
void Artikli::pressF3FromLista()
{
    pressF3();
}

void Artikli::pressEscapeFromLista()
{
    disconnect(m_ArtikliLista,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromLista()));
    m_ArtikliLista = deleteMyWidget<ArtikliLista>(m_ArtikliLista);
    setFocus();
    emit signCloseMyWidget();
}
void Artikli::pressEscapeFromVnes()
{
    m_ArtikliVnes = deleteMyWidget<ArtikliVnes>(m_ArtikliVnes);
    pressF4();
}
void Artikli::pressEscapeFromKorekcija()
{
    disconnect(m_ArtikliKorekcija,SIGNAL(signalpressEscape()),this,SLOT(pressEscapeFromKorekcija()));
    m_ArtikliKorekcija = deleteMyWidget<ArtikliKorekcija>(m_ArtikliKorekcija);
    pressF4();
}





