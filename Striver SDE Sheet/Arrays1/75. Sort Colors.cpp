/*
This is a solution to the problem of sorting an array containing only 0s, 1s, and 2s.
This algorithm is based on counting the occurrences of each number and then filling the array accordingly.
The time complexity is O(2n)=O(n) and the space complexity is O(1) since we are not using any extra space proportional to the input size.
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c0=0;
        int c1=0;
        int c2=0;

        for(int i= 0 ;i < nums.size(); i++){
            if(nums[i] == 0){
                c0++;
            }
            if(nums[i] == 1){
                c1++;
            }
            if(nums[i] == 2){
                c2++;
            }

        }
        for(int i = 0 ; i <c0;i++){
            nums[i] =0;
        }
        for(int i = c0 ; i <c0+c1;i++){
            nums[i] =1;
        }
        for(int i = c0+c1 ; i <c0+c1+c2;i++){
            nums[i] =2;
        }

              
    }
};