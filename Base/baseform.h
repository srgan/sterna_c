#ifndef BASEFORM_H
#define BASEFORM_H

#include <QWidget>
#include <QKeyEvent>


namespace Ui {
class BaseForm;
}

class BaseForm : public QWidget
{
//    Q_OBJECT

public:
    explicit BaseForm(QWidget *parent = 0);
    ~BaseForm();
    virtual void pressF2();
    virtual void pressF3();
    virtual void pressF4();
    virtual void pressEscape();
    virtual void pressReturn();
    virtual void pressEnter();




    QWidget* getSourceWidget();
    void setSourceWidget(QWidget *sourceWidget);
    void setCategoryWidget(QWidget * mWidget){m_Widget = mWidget;}
    QWidget *getCategoryWidget(){return m_Widget;}
private:
    Ui::BaseForm *ui;
    void keyPressEvent(QKeyEvent *event);
    QWidget *m_sourceWidget;
    QWidget *m_Widget;

protected:
    template <class T, class K>
    T* showMyWidget(T *a, K *b)
    {
        a = new T(b);
        a->showMaximized();
        a->setFocus();
        a->raise();
        return a;
    }

    template <class T>
    T* deleteMyWidget(T *a)
    {
        if (a)
        {
            delete a;
            a = 0;
        }
        return a;
    }


};

#endif // BASEFORM_H
