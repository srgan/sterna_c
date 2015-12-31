#ifndef PovratniciVNES_H
#define PovratniciVNES_H

#include "Base/baseform.h"
#include "Helper/qhelperc.h"
#include "xx.h"
#include <QMessageBox>

namespace Ui {
class PovratniciVnes;
}

class PovratniciVnes : public BaseForm
{
    Q_OBJECT

public:
    explicit PovratniciVnes(BaseForm *parent = 0);
    ~PovratniciVnes();
    virtual void pressEscape();
    virtual void pressReturn();
    void setFocusKomintent(QString t);
    void setFocusArtikal(QString t);

private:
    Ui::PovratniciVnes *ui;
    QHelperC *hlp;
signals:
    void signalpressEscape();
    void signalGetArtikal(QString, QWidget*);
    void signalGetKomintent(QString, QWidget*);
private slots:
    void on_pushButton_clicked();
    void getResultEX(QStringList& tlist);

};

#endif // PovratniciVNES_H
