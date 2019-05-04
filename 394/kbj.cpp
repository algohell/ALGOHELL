/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

#include <string>
#include <stack>

using namespace std;

class Solution
{
  public:
    string multiply(int count, string s)
    {
        string ret = "";
        for (int i = 0; i < count; i++)
        {
            ret += s;
        }
        return ret;
    }
    string decodeString(string s)
    {
        string ans = "";
        int currNum = -1;
        string currStr = "";
        stack<pair<int, string>> braceStack;
        for (auto c : s)
        {
            int num = c - '0';
            bool isNumber = num >= 0 && num <= 9;
            if (isNumber)
            {
                if (currNum == -1)
                {
                    currNum = num;
                }
                else
                {
                    currNum = currNum * 10 + num;
                }
            }
            else
            {
                if (currNum == -1)
                {
                    // 비어있다면 처리할게 없으므로 그대로 문자를 넣어줌
                    if (braceStack.empty())
                    {
                        ans += c;
                    }
                    // 닫는 문자라면 스택에서 꺼내서 현재 문자열에 담아줌
                    else if (c == ']')
                    {
                        pair<int, string> prevPair = braceStack.top();
                        braceStack.pop();
                        if (braceStack.empty())
                        {
                            ans += prevPair.second + this->multiply(prevPair.first, currStr);
                            currStr = "";
                        }
                        else
                        {
                            currStr = prevPair.second + this->multiply(prevPair.first, currStr);
                        }
                    }
                    else
                    {
                        currStr += c;
                    }
                }
                else
                {
                    braceStack.push({currNum, currStr});
                    currStr = "";
                    currNum = -1;
                }
            }
        }
        return ans;
    }
};
