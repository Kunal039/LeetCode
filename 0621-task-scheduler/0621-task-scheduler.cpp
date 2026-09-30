class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        std::unordered_map<char, int> freq;
        int maxFreq = 0;
        for (char task : tasks) {
            freq[task]++;
            maxFreq = std::max(maxFreq, freq[task]);
        }
        int maxFreqCount = 0;
        for (const auto& pair : freq) {
            if (pair.second == maxFreq) {
                maxFreqCount++;
            }
        }
        int intervals = (maxFreq - 1) * (n + 1) + maxFreqCount;
        return std::max(intervals, static_cast<int>(tasks.size()));
    }
};