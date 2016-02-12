class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        if(l1 + l2 != l3)
        {
            return false;
        }
        
        if(s1.empty())
        {
            return s2 == s3;
        }
        
        if(s2.empty())
        {
            return s1 == s3;
        }
        
        vector<vector<bool>> opt(l1 + 1, vector<bool>(l2 + 1, false));
        opt[0][0] = true;
        
        for(int i = 0;i < l1;i++)
        {
            if(s1[i] == s3[i])
            {
                opt[i + 1][0] = true;
            }
            else
            {
                break;
            }
        }
        
        for(int j = 0;j < l2;j++)
        {
            if(s2[j] == s3[j])
            {
                opt[0][j + 1] = true;
            }
            else
            {
                break;
            }
        }
        
        for(int i = 1;i < l1 + 1;i++)
        {
            for(int j = 1;j < l2 + 1;j++)
            {
                opt[i][j] = (opt[i][j - 1] && (s2[j - 1] == s3[i + j - 1])) || (opt[i - 1][j] && (s1[i - 1] == s3[i + j - 1]));
            }
        }
        
        return opt[l1][l2];
    }
};