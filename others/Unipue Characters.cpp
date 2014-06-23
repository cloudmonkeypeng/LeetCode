//检验一个string中  字符是否重复  如果是26个字符

//位运算 方法最简单
class uniqueCharacters{

public:
    bool check(string input){
        
        int checker = 0;
        
        for(int i=0;i<input.size();i++){
        
            if((checker&(1<<input[i]))>0) return false;
            
            checker |= (1<<input[i]);
        }
        
        return true;
    }
    
};

//如果是 ascII码  256个

class uniqueCharacters{

public:
    bool check(string input){
    
        vector<bool> answer(256,false);
        
        for(int i=0;i<input.size();i++){
        
            if(answer[input[i]]==true) return false;
            
            answer[input[i]] = true;
        }
        
        return true;
    }
    
    
};