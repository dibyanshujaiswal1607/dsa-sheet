bool isValidWord(string &s, int start, int end, vector<string> &dictionary) {
	string word = s.substr(start, end - start + 1);
	for(int i = 0; i < dictionary.size(); i++) {
		if(word == dictionary[i]) {
			return true;
		}
	}
	return false;
}
void helper(int index, string &s, vector<string> &dictionary, vector<string> &t, vector<string> &ans) {
	if(index == s.size()) {
		string temp = "";
		for(int i = 0; i < t.size(); i++) {
			temp += t[i] + " ";
		}
		ans.push_back(temp);
		return;
	}
	for(int i = index; i < s.size(); i++) {
		if(isValidWord(s, index, i, dictionary)) {
			t.push_back(s.substr(index, i - index + 1));
			helper(i + 1, s, dictionary, t, ans);
			t.pop_back();
		}
	}
}
vector<string> wordBreak(string &s, vector<string> &dictionary) {
    // Write your code here
	vector<string> ans, t;
	helper(0, s, dictionary, t, ans);
	return ans;
}