#include "baseform.h"
#include "ui_baseform.h"

BaseForm::BaseForm(QWidget *parent) :
    QWidget(parent)
   ,ui(new Ui::BaseForm)
{
    ui->setupUi(this);
}

BaseForm::~BaseForm()
{
    delete ui;
}

void BaseForm::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_F2: pressF2(); break;
        case Qt::Key_F3: pressF3(); break;
        case Qt::Key_F4: pressF4(); break;
        case Qt::Key_Escape: pressEscape(); break;
        case Qt::Key_Return: pressReturn(); break;
        case Qt::Key_Enter: pressEnter(); break;

    default:
         QWidget::keyPressEvent(event);
    }
}

void BaseForm::pressF2()
{

}
void BaseForm::pressF3()
{

}
void BaseForm::pressF4()
{

}
void BaseForm::pressEscape()
{

}
void BaseForm::pressEnter()
{

}
void BaseForm::pressReturn()
{

}




QWidget* BaseForm::getSourceWidget()
{
    return m_sourceWidget;
}
void BaseForm::setSourceWidget(QWidget *sourceWidget)
{
    m_sourceWidget = sourceWidget;
}

