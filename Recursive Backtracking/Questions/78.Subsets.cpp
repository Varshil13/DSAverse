class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        
        vector<vector<int>> res;
        vector<int> sol;
        int i = 0;
        backtrack(nums, i, sol, res);
        return res;
    }
 
private:
    // void backtrack(vector<int>& nums, int start, vector<int>& sol, vector<vector<int>>& res) {
    //     res.push_back(sol);
    //     for (int i = start; i < nums.size(); i++) {
    //         sol.push_back(nums[i]);
    //         backtrack(nums, i + 1, sol, res);
    //         sol.pop_back();
    //     }
    // }

    void backtrack(vector<int>& nums, int start, vector<int>& sol, vector<vector<int>>& res) {
       if (start == nums.size()) {
        res.push_back(sol); 
        return;
    }
        sol.push_back(nums[start]);
        backtrack(nums,start+1,sol,res);
        sol.pop_back();

        int index = start+1;
        while(index!=nums.size() && nums[index] == nums[index-1]){
            index ++;   
        }
        backtrack(nums,index,sol,res);

    }
        
    
};