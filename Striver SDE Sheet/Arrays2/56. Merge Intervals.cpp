//we are given a vec of vec , we have to merge the overlapping,
//we first inserted the first vector, and then started checking the last element of 
// the array with the first element of the next vec in the given interval , 
// if the back()[1] is greater then we have overlap so we update it with the new limit.



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         sort(intervals.begin(),intervals.end());
    int n = intervals.size();
    
    vector<vector<int>> ans;
    for(int t = 0 ; t < n; t++){
        if(ans.empty() || ans.back()[1]<intervals[t][0]){
            ans.push_back(intervals[t]);
        }
        
        else{
            ans.back()[1] = max(ans.back()[1],intervals[t][1]);
            
        }
 
    }
    return ans;
        
    }
};