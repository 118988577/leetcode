#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> zChar;
        int Len = s.length();
        int index = 0;
        while(1){
            for (int i = 0; i < numRows && index < Len;i++){
                if(zChar.empty() || i > zChar.size() -1){
                    vector<char> temp;
                    temp.push_back(s[index++]);
                    zChar.push_back(temp);
                }else{
                    zChar[i].push_back(s[index++]);
                }
            }
            for (int j = numRows - 2; j > 0 && index < Len;j--){
                zChar[j].push_back(s[index++]);
            }
            if(index >= Len){
                break;
            }
        }
        string ans = "";
        for (int i = 0; i < zChar.size();i++){
            for (int j = 0; j < zChar[i].size();j++){
                ans += zChar[i][j];
            }
        }
        return ans;
    }
};
int main(){
    Solution test;
    string res = test.convert("LEETCODEISHIRING",3);
    return 0;
}