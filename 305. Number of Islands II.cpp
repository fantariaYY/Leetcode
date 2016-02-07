class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    	int *id = new int[m * n];
    	int *sz = new int[m * n];
    
    	for (int i = 0; i < m * n; ++i)
    	{
    		id[i] = i;
    		sz[i] = 0;
    	}
    
    	vector<int> result;
    	int count = 0;
    	vector<pair<int, int>> offset = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    	for (int i = 0; i < positions.size(); i++)
    	{
    		int index = coord2ind(positions[i].first, positions[i].second, n);
    		sz[index] = 1;
    
    		count++;
    		for (int j = 0; j < 4; j++)
    		{
    			if (positions[i].first + offset[j].first >= 0 && positions[i].first + offset[j].first < m && positions[i].second + offset[j].second >= 0 && positions[i].second + offset[j].second < n)
    			{
    				int newIndex = coord2ind(positions[i].first + offset[j].first, positions[i].second + offset[j].second, n);
    				if (newIndex >= 0 && newIndex < m * n && sz[newIndex] != 0 && !find(id, index, newIndex))
    				{
    					doUnion(id, sz, index, newIndex);
    					count--;
    				}
    			}
    		}
    
    		result.push_back(count);
    	}
    
    	delete id;
    	delete sz;
    	return result;
    }
    
    int root(int* id, int p)
    {
    	while (p != id[p])
    	{
    		id[p] = id[id[p]];
    		p = id[p];
    	}
    
    	return p;
    }
    
    void doUnion(int* id, int* sz, int p, int q)
    {
    	int pRoot = root(id, p), qRoot = root(id, q);
    	if (sz[pRoot] > sz[qRoot])
    	{
    		id[qRoot] = pRoot;
    		sz[pRoot] += sz[qRoot];
    	}
    	else
    	{
    		id[pRoot] = qRoot;
    		sz[qRoot] += sz[pRoot];
    	}
    }
    
    bool find(int* id, int p, int q)
    {
    	return root(id, p) == root(id, q);
    }
    
    int coord2ind(int i, int j, int n)
    {
    	return i * n + j;
    }
};