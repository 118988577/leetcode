/*
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
说明：你不能倾斜容器，且 n 的值至少为 2。

*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int N = height.size();
        int left = 0, right = N - 1;
        ans = (right - left) * min(height[left],height[right]);
        int i = left, j = right;
        while(i < j){
            if(height[i] < height[j]){
                i++;
            }else{
                j++;
            }
            int temp = (j - i) * min(height[i], height[j]);
            if(temp > ans){
                ans = temp;
                right = j;
                left = i;
            }
        }
        return ans;
    }
};