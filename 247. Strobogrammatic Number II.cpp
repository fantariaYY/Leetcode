class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> match = {"00", "11", "88", "69", "96"};
        vector<string> start;
        if(n & 1)
        {
            start = {"0", "1", "8"};
        }
        else
        {
            start = {""};
        }
        
        while(n > 1)
        {
            n -= 2;
            vector<string> tmp;
            for(int i = 0;i < start.size();i++)
            {
                for(int j = (n < 2 ? 1 : 0);j < match.size();j++)
                {
                    tmp.push_back(match[j].substr(0, 1) + start[i] + match[j].substr(1));
                }
            }
            
            start = tmp;
        }
        
        return start;
    }
};