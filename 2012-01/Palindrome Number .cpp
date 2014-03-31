class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0) return false;
        
        int temp =x;
        
        int answer = 0;
        
        int remainder = 0;
        
        while (temp!=0){
            
            remainder = temp%10; 
            
            temp = temp/10;
            
            answer = answer*10+ remainder;    
        }
        
        if(answer==x)
            return true;
            
        return false;
        
    }
};