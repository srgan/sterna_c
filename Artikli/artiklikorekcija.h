#ifndef ARTIKLIKOREKCIJA_H
#define ARTIKLIKOREKCIJA_H

#include "Base/baseform.h"
#include "Helper/qhelperc.h"
#include "xx.h"
#include <QMessageBox>
#include <QKeyEvent>

namespace Ui {
class ArtikliKorekcija;
}

class ArtikliKorekcija : public BaseForm
{
    Q_OBJECT

public:
    explicit ArtikliKorekcija(BaseForm *parent = 0);
    ~ArtikliKorekcija();
    virtual void pressEscape();
    void pressReturn();
    void pressEnter();
    void initProc(QString m_searchID);

private:
    Ui::ArtikliKorekcija *ui;
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

#endif // ARTIKLIKOREKCIJA_H
