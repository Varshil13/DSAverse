

//this is memoization solution
// in this code we are storing th e results of subproblems in a dp array to avoid recomputation
//the time complexity is O(n) which is very fast as the fully recursive code and space complexity is O(n) due to the dp array
class Solution {

    int helper(int n , vector<int>&dp){
         if(n == 0) return 1;
        if(n == 1) return 1;
        if(dp[n] != -1) return dp[n];
        int left = helper(n-1,dp);
        int right = helper(n-2,dp);
    
        dp[n] = left + right;
        return dp[n];

    }

public:
    int climbStairs(int n) {


        vector<int> dp(n + 1, -1);
        return helper(n,dp);
    }
};

//this is a bottom up dynamic programming solution called tabulation
// in this code we are storing the results of subproblems in a dp array to avoid recomputation
//the time complexity is O(n) which is very fast as the fully recursive code and space complexity is O(n) due to the dp array
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2 ; i <= n ; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
        
        
    }
};
