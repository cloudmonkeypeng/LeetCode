// 还有简单方法

class Solution {
public:
    int totalNQueens(int n) {
        
        if(n<=0) return answer;
        
        N=n;
        
        columns = vector<bool>(n,false);
        main_diag = anti_diag = vector<bool>(2*n,false);
        
        dfs(0);
        
        return answer;
    }
private:
    int answer = 0;
    vector<bool> columns;
    vector<bool> main_diag;
    vector<bool> anti_diag;
    
    int N;
    
    void dfs(int row){
    
        if(row==N){
            
            answer++;
           
            return;
        }
        
        for(int i=0;i<N;i++){
        
            bool flag = (columns[i]==false)&&(main_diag[row+i]==false)&&(anti_diag[row-i+N]==false);
            
            if(!flag) continue;
            
            columns[i] = main_diag[row+i]= anti_diag[row-i+N] =true;
            
            dfs(row+1);
            
            columns[i] = main_diag[row+i]= anti_diag[row-i+N] =false;
            
        }
    }
    
};
