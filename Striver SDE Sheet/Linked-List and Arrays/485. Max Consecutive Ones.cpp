/*
Easy code no need for any explanation
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0; 
        int curr = 0;
        for(int x : nums){
            if(x==1){
                curr++;
                maxi = max(maxi , curr);
            }
            if(x==0){
                curr = 0;
            }
        }
        return maxi;
        
    }
};