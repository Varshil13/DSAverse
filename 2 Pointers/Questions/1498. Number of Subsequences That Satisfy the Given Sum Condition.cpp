/*
This question asks for the number of subsequences in a sorted array
that satisfy the condition: the sum of the minimum and maximum elements is less than or equal to a given target.

A brute-force approach using recursion to generate all subsequences would be inefficient.
Instead, a two-pointer approach is used:
- Maintain two pointers (left and right) to represent the current minimum and maximum elements.
- If nums[left] + nums[right] <= target, all subsequences formed by choosing any subset of elements between left and right (inclusive) are valid.
- The number of such subsequences is 2^(right - left), since each element between left and right can be either included or not.
- Increment left to consider the next minimum; otherwise, decrement right to reduce the maximum.
- Repeat until left > right.

The total number of valid subsequences is accumulated in 'ans' and returned.
*/
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int mod = 1e9 + 7;
        int left = 0, right = nums.size() - 1;
        int ans = 0;

        vector<int> pow2(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i)
            pow2[i] = (pow2[i - 1] * 2) % mod;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                ans = (ans + pow2[right - left]) % mod;
                ++left;
            } else {
                --right;
            }
        }

        return ans;
    }
};
