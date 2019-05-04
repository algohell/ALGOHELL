/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */
#include <vector>

using namespace std;

class Solution
{
  public:
    int findDuplicate(vector<int> &nums)
    {
        int tortoise = nums[0];
        int hair = nums[0];
        // 토끼가 두걸음 갈때 거북이는 한 걸음씩 감
        // 중복이 존재하는 한 만나게 되어있다
        // 중복 = 인덱스 순회가 일어나는 지점
        do
        {
            tortoise = nums[tortoise];
            hair = nums[nums[hair]];
        } while (tortoise != hair);

        // 순환되는 사이클의 시작점을 찾는다.
        int ptr1 = nums[0];
        int ptr2 = tortoise;
        while (ptr1 != ptr2)
        {
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }

        return ptr1;
    }
};
