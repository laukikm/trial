#ifndef WIDGET2_H
#define WIDGET2_H

#include <QWidget>
#include "grid2.h"

#include <QtWidgets>
#include <QPushButton>

class Widget2 : public QWidget
{
    Q_OBJECT

public:
    Widget2(QWidget *parent = 0);
    ~Widget2();

protected:
    void mouseDoubleClickEvent(QMouseEvent * event);
    virtual void paintEvent(QPaintEvent *event)Q_DECL_OVERRIDE;
    Grid2* grid;
    QPoint m_mousPos;

};

#endif // WIDGET2_H
