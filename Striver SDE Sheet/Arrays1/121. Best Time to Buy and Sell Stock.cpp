/*

It maintains:
mp: the minimum price seen so far (i.e., best time to buy).
profit: the maximum profit we could get if we sold on the current day.

For each price p:
It updates mp to track the lowest price up to that point.
It computes potential profit by p - mp, and updates profit accordingly.

*/


class Solution {
public:

    int maxProfit(vector<int>& prices) {
         
    int mp = INT_MAX;
    int profit = 0;

    for (int p : prices) {
        mp= min(mp, p);
        profit = max(profit, p - mp);
    };
    return profit;

        
    }
};