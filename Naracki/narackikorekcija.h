#ifndef NarackiKOREKCIJA_H
#define NarackiKOREKCIJA_H

#include "Base/baseform.h"
#include "Helper/qhelperc.h"
#include "xx.h"
#include <QMessageBox>
#include <QKeyEvent>

namespace Ui {
class NarackiKorekcija;
}

class NarackiKorekcija : public BaseForm
{
    Q_OBJECT

public:
    explicit NarackiKorekcija(BaseForm *parent = 0);
    ~NarackiKorekcija();
    virtual void pressEscape();
    virtual void pressReturn();
    void initProc(QString m_searchID);
    void setFocusArtikal(QString t);
    void setFocusKomintent(QString t);

private:
    Ui::NarackiKorekcija *ui;
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

#endif // NarackiKOREKCIJA_H
