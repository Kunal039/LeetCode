class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int f = 0, r = nums.size() - 1;

        while (f<r) {
            int mid = f+(r-f)/2;

            if(nums[mid] < nums[r]) {
                r = mid;
            }

            else if(nums[mid] > nums[r]) {
                f = mid+1;
            }

            else {
                r--;
            }
        }

        return nums[f];
    }
};