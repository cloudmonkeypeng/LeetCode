class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        
        int n = digits.size()-1;
        
        bool temp = false;
        
        do{
            if(digits[n]+1==10){
                digits[n] = 0;
                temp = true;
                n--;
            }else{
                digits[n] = digits[n]+1;
                return digits;
            } 
        }while(temp&&n>=0);
        
        vector<int> answers;
        
        answers.push_back(1);
        
        for(int i=0;i<digits.size();i++)
            answers.push_back(0);
        
        return answers;
    }
};