#ifndef KomintentiVNES_H
#define KomintentiVNES_H

#include "Base/baseform.h"
#include "xx.h"

namespace Ui {
class KomintentiVnes;
}

class KomintentiVnes : public BaseForm
{
    Q_OBJECT

public:
    explicit KomintentiVnes(BaseForm *parent = 0);
    ~KomintentiVnes();
    virtual void pressEscape();


private:
    Ui::KomintentiVnes *ui;

signals:
    void signalpressEscape();
};

#endif // KomintentiVNES_H
