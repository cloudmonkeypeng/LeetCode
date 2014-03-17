class Solution {
public:
    int climbStairs(int n) {
       
       if(n<4) return n;
       
       int b= 3;
       
       int c = 5;
       
       int temp;
       for(int i=4;i<n;i++){
           
           temp =c;
           
           c = c +b;
           
           b = temp;
           
       }
       
       return c;
       
    }
};