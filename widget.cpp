//widget.cpp
#include "widget.h"
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setFixedSize(1000,1000);
    grid=new Grid(height(),width());
    this->setMouseTracking(true);
}

Widget::~Widget()
{

}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(pressed){m_mousPos = event->pos();}

    update();
}

void Widget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter p(this);
    QPoint relative_position=m_mousPos-ellipse_center; //The radius will be half the side of the square.
    QRect r(0,0,relative_position.x(),relative_position.x()); //This is always a square of side relative_position.x()
    r.moveCenter(ellipse_center);

    p.setPen(QColor(0,0,255)); //Draw in Blue
    p.drawEllipse(r);
    grid->DisplayPoints(p);

    //Draw the bounding circles next
    QRect outer_square(0,0,2*grid->max_radius+10,2*grid->max_radius+10); //10 is a buffer to account for the square dimensions
    outer_square.moveCenter(ellipse_center);
    QRect inner_square(0,0,2*grid->min_radius-10,2*grid->min_radius-10);
    inner_square.moveCenter(ellipse_center);
    p.setPen(QColor(255,0,0)); //Draw in red
    p.drawEllipse(outer_square);
    p.drawEllipse(inner_square);


}

void Widget::mousePressEvent(QMouseEvent * event){
    pressed=true;
    ellipse_center=event->pos();
    grid->BlueColor.clear();
    grid->max_radius=-1000000;
    grid->min_radius=10000000;
}

void Widget::mouseReleaseEvent(QMouseEvent * event){
    pressed=false;
    int radius=abs((m_mousPos-ellipse_center).x()/2); //The radius will be half the side of the square.
    grid->ColorPoints(ellipse_center,radius);

    qDebug()<<grid->min_radius;



}
