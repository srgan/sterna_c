#ifndef ProFakturiLISTA_H
#define ProFakturiLISTA_H

#include "Base/baseform.h"
#include <QStandardItemModel>
#include <QHeaderView>
#include "Helper/qhelperc.h"
#include "xx.h"

#define COL 9

namespace Ui {
class ProFakturiLista;
}

class ProFakturiLista : public BaseForm
{
    Q_OBJECT

public:
    explicit ProFakturiLista(BaseForm *parent = 0);
    ~ProFakturiLista();
    virtual void pressF2();
    virtual void pressF3();

    virtual void pressEscape();

    void setTableColumnWidths(int ccolumn);
    void getTableColumnWidths(int ccolumn);
    QString getSelectedID(){return m_selectedID;}
    int geTableSelectedRow(){return m_row;}
    void seTableSelectedRow(int m_row);
    QString getSearchString();
    void setSearchString(QString& searchText);

private:
    Ui::ProFakturiLista *ui;
    QStandardItemModel *model;
    QHeaderView *header;
    QHelperC *hlp;
    int numOffset;
    int colWidth[9];
    QString m_selectedID;
    int m_row;

signals:
    void signalpressF2();
    void signalpressF3();
    void signalpressEscape();

private slots:
    void getResultEX(QStringList&);
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_LE_prebaraj_textChanged(const QString &arg1);
    void selectionChanged(QModelIndex,QModelIndex);

    void procSectionResized(int a, int b, int c);

    void on_pb_vnesi_nov_clicked();
    void on_pb_koregiraj_postoecki_clicked();
};

#endif // ProFakturiLISTA_H
