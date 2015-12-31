#ifndef PovratniciKOREKCIJA_H
#define PovratniciKOREKCIJA_H

#include "Base/baseform.h"
#include "Helper/qhelperc.h"
#include "xx.h"
#include <QMessageBox>
#include <QKeyEvent>

namespace Ui {
class PovratniciKorekcija;
}

class PovratniciKorekcija : public BaseForm
{
    Q_OBJECT

public:
    explicit PovratniciKorekcija(BaseForm *parent = 0);
    ~PovratniciKorekcija();
    virtual void pressEscape();
    virtual void pressReturn();
    void initProc(QString m_searchID);
    void setFocusArtikal(QString t);
    void setFocusKomintent(QString t);

private:
    Ui::PovratniciKorekcija *ui;
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

#endif // PovratniciKOREKCIJA_H
