#ifndef ProFakturi_H
#define ProFakturi_H

#include "Base/baseform.h"
#include "profakturivnes.h"
#include "profakturikorekcija.h"
#include "profakturilista.h"

namespace Ui {
class ProFakturi;
}

class ProFakturi : public BaseForm
{
    Q_OBJECT

public:
    explicit ProFakturi(BaseForm *parent = 0);
    ~ProFakturi();
    virtual void pressF2();
    virtual void pressF3();
    virtual void pressF4();
    virtual void pressEscape();
    void closeAllForm();

private:
    Ui::ProFakturi *ui;
    ProFakturiLista        *m_ProFakturiLista;
    ProFakturiVnes         *m_ProFakturiVnes;
    ProFakturiKorekcija    *m_ProFakturiKorekcija;
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

#endif // ProFakturi_H
