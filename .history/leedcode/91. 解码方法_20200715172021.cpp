/*
一条包含字母 A-Z 的消息通过以下方式进行了编码：

'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

*/
#include<string>

using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        int N = s.length();
        int dp[N + 1];
        if (s[i] == '0')
            return 0;
        //边界
        int pre = 1, cur = 1;
        //状态方程
        for (int i = 1; i < N;i++){
            int temp = cur;
            if(s[i] == '0'){
                if(s[i -1] == '1'||s[i-1] == '2'){
                    cur = pre;
                }else{
                    return 0;
                }
            }else if(s[i-1] == '1' || s[i-1] == 2 && s[i] >= '1' && s[i] <= '6'){
                cur = cur + pre;
            }else{
                cur = cur;
            }
            pre = temp;
        }
        return cur;
    }
};