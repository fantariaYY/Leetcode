class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> opt(n, 1);
        
        for(int i = 1;i < m; ++i)
        {
            for(int j = 1;j < n;j++)
            {
                opt[j] = opt[j - 1] + opt[j];
            }
        }
        
        return opt[n - 1];
    }
};