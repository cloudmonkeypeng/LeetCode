///刷题 真tm不容易

class Solution {
public:
    int numDecodings(string s) {
      
    if(s.empty()||s[0]=='0') return 0;
    
    if(s.length()==1) return 1;
    
    int first,second;
    
    int length = s.length();
    
    first =1; second =2;
    
    if(s[1]=='0'||s[0]>'2'||(s[0]=='2'&&s[1]>'6'))
        second =1;
    
    if(s[0]>'2'&&s[1]=='0')
        second = 0;
    
    
    int sum = second;
    
    //cout<<first<<" "<<second<<endl;
    
    for(int i=2;i<length;i++){
        
        if (s[i]=='0')
            second = 0;
        
        
        if(!(s[i-1]=='1'|| (s[i-1]=='2'&&s[i]<='6') ))
            first = 0;
        
        sum = first +second;
        
        first = second;
        
        second = sum;
        
    }
    
    return sum;


    }
};