class Solution {
public:
    int numDecodings(string s) {
        vector<int> opt(s.length(), 0);
        
        if(s.length() == 0 || s[0] == '0')
        {
            return 0;
        }
        
        if(s.length() == 1)
        {
            return s[0] != '0';
        }
        
        opt[0] = (s[0] != '0');
        opt[1] = (s[1] != '0') + isValid(s[0], s[1]);
        
        for(int i = 2;i < s.length();i++)
        {
            if(s[i] != '0')
            {
                opt[i] = opt[i - 1];
            }
            
            if(isValid(s[i - 1], s[i]))
            {
                opt[i] += opt[i - 2];
            }
        }
        
        return opt[s.length() - 1];
    }
    
    bool isValid(char c1, char c2)
    {
        return (c1 == '1') || (c1 == '2' && c2 >= '0' && c2 <= '6');
    }
};