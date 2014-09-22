class Solution {
public:
    int maxProfit(vector<int> &prices) {
        
        if(prices.size()<=1)
            return 0;
        
        vector<int> temp = vector<int>(prices.size(),0);
        
        int count = 0;
        
        int ans = 0;
        
        for(int i=1;i<prices.size();i++){
        
            if(count<0) count = 0;
            
            count += prices[i] - prices[i-1];
            
            ans = max(ans,count);
            
            temp[i] = ans;
        }
        
        ans = INT_MIN;
        
        int realAns = temp[temp.size()-1];
        
        count = 0;
        
        for(int i=(int)prices.size()-2;i>=0;i--){
            
            if(count<0) count = 0;
            
            count += prices[i+1] - prices[i];
            
            ans = max(count,ans);
            
            if(i>0)
                realAns = max(realAns,temp[i-1]+ans);
            else
                realAns = max(realAns,ans);
        }
    
        return realAns;
        
    }
};