class Solution {
public:
    string intToRoman(int num) {
        
        int temp;
        
        temp = num/1000;
        num = num%1000;
        
        string answer="";
        
        //千位
        
        if(temp!=0){
            for(int i=0;i<temp;i++)
                answer = answer + "M";
        }
        
        temp = num/100;
        num = num%100;
        
        //百位
        
        if(temp!=0){
            if(temp==9) answer = answer + "CM";
            if(5<=temp&&temp<=8){
                answer = answer + "D";
                for(int i=0;i<temp-5;i++){
                    answer = answer+"C";
                }
            }
            
            if(temp==4) answer = answer + "CD";
            
            
            if(1<=temp&&temp<=3){
                for(int i=0;i<temp;i++){
                    answer = answer+"C";
                }
            }
        }
        
        //十位
        
        temp = num/10;
        num = num%10;
        
        if(temp!=0){
            if(temp==9) answer = answer + "XC";
            if(5<=temp&&temp<=8){
                answer = answer + "L";
                for(int i=0;i<temp-5;i++){
                    answer = answer+"X";
                }
            }
            
            if(temp==4) answer = answer + "XL";
            
            
            if(1<=temp&&temp<=3){
                for(int i=0;i<temp;i++){
                    answer = answer+"X";
                }
            }
        }
        
        
        temp = num;
        
        
        if(temp!=0){
            if(temp==9) answer = answer + "IX";
            if(5<=temp&&temp<=8){
                answer = answer + "V";
                for(int i=0;i<temp-5;i++){
                    answer = answer+"I";
                }
            }
            
            if(temp==4) answer = answer + "IV";
            
            
            if(1<=temp&&temp<=3){
                for(int i=0;i<temp;i++){
                    answer = answer+"I";
                }
            }
        }
        
        return answer;
    }
};