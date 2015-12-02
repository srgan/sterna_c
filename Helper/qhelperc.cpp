#include "qhelperc.h"

QHelperC::QHelperC(QWidget *parent) : QWidget(parent)
{
    connect(&restApi, SIGNAL(retValueArtikli(QStringList &)), this, SLOT(getResultArtikli(QStringList &)));
    connect(&restApi, SIGNAL(retValueKomintenti(QStringList &)), this, SLOT(getResultKomintenti(QStringList &)));
    connect(&restApi, SIGNAL(retValueDokumenti(QStringList &)), this, SLOT(getResultDokumenti(QStringList &)));
    connect(&restApi, SIGNAL(retValueDokumentiDetail(QStringList &)), this, SLOT(getResultDokumentiDetail(QStringList &)));
    connect(&restApi, SIGNAL(retValueInsertArticle(QStringList &)), this, SLOT(getResultInsertArticle(QStringList &)));
    connect(&restApi, SIGNAL(retValueUpdateArticle(QStringList &)), this, SLOT(getResultUpdateArticle(QStringList &)));
}
QHelperC::~QHelperC()
{

}

void QHelperC::getResultArtikli(QStringList &resList)
{
    emit signalResultArtikli(resList);
}

void QHelperC::getResultKomintenti(QStringList &resList)
{
    emit signalResultKomintenti(resList);
}

void QHelperC::getResultDokumenti(QStringList &resList)
{
    emit signalResultDokumenti(resList);
}

void QHelperC::getResultDokumentiDetail(QStringList &resList)
{
    emit signalResultDokumentiDetail(resList);
}
void QHelperC::getResultInsertArticle(QStringList &resList)
{
    emit signalResultInsertArticle(resList);
}
void QHelperC::getResultUpdateArticle(QStringList &resList)
{
    emit signalResultUpdateArticle(resList);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////

void QHelperC::getallArtikli(QString& offset, QString& limit, QString& searchName, QString& searchBy)
{
    restApi.getArtikliList(offset, limit, searchName, searchBy);
}

void QHelperC::getallKomintenti(QString& offset, QString& limit, QString& searchName)
{
    restApi.getKomintentiList(offset, limit, searchName);
}

void QHelperC::getallDokumenti(QString& offset, QString& limit, QString& searchName)
{
    restApi.getDokumentiList(offset, limit, searchName);
}

void QHelperC::getallDokumentiDetail(QString& offset, QString& limit, QString& searchDokId, QString& searchDokTip)
{
    restApi.getDokumentiDetailList(offset, limit, searchDokId, searchDokTip);
}

void QHelperC::getInsertArticle(QString &vSif,
                                      QString &vArt,
                                      QString &vEdm,
                                      QString &vRef,
                                      QString &vKtb,
                                      QString &vDdv,
                                      QString &vPrz,
                                      QString &vKtg)
{
    restApi.InsertArticle(vSif,vArt, vEdm, vRef, vKtb, vDdv, vPrz, vKtg);
}


void QHelperC::getUpdateArticle(QString &vSif,
                                      QString &vArt,
                                      QString &vEdm,
                                      QString &vRef,
                                      QString &vKtb,
                                      QString &vDdv,
                                      QString &vPrz,
                                      QString &vKtg)
{
    restApi.UpdateArticle(vSif,vArt, vEdm, vRef, vKtb, vDdv, vPrz, vKtg);
}


