#ifndef GRID2_H
#define GRID2_H

#include "grid.h"
#include <cmath>
class Grid2 : public Grid
{
public:
    using Grid::Grid; //Inheriting constructors thanks to C++11

    void mouseClickEvent(QPoint mouse_position);
    map<vector<int>,int> clicked_points; //Stores a list of points that have been clicked. Map is used to avoid duplicate clicking
    int distance_cutoff=5; //Maximum distance between mouse position and clicked point, in pixels
};

#endif // GRID2_H
