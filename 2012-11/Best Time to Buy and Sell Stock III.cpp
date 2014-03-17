class Solution {
public:
    int maxProfit(vector<int> &prices) {
    if(prices.size()<=1) return 0;
    
    int max = 0;
    
    int start =0;
    
    vector<int> first;
    vector<int> second;
    
    int answer = 0;
    
    
    for(int i=1;i<prices.size();i++){
        
        start = start + prices[i]- prices[i-1];
        
        if(start<0) start = 0;
        
        if(start>max) max =start;
        
        first.push_back(max);
    }
    
    
    
    start =0;max =0;
    
    second.push_back(0);
    
    for(int i= prices.size()-1;i>0;i--){
        
        start = start +prices[i]- prices[i-1];
        
        if(start<0) start = 0;
        
        if(start>max) max =start;
    
        second.push_back(max);
        
    }
    
    
    int temp =0;
    
    for(int i=0;i<first.size();i++){
        temp = first[i] + second[second.size()-i-2];
        if(temp>answer) answer =temp;
    }
    
    
    return answer;
}



};