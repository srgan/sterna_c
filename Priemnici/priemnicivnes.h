#ifndef PriemniciVNES_H
#define PriemniciVNES_H

#include "Base/baseform.h"
#include "xx.h"
#include <QObjectList>
namespace Ui {
class PriemniciVnes;
}

class PriemniciVnes : public BaseForm
{
    Q_OBJECT

public:
    explicit PriemniciVnes(BaseForm *parent = 0);
    ~PriemniciVnes();
    virtual void pressEscape();
    virtual void pressEnter();
    virtual void pressReturn();

private:
    Ui::PriemniciVnes *ui;


protected:
    bool eventFilter(QObject *obj, QEvent *ev);

signals:
    void signalpressEscape();
private slots:

};

#endif // PriemniciVNES_H
