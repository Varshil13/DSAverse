//https://leetcode.com/problems/permutations


//code

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> sol ;
        vector<vector<int>> res;
        per(nums,res,0);
        return res;

    }
   void per(vector<int> &nums, vector<vector<int>>&res, int start){
        if(start == nums.size()){
            res.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);           
        per(nums, res, start + 1);  
        swap(nums[start], nums[i]);           
    }

    

    }
    
};



// recursive calls

// per(nums=[1,2,3], start=0)
// │
// ├── swap(0,0) → [1,2,3]
// │   └── per(start=1)
// │       ├── swap(1,1) → [1,2,3]
// │       │   └── per(start=2)
// │       │       ├── swap(2,2) → [1,2,3] ✅ push to res
// │       │       └── backtrack → [1,2,3]
// │       └── swap(1,2) → [1,3,2]
// │           └── per(start=2)
// │               └── swap(2,2) → [1,3,2] ✅ push to res
// │               └── backtrack → [1,2,3]
// │
// ├── swap(0,1) → [2,1,3]
// │   └── per(start=1)
// │       ├── swap(1,1) → [2,1,3]
// │       │   └── per(start=2)
// │       │       └── swap(2,2) → [2,1,3] ✅ push to res
// │       └── swap(1,2) → [2,3,1]
// │           └── per(start=2)
// │               └── swap(2,2) → [2,3,1] ✅ push to res
// │               └── backtrack → [2,1,3]
// │   └── backtrack → [1,2,3]
// │
// └── swap(0,2) → [3,2,1]
//     └── per(start=1)
//         ├── swap(1,1) → [3,2,1]
//         │   └── per(start=2)
//         │       └── swap(2,2) → [3,2,1] ✅ push to res
//         └── swap(1,2) → [3,1,2]
//             └── per(start=2)
//                 └── swap(2,2) → [3,1,2] ✅ push to res
//             └── backtrack → [3,2,1]
//     └── backtrack → [1,2,3]
