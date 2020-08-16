/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 *
 * https://leetcode-cn.com/problems/repeated-dna-sequences/description/
 *
 * algorithms
 * Medium (44.93%)
 * Likes:    108
 * Dislikes: 0
 * Total Accepted:    21.1K
 * Total Submissions: 46.8K
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * 所有 DNA 都由一系列缩写为 A，C，G 和 T 的核苷酸组成，例如：“ACGAATTCCG”。在研究 DNA 时，识别 DNA
 * 中的重复序列有时会对研究非常有帮助。
 * 
 * 编写一个函数来查找目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * 输出：["AAAAACCCCC", "CCCCCAAAAA"]
 * 
 */

// @lc code=start
#include<vector>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int N = 10;
        vector<string> ans;
        if(s.empty() || s.length() <= N)
            return ans;
        map<string, int> subStrCount;
        string subStr;
        for (int i = 0; i <= s.length() - N;i++){
            subStr = s.substr(i,N);
            if(subStrCount.count(subStr) == 0){
                subStrCount[subStr] = 1;
            }else{
                subStrCount[subStr]++;
            }
        }
        for (map<string, int>::iterator it = subStrCount.begin(); it != subStrCount.end();it++)
        {
            if(it->second > 1){
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};
// @lc code=end

