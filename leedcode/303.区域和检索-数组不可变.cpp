#include <vector>
using namespace std;

class NumArray {
    vector<int> sum;

public:
    NumArray(vector<int>& nums) {
        int temp = 0;
        for (int j = 0; j < nums.size();j++){
            temp += nums[j];
            sum.push_back(temp);
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j - 1] - sum[i - 2];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */