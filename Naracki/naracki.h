#ifndef Naracki_H
#define Naracki_H

#include "Base/baseform.h"
#include "narackivnes.h"
#include "narackikorekcija.h"
#include "narackilista.h"

namespace Ui {
class Naracki;
}

class Naracki : public BaseForm
{
    Q_OBJECT

public:
    explicit Naracki(BaseForm *parent = 0);
    ~Naracki();
    virtual void pressF2();
    virtual void pressF3();
    virtual void pressF4();
    virtual void pressEscape();
    void closeAllForm();

private:
    Ui::Naracki *ui;
    NarackiLista        *m_NarackiLista;
    NarackiVnes         *m_NarackiVnes;
    NarackiKorekcija    *m_NarackiKorekcija;
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

#endif // Naracki_H
