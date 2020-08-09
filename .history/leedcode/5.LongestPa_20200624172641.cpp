#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.length();
        int dp[N][N];
        int left = 0, right = 0;
        //边界
        for (int i = 0; i < N;i++){
            dp[i][i] = 1;
            if(i < N - 1){
                if(s[i] == s[i + 1]){
                    dp[i][i + 1] = 1;
                    left = i;
                    right = i + 1;
                }
            }
        }
        //状态转移
        for (int L = 3; L <= N;L++){
            for (int j = 0; j + L - 1 < N;j++){
                int i = j + L - 1;
                if(s[i] == s[j] && dp[i + 1][j - 1] == 1){
                    dp[i][j] = 1;
                    left = i;
                    right = j;
                }
            }
        }
        string ans;
        for (int i = left; i <= right;i++){
            ans += s[i];
        }
        return ans;
    }
};
int main(){
    Solution test;
    string res = test.longestPalindrome("babad");
    return 0;
}