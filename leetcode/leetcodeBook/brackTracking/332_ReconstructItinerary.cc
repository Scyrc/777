//
// Created by sc on 2023/9/14.
//
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
private:
    unordered_map<string, map<string, int>> allPath;
    bool backTracking(vector<string>& res, const int& ticketNum)
    {
        if(res.size() ==  ticketNum + 1)
        {
            return true;
        }

        for (auto& ticket : allPath[res.back()]) {
            if(ticket.second > 0)
            {
                res.push_back(ticket.first);
                --ticket.second;
                if(backTracking(res, ticketNum)) return true;
                res.pop_back();
                ++ticket.second;
            }
        }

        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        allPath.clear();
        vector<string> res;
        res.push_back("JFK");
        for(const vector<string>& v : tickets)
        {
            allPath[v[0]][v[1]] ++;
        }
        backTracking(res, tickets.size());
        return res;
    }
};

int main()
{
    vector<vector<string>> tickets;
    tickets.push_back(vector<string>{"MUC","LHR"});
    tickets.push_back(vector<string>{"JFK","MUC"});
    tickets.push_back(vector<string>{"SFO","SJC"});
    tickets.push_back(vector<string>{"LHR","SFO"});

    Solution s;
    s.findItinerary(tickets);
}