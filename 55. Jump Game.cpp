class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty())
        {
            return false;
        }
        
        int maxLen = nums[0];
        for(int i = 1;i < nums.size();i++)
        {
            if(i > maxLen)
            {
                return false;
            }
            
            if(maxLen >= nums.size() - 1)
            {
                return true;
            }
            
            maxLen = max(maxLen, i + nums[i]);
        }
        
        return maxLen >= nums.size() - 1;
    }
};