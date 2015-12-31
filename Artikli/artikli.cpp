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
    connect(m_ArtikliLista,SIGNAL(signalReturnResult(QString)),this,SLOT(pressReturnResult(QString )));

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


void Artikli::pressReturnResult(QString text)
{
    QWidget *sour = getSourceWidget();
    if (qobject_cast<PriemniciVnes*>(sour))
    {
        PriemniciVnes *dest = qobject_cast<PriemniciVnes*>(sour);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusArtikal(text);
        dest->raise();
    }
    if (qobject_cast<PriemniciKorekcija*>(sour))
    {
        PriemniciKorekcija *dest = qobject_cast<PriemniciKorekcija*>(sour);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusArtikal(text);
        dest->raise();
    }
    if (qobject_cast<IspratniciVnes*>(sour))
    {
        IspratniciVnes *dest = qobject_cast<IspratniciVnes*>(sour);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusArtikal(text);
        dest->raise();
    }
    if (qobject_cast<IspratniciKorekcija*>(sour))
    {
        IspratniciKorekcija *dest = qobject_cast<IspratniciKorekcija*>(sour);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusArtikal(text);
        dest->raise();
    }
    if (qobject_cast<FakturiVnes*>(sour))
    {
        FakturiVnes *dest = qobject_cast<FakturiVnes*>(sour);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusArtikal(text);
        dest->raise();
    }
    if (qobject_cast<FakturiKorekcija*>(sour))
    {
        FakturiKorekcija *dest = qobject_cast<FakturiKorekcija*>(sour);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusArtikal(text);
        dest->raise();
    }
    if (qobject_cast<SmetkiVnes*>(sour))
    {
        SmetkiVnes *dest = qobject_cast<SmetkiVnes*>(sour);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusArtikal(text);
        dest->raise();
    }
    if (qobject_cast<SmetkiKorekcija*>(sour))
    {
        SmetkiKorekcija *dest = qobject_cast<SmetkiKorekcija*>(sour);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusArtikal(text);
        dest->raise();
    }
    if (qobject_cast<ProFakturiVnes*>(sour))
    {
        ProFakturiVnes *dest = qobject_cast<ProFakturiVnes*>(sour);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusArtikal(text);
        dest->raise();
    }
    if (qobject_cast<ProFakturiKorekcija*>(sour))
    {
        ProFakturiKorekcija *dest = qobject_cast<ProFakturiKorekcija*>(sour);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusArtikal(text);
        dest->raise();
    }
    if (qobject_cast<PovratniciVnes*>(sour))
    {
        PovratniciVnes *dest = qobject_cast<PovratniciVnes*>(sour);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusArtikal(text);
        dest->raise();
    }
    if (qobject_cast<PovratniciKorekcija*>(sour))
    {
        PovratniciKorekcija *dest = qobject_cast<PovratniciKorekcija*>(sour);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusArtikal(text);
        dest->raise();
    }
    if (qobject_cast<NarackiVnes*>(sour))
    {
        NarackiVnes *dest = qobject_cast<NarackiVnes*>(sour);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusArtikal(text);
        dest->raise();
    }
    if (qobject_cast<NarackiKorekcija*>(sour))
    {
        NarackiKorekcija *dest = qobject_cast<NarackiKorekcija*>(sour);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusArtikal(text);
        dest->raise();
    }
}




