class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int starIndex = -1, iIndex = -1;
        
        while(i < s.length())
        {
            if(s[i] == p[j] || p[j] == '?')
            {
                i++;
                j++;
            }
            else
            {
                if(j < p.length() && p[j] == '*')
                {
                    starIndex = j;
                    iIndex = i;
                    j++;
                }
                else
                {
                    if(starIndex != -1)
                    {
                        j = starIndex + 1;
                        i = iIndex + 1;
                        iIndex++;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        
        while(j < p.length() && p[j] == '*')
        {
            j++;
        }
        
        return j == p.length();
    }
};