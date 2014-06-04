
#include <vector>
#include <string>
#include <iostream>

using namespace std;


void addSpaces(string &s,int i,int num,int L,bool isLast){

    if(num<1||i>=num) return;
    
    int spaceNum = 0;
    
    if (isLast) {
        spaceNum =1;
    }else{
        
        spaceNum = L/num;
        
        if(i<L%num)
            spaceNum +=1;
    }
    
    s.append(spaceNum, ' ');
    
}

string connect(vector<string> &words,int begin,int end,int len,int L,int isLast){

    string s = "";
    
    for(int i=begin;i<=end;i++){
        s +=words[i];
        addSpaces(s,i-begin,end-begin,L-len,isLast);
    }
    if(s.size()<L) s.append(L-s.size(),' ');
    return s;

}

vector<string> fullJustify(vector<string> &words, int L) {
    
    vector<string> answer;
    
    int len=0,start=0;
    
    for(int i=0;i<words.size();i++){
        
        if(len+words[i].size()+i-start>L){
            answer.push_back(connect(words,start,i-1,len,L,false));
            len = 0;
            start = i;
        }
        len +=words[i].size();
    }
    answer.push_back(connect(words,start,words.size()-1,len,L,true));
    return answer;
    
}


int main(){

    vector<string> words;
    
    words.push_back("This");
    
    words.push_back("is");
    
    words.push_back("an");
    
    words.push_back("example");
    
    words.push_back("of");
    
    words.push_back("text");
    
    words.push_back( "justification.");
    
    vector<string> answer  = fullJustify(words, 16);
    
    for(int i=0;i<answer.size();i++)
        cout<<answer[i]<<endl;
}