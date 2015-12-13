#ifndef ProFakturiKOREKCIJA_H
#define ProFakturiKOREKCIJA_H

#include "Base/baseform.h"
#include "Helper/qhelperc.h"
#include "xx.h"
#include <QMessageBox>
#include <QKeyEvent>

namespace Ui {
class ProFakturiKorekcija;
}

class ProFakturiKorekcija : public BaseForm
{
    Q_OBJECT

public:
    explicit ProFakturiKorekcija(BaseForm *parent = 0);
    ~ProFakturiKorekcija();
    virtual void pressEscape();
    virtual void pressReturn();
    void initProc(QString m_searchID);
    void setFocusArtikal(QString t);
    void setFocusKomintent(QString t);

private:
    Ui::ProFakturiKorekcija *ui;
    QHelperC *hlp;
    QString m_id_artikal;
    bool statusWait;
signals:
    void signalpressEscape();
    void signalGetArtikal(QString, QWidget*);
    void signalGetKomintent(QString, QWidget*);
private slots:
    void getResultEX(QStringList& );
    void getResultEXUpdate22(QStringList& tlist);
    void on_pushButton_released();
};

#endif // ProFakturiKOREKCIJA_H
