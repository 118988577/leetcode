/*
给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

*/
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int> section;
        for (int i = 0; i < intervals.size();i++){
            while(section.size() < intervals[i][0]+1){
                section.push_back(0);
            }
            for (int j = intervals[i][0]+1; j <= intervals[i][1];j++){
                if(section.size() < j){
                    section.push_back(1);
                }else{
                    section[j - 1] = 1;
                }
            }
        }
        vector<int> temp;
        vector<vector<int>> ans;
        bool start = false;
        for (int w = 0; w < section.size();w++){
            if(section[w] == 1){
                if(start == false){
                    start = true;
                    temp.push_back(w);
                }else if(w == section.size() - 1){
                    start = false;
                    temp.push_back(w+1);
                    ans.push_back(temp);
                    temp.clear();    
                }
                
            }else{
                if(start == true){
                    start = false;
                    temp.push_back(w+1);
                    ans.push_back(temp);
                    temp.clear();
                }
            }
        }
        return ans;
    }
};
