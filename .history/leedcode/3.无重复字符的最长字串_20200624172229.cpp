#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        unordered_set<char> charSet;
        int left = 0, right = 0;
        if(s.empty())
            return 0;
        for (int i = 0; i < s.length();i++){
            if(charSet.find(s[i]) == charSet.end()){
                charSet.insert(s[i]);
                right = i;
            }else{
                while(!charSet.empty()&&charSet.find(s[i]) != charSet.end()){
                    charSet.erase(s[left]);
                    left++;
                }
                charSet.insert(s[i]);
                right = i;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};