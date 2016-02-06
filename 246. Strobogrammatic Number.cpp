class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<int, int> match;
        match[0] = 0;
        match[1] = 1;
        match[6] = 9;
        match[9] = 6;
        match[8] = 8;
        
        int i = 0, j = num.size() - 1;
        while(i <= j)
        {
            int num1 = num[i] - '0', num2 = num[j] - '0';
            if(!match.count(num1) || !match.count(num2) || match[num1] != num2)
            {
                return false;
            }
            else
            {
                i++;
                j--;
            }
        }
        
        return true;
    }
};