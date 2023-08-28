//
// Created by sc on 2023/8/26.
//

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    struct MyPoint {
        int x;
        int y;

        MyPoint(int x_, int y_) : x(x_), y(y_) {}
    };
    static bool myCompare(MyPoint a, MyPoint b) {
        if (a.x == b.x) {
            return a.y < b.y;
        }
        return a.x < b.x;
    }
    static int minAreaRect(vector<vector<int>>& points) {
        vector<MyPoint> vec;
        for(auto& p : points )
        {
            vec.emplace_back(p[0], p[1]);
        }
        std::sort(vec.begin(), vec.end(), myCompare);

        vector<vector<MyPoint>> edges;
        for (auto &point: vec) {
            if (edges.empty()) {
                vector<MyPoint> tmp{point};
                edges.push_back(tmp);
            } else if (point.x == edges.back().back().x) {
                edges.back().push_back(point);
            } else {
                vector<MyPoint> tmp{point};
                edges.push_back(tmp);
            }
        }
        long minArea = 0;
        for (int i = 0; i < edges.size() - 1; ++i) {
            if (edges[i].size() < 2) continue;
            vector<MyPoint> &edge1 = edges[i];
            for (int j = i + 1; j < edges.size(); ++j) {
                if (edges[j].size() < 2) continue;
                vector<MyPoint> &edge2 = edges[j];
                int xSize = edge2.back().x - edge1.back().x;
                vector<int> selectY;
                for (auto &p: edge1) {
                    for (auto &p1: edge2) {
                        if (p1.y == p.y) {
                            if (selectY.empty()) {
                                selectY.push_back(p.y);
                            } else {
                                long ySize = p.y - selectY.back();
                                if (minArea == 0)
                                    minArea = (ySize * xSize);
                                else {
                                    minArea = minArea > (ySize * xSize) ? (ySize * xSize) : minArea;
                                }
                                selectY.push_back(p.y);
                            }
                        }
                    }
                }
            }
        }
        return minArea;
    }
};