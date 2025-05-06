#include "circle.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <random>
using namespace std;
double Circle::calculateAreaBetween(double xmax, double ymax, int data_points) {
    random_device dev;
    std::mt19937 e2(dev());

    if(xmax - x_center < radius || ymax - y_center < radius) {
        return 0.0;
    }
    double area = 0.0;
    std::uniform_real_distribution<> x_distances(0.0, xmax);
    std::uniform_real_distribution<> y_distances(0.0, ymax);

    double area_max = xmax*ymax;

    uint64_t counter{0};
    //  Find the area above the circle and bounded by xmax to the right and ymax to the top.
    for(int i = 0; i < data_points; ++i) {
        double x = x_distances(e2);
        double y = y_distances(e2);
        double r = sqrt(x*x + y*y);

        if(r > radius) {
            ++counter;
        }
    }

    double area_est = area_max*double(counter)/data_points;
    return area_est;
}


