class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.empty() || rooms[0].empty())
        {
            return;
        }
        
        int n = rooms.size(), m = rooms[0].size();
        
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(rooms[i][j] == 0)
                {
                    dfs(rooms, i, j, 0);
                }
            }
        }
    }
    
    void dfs(vector<vector<int>> &rooms, int i, int j, int dist)
    {
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        
        for(int k = 0;k < 4; ++k)
        {
            int newi = i + dx[k], newj = j + dy[k];
            if(newi >= 0 && newi < rooms.size() && newj >= 0 && newj < rooms[0].size() && rooms[newi][newj] != -1 && rooms[newi][newj] > dist + 1)
            {
                rooms[newi][newj] = dist + 1;
                dfs(rooms, newi, newj, dist + 1);
            }
        }
    }
};