class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;
        queue<string> q;
        q.push(beginWord);
        int steps = 1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string curr = q.front();
                q.pop();
                if (curr == endWord) return steps;
                for (int i = 0; i < curr.length(); ++i) {
                    char orig = curr[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        curr[i] = c;
                        if (dict.count(curr)) {
                            q.push(curr);
                            dict.erase(curr);
                        }
                    }
                    curr[i] = orig;
                }
            }
            steps++;
        }
        return 0;
    }
};