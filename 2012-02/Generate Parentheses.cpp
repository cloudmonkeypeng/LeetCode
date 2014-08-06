class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        if(n<=0)
            return ans;
        
        generate(n-1,n,"(");
        
        return ans;
    }
    
    
    void generate(int left,int right,string temp){
        
        if(left==0){
            
            while(right>0){
                temp +=")";
                right--;
            }
            
            ans.push_back(temp);
            
            return;
        }
        
        if(left==right){
            
            generate(left-1,right,temp+"(");
            
        }else{
            
            generate(left,right-1,temp+")");
            
            
            generate(left-1,right,temp+"(");
        }
        
    }
private:
    vector<string> ans;
};