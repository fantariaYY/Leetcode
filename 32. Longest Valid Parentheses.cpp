class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length(), result = 0;
        vector<int> opt(n + 1, 0);
        
        for(int i = 1;i <= n; ++i)
        {
            int j = i - 2 - opt[i - 1];
            if(s[i - 1] == '(' || j < 0 || s[j] == ')')
            {
                opt[i] = 0;
            }
            else
            {
                opt[i] = opt[i - 1] + 2 + opt[j];
                result = max(result, opt[i]);
            }
        }
        
        return result;
    }
};