class Solution{
    public:
    void helper(int i, int j, string path, vector<vector<int>> &m, int n, vector<string> &ans, int di[], int dj[]) {
        if(i == n - 1 and j == n - 1) {
            ans.push_back(path);
            return;
        }
        string dir = "DLRU";
        for(int ind = 0; ind < 4; ind++) {
            int nexti = i + di[ind];
            int nextj = j + dj[ind];
            if(nexti >= 0 and nexti < n and nextj >= 0 and nextj < n and m[nexti][nextj] == 1) {
                m[i][j] = 2;
                helper(nexti, nextj, path + dir[ind], m, n, ans, di, dj);
                m[i][j] = 1;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        if(m[0][0] == 1) {
            // note
            m[0][0] = 2;
            helper(0, 0, "", m, n, ans, di, dj);
        }
        return ans;
    }
};