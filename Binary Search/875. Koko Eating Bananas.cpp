/*
We are given array and h , we have to  find a min integer k such that summation of ceil(arr[i]/k) <= h;
we knew that the minimum k will be between 1 and the max element of the array , so we used binary
serach in the range (1,max_element(array)) and use a function ktest to check the conditon. 
*/
class Solution {

bool ktest(int k,vector<int>& piles,int h){
    int hours = 0 ;
    for(auto p : piles){
        hours += (p + k - 1) / k;
    }
    return hours<=h;

}
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        while(l<r){
           int k =  l + (r - l) / 2;
           if(ktest(k,piles,h)){
            r = k;
           }
           else{
            l = k+1;
           }
        }

return r;        
    }
};