class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        
        vector<int> opt(m, 1);

        opt[0] = obstacleGrid[0][0] != 1;
        for(int i = 1;i < m;i++)
        {
            if(obstacleGrid[0][i] == 1)
            {
                opt[i] = 0;
            }
            else
            {
                opt[i] = opt[i - 1];
            }
        }
        
        for(int i = 1;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    opt[j] = 0;
                    continue;
                }
                
                if(j == 0)
                {
                    continue;
                }
                
                opt[j] = opt[j - 1] + opt[j];
            }
        }
        
        return opt[m - 1];
    }
};