//
// Created by sc on 2023/8/26.
//


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        return test(points);
    }
struct MyPoint
{
    int x;
    int y;
    MyPoint(int x_, int y_) : x(x_), y(y_){}
};

static bool myCompare(MyPoint a, MyPoint b)
{
    return a.x < b.x;
}
static bool myCompare1(MyPoint a, MyPoint b)
{
    return a.x == b.x ? a.y < b.y : false;
}
int test(vector<vector<int>>& points) {
    vector<MyPoint> vec;
    for(auto& p : points )
    {
        vec.emplace_back(p[0], p[1]);
    }

    std::sort(vec.begin(), vec.end(), myCompare);
    std::sort(vec.begin(), vec.end(), myCompare1);

    for(auto& elem : vec)
    {
        std::cout << elem.x << " " << elem.y <<std::endl;
    }
    vector<vector<MyPoint>> edges;
    for(auto& point : vec)
    {
        if (edges.empty())
        {
            vector<MyPoint> tmp {point};
            edges.push_back(tmp);
        }

        else if(point.x == edges.back().back().x)
        {
            edges.back().push_back(point);
        }
        else
        {
            vector<MyPoint> tmp {point};
            edges.push_back(tmp);
        }
    }
    long minArea = 0;

    for (int i = 0; i < edges.size() - 1; ++i)
    {
        if(edges[i].size() < 2) continue;
        vector<MyPoint>& edge1 = edges[i];
        for (int j = 0; j < edge1.size() - 1; ++j)
        {
            int y1 = edge1[j].y;
            for (int m = j+1; m < edge1.size(); ++m) {
                int y2 = edge1[m].y;
                int ySize = (y2 - y1);
                for (int k = i+1; k < edges.size(); ++k)
                {
                    if(edges[k].size() < 2) continue;
                    vector<MyPoint>& edge2 = edges[k];
                    int xSize = edge2.back().x - edge1.back().x;

                    int matchCount = 0;
                    for (int l = 0; l < edge2.size(); ++l) {
                        if(edge2[l].y == y1 || edge2[l].y == y2)
                        {
                            ++matchCount;
                        }
                    }
                    if(matchCount >= 2)
                    {
                        if(minArea == 0)
                            minArea = ySize * xSize;
                        else
                        {
                            minArea == minArea > ySize * xSize ? ySize * xSize : minArea;
                        }
                    }

                }
            }

        }
    }
    return minArea;
}
};

int main()
{
    vector<vector<int>> test = {{1,1},{1,3},{3,1},{3,3},{4,1},{4,3}};
    Solution s;
    std::cout<<s.minAreaRect(test);
}