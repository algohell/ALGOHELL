/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    void traverse(unordered_map<string, unordered_map<string, double>> map, string current, string target, unordered_map<string, bool> visited, double value, double &ans, bool &meet)
    {
        // 끝나는 조건
        if (current == target)
        {
            ans = value;
            meet = true;
            return;
        }

        for (auto next : map[current])
        {
            if (visited[next.first])
                continue;
            visited[next.first] = true;
            traverse(map, next.first, target, visited, value * next.second, ans, meet);
            visited[next.first] = false;
        }
    }
    double getValue(unordered_map<string, unordered_map<string, double>> map, string start, string end, unordered_map<string, bool> visited)
    {
        if (map.count(start) == 0)
        {
            return -1.0f;
        }
        double ans = 1.0f;
        bool meet = false;
        this->traverse(map, start, end, visited, 1.0f, ans, meet);
        if (!meet)
            return -1.0f;
        return ans;
    }

    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, unordered_map<string, double>> map;

        for (int i = 0; i < equations.size(); i++)
        {
            string first = equations[i][0];
            string second = equations[i][1];
            double value = values[i];
            if (map.count(first) == 0)
            {
                map.emplace(first, unordered_map<string, double>());
                map[first].emplace(first, 1);
            }
            if (map.count(second) == 0)
            {
                map.emplace(second, unordered_map<string, double>());
                map[second].emplace(second, 1);
            }
            map[first].emplace(second, value);
            map[second].emplace(first, 1 / value);
        }

        vector<double> ans;

        unordered_map<string, bool> visited;
        for (auto m : map)
        {
            visited.emplace(m.first, false);
        }

        for (auto q : queries)
        {
            ans.push_back(this->getValue(map, q[0], q[1], visited));
        }
        return ans;
    }
};
