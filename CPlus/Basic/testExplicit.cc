//
// Created by sc on 2023/8/31.
//

#include <iostream>
using namespace std;
class Point1
{

public:
    Point1(int x_ = 0, int y_ = 0) : X(x_), Y(y_) {}

    int X;
    int Y;
};

class Point2
{

public:
    explicit Point2(int x_ = 0, int y_ = 0) : X(x_), Y(y_) {}
private:
    int X;
    int Y;
};

int main()
{
    Point1 p1 = 1;
    cout<< p1.X << " " << p1.Y << std::endl;

    //Point2 p2 = 1;  error
    return 0;
}