class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        it = vec2d.begin();
        it_end = vec2d.end();
        index = 0;
    }

    int next() {
        if(hasNext())
        {
            return (*it)[index++];
        }
        else
        {
            return -1;
        }
    }

    bool hasNext() {
        while(it != it_end && index == (*it).size())
        {
            it++;
            index = 0;
        }
        
        return it != it_end;
    }
    
private:
    vector<vector<int>>::iterator it, it_end;
    int index;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */