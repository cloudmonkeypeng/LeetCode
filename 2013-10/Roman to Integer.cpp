class Solution {
public:
      int romanToInt(string s) {
        
        int num = 0;
        
        int length = s.size()-1;
        
        while(length>=0&&(s.compare(length,1,"I")==0||s.compare(length,1,"V")==0)){
            
            if(s.compare(length,1,"V")==0){
                
                num = num+5;
                length--;
                if(length>=0&&s.compare(length,1,"I")==0){
                    num--;
                    length--;
                }
                break;
            }
            
            if(s.compare(length,1,"I")==0){
                num++;
                length--;
            }
        }
        
        if(length>=0&&(length-1)>=0&&s.compare(length,1,"X")==0&&s.compare(length-1,1,"I")==0) {
            num=num+9;
            length =length -2;
        }
        
        while(length>=0&&(s.compare(length,1,"X")==0||s.compare(length,1,"L")==0)){
            
            if(s.compare(length,1,"L")==0){
                
                num = num+50;
                length--;
                if(length>=0&&s.compare(length,1,"X")==0){
                    num = num -10;
                    length--;
                }
                break;
            }
            
            if(s.compare(length,1,"X")==0){
                num =num+10;
                length--;
            }
        }
        
        if(length>=0&&(length-1)>=0&&s.compare(length,1,"C")==0&&s.compare(length-1,1,"X")==0) {
            num=num+90;
            length =length -2;
        }
        
        
        while(length>=0&&(s.compare(length,1,"D")==0||s.compare(length,1,"C")==0)){
            
            if(s.compare(length,1,"D")==0){
                
                num = num+500;
                length--;
                if(length>=0&&s.compare(length,1,"C")==0){
                    num = num -100;
                    length--;
                }
                break;
            }
            
            if(s.compare(length,1,"C")==0){
                num =num+100;
                length--;
            }
        }
        
        if(length>=0&&(length-1)>=0&&s.compare(length,1,"M")==0&&s.compare(length-1,1,"C")==0) {
            num=num+900;
            length =length -2;
        }
        
        while(length>=0&&s.compare(length,1,"M")==0){
            num = num+1000;
            length--;
        }
        
        return num;
        
        
    }

};