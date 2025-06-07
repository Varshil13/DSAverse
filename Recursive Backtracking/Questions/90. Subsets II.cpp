class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> sol;
        backtrack( nums,res,sol,0);
        return res;
    }

    void backtrack(vector<int>& nums,vector<vector<int>>&res,vector<int> &sol, int start){
        if(start == nums.size()) {
            res.push_back(sol);
            return;
        }

        sol.push_back(nums[start]);
        backtrack(nums,res,sol,start+1);
        sol.pop_back();
        int index = start+1;
        while(index <nums.size() && nums[index-1] == nums[index]){
            index++;
        }
        backtrack(nums,res,sol,index);
        


    }


   

};