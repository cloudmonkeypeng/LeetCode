class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
         
        std::sort(num.begin(), num.end());
             
        int len = num.size();
        
        int min = numeric_limits<int>::max();
        
        int sum  = numeric_limits<int>::max();
        
        for(int i =0; i< len; i++){
            
            int start = i+1, end =len-1;
            
            while(start<end){
                
                int temp =abs(target-num[i]-num[start] - num[end]);
                
                if(temp<min){
                    
                    min =temp;
                    
                    sum = num[i] +num[start]+num[end];
                }
                
                
                if(target>num[i]+num[start] + num[end]){
                    
                    start++;
                    while(start<end && num[start] == num[start-1]) start++;
                    
                
                }else{
                    
                    end--;
                    
                    
                    while(start<end && num[end] == num[end+1]) end--;
                
                }
            }
            
            if(i<len-1){
                while(num[i] == num[i+1]) i++;
            }
        }
        
        return sum;
    }
};