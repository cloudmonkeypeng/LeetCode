class Solution {
public:
    string addBinary(string a, string b) {
        
        if(a.size()==0)
            return b;
        
        if(b.size()==0)
            return a;
        
        int num = abs((int)a.length()-(int)b.length());
        
        string temp = string(num,'0');
        
        if(a.length()>b.length()){
        
            b.insert(b.begin(), temp.begin(),temp.end());
            
        }else{
        
            a.insert(a.begin(), temp.begin(), temp.end());
        }
        
        
        int carry = 0;
        
        for(int i= (int)a.length()-1;i>=0;i--){
        
            a[i] = a[i] +b[i] -'0'+carry;
            
            if(a[i]=='3'){
                
                a[i] ='1';
                
                carry =1;
                
            }else if(a[i]=='2'){
            
                a[i]='0';
                
                carry = 1;
                
            }else {
                carry = 0;
            }
        
        }
        
        if(carry!=0){
        
            a.insert(a.begin(), '1');
        }
        
        return a;
        
        
    }
};