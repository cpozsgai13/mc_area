#ifndef _POLYGON_H_
#define _POLYGON_H_

#include <vector>

struct Coord {
    double x;
    double y;
};

class Polygon {
public:
    Polygon(std::vector<Coord>&& data):points(std::move(data)){}

    double calculateAreaBetween(double xmax, double ymax, int data_points = 100) const;
    double area() const;
private:
    std::vector<Coord> points;
};
#endif