




class Solution {
    private:
    int helper(vector<int>& nums , int n ,vector<int> & dp){
        if (n == 0) return nums[0];
        if (n == -1) return 0;
        if(dp[n] != -1) return dp[n];
        int l = nums[n] + helper(nums,n-2,dp);
        int r =  helper(nums,n-1,dp);
         dp[n]=max(l,r);
         return dp[n];

    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        vector<int> dp(n+1,-1);
        return helper(nums,n,dp);
    }
};







class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for(int i = 1; i < n; i++){
            int l = nums[i];
            if(i>1){
               l = l + dp[i-2];
            }
            int r =  dp[i-1];
            dp[i] = max(l,r);
        }
        return dp[n-1];    
    }
};


