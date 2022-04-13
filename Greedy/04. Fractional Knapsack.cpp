bool compare(Item &a, Item &b) {
    // a.value/a.weight > b.value/b.weight
    return a.value * b.weight > b.value * a.weight;
}
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n) {
        // Your code here
        sort(arr, arr + n, compare);
        double ans = 0.0;
        for(int i = 0; i < n; i++) {
            if(arr[i].weight <= W) {
                ans += arr[i].value;
                W -= arr[i].weight;
            } else {
                ans += W * (arr[i].value / (arr[i].weight * 1.0));
                W = 0;
                break;
            }
        }
        return ans;
    }
        
};