class Solution {
    int quickSelect(vector<int>& nums, int l, int r, int k) {
        if (l == r) {
            if (l == k) return nums[k];
            else return -1;
        }
        int rand_i = l + rand()%(r-l+1);
        swap(nums[rand_i], nums[r]);
        int p = l;
        for (int i = l; i < r; i++) {
            if (nums[i] < nums[r]) {
                swap(nums[i], nums[p]);
                p++;
            }
        }
        swap(nums[r], nums[p]);
        // call on either left or right range if required
        if (p == k) return nums[p];
        else if (p < k) {
            return quickSelect(nums, p+1, r, k);
        }
        else return quickSelect(nums, l, p-1, k);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickSelect(nums, 0, n-1, n-k);
    }
};
