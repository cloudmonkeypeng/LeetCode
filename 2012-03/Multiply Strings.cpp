//leetcode 答案上面的 transform 不太会用，要复习


class Solution {
public:
   string multiply(string num1, string num2) {
    
    reverse(num1.begin(),num1.end());
    
    reverse(num2.begin(),num2.end());
    
    
    vector<int> num3(num1.size()+num2.size());
    
    for(int m=0;m<num1.size();m++){

         if(num1[m]=='0') continue;
    
        for(int n=0;n<num2.size();n++){
        
            num3[m+n] += (num1[m]-'0')*(num2[n]-'0');
            
            num3[m+n+1] += num3[m+n]/10;
            
            num3[m+n] %=10;
        
        }
        
    }

    
    int length =num3.size()-1;
    
    while(num3[length]==0) length--;
    
    string answer;
    
    for(int i=length;i>=0;i--)
        answer.push_back(num3[i]+'0');
        
    if(answer.size()==0) return "0";
    
    return answer;
}
        

};