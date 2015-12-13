#ifndef IspratniciKOREKCIJA_H
#define IspratniciKOREKCIJA_H

#include "Base/baseform.h"
#include "Helper/qhelperc.h"
#include "xx.h"
#include <QMessageBox>
#include <QKeyEvent>

namespace Ui {
class IspratniciKorekcija;
}

class IspratniciKorekcija : public BaseForm
{
    Q_OBJECT

public:
    explicit IspratniciKorekcija(BaseForm *parent = 0);
    ~IspratniciKorekcija();
    virtual void pressEscape();
    void initProc(QString m_searchID);
    void setFocusArtikal(QString t);
    void setFocusKomintent(QString t);

private:
    Ui::IspratniciKorekcija *ui;
    QHelperC *hlp;
    QString m_id_artikal;
    bool statusWait;
signals:
    void signalpressEscape();
    void signalPrePressEscape();
private slots:
    void getResultEX(QStringList& );
    void getResultEXUpdate22(QStringList& tlist);
    void on_pushButton_released();
};

#endif // IspratniciKOREKCIJA_H
