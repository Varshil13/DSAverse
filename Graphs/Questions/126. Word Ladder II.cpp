class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        unordered_set<string> visitedThisLevel;
        int level = 0;
        vector<vector<string>> ans;

        while (!q.empty()) {
            vector<string> path = q.front(); q.pop();
            if (path.size() > level) {
                level++;
                for (auto& w : visitedThisLevel) {
                    st.erase(w);
                }
                visitedThisLevel.clear();
            }

            string word = path.back();
            if (word == endWord) {
                if (ans.empty()) ans.push_back(path);
                else if (ans[0].size() == path.size()) ans.push_back(path);
            }

            for (int i = 0; i < word.size(); ++i) {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    word[i] = c;
                    if (st.count(word)) {
                        path.push_back(word);
                        q.push(path);
                        visitedThisLevel.insert(word);
                        path.pop_back();
                    }
                }
                word[i] = original;
            }
        }

        return ans;
    }
};
