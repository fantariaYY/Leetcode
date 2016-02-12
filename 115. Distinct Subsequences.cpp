class Solution {
public:
    int numDistinct(string s, string t) {
        int l1 = s.length(), l2 = t.length();
        vector<vector<int>> opt(l2 + 1, vector<int>(l1 + 1, 0));
        
        for(int i = 1;i < l2 + 1;i++)
        {
            opt[i][0] = 0;
        }
        
        for(int i = 0;i < l1 + 1;i++)
        {
            opt[0][i] = 1;    
        }
        
        for(int i = 1;i < l2 + 1;i++)
        {
            for(int j = 1;j < l1 + 1;j++)
            {
                opt[i][j] = opt[i][j - 1];
                if(s[j - 1] == t[i - 1])
                {
                    opt[i][j] += opt[i - 1][j - 1];
                }
            }
        }
        
        return opt[l2][l1];
    }
};