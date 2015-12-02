#ifndef ARTIKLI_H
#define ARTIKLI_H

#include "Base/baseform.h"
#include "artiklivnes.h"
#include "artiklikorekcija.h"
#include "artiklilista.h"

namespace Ui {
class Artikli;
}

class Artikli : public BaseForm
{
    Q_OBJECT

public:
    explicit Artikli(BaseForm *parent = 0);
    ~Artikli();
    virtual void pressF2();
    virtual void pressF3();
    virtual void pressF4();
    virtual void pressEscape();
    void closeAllForm();

private:
    Ui::Artikli *ui;
    ArtikliLista        *m_ArtikliLista;
    ArtikliVnes         *m_ArtikliVnes;
    ArtikliKorekcija    *m_ArtikliKorekcija;
    QString m_SearchString;
    int m_SelectedID;
    QString m_strID;



private slots:
    void pressF2FromLista();
    void pressF3FromLista();
    void pressEscapeFromLista();
    void pressEscapeFromVnes();
    void pressEscapeFromKorekcija();

signals:
    void signCloseMyWidget();

};

#endif // ARTIKLI_H
