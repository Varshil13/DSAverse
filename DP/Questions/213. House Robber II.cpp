class Solution {
public:


    int rob1(vector<int>& nums) {

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
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> a,b;
        for(int i = 0 ; i < n ; i ++){
            if(i!=0){
                a.push_back(nums[i]);
            }
            if(i!=n-1){
                b.push_back(nums[i]);
            }
        }
            return max(rob1(a),rob1(b));

        
    }
};