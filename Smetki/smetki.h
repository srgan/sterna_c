#ifndef Smetki_H
#define Smetki_H

#include "Base/baseform.h"
#include "smetkivnes.h"
#include "smetkikorekcija.h"
#include "smetkilista.h"

namespace Ui {
class Smetki;
}

class Smetki : public BaseForm
{
    Q_OBJECT

public:
    explicit Smetki(BaseForm *parent = 0);
    ~Smetki();
    virtual void pressF2();
    virtual void pressF3();
    virtual void pressF4();
    virtual void pressEscape();
    void closeAllForm();

private:
    Ui::Smetki *ui;
    SmetkiLista        *m_SmetkiLista;
    SmetkiVnes         *m_SmetkiVnes;
    SmetkiKorekcija    *m_SmetkiKorekcija;
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

signals:
    void signCloseMyWidget();
    void signArtikal(QString, QWidget* );
    void signKomintent(QString, QWidget*);
    void eupdateNanigator(QWidget*, QWidget*);

};

#endif // Smetki_H
