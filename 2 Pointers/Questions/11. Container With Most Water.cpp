/*we are required to find 2 such index such that they form the container which
 can carry the most amount of water, this means we have to maximize the area => window
  width * min(height1,height2) , we which ever pointer's height is less we move it.*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right =n-1;

        int area = (n-1) * min(height[0], height[n-1]);
        int ans  = area;
        
        while(left<right){
            ans = max(ans, (right-left)*min(height[left], height[right]));

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return ans;
        
    }
};
