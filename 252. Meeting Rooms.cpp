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
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<int> start;
        vector<int> end;
        
        for(int i = 0;i < intervals.size();i++)
        {
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int i = 0, j = 0;
        int count = 0;
        while(i < intervals.size() && j < intervals.size())
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
            
            if(count > 1)
            {
                return false;
            }
        }
        
        return true;
    }
};