class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort (nums.begin(), nums.end());

        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (target == nums[mid]) return true;

            else if (target < nums[mid]) high = mid - 1;

            else low = mid + 1;
        }

        return false;
    }
};