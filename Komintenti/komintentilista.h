#ifndef KomintentiLISTA_H
#define KomintentiLISTA_H

#include "Base/baseform.h"
#include <QStandardItemModel>
#include <QHeaderView>
#include "Helper/qhelperc.h"
#include "xx.h"

#define COL 9

namespace Ui {
class KomintentiLista;
}

class KomintentiLista : public BaseForm
{
    Q_OBJECT

public:
    explicit KomintentiLista(BaseForm *parent = 0);
    ~KomintentiLista();
    virtual void pressF2();
    virtual void pressF3();
    void pressReturn();
    virtual void pressEscape();

    void setTableColumnWidths(int ccolumn);
    void getTableColumnWidths(int ccolumn);
    QString getSelectedID(){return m_selectedID;}
    int geTableSelectedRow(){return m_row;}
    void seTableSelectedRow(int m_row);
    QString getSearchString();
    void setSearchString(QString& searchText);

private:
    Ui::KomintentiLista *ui;
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
    void signalReturnResult(QString);

private slots:
    void getResultEX(QStringList&);
    void on_pushButton_5_clicked();
    void on_LE_prebaraj_textChanged(const QString &arg1);
    void selectionChanged(QModelIndex,QModelIndex);

    void procSectionResized(int a, int b, int c);

    void on_pushButton_4_clicked();
    void on_lineEdit_textChanged(const QString &arg1);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_lineEditPrebaraj_textChanged(const QString &arg1);
};

#endif // KomintentiLISTA_H
