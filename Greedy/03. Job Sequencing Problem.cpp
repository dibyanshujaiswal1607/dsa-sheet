bool compare(Job &a, Job &b) {
    return a.profit > b.profit;
}
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) { 
        // your code here
        sort(arr, arr + n, compare);
        
        int mx = arr[0].dead;
        for(int i = 1; i < n; i++) {
            mx = max(mx, arr[i].dead);
        }
        
        vector<int> slot(mx + 1, -1);
        int ans = 0, cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = arr[i].dead; j > 0; j--) {
                if(slot[j] == -1) {
                    slot[j] = arr[i].id;
                    cnt++;
                    ans += arr[i].profit;
                    break;
                }
            }
        }
        return {cnt, ans};
    } 
};