#ifndef LEFT_H
#define LEFT_H

#include <QWidget>
#include <QTreeWidgetItem>
#include <QMap>
class QMyBaseWidget;


namespace Ui {
class Left;
}

class Left : public QWidget
{
    Q_OBJECT

public:
    explicit Left(QWidget *parent = 0);
    ~Left();
    void addTreeWidgetItem(QString itemInfo, QWidget *fWidget);
    void deleteTreeWidgetItem(QWidget* itemWidget);
    void getSelection();
    void updateSelection(QWidget* a);
private:
    Ui::Left *ui;
    QMap<QTreeWidgetItem*, QWidget*> itemsMap;
    QList<QTreeWidgetItem*> items;
    QTreeWidgetItem * item;
    void keyPressEvent(QKeyEvent *event);

signals:
//	void signCloseMyWidget();
    void updatePrinterStatus(QWidget* i);
private slots:
    void on_treeWidget_itemSelectionChanged();
    void on_treeWidget_itemPressed(QTreeWidgetItem*,int);
    void on_treeWidget_itemClicked(QTreeWidgetItem*,int);

};

#endif // LEFT_H
