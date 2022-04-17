class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int total = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 0) total++;
                if(grid[i][j] == 2) q.push({i, j});
            }
        }
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        int time = 0, cnt = 0;
        while(!q.empty()) {
            int k = q.size();
            cnt += k;
            while(k--) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 or ny < 0 or nx >= n or ny >= m or grid[nx][ny] != 1)  continue;
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
            if(!q.empty())  time++;
        }
        
        return cnt == total ? time : -1;
    }
};