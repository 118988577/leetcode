#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0, pre = 0, cur = 1;
        for (int i = ; i < s.length();i++){
            if(s[i-1]!=s[i]){
                ans += min(pre,cur);
                pre = cur;
                cur = 1;
            }else{
                cur++;
            }
        }
        return ans + min(pre,cur);
    }
 
};
