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
    connect(m_KomintentiLista,SIGNAL(signalReturnResult(QString)),this,SLOT(pressReturnResult(QString )));
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


void Komintenti::pressReturnResult(QString text)
{
    QWidget *sour = getSourceWidget();

    if (qobject_cast<PriemniciVnes*>(sour))
    {
        PriemniciVnes *dest = qobject_cast<PriemniciVnes*>(sour);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusKomintent(text);
        dest->raise();
    }
    if (qobject_cast<PriemniciKorekcija*>(sour))
    {
        PriemniciKorekcija *dest = qobject_cast<PriemniciKorekcija*>(sour);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusKomintent(text);
        dest->raise();
    }
    if (qobject_cast<IspratniciVnes*>(sour))
    {
        IspratniciVnes *dest = qobject_cast<IspratniciVnes*>(sour);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusKomintent(text);
        dest->raise();
    }
    if (qobject_cast<IspratniciKorekcija*>(sour))
    {
        IspratniciKorekcija *dest = qobject_cast<IspratniciKorekcija*>(sour);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusKomintent(text);
        dest->raise();
    }
    if (qobject_cast<FakturiVnes*>(sour))
    {
        FakturiVnes *dest = qobject_cast<FakturiVnes*>(sour);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusKomintent(text);
        dest->raise();
    }
    if (qobject_cast<FakturiKorekcija*>(sour))
    {
        FakturiKorekcija *dest = qobject_cast<FakturiKorekcija*>(sour);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusKomintent(text);
        dest->raise();
    }
    if (qobject_cast<ProFakturiVnes*>(sour))
    {
        ProFakturiVnes *dest = qobject_cast<ProFakturiVnes*>(sour);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusKomintent(text);
        dest->raise();
    }
    if (qobject_cast<ProFakturiKorekcija*>(sour))
    {
        ProFakturiKorekcija *dest = qobject_cast<ProFakturiKorekcija*>(sour);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusKomintent(text);
        dest->raise();
    }
    if (qobject_cast<PovratniciVnes*>(sour))
    {
        PovratniciVnes *dest = qobject_cast<PovratniciVnes*>(sour);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusKomintent(text);
        dest->raise();
    }
    if (qobject_cast<PovratniciKorekcija*>(sour))
    {
        PovratniciKorekcija *dest = qobject_cast<PovratniciKorekcija*>(sour);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusKomintent(text);
        dest->raise();
    }
    if (qobject_cast<NarackiVnes*>(sour))
    {
        NarackiVnes *dest = qobject_cast<NarackiVnes*>(sour);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusKomintent(text);
        dest->raise();
    }
    if (qobject_cast<NarackiKorekcija*>(sour))
    {
        NarackiKorekcija *dest = qobject_cast<NarackiKorekcija*>(sour);
        emit eupdateNanigator(dest->getCategoryWidget(), this);
        dest->setFocusKomintent(text);
        dest->raise();
    }
}



