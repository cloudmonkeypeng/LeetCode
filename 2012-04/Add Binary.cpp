class Solution {
public:
    string addBinary(string a, string b) {
        string answer;
        if(b.length()>a.length()){
            answer = a;
            a = b;
            b = answer;
        }
        int length =a.length()-b.length();
        for(int i=0;i<length;i++){
            b = "0"+b;
        }
        int carry;
        carry = 0;
        answer = "";
        for(int i=a.length()-1;i>=0;i--){
            int num = (int(a[i])-48)+ (int(b[i])-48)+carry;
            if(num==0){
                answer = "0"+answer;
                carry = 0;
            }
            if(num==1){
                answer = "1"+answer;
                carry = 0;
            }
            if(num==2){
                answer = "0"+answer;
                carry = 1;
            }
            if(num==3){
                answer = "1"+answer;
                carry = 1;
            }
        }
        
        if(carry){
            return "1"+answer;
        }else{
            if(answer=="0") return "0";
            return string(answer);
        }
    }
};