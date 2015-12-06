#include "qrestapiex.h"
#include <QUrlQuery>

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>


QRestApiEx::QRestApiEx(QWidget *parent) : QWidget(parent)
{
   urlhost = "http://92.53.51.86:5002/";
   //urlhost = "http://127.0.0.1:5002/";
}

QRestApiEx::~QRestApiEx()
{
}

QString QRestApiEx::base64_decode(QString string)
{
    QByteArray ba;
    ba.append(string);
    return QByteArray::fromBase64(ba);
}

//------------------------------------------------------------------------------------------------
void QRestApiEx::getArtikliList( QString &vOffset, QString &vLimit,QString &vSearchName, QString &vSearchBy )
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostArtikliList(QNetworkReply*)));
    networkManager.clearAccessCache();
    QUrl serviceUrl = QUrl(urlhost + "get_article_list");
    QByteArray HeaderVar = "X-Api-Key";
    QByteArray HeaderValue = "aaa";
    QByteArray postData;
    QString tt = "{\"offset\":\"%offs%\", \"limit\":\"%lim%\", \"search_name\":\"%searchname%\", \"search_by\":\"%searchby%\"}";
    tt = tt.replace("%offs%", vOffset);
    tt = tt.replace("%lim%", vLimit);
    tt = tt.replace("%searchname%", vSearchName);
    tt = tt.replace("%searchby%", vSearchBy);

    postData.append(tt);
    QNetworkRequest networkRequest(serviceUrl);
    networkRequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    networkRequest.setRawHeader(HeaderVar, HeaderValue );
    networkManager.post(networkRequest,postData);
    HeaderVar.clear();
    HeaderValue.clear();
    postData.clear();
}
void QRestApiEx::onPostArtikliList(QNetworkReply *rep)
{
    disconnect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostArtikliList(QNetworkReply*)));
    QByteArray bts = rep->readAll();
    QString str(bts);
    bts.clear();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(str.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();
    QJsonArray jsonArray = jsonObject["properties"].toArray();
    QStringList listArt;


    for (int a = 0; a < jsonArray.count(); a++)
    {
        const QJsonValue & value = jsonArray.at(a);
        QJsonObject obj = value.toObject();
        QString t_id = QString::number(obj["id"].toInt());
        QString t_sifra = base64_decode(obj["sifra"].toString());
        QString t_ar = base64_decode(obj["artikal"].toString());
        QString t_edm = base64_decode(obj["edm"].toString());
        QString t_ref = base64_decode(obj["ref"].toString());
        QString t_kataloski_broj = base64_decode(obj["kataloski_broj"].toString());
        QString t_ddv = QString::number(obj["ddv"].toInt());
        QString t_proizvoditel = base64_decode(obj["proizvoditel"].toString());
        QString t_kategorija = base64_decode(obj["kategorija"].toString());
//        QString t_ed = base64_decode(obj["edm"].toString());

        if(t_id == "end")
        {
            continue;
        }
        else
        {
            listArt << t_id + "#;#"
                       + t_sifra + "#;#"
                       + t_ar + "#;#"
                       + t_edm + "#;#"
                       + t_ref + "#;#"
                       + t_kataloski_broj + "#;#"
                       + t_ddv + "#;#"
                       + t_proizvoditel + "#;#"
                       + t_kategorija ;
        }
    }
    emit retValueArtikli(listArt);
}
//------------------------------------------------------------------------------------------------
void QRestApiEx::getKomintentiList( QString &vOffset, QString &vLimit,QString &vSearchName )
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostKomintentiList(QNetworkReply*)));
    networkManager.clearAccessCache();
    QUrl serviceUrl = QUrl(urlhost + "get_komintenti_list");
    QByteArray HeaderVar = "X-Api-Key";
    QByteArray HeaderValue = "aaa";
    QByteArray postData;
    QString tt = "{\"offset\":\"%offs%\", \"limit\":\"%lim%\", \"search_name\":\"%searchname%\"}";
    tt = tt.replace("%offs%", vLimit);
    tt = tt.replace("%lim%", vOffset);
    tt = tt.replace("%searchname%", vSearchName);

    postData.append(tt);
    QNetworkRequest networkRequest(serviceUrl);
    networkRequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    networkRequest.setRawHeader(HeaderVar, HeaderValue );
    networkManager.post(networkRequest,postData);
    HeaderVar.clear();
    HeaderValue.clear();
    postData.clear();
}


