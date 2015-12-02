#include "komintentivnes.h"
#include "ui_komintentivnes.h"

KomintentiVnes::KomintentiVnes(BaseForm *parent) :
    BaseForm(parent),
    ui(new Ui::KomintentiVnes)
{
    ui->setupUi(this);
}

KomintentiVnes::~KomintentiVnes()
{
    if (ui){
        delete ui;
    }

}
void KomintentiVnes::pressEscape()
{
    emit signalpressEscape();
}

