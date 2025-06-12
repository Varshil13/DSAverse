class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int sum = 0;
        m[0]=-1;
        for(int i = 0 ; i < nums.size();i++){
            sum = sum  + nums[i];
            int x = sum%k;
            if(m.find(x) != m.end()){
                if(i-m[x]>=2){
                    return true;
                }

            }
            else{
                m[x]=i;
            }
        }
        return false;
        
    }
};

    /// Total Time Complexity = O(N)
    /// Total Space Complexity = O(N) for: unordered_map
    /// where N is the size of the input vector nums.
    
    /// This solution uses a hash map to store the cumulative sum modulo k,
    /// allowing us to efficiently check for subarrays that sum to a multiple of k.
