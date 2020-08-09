/*
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。

*/
#include<vector>
#include<string>
#include<map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> AnagramsMap;
        vector<vector<string>> ans;
        int index = 0;
        for (int i = 0; i < strs.size();i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            if(AnagramsMap.find(temp) == AnagramsMap.end()){
                AnagramsMap[temp] = index++;
                vector<string> Anagrams;
                Anagrams.push_back(strs[i]);
                ans.push_back(Anagrams);
            }else{
                ans[AnagramsMap[temp]].push_back(strs[i]);
            }
        }
        return ans;
    }
};