class Solution {
public:
    int jump(vector<int>& nums) {
        int currMax = 0;
        int nextMax = 0;
        int result = 0;
        
        for(int i = 0;i < nums.size();i++)
        {
            if(currMax >= nums.size() - 1)
            {
                return result;
            }
            
            if(nextMax >= nums.size() - 1)
            {
                return result + 1;
            }
            
            if(i > currMax)
            {
                currMax = nextMax;
                result++;
            }
            
            nextMax = max(nextMax, i + nums[i]);
        }
        
        return result;
    }
};