#ifndef Komintenti_H
#define Komintenti_H

#include "Base/baseform.h"
#include "komintentivnes.h"
#include "komintentikorekcija.h"
#include "komintentilista.h"
#include "Priemnici/priemnici.h"
#include "Ispratnici/ispratnici.h"
#include "Fakturi/fakturi.h"
#include "ProFakturi/profakturi.h"
#include "Povratnica/povratnica.h"
#include "Naracki/naracki.h"


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
    void pressReturnResult(QString text);


signals:
    void signCloseMyWidget();
    void eupdateNanigator(QWidget*, QWidget*);

};

#endif // Komintenti_H
