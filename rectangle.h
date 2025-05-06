#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

class Rectangle {
public:
    Rectangle(double x0, double y0, double x1, double y1): x0(x0), y0(y0), x1(x1), y1(y1){}

    double calculateAreaBetween(double xmax, double ymax, int data_points = 100);
private:
    double x0;
    double y0;
    double x1;
    double y1;
};
#endif