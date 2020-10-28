#ifndef UTIL_H
#define UTIL_H

#include<QPoint>
using namespace std;
vector<int> VectorFromQPoint(QPoint& point){
    return {point.x(),point.y()};
}

QPoint QPointFromVector(vector<int> v){
    return QPoint(v[0],v[1]);
}


#endif // UTIL_H
