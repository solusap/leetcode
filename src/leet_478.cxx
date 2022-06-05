#include "leetall.h"
#include <cmath>
#include <random>
 
vector<double> randPoint(double radius, double x_center, double y_center) {
    // const double PI = 3.14159265358979323846;
    std::random_device rd;

    std::uniform_real_distribution<double> distRadius(0, 1);
    std::uniform_real_distribution<double> distAngle(0, 360);

    double newradius = radius * std::sqrt(distRadius(rd));
    double angle = distAngle(rd);

    double x = x_center + newradius * cos(angle);
    double y = y_center + newradius * sin(angle);
    return {x, y};
}

void test()
{
    auto r = randPoint(10, 0, 0);
    fmt::print("ret = {}\n", r);
}

int main()
{
    test();
}