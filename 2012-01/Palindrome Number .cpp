//加入了翻转检测

class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0) return false;
        
        int ans = 0;
    
        int temp = x;
        
        while(temp){
            
            if(ans>INT_MAX/10||(ans==INT_MAX/10&&temp>INT_MAX%10))
                return false;
            
            ans = ans*10+temp%10;
            
            
            temp = temp/10;
            
           
        }
        
        
        if(ans==x)
            return true;
        
        return false;
        
    }
};