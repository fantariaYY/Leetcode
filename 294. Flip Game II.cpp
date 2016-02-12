class Solution {
public:
    bool canWin(string s) {
        if(s.empty())
        {
            return false;
        }
        
        for(int i = 0;i < s.length() - 1; ++i)
        {
            if(s[i] == '+' && s[i + 1] == '+')
            {
                s[i] = '-';
                s[i + 1] = '-';
                if(!canWin(s))
                {
                    return true;
                }
                
                s[i] = '+';
                s[i + 1] = '+';
            }
        }
        
        return false;
    }
};