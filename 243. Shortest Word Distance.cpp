class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        unordered_map<string, int> hashMap;
        int result = INT_MAX;
        for(int i = 0;i < words.size();i++)
        {
            if(words[i] == word1)
            {
                if(hashMap.count(word2))
                {
                    result = min(result, i - hashMap[word2]);
                }

                hashMap[word1] = i;
                
            }
            else
            {
                if(words[i] == word2)
                {
                    if(hashMap.count(word1))
                    {
                        result = min(result, i - hashMap[word1]);
                    }
                    
                    hashMap[word2] = i;
                }
            }
        }
        
        return result;
    }
};