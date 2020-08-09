#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        int dp[N + 1];
        if(N == 0){
            return 0;
        }else if(N == 1){
            return nums[0];
        }else if(N == 2){
            return max(nums[0],nums[1]);
        }else{
            dp[0] = 0;
            dp[1] = nums[0];
            dp[2] = max(nums[0],nums[1]);
            for (int i = 3; i <= N;i++){
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
            }
        }
        return dp[N];
    }
};