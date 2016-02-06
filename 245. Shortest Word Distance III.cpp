class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int index1 = -1, index2 = -1;
        
        int result = INT_MAX;
        for(int i = 0;i < words.size();i++)
        {
            if(words[i] == word1)
            {
                index1 = i;
                if(index2 != -1)
                {
                    result = min(result, index1 - index2);
                }
            }
            
            if(words[i] == word2)
            {
                index2 = i;
                if(index1 != -1)
                {
                    result = (index1 == index2) ? result : min(result, index2 - index1);
                }
            }
        }
        
        return result;
    }
};