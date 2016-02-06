class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for(int i = 0;i < words.size(); ++i)
        {
            if(!hashMap.count(words[i]))
            {
                vector<int> tmp;
                hashMap[words[i]] = tmp;
            }
            hashMap[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        vector<int> list1 = hashMap[word1];
        vector<int> list2 = hashMap[word2];
        int result = INT_MAX;
        
        for(int i = 0, j = 0;i < list1.size() && j < list2.size();)
        {
            result = min(result, abs(list1[i] - list2[j]));
            if(list1[i] > list2[j])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        
        return result;
    }

private:
    unordered_map<string, vector<int>> hashMap;
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");