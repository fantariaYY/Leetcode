class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        vector<vector<int>> opt(l1 + 1, vector<int>(l2 + 1, 0));
        
        for(int i = 0;i <= l1;i++)
        {
            opt[i][0] = i;
        }
        
        for(int i = 1; i <= l2;i++)
        {
            opt[0][i] = i;
        }
        
        for(int i = 0;i < l1;i++)
        {
            for(int j = 0;j < l2;j++)
            {
                int k = word1[i] != word2[j];
                opt[i + 1][j + 1] = min(min(opt[i][j] + k, opt[i][j + 1] + 1), opt[i + 1][j] + 1);
            }
        }
        
        return opt[l1][l2];
    }
};