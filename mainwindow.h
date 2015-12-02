#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Artikli/artikli.h"
#include "Komintenti/komintenti.h"
#include "Left/left.h"

#include <QDockWidget>
#include <QDesktopWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createDockWindows();
private slots:
    void on_actionArtikal_triggered();
    void closeMyWidget();
    void on_actionClose_triggered();

    void on_actionKomintent_triggered();

private:
    Ui::MainWindow *ui;
    QDockWidget *dock;
    Left *m_left;
    QRect rMain;

    template <class T, class P, class S>
    T* showMyWidget(T *a, QString info, P *parent, S* source)
    {
        if (a)
        {
            a->setFocus();
//            a->refresh();
            a->raise();
            a->setSourceWidget(source);
            m_left->updateSelection((QWidget*)a);
            return a;
        }
        a = new T(parent);
        connect(a, SIGNAL(signCloseMyWidget()), this, SLOT(closeMyWidget()));
        a->setGeometry(parent->rect());
        m_left->addTreeWidgetItem(info, (P*)a);
        a->setSourceWidget(source);
        a->setGeometry(rMain);
        a->showMaximized();
        a->setFocus();
        a->raise();
        return a;
    }

    template <class T>
    void deleteMyWidget(T *a)
    {
        disconnect(a, SIGNAL(signCloseMyWidget()), this, SLOT(closeMyWidget()));
        m_left->deleteTreeWidgetItem((QWidget*)a);
        if(a)
        {
            delete a;
            a = 0;
        }
    }

    Artikli *m_artikliModul;
    Komintenti *m_komintentiModul;


    QString m_artikliModul_description;
    QString m_komintentiModul_description;

    void updateNavigator(QWidget* a, QWidget* b);

};

#endif // MAINWINDOW_H
