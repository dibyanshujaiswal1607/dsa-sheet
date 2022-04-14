class Solution {
public:
    bool isPalindrome(string &s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
    void helper(int ind, string &s, vector<string> &t, vector<vector<string>> &ans) {
        if(ind == s.size()) {
            ans.push_back(t);
            return;
        }
        for(int i = ind; i < s.size(); i++) {
            if(isPalindrome(s, ind, i)) {
                t.push_back(s.substr(ind, i - ind + 1));
                helper(i + 1, s, t, ans);
                t.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> t;
        helper(0, s, t, ans);
        return ans;
    }
};