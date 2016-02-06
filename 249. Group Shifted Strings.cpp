class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> hashMap;
        
        for(int i = 0;i < strings.size();i++)
        {
            string key = "";
            for(int j = 1;j < strings[i].length();j++)
            {
                key += to_string((strings[i][j] - strings[i][j - 1] + 26) % 26);
            }
            
            if(!hashMap.count(key))
            {
                vector<string> tmp;
                hashMap[key] = tmp;
            }
            
            hashMap[key].push_back(strings[i]);
        }
        
        vector<vector<string>> result;
        for(auto it = hashMap.begin();it != hashMap.end();it++)
        {
            sort(it->second.begin(), it->second.end());
            result.push_back(it->second);
        }
        
        return result;
    }
};