#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Artikli/artikli.h"
#include "Komintenti/komintenti.h"
#include "Priemnici/priemnici.h"
#include "Fakturi/fakturi.h"
#include "Ispratnici/ispratnici.h"
#include "Smetki/smetki.h"
#include "ProFakturi/profakturi.h"
#include "Povratnica/povratnica.h"
#include "Naracki/naracki.h"

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
    void on_actionPriemnica_triggered();
    void on_actionFaktura_triggered();

    void on_actionIspretnicia_triggered();

    void on_actionSmetka_triggered();

    void on_actionProFaktura_triggered();

    void on_actionPovratnica_triggered();

    void on_actionNaracka_triggered();

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
    Priemnici *m_priemnicaModul;
    Fakturi *m_fakturaModul;
    Ispratnici *m_ispratnicaModul;
    Smetki *m_smetkaModul;
    ProFakturi *m_profakturaModul;
    Povratnici *m_povratnicaModul;
    Naracki *m_narackaModul;


    QString m_artikliModul_description;
    QString m_komintentiModul_description;
    QString m_priemnicaModul_description;
    QString m_fakturaModul_description;
    QString m_ispratnicaModul_description;
    QString m_smetkaModul_description;
    QString m_profakturaModul_description;
    QString m_povratnicaModul_description;
    QString m_narackaModul_description;

public slots:
    void updateNavigator(QWidget* a, QWidget* b);
    void procCreateModulArtikal(QString, QWidget *p);
    void procCreateModulKomintent(QString, QWidget *p);
    void procCreateModulPriemnica(QString, QWidget *p);
    void procCreateModulFaktura(QString, QWidget *p);
    void procCreateModulIspratnica(QString, QWidget *p);
    void procCreateModulSmetka(QString, QWidget *p);
    void procCreateModulProFaktura(QString, QWidget *p);
    void procCreateModulPovratnica(QString, QWidget *p);
    void procCreateModulNaracka(QString, QWidget *p);

};

#endif // MAINWINDOW_H
