class Solution {
public:
    

    vector<string> generate_Parenthesis(int left,int right){
        
        vector<string> answer;
        
        
        if(left==0&&right==1){
            answer.push_back(")");
            return answer;
        }
        
        vector<string> temp;
        
        string list;
        
        
        if(left>=1){
            temp = generate_Parenthesis(left-1,right);
            
            for(int i=0;i<temp.size();i++){
                list ="("+temp[i];
                answer.push_back(list);
            }
        }
        
        
        if(left<right&&right>=1){
            temp = generate_Parenthesis(left,right-1);
            
            for(int i=0;i<temp.size();i++){
                list =")"+temp[i];
                answer.push_back(list);
            }
        }
        
        return answer;
        
    }
    
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> answer;
        
        if(n==0) return answer;
        
        return generate_Parenthesis(n,n);
    }
};