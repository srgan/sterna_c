#ifndef Povratnici_H
#define Povratnici_H

#include "Base/baseform.h"
#include "povratnicavnes.h"
#include "povratnicakorekcija.h"
#include "povratnicalista.h"

namespace Ui {
class Povratnici;
}

class Povratnici : public BaseForm
{
    Q_OBJECT

public:
    explicit Povratnici(BaseForm *parent = 0);
    ~Povratnici();
    virtual void pressF2();
    virtual void pressF3();
    virtual void pressF4();
    virtual void pressEscape();
    void closeAllForm();

private:
    Ui::Povratnici *ui;
    PovratniciLista        *m_PovratniciLista;
    PovratniciVnes         *m_PovratniciVnes;
    PovratniciKorekcija    *m_PovratniciKorekcija;
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

#endif // Povratnici_H
