class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> meetings;
        for(int i = 0; i < n; i++) {
            meetings.push_back({end[i], start[i]});
        }
        sort(meetings.begin(), meetings.end());
        
        int ans = 0;
        int prevEnd = -1;
        for(int i = 0; i < n; i++) {
            int s = meetings[i].second, e = meetings[i].first;
            if(s > prevEnd) {
                ans++;
                prevEnd = e;
            }
        }
        return ans;
    }
};