class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if(preorder.size() == 0)
        {
            return true;
        }
        
        int max = INT_MIN;
        stack<int> s;
        
        for(int i = 0;i < preorder.size(); ++i)
        {
            if(preorder[i] < max)
            {
                return false;
            }
            
            while(!s.empty() && preorder[i] > s.top())
            {
                max = s.top();
                s.pop();
            }
            
            s.push(preorder[i]);
        }
        
        return true;
    }
};