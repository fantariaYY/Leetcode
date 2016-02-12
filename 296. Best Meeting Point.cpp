class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<int> row, column;
        for(int i = 0;i < grid.size();i++)
        {
            for(int j = 0;j < grid[0].size();j++)
            {
                if(grid[i][j])
                {
                    row.push_back(i);
                    column.push_back(j);
                }
            }
        }
        
        return getMin(row) + getMin(column);
    }
    
    int getMin(vector<int> &vec)
    {
        sort(vec.begin(), vec.end());
        int i = 0, j = vec.size() - 1;
        
        int result = 0;
        while(i < j)
        {
            result += vec[j--] - vec[i++];    
        }
        
        return result;
    }
};