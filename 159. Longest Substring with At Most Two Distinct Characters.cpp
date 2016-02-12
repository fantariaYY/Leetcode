class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int result = 0;
        unordered_map<char, int> hashMap;
        
        int i = 0, j = 0;
        for(;i < s.length();i++)
        {
            while(j < s.length())
            {
                if(!hashMap.count(s[j]))
                {
                    if(hashMap.size() == 2)
                    {
                        break;
                    }
                }
                
                hashMap[s[j]]++;
                j++;
            }
            
            result = max(result, j - i);
            hashMap[s[i]]--;
            if(hashMap[s[i]] == 0)
            {
                hashMap.erase(s[i]);
            }
        }
        
        return result;
    }
};