#ifndef FakturiVNES_H
#define FakturiVNES_H

#include "Base/baseform.h"
#include "Helper/qhelperc.h"
#include "xx.h"
#include <QMessageBox>

namespace Ui {
class FakturiVnes;
}

class FakturiVnes : public BaseForm
{
    Q_OBJECT

public:
    explicit FakturiVnes(BaseForm *parent = 0);
    ~FakturiVnes();
    virtual void pressEscape();


private:
    Ui::FakturiVnes *ui;
    QHelperC *hlp;
signals:
    void signalpressEscape();
private slots:
    void on_pushButton_clicked();
    void getResultEX(QStringList& tlist);

};

#endif // FakturiVNES_H
