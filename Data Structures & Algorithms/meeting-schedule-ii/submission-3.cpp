/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int,int> mp;
        for(int i = 0 ; i<intervals.size(); i++){
            mp[intervals[i].start]++;
            mp[intervals[i].end]--;
        }
        int rooms = 0;
        int sum = 0;
        for(auto& d : mp){
            sum+=d.second;
            rooms= max(rooms,sum);
        }
        return rooms;
    }
};
