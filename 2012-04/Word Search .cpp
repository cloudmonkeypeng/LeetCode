class Solution{
public:
    bool exist(vector<vector<char> > &board, string word) {
        
        height = board.size();
        
        if(height==0) return false;
        
        width = board[0].size();
        
        visitd = vector<vector<bool>>(height,vector<bool>(width,false));
        
        for(int m=0;m<height;m++)
            for(int n=0;n<width;n++)
                if(dfs(m,n,board,word,0))
                    return true;
            
        return false;
    }
    
private:
    
    int width;
    int height;
    
    vector<vector<bool>> visitd;
    
    bool dfs(int x,int y,vector<vector<char> > &board,string word,int length){
        
        if(length==word.size()) return true;
        
        if(x<0||y<0||x>=height||y>=width) return false;
        
        if(visitd[x][y]) return false;
        
        if(board[x][y]!=word[length]) return false;
    
        
        visitd[x][y] = true;
        
        bool flag = dfs(x+1, y, board, word, length+1)||
        dfs(x, y-1, board, word, length+1)||
        dfs(x, y+1, board, word, length+1)||
        dfs(x-1, y, board, word, length+1);
        
        if(!flag)
        visitd[x][y] = false;
        
        return flag;
    }
    

};