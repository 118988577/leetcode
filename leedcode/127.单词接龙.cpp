/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 *
 * https://leetcode-cn.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (43.01%)
 * Likes:    398
 * Dislikes: 0
 * Total Accepted:    53.8K
 * Total Submissions: 124.6K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord
 * 的最短转换序列的长度。转换需遵循如下规则：
 * 
 * 
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 * 
 * 
 * 说明:
 * 
 * 
 * 如果不存在这样的转换序列，返回 0。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * 输出: 5
 * 
 * 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * ⁠    返回它的长度 5。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * 输出: 0
 * 
 * 解释: endWord "cog" 不在字典中，所以无法进行转换。
 * 
 */

// @lc code=start
#include<map>
#include<utility>
#include<vector>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
        map<string, vector<string>> common_dict;
    int visitWordNode(queue<pair<string,int>> &Q,map<string,int> visited,map<string,int> otherVisited){

        pair<string, int> WordNode = Q.front();
        Q.pop();
        string word = WordNode.first;
        int level = WordNode.second;
        int len = word.size();
        for (int i = 0; i < len; i++)
        {
            string new_word = word.substr(0, i) + "*" + word.substr(i + 1, len - i - 1);
            vector<string> commonWords = common_dict[new_word];
            for (vector<string>::iterator it = commonWords.begin(); it != commonWords.end(); it++)
            {
                if (otherVisited.find(*it)!=otherVisited.end())
                {
                    return level + otherVisited[*it];
                }
                if (visited.find(*it) == visited.end())
                {
                    Q.push(make_pair(*it, level + 1));
                    visited[*it] = level + 1;
                }
            }
        }
        return -1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool containend = false;
        for (vector<string>::iterator it = wordList.begin(); it != wordList.end();it++){
            if(*it == endWord){
                containend = true;
                break;
            }
        }
        if (containend == false)
            return 0;
        //对于字典中的单词做一个预处理，构建一个通用状态对应的一个单词组

        for (vector<string>::iterator it = wordList.begin(); it != wordList.end();it++){
            int len = (*it).size();
            for (int i = 0; i < len;i++){
                string new_word = (*it).substr(0, i) + "*" + (*it).substr(i+1,len - i -1);
                if(common_dict.find(new_word) == common_dict.end()){
                    vector<string> temp = {(*it)};
                    common_dict[new_word] = temp;
                }else{
                    common_dict[new_word].push_back(*it);
                }
            }
        }

        //使用广度优先搜索的方法，构建一个队列存放当前搜索单词节点的相邻单词节点
        queue<pair<string, int>> beginwordQueue;
        queue<pair<string, int>> endwordQueue;
        beginwordQueue.push(make_pair(beginWord,1));
        endwordQueue.push(make_pair(endWord,1));

        //为了避免出现环，使用一个数组检录一访问过的单词
        map<string, int> beginvisited;
        map<string, int> endvisited;
        beginvisited[beginWord] = 1;
        endvisited[endWord] = 1;

        while(!beginwordQueue.empty() && !endwordQueue.empty()){
            int ans = visitWordNode(beginwordQueue,beginvisited,endvisited);
            if(ans > -1){
                return ans;
            }
            ans = visitWordNode(endwordQueue,endvisited,beginvisited);
            if(ans > -1)
                return ans;
        }
        return 0;
    }
};
// @lc code=end

