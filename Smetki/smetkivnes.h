#ifndef SmetkiVNES_H
#define SmetkiVNES_H

#include "Base/baseform.h"
#include "Helper/qhelperc.h"
#include "xx.h"
#include <QMessageBox>

namespace Ui {
class SmetkiVnes;
}

class SmetkiVnes : public BaseForm
{
    Q_OBJECT

public:
    explicit SmetkiVnes(BaseForm *parent = 0);
    ~SmetkiVnes();
    virtual void pressEscape();
    virtual void pressReturn();
    void setFocusArtikal(QString t);


private:
    Ui::SmetkiVnes *ui;
    QHelperC *hlp;
signals:
    void signalpressEscape();
    void signalGetArtikal(QString, QWidget*);
private slots:
    void on_pushButton_clicked();
    void getResultEX(QStringList& tlist);

};

#endif // SmetkiVNES_H
