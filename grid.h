#ifndef GRID_H
#define GRID_H

#include <QObject>
#include<QPoint>
#include<QPaintEvent>
#include <QPainter>
#include <QDebug>

#include<cmath>
//#include "util.h"
using namespace std;

/*
 * The Grid class contains the code to display points. The function 'ColorPoints' is responsible for doing all computation,
 * once it knows the circle center and radius given to it by its widget.
 *
 * 'ColorPoints' takes the center and radius of the circle as input by moving anticlockwise from the bottom most point of the circle
 * The pseudocode is as follows
 * 1. Calculate the bottom_most point of the circle, given its center and radius.
 * 2. Calculate the 'next' points depending on the quadrant. (e.g.) if in the 1st quadrant, and moving acw, x has to decrease, and y had to increase)
 * 3. While(next_points are all not visited){
 * 4.  best_point=nearest_to_circle(next_points)
 * 5.  color(best_point)=blue;
 * 6.  current_point=best_point
 * 7.}
 *
 *
 * This always results in a complete solution, because when the acw traversal loops back, it always encounters the bottom point,
 *  where the algorithm started, and recognizes it as being visited, stopping the execution.

 */
class Grid
{
public:
    //Attributes
    QPoint points[20][20];
    int point_size=10;
    int n_points_x=20;
    int n_points_y=20;
    int start_x,start_y,dx,dy;
    int max_radius;
    int min_radius;

     map<vector<int>,int> BlueColor; //Stores whether or not a point should be colored, default=0

    //Functions
    Grid(int height,int width,int n_points_x=20,int n_points_y=20);
    void DisplayPoints(QPainter& p);
    void ColorPoints(QPoint center,int radius);
    vector<vector<int>> NextPoints(vector<int> point,QPoint center, int radius);
    vector<int> NearestPoint(vector<vector<int>> next_points,QPoint center,int radius);


};

#endif // GRID_H
