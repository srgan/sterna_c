#ifndef KomintentiKOREKCIJA_H
#define KomintentiKOREKCIJA_H

#include "Base/baseform.h"
#include "Helper/qhelperc.h"
#include "xx.h"
#include <QMessageBox>
#include <QKeyEvent>

namespace Ui {
class KomintentiKorekcija;
}

class KomintentiKorekcija : public BaseForm
{
    Q_OBJECT

public:
    explicit KomintentiKorekcija(BaseForm *parent = 0);
    ~KomintentiKorekcija();
    virtual void pressEscape();
    void initProc(QString m_searchID);

private:
    Ui::KomintentiKorekcija *ui;
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

#endif // KomintentiKOREKCIJA_H
