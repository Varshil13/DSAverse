class Solution {
public:
    bool isPalindrome(int x) {
        
        // string t = to_string(x);

        // int left = 0;
        // int right = t.size()-1;

        // while (left<right){
        //     if(t[left]!=t[right]){
        //         return false;
        //     }
        //     left++;
        //     right--;
        // }
        // return true;

        if(x<0) return false;
        long long int rem = 0;
        int t = x;
        

        while(t!=0){
            rem = t%10 + rem*10;
            t=t/10;
        }
        return (rem==x);


        
    }
};