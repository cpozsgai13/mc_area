#include "rectangle.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <random>
using namespace std;
double Rectangle::calculateAreaBetween(double xmax, double ymax, int data_points) {
    random_device dev;
    std::mt19937 e2(dev());

    if(xmax < x0 || xmax < x1  || ymax < y0 || ymax < y1) {
        return 0.0;
    }
    double area = 0.0;
    std::uniform_real_distribution<> x_distances(x0, xmax);
    std::uniform_real_distribution<> y_distances(y0, ymax);

    double area_max = xmax*ymax;

    uint64_t counter{0};
    //  Find the area above the circle and bounded by xmax to the right and ymax to the top.
    for(int i = 0; i < data_points; ++i) {
        double x = x_distances(e2);
        double y = y_distances(e2);

        if(x > x1 || y > y1) {
            ++counter;
        }
    }

    double area_est = area_max*double(counter)/data_points;
    return area_est;
}


