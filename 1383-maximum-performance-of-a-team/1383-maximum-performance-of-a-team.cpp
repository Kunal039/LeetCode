class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> engineers(n);
        for (int i = 0; i < n; i++) {
            engineers[i] = {efficiency[i], speed[i]};
        }
        
        sort(engineers.rbegin(), engineers.rend());

        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        long long currentSpeedSum = 0;
        long long maxPerf = 0;

        for (const auto& [eff, spd] : engineers) {
            minHeap.push(spd);
            currentSpeedSum += spd;

            if (minHeap.size() > k) {
                currentSpeedSum -= minHeap.top();
                minHeap.pop();
            }

            maxPerf = max(maxPerf, currentSpeedSum * eff);
        }

        const int MOD = 1e9 + 7;
        return maxPerf % MOD;
    }
};