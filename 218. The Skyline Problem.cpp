class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> height;
        for(auto it = buildings.begin();it != buildings.end();it++)
        {
            height.push_back(make_pair((*it)[0], -(*it)[2]));
            height.push_back(make_pair((*it)[1], (*it)[2]));
        }
        
        sort(height.begin(), height.end());
        
        multiset<int> heap;
        heap.insert(0);
        
        vector<pair<int, int>> result;
        int curr = 0, prev = 0;
        for(int i = 0;i < height.size();i++)
        {
            if(height[i].second < 0)
            {
                heap.insert(-height[i].second);
            }
            else
            {
                heap.erase(heap.find(height[i].second));
            }
            
            curr = *heap.rbegin();
            if(curr != prev)
            {
                result.push_back(make_pair(height[i].first, curr));
                prev = curr;
            }
        }

        return result;        
    }
};