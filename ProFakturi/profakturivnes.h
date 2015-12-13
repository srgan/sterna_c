#ifndef ProFakturiVNES_H
#define ProFakturiVNES_H

#include "Base/baseform.h"
#include "Helper/qhelperc.h"
#include "xx.h"
#include <QMessageBox>

namespace Ui {
class ProFakturiVnes;
}

class ProFakturiVnes : public BaseForm
{
    Q_OBJECT

public:
    explicit ProFakturiVnes(BaseForm *parent = 0);
    ~ProFakturiVnes();
    virtual void pressEscape();
    virtual void pressReturn();
    void setFocusKomintent(QString t);
    void setFocusArtikal(QString t);

private:
    Ui::ProFakturiVnes *ui;
    QHelperC *hlp;
signals:
    void signalpressEscape();
    void signalGetArtikal(QString, QWidget*);
    void signalGetKomintent(QString, QWidget*);
private slots:
    void on_pushButton_clicked();
    void getResultEX(QStringList& tlist);

};

#endif // ProFakturiVNES_H
