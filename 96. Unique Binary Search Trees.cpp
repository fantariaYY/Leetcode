class Solution {
public:
    int numTrees(int n) {
        vector<int> opt(n + 1, 0);
        opt[0] = 1;
        for(int i = 0;i <= n;i++)
        {
            for(int j = 0;j < i;j++)
            {
                opt[i] += opt[j] * opt[i - j - 1];
            }
        }
        
        return opt[n];
    }
};