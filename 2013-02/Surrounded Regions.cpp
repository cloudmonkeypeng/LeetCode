////大数据没通过

class Solution {
public:
  bool isSurrounded(vector<vector<char>> &board,vector<vector<bool>> &haveCompare,int m,int n){

    if(board[m][n]=='X')
        return true;
    
    if(m==0||n==0||m==board.size()-1||n==board[m].size()-1)
        return false;
    
    bool temp = true;
    
    if(haveCompare[m-1][n]==false){
    
        haveCompare[m-1][n] =true;
        temp = temp&&isSurrounded(board, haveCompare, m-1, n);
    }
    
    if(haveCompare[m+1][n]==false){
        
        haveCompare[m+1][n] =true;
        temp = temp&&isSurrounded(board, haveCompare, m+1, n);
    }
    
    if(haveCompare[m][n+1]==false){
        
        haveCompare[m][n+1] =true;
        temp = temp&&isSurrounded(board, haveCompare, m, n+1);
    }
    
    if(haveCompare[m][n-1]==false){
        
        haveCompare[m][n-1] =true;
        temp = temp&&isSurrounded(board, haveCompare, m, n-1);
    }
    
    
    if(temp){
        
        board[m][n] ='X';
        return true;
    
    }else{
        return false;
    }
}



void solve(vector<vector<char>> &board) {
 
    if(board.size()<=2||board[0].size()<=2)
        return;
    
    vector<vector<bool>> haveCompare;
    
    haveCompare =vector<vector<bool> >(board.size(), vector<bool>(board[0].size(), false));
    
    for(int m=1;m<board.size()-1;m++){
    
        for(int n=1;n<board[0].size()-1;n++){
        
            if (board[m][n]=='O'&&haveCompare[m][n]==false) {
                
                haveCompare[m][n] = true;
                isSurrounded(board,haveCompare, m, n);
                
            }
        }
    
    }
    
}


};



///正确答案


class Solution {
public:
  
vector<int> xIndex;  
vector<int> yIndex;  

void solve(vector<vector<char>> &board) {  

	int row = board.size();  
	if(row == 0) return;

	int col = board[0].size();  
	xIndex.clear();
	yIndex.clear();

	for(int i =0; i< row; i++){
		
		if(board[i][0] == 'O'){
			xIndex.push_back(i);
			yIndex.push_back(0);
		}

		if(board[i][col-1] == 'O'){
			xIndex.push_back(i);
			yIndex.push_back(col-1);
		}
	}  

	for(int i =0; i< col; i++){
		
		if(board[0][i] == 'O'){
			xIndex.push_back(0);
			yIndex.push_back(i);
		}

		if(board[row-1][i] == 'O'){
			xIndex.push_back(row-1);
			yIndex.push_back(i);
		}
	} 
    

    int k =0;

    while(k<xIndex.size()){

    	int x = xIndex[k];
    	int y = yIndex[k];
    	board[x][y] = 'Y';

    	if(x>0 && board[x-1][y] == 'O' ) {xIndex.push_back(x-1); yIndex.push_back(y);}
    	if(x<row-1 && board[x+1][y] == 'O' ) {xIndex.push_back(x+1); yIndex.push_back(y);}
    	if(y>0 && board[x][y-1] == 'O' ) {xIndex.push_back(x); yIndex.push_back(y-1);}
    	if(y<col-1 && board[x][y+1] == 'O' ) {xIndex.push_back(x); yIndex.push_back(y+1);}
    	k++;
    }  

    for(int m=0;m<row;m++){

    	for(int n=0;n<col;n++){
    		if(board[m][n]=='Y'){

    			board[m][n]='O';
    			
    		}else if(board[m][n]=='O'){

    			board[m][n]='X';
    		}

    	}

    }

}



};