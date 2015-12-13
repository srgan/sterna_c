#ifndef SmetkiKOREKCIJA_H
#define SmetkiKOREKCIJA_H

#include "Base/baseform.h"
#include "Helper/qhelperc.h"
#include "xx.h"
#include <QMessageBox>
#include <QKeyEvent>

namespace Ui {
class SmetkiKorekcija;
}

class SmetkiKorekcija : public BaseForm
{
    Q_OBJECT

public:
    explicit SmetkiKorekcija(BaseForm *parent = 0);
    ~SmetkiKorekcija();
    virtual void pressEscape();
    virtual void pressReturn();
    void initProc(QString m_searchID);
    void setFocusArtikal(QString t);

private:
    Ui::SmetkiKorekcija *ui;
    QHelperC *hlp;
    QString m_id_artikal;
    bool statusWait;
signals:
    void signalpressEscape();
    void signalGetArtikal(QString, QWidget*);
private slots:
    void getResultEX(QStringList& );
    void getResultEXUpdate22(QStringList& tlist);
    void on_pushButton_released();
};

#endif // SmetkiKOREKCIJA_H
