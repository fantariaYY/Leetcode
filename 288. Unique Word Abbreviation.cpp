class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for(int i = 0;i < dictionary.size(); ++i)
        {
            string key = dictionary[i][0] + to_string(dictionary[i].length() - 2) + dictionary[i][dictionary[i].length() - 1];
            dict[key].insert(dictionary[i]);
        }
    }

    bool isUnique(string word) {
        string key = word[0] + to_string(word.length() - 2) + word[word.size() - 1];
        if(!dict.count(key) || (dict[key].size() == dict[key].count(word)))
        {
            return true;
        }
        
        return false;
    }
    
private:
    unordered_map<string, unordered_set<string>> dict;
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");