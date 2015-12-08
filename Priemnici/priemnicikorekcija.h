#ifndef PriemniciKOREKCIJA_H
#define PriemniciKOREKCIJA_H

#include "Base/baseform.h"
#include "Helper/qhelperc.h"
#include "xx.h"
#include <QMessageBox>
#include <QKeyEvent>

namespace Ui {
class PriemniciKorekcija;
}

class PriemniciKorekcija : public BaseForm
{
    Q_OBJECT

public:
    explicit PriemniciKorekcija(BaseForm *parent = 0);
    ~PriemniciKorekcija();
    virtual void pressEscape();
    virtual void pressEnter();
    virtual void pressReturn();
    void initProc(QString m_searchID);
    void setFocusArtikal(QString);
    void setFocusKomintent(QString);

private:
    Ui::PriemniciKorekcija *ui;
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
    void on_pushButton_5_clicked();
protected:
    bool eventFilter(QObject *obj, QEvent *ev);
};

#endif // PriemniciKOREKCIJA_H
