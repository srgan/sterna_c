#ifndef ARTIKLIVNES_H
#define ARTIKLIVNES_H

#include "Base/baseform.h"
#include "Helper/qhelperc.h"
#include "xx.h"
#include <QMessageBox>

namespace Ui {
class ArtikliVnes;
}

class ArtikliVnes : public BaseForm
{
    Q_OBJECT

public:
    explicit ArtikliVnes(BaseForm *parent = 0);
    ~ArtikliVnes();
    virtual void pressEscape();
    virtual void pressEnter();
    virtual void pressReturn();


private:
    Ui::ArtikliVnes *ui;
    QHelperC *hlp;
signals:
    void signalpressEscape();

private slots:
    void on_pushButton_clicked();
    void getResultEX(QStringList& tlist);

};

#endif // ARTIKLIVNES_H
