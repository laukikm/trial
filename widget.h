#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include "grid.h"

/*The Widget Class describes the widget that is shown when the code is run.
 * It has functions to process the mouse movement and clicking, as well as a grid object that
 * plots the 20x20 grid and computes and displays the circle.
 *
 * This class takes the mouse movement as input from the user, and passes that to the grid object,
 * who computes and plots the result in the paintEvent function of the Widget Class.
*/

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected:
    virtual void mouseMoveEvent(QMouseEvent *event)Q_DECL_OVERRIDE;
    virtual void paintEvent(QPaintEvent *event)Q_DECL_OVERRIDE;

    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);

    Grid* grid; //The class that plots the 20x20 grid as well as the circle
    QPoint m_mousPos;
    QPoint ellipse_center;
    bool pressed=false;

};

#endif // WIDGET_H
