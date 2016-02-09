class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        m_begin.push_back(v1.begin());
        m_begin.push_back(v2.begin());
        m_end.push_back(v1.end());
        m_end.push_back(v2.end());
        
        index = 0;
    }

    int next() {
        while(m_begin[index] == m_end[index])
        {
            index = (index + 1) % m_begin.size();
        }
        
        int result = *m_begin[index];
        m_begin[index]++;
        index = (index + 1) % m_begin.size();
        
        return result;
    }

    bool hasNext() {
        for(int i = 0;i < m_begin.size();i++)
        {
            if(m_begin[i] != m_end[i])
            {
                return true;
            }
        }
        
        return false;
    }
    
    vector<vector<int>::iterator> m_begin;
    vector<vector<int>::iterator> m_end;
    int index;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */