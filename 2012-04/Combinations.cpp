//这种只调用，两个vector的 比较好
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

//  新写的方法  不是很好

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        
        vector<vector<int>>  ans;
        
        if(n==0||k==0)
            return ans;
        
        ans =  recursion(1,n,k);
        
              
        return ans;
    }
private:
    
    vector<vector<int>> recursion(int begin ,int end, int k){
        
        vector<vector<int>>  ans;
        
        if(k==0){
            vector<int> row;
            ans.push_back(row);
            return ans;
        }
        
        for(int i=begin;i<=end-k+1;i++){
            
            vector<vector<int>> temp;
            
            temp = recursion(i+1, end, k-1);
            
            for(int m=0;m<temp.size();m++){
            
                temp[m].insert(temp[m].begin(), i);
                
                ans.push_back(temp[m]);
            }
            
        }
        
        return ans;
        
    }
    
};

