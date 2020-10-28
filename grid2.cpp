#include "grid2.h"

double Distance(QPoint p1,QPoint p2){
    double dx=p1.x()-p2.x();
    double dy=p1.y()-p2.y();
    return sqrt(dx*dx+dy*dy);
}

void Grid2::mouseClickEvent(QPoint mouse_position){


    QPoint relative_coords=mouse_position-QPoint(start_x,start_y);

    int i=relative_coords.x()/dx;
    int j=relative_coords.y()/dx;

    vector<vector<int>> possible_points={{i,j}};
    if(i<n_points_x-1){
        possible_points.push_back({i+1,j});
    }

    if(j<n_points_y-1){
        possible_points.push_back({i,j+1});
    }

    if(i<n_points_x-1 and j<n_points_y-1){
        possible_points.push_back({i+1,j+1});
    }

    //Convert position to grid point

    for(auto point : possible_points){
        int x=point[0];
        int y=point[1];
        QPoint current_point=points[x][y];

        if(Distance(current_point,mouse_position)<distance_cutoff){
            clicked_points[point]=1-clicked_points[point];
            BlueColor[point]=1-BlueColor[point];


        }


    }


}
