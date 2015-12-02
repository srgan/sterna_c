#ifndef Komintenti_H
#define Komintenti_H

#include "Base/baseform.h"
#include "komintentivnes.h"
#include "komintentikorekcija.h"
#include "komintentilista.h"

namespace Ui {
class Komintenti;
}

class Komintenti : public BaseForm
{
    Q_OBJECT

public:
    explicit Komintenti(BaseForm *parent = 0);
    ~Komintenti();
    virtual void pressF2();
    virtual void pressF3();
    virtual void pressF4();
    virtual void pressEscape();
    void closeAllForm();

private:
    Ui::Komintenti *ui;
    KomintentiLista        *m_KomintentiLista;
    KomintentiVnes         *m_KomintentiVnes;
    KomintentiKorekcija    *m_KomintentiKorekcija;
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

#endif // Komintenti_H