void QRestApiEx::onPostKomintentiList(QNetworkReply *rep)
{
   disconnect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostKomintentiList(QNetworkReply*)));

    QByteArray bts = rep->readAll();
    QString str(bts);
    bts.clear();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(str.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();
    QJsonArray jsonArray = jsonObject["properties"].toArray();
    QStringList listArt;
    for (int a = 0; a < jsonArray.count(); a++)
    {
        const QJsonValue & value = jsonArray.at(a);
        QJsonObject obj = value.toObject();
        QString t_id = QString::number(obj["id"].toInt());
        QString t_sif = base64_decode(obj["sifra"].toString());
        QString t_naz = base64_decode(obj["naziv"].toString());
        QString t_adr = base64_decode(obj["adresa"].toString());
        QString t_tel = base64_decode(obj["tel"].toString());
        QString t_mobil = base64_decode(obj["mobil"].toString());
        QString t_zirosmetka = base64_decode(obj["zirosmetka"].toString());
        QString t_edb = base64_decode(obj["edb"].toString());
        QString t_deponent = base64_decode(obj["deponent"].toString());
        QString t_sifradejnost = base64_decode(obj["sifdejnost"].toString());
        QString t_mb = base64_decode(obj["mb"].toString());
        QString t_zabeleska1 = base64_decode(obj["zabeleska1"].toString());
        QString t_zabeleska2 = base64_decode(obj["zabeleska2"].toString());
        QString t_rabat = base64_decode(obj["rabat"].toString());
        QString t_grad = base64_decode(obj["grad"].toString());


        if(t_id == "end")
        {
            continue;
        }
        else
        {
            listArt << t_id  + "#;#" +
                       t_sif + "#;#" +
                       t_naz + "#;#" +
                       t_adr + "#;#" +
                       t_tel + "#;#" +
                       t_mobil + "#;#" +
                       t_zirosmetka + "#;#" +
                       t_edb + "#;#" +
                       t_deponent + "#;#" +
                       t_sifradejnost + "#;#" +
                       t_mb + "#;#" +
                       t_zabeleska1 + "#;#" +
                       t_zabeleska2 + "#;#" +
                       t_rabat + "#;#" +
                       t_grad;
        }

    }
    emit retValueKomintenti(listArt);
}
//------------------------------------------------------------------------------------------------
void QRestApiEx::getDokumentiList( QString &vOffset, QString &vLimit,QString &vSearchName )
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostDokumentiList(QNetworkReply*)));
    networkManager.clearAccessCache();
    QUrl serviceUrl = QUrl(urlhost + "get_dokumenti_list");
    QByteArray HeaderVar = "X-Api-Key";
    QByteArray HeaderValue = "aaa";
    QByteArray postData;
    QString tt = "{\"offset\":\"%offs%\", \"limit\":\"%lim%\", \"dok_tip\":\"%dok_tip%\"}";
    tt = tt.replace("%offs%", vLimit);
    tt = tt.replace("%lim%", vOffset);
    tt = tt.replace("%dok_tip%", vSearchName);

    postData.append(tt);
    QNetworkRequest networkRequest(serviceUrl);
    networkRequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    networkRequest.setRawHeader(HeaderVar, HeaderValue );
    networkManager.post(networkRequest, postData);
    HeaderVar.clear();
    HeaderValue.clear();
    postData.clear();
}
void QRestApiEx::onPostDokumentiList(QNetworkReply *rep)
{
   disconnect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostDokumentiList(QNetworkReply*)));

    QByteArray bts = rep->readAll();
    QString str(bts);
    bts.clear();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(str.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();
    QJsonArray jsonArray = jsonObject["properties"].toArray();
    QStringList listArt;
    for (int a = 0; a < jsonArray.count(); a++)
    {
        const QJsonValue & value = jsonArray.at(a);
        QJsonObject obj = value.toObject();
        QString t_id = obj["id"].toString();
        QString t_dok_id = obj["dok_id"].toString();
        QString t_dok_tip = obj["dok_tip"].toString();
        QString t_dok_tip_link = obj["dok_tip_link"].toString();
        QString t_komintent_id = obj["komintent_id"].toString();


        if(t_id == "end")
        {
            continue;
        }
        else
        {
            listArt << t_id + "#;#" + t_dok_id + "#;#" + t_dok_tip+ "#;#" + t_dok_tip_link + "#;#" + t_komintent_id;
        }
    }
    emit retValueDokumenti(listArt);
}
//------------------------------------------------------------------------------------------------
void QRestApiEx::getDokumentiDetailList( QString &vOffset, QString &vLimit,QString &vSearchDokId, QString &vSearchDokTip)
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostDokumentiListDetail(QNetworkReply*)));
    networkManager.clearAccessCache();
    QUrl serviceUrl = QUrl(urlhost + "get_dokumenti_detail_list");
    QByteArray HeaderVar = "X-Api-Key";
    QByteArray HeaderValue = "aaa";
    QByteArray postData;
    QString tt = "{\"offset\":\"%offs%\", \"limit\":\"%lim%\", \"dok_tip\":\"%dok_tip%\", \"dok_id\":\"%dok_id%\"}";
    tt = tt.replace("%offs%", vLimit);
    tt = tt.replace("%lim%", vOffset);
    tt = tt.replace("%dok_id%", vSearchDokId);
    tt = tt.replace("%dok_tip%", vSearchDokTip);

    postData.append(tt);
    QNetworkRequest networkRequest(serviceUrl);
    networkRequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    networkRequest.setRawHeader(HeaderVar, HeaderValue );
    networkManager.post(networkRequest,postData);
    HeaderVar.clear();
    HeaderValue.clear();
    postData.clear();
}

