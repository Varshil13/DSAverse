/*
The approach to find the next lexographically greater permutation is a bit tricky.
The idea is to find the first pair of adjacent elements from last (i, i+1) such that nums[i] < nums[i+1].
Once we find such a pair, we need to find the smallest element in the suffix (i+1 to end) that is greater than nums[i] and swap them.
Finally, it will become from [1,2,3,6,5,4] to [1,2,4,6,5,3] now we need to reverse the suffix or sort it to get the next permutation.
Time Complexity: O(n) 
*/



class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin()+i+1, nums.end());
    }
};
