#ifndef FakturiKOREKCIJA_H
#define FakturiKOREKCIJA_H

#include "Base/baseform.h"
#include "Helper/qhelperc.h"
#include "xx.h"
#include <QMessageBox>
#include <QKeyEvent>

namespace Ui {
class FakturiKorekcija;
}

class FakturiKorekcija : public BaseForm
{
    Q_OBJECT

public:
    explicit FakturiKorekcija(BaseForm *parent = 0);
    ~FakturiKorekcija();
    virtual void pressEscape();
    void initProc(QString m_searchID);

private:
    Ui::FakturiKorekcija *ui;
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

#endif // FakturiKOREKCIJA_H
