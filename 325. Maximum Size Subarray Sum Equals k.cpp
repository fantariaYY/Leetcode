class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if(nums.empty())
        {
            return 0;
        }
        
        int result = 0, currSum = 0;
        unordered_map<int, int> hashMap;
        for(int i = 0;i < nums.size();i++)
        {
            currSum += nums[i];
            if(currSum == k)
            {
                result = i + 1;
            }
            else
            {
                if(hashMap.count(currSum - k))
                {
                    result = max(result, i - hashMap[currSum - k]);
                }
            }
            
            if(!hashMap.count(currSum))
            {
                hashMap[currSum] = i;
            }
        }
        
        return result;
    }
};