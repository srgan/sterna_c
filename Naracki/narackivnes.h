#ifndef NarackiVNES_H
#define NarackiVNES_H

#include "Base/baseform.h"
#include "Helper/qhelperc.h"
#include "xx.h"
#include <QMessageBox>

namespace Ui {
class NarackiVnes;
}

class NarackiVnes : public BaseForm
{
    Q_OBJECT

public:
    explicit NarackiVnes(BaseForm *parent = 0);
    ~NarackiVnes();
    virtual void pressEscape();
    virtual void pressReturn();
    void setFocusKomintent(QString t);
    void setFocusArtikal(QString t);

private:
    Ui::NarackiVnes *ui;
    QHelperC *hlp;
signals:
    void signalpressEscape();
    void signalGetArtikal(QString, QWidget*);
    void signalGetKomintent(QString, QWidget*);
private slots:
    void on_pushButton_clicked();
    void getResultEX(QStringList& tlist);

};

#endif // NarackiVNES_H
