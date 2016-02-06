class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        int *id = new int[n];
        int *sz = new int[n];
        
        for(int i = 0;i < n;i++)
        {
            id[i] = i;
            sz[i] = 1;
        }
        
        for(int i = 0;i < edges.size(); ++i)
        {
            if(find(id, edges[i].first, edges[i].second))
            {
                return false;
            }
            else
            {
                Union(id, sz, edges[i].first, edges[i].second);
            }
        }
        
        int count = 0;
        
        for(int i = 0;i < n;i++)
        {
            if(i == id[i])
            {
                count++;
            }
            
            if(count > 1)
            {
                return false;
            }
        }
        
        return true;
    }
    
    int root(int* id, int i)
    {
        while(i != id[i])
        {
            id[i] = id[id[i]];
            i = id[i];
        }
        
        return i;
    }
    
    void Union(int* id, int* sz, int i, int j)
    {
        int iroot = root(id, i);
        int jroot = root(id, j);
        if(sz[iroot] > sz[jroot])
        {
            id[jroot] = id[iroot];
            sz[iroot] += sz[jroot];
        }
        else
        {
            id[iroot] = id[jroot];
            sz[jroot] += sz[iroot];
        }
    }
    
    bool find(int* id, int p, int q)
    {
        return root(id, p) == root(id, q);
    }
};