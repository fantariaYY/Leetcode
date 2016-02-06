/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start;
        vector<int> end;
        
        for(int i = 0;i < intervals.size(); ++i)
        {
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int result = 0;
        int i = 0, j = 0, count = 0;
        while(i != start.size() && j != end.size())
        {
            if(start[i] < end[j])
            {
                count++;
                i++;
            }
            else
            {
                count--;
                j++;
            }
            
            if(count > result)
            {
                result = count;
            }
        }
        
        return result;
    }
};