void QRestApiEx::onPostDokumentiListDetail(QNetworkReply *rep)
{
   disconnect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostDokumentiListDetail(QNetworkReply*)));

    QByteArray bts = rep->readAll();
    QString str(bts);
    bts.clear();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(str.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();
    QJsonArray jsonArray = jsonObject["properties"].toArray();
    QStringList listArt;
    for (int a = 0; a < jsonArray.count(); a++)
    {
        const QJsonValue & value = jsonArray.at(a);
        QJsonObject obj = value.toObject();
        QString t_id = obj["id"].toString();
        QString t_dok_id = obj["dok_id"].toString();
        QString t_dok_tip = obj["dok_tip"].toString();
        QString t_dok_tip_link = obj["dok_tip_link"].toString();
        QString t_komintent_id = obj["artikal_id"].toString();


        if(t_id == "end")
        {
            continue;
        }
        else
        {
            listArt << t_id + "#;#" + t_dok_id + "#;#" + t_dok_tip+ "#;#" + t_dok_tip_link + "#;#" + t_komintent_id;
        }
    }
    emit retValueDokumentiDetail(listArt);
}
//------------------------------------------------------------------------------------------------

void QRestApiEx::InsertArticle( QString &vSif,
                                QString &vArt,
                                QString &vEdm,
                                QString &vRef,
                                QString &vKtb,
                                QString &vDdv,
                                QString &vPrz,
                                QString &vKtg
                                )
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostInsertArticle(QNetworkReply*)));
    networkManager.clearAccessCache();
    QUrl serviceUrl = QUrl(urlhost + "insert_article");
    QByteArray HeaderVar = "X-Api-Key";
    QByteArray HeaderValue = "aaa";
    QByteArray postData;
    QString tt =
    "{"
    "\"sifra\": \"%sifra%\","
    "\"artikal\": \"%artikal%\","
    "\"edm\": \"%edm%\","
    "\"ref\":\"%ref%\","
    "\"kataloski_broj\":\"%kataloskibroj%\","
    "\"ddv\": %ddv%,"
    "\"proizvoditel\":\"%proizvoditel%\","
    "\"kategorija\":\"%kategorija%\""
    "}";

    tt = tt.replace("%sifra%", vSif);
    tt = tt.replace("%artikal%", vArt);
    tt = tt.replace("%edm%", vEdm);
    tt = tt.replace("%ref%", vRef);
    tt = tt.replace("%kataloskibroj%", vKtb);
    tt = tt.replace("%ddv%", vDdv);
    tt = tt.replace("%proizvoditel%", vPrz);
    tt = tt.replace("%kategorija%", vKtg);

    postData.append(tt);
    QNetworkRequest networkRequest(serviceUrl);
    networkRequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    networkRequest.setRawHeader(HeaderVar, HeaderValue );
    networkManager.post(networkRequest,postData);
    HeaderVar.clear();
    HeaderValue.clear();
    postData.clear();
}

