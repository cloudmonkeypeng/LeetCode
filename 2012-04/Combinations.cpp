class Solution {
public:
    
    
    void getAnswer(int start,int end,int k,vector<int> &list,vector<vector<int>> &answer){
        
        if(k==0){
            answer.push_back(list);
        }else{
            for(int i=start;i<=end-k+1;i++){
                list.push_back(i);
                getAnswer(i+1,end,k-1,list,answer);
                list.pop_back();
            }
        }
    }
    
    
    vector<vector<int> > combine(int n, int k) {
        
        vector<vector<int>> answer;
        
        if(k<=0) return answer;
        
        vector<int> list;
        
        getAnswer(1,n,k,list,answer);
        
        return answer;
    }
};