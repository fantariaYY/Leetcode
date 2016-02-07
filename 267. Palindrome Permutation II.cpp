class Solution {
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> count;
        bool isOdd = false;
        
        for(int i = 0;i < s.length(); i++)
        {
            count[s[i]]++;
        }
        
        char odd;
        vector<string> result;
        vector<char> charSet;
        for(auto it = count.begin();it != count.end();it++)
        {
            if(it->second % 2)
            {
                if(isOdd)
                {
                    return result;
                }
                
                odd = it->first;
                isOdd = true;
            }

            for(int j = 0;j < it->second / 2;j++)
            {
                charSet.push_back(it->first);
            }
        }
        
        sort(charSet.begin(), charSet.end());
        vector<bool> visited(charSet.size(), false);
        generate(result, "", charSet, visited, isOdd, odd);
        
        return result;
    }
    
    void generate(vector<string> &result, string curr, vector<char> &charSet, vector<bool> &visited, bool isOdd, char odd)
    {
        if(curr.length() == charSet.size())
        {
            string tmp = curr;
            reverse(tmp.begin(), tmp.end());
            
            if(isOdd)
            {
                curr.push_back(odd);
            }
            
            curr += tmp;
            result.push_back(curr);
            return;
        }
        
        for(int i = 0;i < charSet.size();i++)
        {
            if(visited[i] || (i > 0 && charSet[i] == charSet[i - 1] && !visited[i - 1]))
            {
                continue;
            }
            
            visited[i] = true;
            curr += charSet[i];
            generate(result, curr, charSet, visited, isOdd, odd);
            curr = curr.substr(0, curr.length() - 1);
            visited[i] = false;
        }
    }
};