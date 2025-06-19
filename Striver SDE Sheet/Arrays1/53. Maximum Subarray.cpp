/**
 * Kadane's Algorithm - Maximum Subarray Sum
 *
 * This function implements Kadane's Algorithm to find the maximum sum of a contiguous subarray
 * within a given integer array `nums`.
 *
 * Algorithm Explanation:
 * - The algorithm maintains two variables:
 *   1. `sum`: The current sum of the subarray being considered.
 *   2. `maxi`: The maximum subarray sum found so far.
 * - Iterate through each element in the array:
 *   - Add the current element to `sum`.
 *   - Update `maxi` if `sum` is greater than the current `maxi`.
 *   - If `sum` becomes negative, reset it to 0. This is because a negative sum will decrease the sum
 *     of any future subarray, so it's better to start a new subarray from the next element.
 * - After the loop, `maxi` contains the maximum subarray sum.
 *
 * Time Complexity: O(n), where n is the number of elements in the array.
 * Space Complexity: O(1), as only a constant amount of extra space is used.
 *
 * Example:
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: The subarray [4,-1,2,1] has the largest sum = 6.
 */

 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxi = INT_MIN;
        for(int i =0 ; i< n ; i++){
            sum = sum + nums[i];
            maxi = max(maxi,sum);
            if(sum<0){
                sum =0;
            }

        }
        return maxi;
    }
};