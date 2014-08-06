class Solution {
public:
    int maxProfit(vector<int> &prices) {

        if(prices.size()<=1)
            return 0;


        int ans = prices[1] - prices[0];

        int count = ans;

        for(int i=2;i<=prices.size()-1;i++){

            count = max(count,0);

            count += prices[i]-prices[i-1];

            ans = max(ans,count);
        }

        if(ans<0)
            return 0;

        return ans;
        
    }
};