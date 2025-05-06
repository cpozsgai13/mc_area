#include "polygon.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <random>
using namespace std;

auto isInside=[](const std::vector<Coord>& points, double x, double y) -> bool {
    bool inside = false;
    int N = points.size();
    for(int i = 0, j = N - 1; i < N; j = i++) {
        auto x1 = points[i].x;
        auto y1 = points[i].y;
        auto x2 = points[j].x;
        auto y2 = points[j].y;
        if((y1 > y) != (y2 > y) && (x < (x2 - x1) * (y - y1) / (y2 - y1) + x1)) {
            inside = !inside;
        }
    }
    return inside;
};

double Polygon::area() const {
    double a = 0.0;

    //  Assume polygon 0 = polygon N - 1
    int N = points.size();
    for(int i = 0; i < N; ++i) {
        double x1 = points[i].x;
        double y1 = points[i].y;
        double x2 = points[(i + 1)%N].x;
        double y2 = points[(i + 1)%N].y;

        a += x1*y2 - y1*x2;
    }
    return abs(a)/2.0;
}

double Polygon::calculateAreaBetween(double xt, double yt, int data_points) const {
    random_device dev;
    std::mt19937 e2(dev());

    double xmin = 1000, xmax = -1000;
    double ymin = 1000, ymax = -1000;
    for(auto pt: points) {
        if(pt.x > xmax) {
            xmax = pt.x;
        }
        if(pt.x < xmin) {
            xmin = pt.x;
        }
        if(pt.y > ymax) {
            ymax = pt.y;
        }
        if(pt.y < ymin) {
            ymin = pt.y;
        }
    }

    double area = 0.0;
    std::uniform_real_distribution<> x_distances(xmin, xt);
    std::uniform_real_distribution<> y_distances(ymin, yt);

    double area_max = xt*yt;

    uint64_t counter{0};
    //  Find the area above the circle and bounded by xmax to the right and ymax to the top.
    for(int i = 0; i < data_points; ++i) {
        double x = x_distances(e2);
        double y = y_distances(e2);

        if(!isInside(points, x, y)) {
            ++counter;
        }
    }

    double area_est = area_max*double(counter)/data_points;
    return area_est;
}


