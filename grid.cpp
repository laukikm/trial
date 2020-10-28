#include "grid.h"

//Include Some Useful Functions First
vector<int> VectorFromQPoint(QPoint& point){
    return {point.x(),point.y()};
}


QPoint QPointFromVector(vector<int> v){
    return QPoint(v[0],v[1]);
}

double DistanceFromCircle(QPoint center,QPoint point,int radius){
    double dx=center.x()-point.x();
    double dy=center.y()-point.y();
    return abs(sqrt(dx*dx+dy*dy)-radius);

}


//Main Functions after this point
Grid::Grid(int height,int width,int n_points_x,int n_points_y) //Initialize the grid of points by their locations and colors
{
    //Initializes the grid points wrt the GUI window.
    start_x=int(0.2*width);
    start_y=int(0.2*height);

    this->n_points_x=n_points_x;
    this->n_points_y=n_points_y;

    dx=int(0.6*width/20);
    dy=int(0.6*height/20);



    for(int i=0;i<n_points_x;i++){
        for(int j=0;j<n_points_y;j++){
            points[i][j]=QPoint(start_x+dx*i,start_y+dy*j); //i is the row number, j is the column number
        }
    }
}

void Grid::DisplayPoints(QPainter& p){
    //Uses qpainter instance p to display all the grid points

    for(int i=0;i<n_points_x;i++){
        for(int j=0;j<n_points_y;j++){
            QPoint point=points[i][j];
            QRect square(0,0,point_size,point_size);
            square.moveCenter(point);

            vector<int> point_vector=VectorFromQPoint(point);

            if(BlueColor[{i,j}]==1){
                p.fillRect(square,QColor(0,0,255)); //Fill the rectangle with blue

            }
            else{p.fillRect(square,QColor(100,100,100));} //Fill the rectangle with grey}

        }
    }
}

vector<vector<int>> Grid::NextPoints(vector<int> point,QPoint center, int radius){
    int i=point[0];
    int j=point[1];
    vector<int> next_i_values={i},next_j_values{j};
    QPoint current_point=points[i][j];

    //Calculate quadrant first
    int quadrant=0;

    if(current_point.x()>=center.x() and current_point.y()>=center.y()){quadrant=4;}
    if(current_point.x()>=center.x() and current_point.y()<center.y()){quadrant=1;}

    if(current_point.x()<center.x() and current_point.y()>=center.y()){quadrant=3;}
    if(current_point.x()<center.x() and current_point.y()<center.y()){quadrant=2;}

    //To increase x coordinate, increment i.
    //To increase y coordinate (in the conventional frame, not QT frame) decrement j
    if(quadrant==1){
        //Decrement x, increment y (decrement in QPoint frame)
        if(i>0){next_i_values.push_back(i-1);}
        if(j>0){next_j_values.push_back(j-1);}
    }

    if(quadrant==2){
        //Decrement x, decrement y (increment in QPoint frame)
        if(i>0){next_i_values.push_back(i-1);}
        if(j<n_points_y-1){next_j_values.push_back(j+1);}
    }

    if(quadrant==3){
        //Increment x, Decrement y (increment in QPoint frame)
        if(i<n_points_x-1){next_i_values.push_back(i+1);}
        if(j<n_points_y-1){next_j_values.push_back(j+1);}
    }

    if(quadrant==4){
        //Increment x, increment y (decrement in QPoint frame)
        if(i<n_points_x-1){next_i_values.push_back(i+1);}
        if(j>0){next_j_values.push_back(j-1);}
    }


    vector<vector<int>> next_points;
    for(int next_i : next_i_values){
        for(int next_j : next_j_values){
            if(next_i==i and next_j==j){continue;}
            next_points.push_back({next_i,next_j});
        }
    }
    return next_points;
}

vector<int> Grid::NearestPoint(vector<vector<int>> next_points,QPoint center,int radius){
    double min_distance=10000;
    vector<int> best_point;
    //Amongst the possible candidates, choose the one closest to the circle
    for(auto candidate : next_points){
        QPoint candidate_qpoint=points[candidate[0]][candidate[1]];
        if(DistanceFromCircle(center,candidate_qpoint,radius)<min_distance){
            min_distance=DistanceFromCircle(center,candidate_qpoint,radius);
            best_point=candidate;
        }
    }
    //Update maximum and minimum radii
    QPoint best_point_QPoint=points[best_point[0]][best_point[1]];
    int current_distance=int(DistanceFromCircle(best_point_QPoint,center,0)); //Calculates distance of point from the center of the circle
    max_radius=max(max_radius,current_distance);
    min_radius=min(min_radius,current_distance);

    return best_point;
}

void Grid::ColorPoints(QPoint center,int radius){
    //Depending on where and how big the circle is, decides which points to color blue

    //Calculate relative position first
    int start_x=int(0.2*1000);
    int start_y=int(0.2*1000);

    center-=QPoint(start_x,start_y); //This is in grid coordinates, where the top left grid point is 0
    QPoint bottom_point=center+QPoint(0,radius);

    int i=int(bottom_point.x()/dx);
    int j=int(bottom_point.y()/dy);

    center+=QPoint(start_x,start_y); //This is in window coordinates
    vector<int> point={i,j}; //i j inverted because the vector indexing uses a different coordinate system


    BlueColor[point]=1;

    int count=0;
    bool flag=false;
    while(!flag){

        count++;
        //Calculate possible directions (anticlockwise) to move in based on the circle and point location
        vector<vector<int>> next_points=NextPoints(point,center,radius);

        if(next_points.size()==0){break;} //To avoid segmentation fault

        for(auto candidate : next_points){
            if(BlueColor[candidate]==1 or count>200){flag=true;}
        } //Termination condition
        qDebug()<<point;
        vector<int> best_point=NearestPoint(next_points,center,radius);
        //Color the next point and repeat
        BlueColor[best_point]=1;
        point=best_point;

    }



}
