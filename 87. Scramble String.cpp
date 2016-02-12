class Solution {
public:
    bool isScramble(string s1, string s2) {
        int l1 = s1.length(), l2 = s2.length();
        if(l1 != l2)
        {
            return false;
        }
        
        if(l1 == 0 && l2 == 0)
        {
            return true;
        }
        
        vector<vector<vector<bool>>> opt(l1, vector<vector<bool>>(l1, vector<bool>(l1 + 1, 0)));
        
        for(int k = 1;k <= l1;k++)
        {
            for(int i = 0;i <= l1 - k;i++)
            {
                for(int j = 0;j <= l1 - k;j++)
                {
                    if(k == 1)
                    {
                        opt[i][j][k] = (s1[i] == s2[j]);
                        continue;
                    }
                    
                    opt[i][j][k] = false;
                    
                    for(int l = 1;l <= k - 1;l++)
                    {
                        if((opt[i][j][l] && opt[i + l][j + l][k - l]) || (opt[i][j + k - l][l] && opt[i + l][j][k - l]))
                        {
                            opt[i][j][k] = true;
                            break;
                        }
                    }
                }
            }
        }
        
        return opt[0][0][l1];
    }
};