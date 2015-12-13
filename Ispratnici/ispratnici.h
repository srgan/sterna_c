#ifndef Ispratnici_H
#define Ispratnici_H

#include "Base/baseform.h"
#include "ispratnicivnes.h"
#include "ispratnicikorekcija.h"
#include "ispratnicilista.h"

namespace Ui {
class Ispratnici;
}

class Ispratnici : public BaseForm
{
    Q_OBJECT

public:
    explicit Ispratnici(BaseForm *parent = 0);
    ~Ispratnici();
    virtual void pressF2();
    virtual void pressF3();
    virtual void pressF4();
    virtual void pressEscape();
    void closeAllForm();

private:
    Ui::Ispratnici *ui;
    IspratniciLista        *m_IspratniciLista;
    IspratniciVnes         *m_IspratniciVnes;
    IspratniciKorekcija    *m_IspratniciKorekcija;
    QString m_SearchString;
    int m_SelectedID;
    QString m_strID;



private slots:
    void pressF2FromLista();
    void pressF3FromLista();
    void pressEscapeFromLista();
    void pressEscapeFromVnes();
    void pressEscapeFromKorekcija();

    void procSentGetArtikal(QString text, QWidget* p);
    void procSentGetKomintent(QString text, QWidget* p);

signals:
    void signCloseMyWidget();
    void signArtikal(QString, QWidget* );
    void signKomintent(QString, QWidget*);
    void eupdateNanigator(QWidget*, QWidget*);

};

#endif // Ispratnici_H
