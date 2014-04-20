class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
          
    std::sort(num.begin(), num.end());
    vector<vector<int> > result;
    int len = num.size();
    
    if(num.size()<=3) return result;
    
    for(int m=0;m<len-3;m++){
    
        for(int n=m+1;n<len-2;n++){
        
            int curTarget = target - num[m] - num[n];
            
            int start = n+1;
            
            int end = len-1;
            
            
            while(start<end){
            
                
                if(num[start] + num[end] == curTarget){
                    
                    vector<int> solution;
                    
                    solution.push_back(num[m]);
                    solution.push_back(num[n]);
                    solution.push_back(num[start]);
                    solution.push_back(num[end]);
                    result.push_back(solution);
                    
                    start++; end--;
                    
                    while(start<end && num[start] == num[start-1]) start++;
                    while(start<end && num[end] == num[end+1]) end--;
                    
                }else if(num[start] + num[end] < curTarget){
                    
                    start++;
                    
                }else{
                    
                    end--;
                }

            }
            
            if(n<len-1){
                while(num[n] == num[n+1]) n++;
            }

        }
        
        if(m<len-1){
            while(num[m] == num[m+1]) m++;
        }
        
    }
    
    
    return result;
    }
};