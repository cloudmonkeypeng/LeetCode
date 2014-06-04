class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        
        if(n<=0) return answer;
        
        N=n;
        
        columns = vector<bool>(n,false);
        main_diag = anti_diag = vector<bool>(2*n,false);

        rows = vector<int>(n,-1);
        
        dfs(0);
        
        return answer;
    }
private:
    vector<vector<string>> answer;
    vector<bool> columns;
    vector<bool> main_diag;
    vector<bool> anti_diag;
    
    vector<int> rows;
    
    int N;
    
    void dfs(int row){
    
        if(row==N){
            
            vector<string> level;
            
            for(int i=0;i<N;i++){
                string s(N,'.');
                s[rows[i]] = 'Q';
                level.push_back(s);
            }
            
            answer.push_back(level);
            return;
        }
        
        for(int i=0;i<N;i++){
        
            bool flag = (columns[i]==false)&&(main_diag[row+i]==false)&&(anti_diag[row-i+N]==false);
            
            if(!flag) continue;
            
            rows[row] = i;
            
            columns[i] = main_diag[row+i]= anti_diag[row-i+N] =true;
            
            dfs(row+1);
            
            rows[row] = -1;
            
             columns[i] = main_diag[row+i]= anti_diag[row-i+N] =false;
            
        }
    }
    
};
