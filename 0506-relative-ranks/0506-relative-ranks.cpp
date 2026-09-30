class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> sorted_scores(n);
        for (int i = 0; i < n; ++i) {
            sorted_scores[i] = {score[i], i};
        }

        sort(sorted_scores.rbegin(), sorted_scores.rend());

        vector<string> answer(n);
        for (int i = 0; i < n; ++i) {
            int original_index = sorted_scores[i].second;
            if (i == 0) {
                answer[original_index] = "Gold Medal";
            } else if (i == 1) {
                answer[original_index] = "Silver Medal";
            } else if (i == 2) {
                answer[original_index] = "Bronze Medal";
            } else {
                answer[original_index] = to_string(i + 1);
            }
        }

        return answer;
    }
};