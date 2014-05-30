class Solution {
public:
    bool isValid(int x,int y,vector<vector<char> > &board){

    for(int m=0;m<9;m++){
        
        if((x!=m&&board[x][y]==board[m][y])||(y!=m&&board[x][y]==board[x][m]))
            return false;

    }
    
    
    for (int i = 3 * (x / 3); i < 3 * (x / 3 + 1); i++)
        for (int j = 3 * (y / 3); j < 3 * (y / 3 + 1); j++)
            if ((i != x || j != y) && board[i][j] == board[x][y])
                return false;

    return true;

}


bool solveSudoku(vector<vector<char> > &board) {
 
    for(int m=0;m<9;m++){
    
        for(int n = 0;n<9;n++){
        
            if(board[m][n]=='.'){
                
                for(int i=0;i<9;i++){
                
                    board[m][n] = i+'1';
                
                    if(isValid(m,n,board)&&solveSudoku(board))
                        return true;
                    
                    board[m][n] ='.';
                }
                return false;
            }
            
        }
    }
    return true;
}


};