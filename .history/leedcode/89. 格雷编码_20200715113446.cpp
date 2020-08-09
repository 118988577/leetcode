/*
格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。

给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。即使有多个不同答案，你也只需要返回其中一种。

格雷编码序列必须以 0 开头。
*/
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:


    vector<int> grayCode(int n) {
        vector<int> ans = {0};
        int head = 1;
         for (int i = 0; i < n; i++) {
            for (int j = ans.size() - 1; j >= 0; j--)
                ans.push_back(head + ans[j]);
            head <<= 1;
        }
        return ans;
    }
};