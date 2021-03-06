class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty())
        {
            return 0;
        }
        
        vector<int> opt = triangle.back();
        for(int i = triangle.size() - 2;i >= 0 ;i--)
        {
            for(int j = 0;j < triangle[i].size();j++)
            {
                opt[j] = triangle[i][j] + min(opt[j], opt[j + 1]);
            }
        }
        
        return opt[0];
    }
};