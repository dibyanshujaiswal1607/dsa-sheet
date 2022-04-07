#include<bits/stdc++.h> 
using namespace std;

class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > matrix, int n, int m, int x) 
    {
        // code here 
        // setting index to top-right
        int i = 0, j = m - 1;
        while(i < n and j >= 0) {
            if(matrix[i][j] == x) {
                return true;
            } else if(matrix[i][j] < x) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
};