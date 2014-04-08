class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        
        
        if(board.size() == 0) return false;  
        
        
        bool row[9], col[9];      
        
        
        for(int i =0; i<9; i++){  
            
            
            memset(row, true, 9*sizeof(bool));  
            memset(col, true, 9*sizeof(bool));  
            
            for(int j =0; j<9; j++){  
                
                if(board[i][j] != '.'){   
                    
                    if(row[board[i][j]-49] ==false)
                        return false;
                    
                    row[board[i][j]-49] = false;
                }
                
                if(board[j][i] != '.'){
                    
                    if(col[board[j][i]-49] ==false)
                        return false;
                        
                    col[board[j][i]-49] = false;
                }
            
            }
        }    



        for(int i =0; i< 9; i+=3){  
        
            for(int j =0; j<9; j+=3){  
                
                memset(row, true, 9*sizeof(bool));
               
                for(int m=0; m<3; m++){
                    
                    for(int n =0; n<3; n++){
                        
                        if(board[m+i][n+j] == '.')
                            continue;
                            
                        if(row[board[m+i][n+j]-49] ==false)
                            return false;
                            
                        row[board[m+i][n+j]-49] = false;
                    }
                
                }
                
            }
        
        }
        return true;  
        
    }
};