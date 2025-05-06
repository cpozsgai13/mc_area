#ifndef _CIRCLE_H_
#define _CIRCLE_H_

class Circle {
public:
    Circle(double ctr_x, double ctr_y, double rad): x_center(ctr_x), y_center(ctr_y), radius(rad){}

    double calculateAreaBetween(double xmax, double ymax, int data_points = 100);
private:
    double x_center;
    double y_center;
    double radius;

};
#endif