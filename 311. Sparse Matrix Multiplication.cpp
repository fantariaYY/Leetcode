class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), n = A[0].size(), l = B[0].size();
        
        vector<vector<int>> result(m, vector<int>(l, 0));
        
        unordered_map<int, unordered_set<int>> denseA;
        for(int i = 0;i < m;++i)
        {
            for(int j = 0;j < n;++j)
            {
                if(A[i][j] != 0)
                {
                    denseA[i].insert(j);
                }
            }
        }
        
        unordered_map<int, unordered_set<int>> denseB;
        for(int i = 0;i < n;++i)
        {
            for(int j = 0;j < l;++j)
            {
                if(B[i][j] != 0)
                {
                    denseB[j].insert(i);
                }
            }
        }
        
        for(int i = 0;i < m; ++i)
        {
            for(int j = 0;j < l; ++j)
            {
                if(denseA.count(i) && denseB.count(j))
                {
                    for(auto k = denseA[i].begin();k != denseA[i].end();k++)
                    {
                        if(denseB[j].count(*k))
                        {
                            result[i][j] += A[i][*k] * B[*k][j];
                        }
                    }
                }
            }
        }
        
        return result;
    }
};