#ifndef QHELPERC_H
#define QHELPERC_H
#include <QWidget>
#include "qrestapiex.h"

class QHelperC : public QWidget
{
    Q_OBJECT
public:
    explicit QHelperC(QWidget *parent = 0);
    ~QHelperC();
    void getallArtikli(QString& offset, QString& limit, QString& searchName, QString& searchBy);
    void getallKomintenti(QString& offset, QString& limit, QString& searchName);
    void getallDokumenti(QString& offset, QString& limit, QString& searchName);
    void getallDokumentiDetail(QString& offset, QString& limit, QString& searchDokId, QString& searchDokTip);
    void getInsertArticle(QString &vSif,
                                          QString &vArt,
                                          QString &vEdm,
                                          QString &vRef,
                                          QString &vKtb,
                                          QString &vDdv,
                                          QString &vPrz,
                                          QString &vKtg);
    void getUpdateArticle(QString &vSif,
                                          QString &vArt,
                                          QString &vEdm,
                                          QString &vRef,
                                          QString &vKtb,
                                          QString &vDdv,
                                          QString &vPrz,
                                          QString &vKtg);
private:
    QRestApiEx restApi;
signals:
    void signalResult(QStringList &);
    void signalResultArtikli(QStringList &);
    void signalResultKomintenti(QStringList &);
    void signalResultDokumenti(QStringList &);
    void signalResultDokumentiDetail(QStringList &);
    void signalResultInsertArticle(QStringList &);
    void signalResultUpdateArticle(QStringList &);


private slots:

    void getResultArtikli(QStringList &resList);
    void getResultKomintenti(QStringList &resList);
    void getResultDokumenti(QStringList &);
    void getResultDokumentiDetail(QStringList &);
    void getResultInsertArticle(QStringList &);
    void getResultUpdateArticle(QStringList &);

};

#endif // QHELPERC_H
