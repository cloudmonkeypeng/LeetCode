#include <unordered_map>
#include <vector>
#include <string>

using namespace std;


vector<int> findSubstring(string S, vector<string> &L) {
    
    vector<int> answer;
    
    if(L.size()==0) return answer;
    
    int dictLength = L[0].length();
    
    int allLength = dictLength*L.size();
    
    if(allLength>S.length()) return answer;
    
    unordered_map<string, int> expected;
    
    for(int i=0;i<L.size();i++)
        expected[L[i]]++;
    
    int lastIndex = S.length()-allLength;
    
    for(int i=0;i<=lastIndex;i++){
        
        unordered_map<string, int>  unused(expected);
        
        for(int m=i;m<i+allLength;m +=dictLength){
            
            string tempString =S.substr(m,dictLength);
            
            auto pos = unused.find(tempString);
            
            if(pos==expected.end()||pos->second==0) break;
            
            pos->second--;
            
            if(pos->second==0) unused.erase(pos);
            
        }
        
        if(unused.size()==0) answer.push_back(i);
        
    }
    
    return answer;
}


int main(){


}