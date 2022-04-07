#include <bits/stdc++.h>
using namespace std;

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<vector<bool>> vis(r, vector<bool>(c));
        // R -> D, D -> L, L -> U, U -> R
        char direction = 'R';
        vector<int> res;
        int i = 0, j = 0;
        while(res.size() != r*c) {
            res.push_back(matrix[i][j]);
            vis[i][j] = 1;
            switch(direction) {
                case 'R':
                    if(j + 1 < c and !vis[i][j + 1]) {
                        j++;
                    } else {
                        direction = 'D';
                        i++;
                    }
                    break;
                case 'D':
                    if(i + 1 < r and !vis[i + 1][j]) {
                        i++;
                    } else {
                        direction = 'L';
                        j--;
                    }
                    break;
                case 'L':
                    if(j - 1 >= 0 and !vis[i][j - 1]) {
                        j--;
                    } else {
                        direction = 'U';
                        i--;
                    }
                    break;
                case 'U':
                    if(i - 1 >= 0 and !vis[i - 1][j]) {
                        i--;
                    } else {
                        direction = 'R';
                        j++;
                    }
                    break;
            }
        }
        return res;
    }
};