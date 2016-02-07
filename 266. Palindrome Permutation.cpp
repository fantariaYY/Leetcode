class Solution {
public:
    bool canPermutePalindrome(string s) {
        int charCount[256] = { 0 };
        
        for(int i = 0;i < s.length(); ++i)
        {
            int index = (int)s[i];
            charCount[index]++;
        }
        
        bool hasOdd = false;
        for(int i = 0;i < 256;i++)
        {
            if(charCount[i] % 2)
            {
                if(hasOdd)
                {
                    return false;
                }
                
                hasOdd = true;
            }
        }
        
        return true;
    }
};