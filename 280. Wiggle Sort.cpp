class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() <= 1)
        {
            return;
        }
        
        bool isGreater = true;
        
        for(int i = 1;i < nums.size(); ++i)
        {
            if(isGreater)
            {
                if(nums[i] < nums[i - 1])
                {
                    swap(nums[i], nums[i - 1]);
                }
            }
            else
            {
                if(nums[i] > nums[i - 1])
                {
                    swap(nums[i], nums[i - 1]);
                }
            }
            
            isGreater = !isGreater;
        }
    }
};