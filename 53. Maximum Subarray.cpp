class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN, currSum = 0;
        
        for(int i = 0;i < nums.size(); ++i)
        {
            currSum = max(currSum + nums[i], nums[i]);
            result = max(result, currSum);
        }
        
        return result;
    }
};