/*
给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

说明：

给定 n 的范围是 [1, 9]。
给定 k 的范围是[1,  n!]。

*/
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        vector<int> factorials;
        vector<int> nums;
        factorials.push_back(0);
        nums.push_back(1);
        for (int i = 1; i < n;i++){
            factorials.push_back(factorials[i-1] *i);
            nums.push_back(i + 1);
        }
        k--;
        for (int i = n - 1; i > -1;i--){
            int index = k / factorials[i];
            k -= index * factorials[i];
            ans += to_string(nums[index]);
            nums.erase(nums.begin() + index);
        }
        return ans;
    }
};