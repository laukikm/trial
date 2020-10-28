#include "widget2.h"

Widget2::Widget2(QWidget *parent)
{    
    this->setFixedSize(1000,1000);
    grid=new Grid2(height(),width());
    this->setMouseTracking(true);

}

Widget2::~Widget2()
{

}

void Widget2::mouseDoubleClickEvent(QMouseEvent * event){
    int mouse_x=event->pos().x();
    int mouse_y=event->pos().y();

    QPoint mouse_position=event->pos();

    grid->mouseClickEvent(mouse_position);

    update();
}

void Widget2::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter p(this);
    qDebug()<<grid->BlueColor[{0,0}];
    grid->DisplayPoints(p);

}
