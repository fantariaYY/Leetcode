class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int n = image.size();
        int m = image[0].size();
        
        int left = searchRow(image, 0, y, true);
        int right = searchRow(image, y + 1, m, false);
        int top = searchCol(image, 0, x, true);
        int bottom = searchCol(image, x + 1, n, false);
        
        return (right - left) * (bottom - top);
    }
    
    int searchRow(vector<vector<char>>& image, int start, int end, bool left)
    {
        int n = image.size();
        while(start < end)
        {
            int mid = start + (end - start) / 2;
            int k = 0;
            while(k < n && image[k][mid] == '0')
            {
                k++;
            }
            
            if(k < n == left)
            {
                end = mid; 
            }
            else
            {
                start = mid + 1;
            }
        }
        
        return start;
    }
    
    int searchCol(vector<vector<char>>& image, int start, int end, bool top)
    {
        int n = image[0].size();
        while(start < end)
        {
            int mid = start + (end - start) / 2;
            int k = 0;
            while(k < n && image[mid][k] == '0')
            {
                k++;
            }
            
            if(k < n == top)
            {
                end = mid; 
            }
            else
            {
                start = mid + 1;
            }
        }
        
        return start;
    }
};