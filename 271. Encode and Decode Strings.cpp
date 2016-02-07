class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result = "";
        for(int i = 0;i < strs.size();i++)
        {
            result += to_string(strs[i].length()) + '#' + strs[i];
        }
        
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
    	int i = 0;
    	while (i < s.length())
    	{
    		int start = i;
    		while (s[i] != '#')
    		{
    			i++;
    		}
    
    		int len = stoi(s.substr(start, i - start));
    		i++;
    		result.push_back(s.substr(i, len));
    		i += len;
    	}
    
    	return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));