// Question:
// Given N meetings with their start and end times, 
// find the maximum number of meetings that can be accommodated 
// in a single meeting room, assuming only one meeting can be held 
// in the room at a particular time. Meetings must not overlap.

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int,int>> meetings;

        for(int i=0;i<start.size();i++) {
            meetings.push_back({end[i],start[i]});
        }
        sort(meetings.begin(),meetings.end());
        
        int count=0;
        int lastvalue=-1;
        for(auto a:meetings) {
            if(a.second>lastvalue) {
                count++;
                lastvalue=a.first;
            }
        }
        return count;
    }
};
