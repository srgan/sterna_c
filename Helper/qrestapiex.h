#ifndef QRESTAPIEX_H
#define QRESTAPIEX_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QUrl>

class QRestApiEx : public QWidget
{
    Q_OBJECT
public:
    explicit QRestApiEx(QWidget *parent = 0);
    ~QRestApiEx();
    void getArtikliList(QString &vOffset, QString &vLimit, QString &vSearchName, QString &vSearchBy);
    void getKomintentiList( QString &vOffset, QString &vLimit,QString &vSearchName );
    void getDokumentiList( QString &vOffset, QString &vLimit,QString &vSearchName );
    void getDokumentiDetailList( QString &vOffset, QString &vLimit,QString &vSearchDokId, QString &vSearchDokTip);
    void InsertArticle( QString &vSif,
                                    QString &vArt,
                                    QString &vEdm,
                                    QString &vRef,
                                    QString &vKtb,
                                    QString &vDdv,
                                    QString &vPrz,
                                    QString &vKtg
                                    );
    void UpdateArticle( QString &vSif,
                                    QString &vArt,
                                    QString &vEdm,
                                    QString &vRef,
                                    QString &vKtb,
                                    QString &vDdv,
                                    QString &vPrz,
                                    QString &vKtg
                                    );


private:
    QNetworkAccessManager networkManager;
    QString urlhost;
    QString base64_decode(QString string);

signals:
    void retValueArtikli(QStringList &);
    void retValueKomintenti(QStringList &);
    void retValueDokumenti(QStringList &);
    void retValueDokumentiDetail(QStringList &);
    void retValueInsertArticle(QStringList &);
    void retValueUpdateArticle(QStringList &);

private slots:
    void onPostArtikliList(QNetworkReply *rep);
    void onPostKomintentiList(QNetworkReply *rep);
    void onPostDokumentiList(QNetworkReply *rep);
    void onPostDokumentiListDetail(QNetworkReply *rep);
    void onPostInsertArticle(QNetworkReply *rep);
    void onPostUpdateArticle(QNetworkReply *rep);

};

#endif // QRESTAPIEX_H
