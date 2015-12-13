#ifndef IspratniciVNES_H
#define IspratniciVNES_H

#include "Base/baseform.h"
#include "Helper/qhelperc.h"
#include "xx.h"
#include <QMessageBox>

namespace Ui {
class IspratniciVnes;
}

class IspratniciVnes : public BaseForm
{
    Q_OBJECT

public:
    explicit IspratniciVnes(BaseForm *parent = 0);
    ~IspratniciVnes();
    virtual void pressEscape();
    virtual void pressReturn();
    void setFocusArtikal(QString t);
    void setFocusKomintent(QString t);

private:
    Ui::IspratniciVnes *ui;
    QHelperC *hlp;
signals:
    void signalpressEscape();
    void signalGetArtikal(QString, QWidget*);
    void signalGetKomintent(QString, QWidget*);
private slots:
    void on_pushButton_clicked();
    void getResultEX(QStringList& tlist);

};

#endif // IspratniciVNES_H