void QRestApiEx::onPostInsertArticle(QNetworkReply *rep)
{
   disconnect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostInsertArticle(QNetworkReply*)));

    QByteArray bts = rep->readAll();
    QString str(bts);
    bts.clear();
    QStringList listArt;
    emit retValueInsertArticle(listArt);
}
//------------------------------------------------------------------------------------------------

void QRestApiEx::UpdateArticle( QString &vSif,
                                QString &vArt,
                                QString &vEdm,
                                QString &vRef,
                                QString &vKtb,
                                QString &vDdv,
                                QString &vPrz,
                                QString &vKtg
                                )
{
    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostUpdateArticle(QNetworkReply*)));
    networkManager.clearAccessCache();
    QUrl serviceUrl = QUrl(urlhost + "update_article");
    QByteArray HeaderVar = "X-Api-Key";
    QByteArray HeaderValue = "aaa";
    QByteArray postData;
    QString tt =
    "{"
    "\"sifra\": \"%sifra%\","
    "\"artikal\": \"%artikal%\","
    "\"edm\": \"%edm%\","
    "\"ref\":\"%ref%\","
    "\"kataloski_broj\":\"%kataloskibroj%\","
    "\"ddv\": %ddv%,"
    "\"proizvoditel\":\"%proizvoditel%\","
    "\"kategorija\":\"%kategorija%\""
    "}";

    tt = tt.replace("%sifra%", vSif);
    tt = tt.replace("%artikal%", vArt);
    tt = tt.replace("%edm%", vEdm);
    tt = tt.replace("%ref%", vRef);
    tt = tt.replace("%kataloskibroj%", vKtb);
    tt = tt.replace("%ddv%", vDdv);
    tt = tt.replace("%proizvoditel%", vPrz);
    tt = tt.replace("%kategorija%", vKtg);

    postData.append(tt);
    QNetworkRequest networkRequest(serviceUrl);
    networkRequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    networkRequest.setRawHeader(HeaderVar, HeaderValue );
    networkManager.post(networkRequest,postData);
    HeaderVar.clear();
    HeaderValue.clear();
    postData.clear();
}

void QRestApiEx::onPostUpdateArticle(QNetworkReply *rep)
{
   disconnect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onPostUpdateArticle(QNetworkReply*)));

    QByteArray bts = rep->readAll();
    QString str(bts);
    bts.clear();
    QStringList listArt;
    emit retValueUpdateArticle(listArt);
}
//------------------------------------------------------------------------------------------------
