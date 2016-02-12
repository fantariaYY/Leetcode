class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> result;
        if(s.length() <= 1)
        {
            return result;
        }
        
        string sol = s;
        
        for(int i = 0;i < s.length() - 1;i++)
        {
            if(s[i] == '+' && s[i + 1] == '+')
            {
                sol[i] = '-';
                sol[i + 1] = '-';
                result.push_back(sol);
                sol = s;
            }
        }
        
        return result;
    }
};