#include <iostream>
#include <map>
#include <string>
#include <complex>

using namespace std;

typedef     map<string,   int>   MY_MAP;

MY_MAP   stringMap;


int main(){

	stringMap.insert(pair<string,int>("m",9));
	stringMap.insert(pair<string,int>("dm",8));
	stringMap.insert(pair<string,int>("cm",7));
	stringMap.insert(pair<string,int>("mm",6));
	stringMap.insert(pair<string,int>("um",3));
	stringMap.insert(pair<string,int>("nm",0));

	int length=0;
	cin>>length;
	
	for(int i=0;i<length;i++){

		double up=0;
		string sup;
		string sdown;
		string spx;
		double down=0;
		double px=0;

		cin>>up>>sup;
		cin>>down>>sdown;
		cin>>px>>spx;
		
		int math=stringMap[sup]-stringMap[sdown];
		double result=up*pow(10,math)/down*px;
		cout<<"Case "<<i+1<<": "<<result<<"px"<<endl;
	}
}