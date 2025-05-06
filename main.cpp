#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include "circle.h"
#include "rectangle.h"
#include "polygon.h"
#include <math.h>
using namespace std;

auto parseIniFile=[](const char *path) -> boost::property_tree::ptree {
    boost::property_tree::ptree res;

    boost::property_tree::ini_parser::read_ini(path, res);
    return res;
};


int main(int argc, char *argv[]) {
    if(argc > 1)
    {
        auto properties = parseIniFile(argv[1]);

        if(properties.empty()) {
            return 1;
        }

        auto circle_x = properties.get<double>("circle.x0");
        auto circle_y = properties.get<double>("circle.y0");
        auto circle_radius = properties.get<double>("circle.R");
        auto xmax = properties.get<double>("circle.xmax");
        auto ymax = properties.get<double>("circle.ymax");
        auto num_points = properties.get<double>("circle.num_points");

        Circle circle{circle_x, circle_y, circle_radius};

        double area = circle.calculateAreaBetween(xmax, ymax, num_points);
        cout << "Full Area = " << xmax*ymax << endl;
        cout << "Circle Area = " << M_PI_4*circle_radius*circle_radius << endl;
        cout << "Est Area = " << area << endl;
        cout << "Actual area = " << xmax*ymax - M_PI_4*circle_radius*circle_radius << endl;

        double x0 = properties.get<double>("rectangle.x0");
        double y0 = properties.get<double>("rectangle.y0");
        double x1 = properties.get<double>("rectangle.x1");
        double y1 = properties.get<double>("rectangle.y1");
        xmax =  properties.get<double>("rectangle.xmax");
        ymax =  properties.get<double>("rectangle.ymax");
        num_points = properties.get<double>("rectangle.num_points");
        Rectangle rectangle{x0, y0, x1, y1};
        area = rectangle.calculateAreaBetween(xmax, ymax, num_points);
        cout << "Full Area = " << xmax*ymax << endl;
        cout << "Rectangle Area = " << (x1 - x0)*(y1 - y0) << endl;
        cout << "Est Area = " << area << endl;
        cout << "Actual area = " << xmax*ymax - (x1 - x0)*(y1 - y0) << endl;

        int N = properties.get<int>("polygon.N");
        string x_base = "x";
        string y_base = "y";
        vector<Coord> points;
        for(int i = 0; i < N; ++i) {
            string xname = "polygon.x" + to_string(i);
            string yname = "polygon.y" + to_string(i);
            double x = properties.get<double>(xname);
            double y = properties.get<double>(yname);
            points.push_back({x, y});
        }
        xmax =  properties.get<double>("polygon.xmax");
        ymax =  properties.get<double>("polygon.ymax");
        num_points = properties.get<double>("polygon.num_points");
        Polygon polygon(std::move(points));
        area = polygon.calculateAreaBetween(xmax, ymax, num_points);
        cout << "Polygon Area = " << polygon.area() << endl;
        cout << "Full Area = " << xmax*ymax << endl;
        cout << "Est Area = " << area << endl;
    }

    return 0;
}
