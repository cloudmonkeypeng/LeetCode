#include <iostream>
#include <string>

using namespace std;

class myString{
public:
    
	myString(const char* str=NULL);
	myString(const myString &other);
	~myString(void);
	myString & operator = (const myString &other);
    
private:
	char* m_data;
};




myString::myString(const char* str){
    
	if(str==NULL){
        
		m_data = new char[1];
        
		*m_data = '\0';
        
	}else{
        
		int length = strlen(str);
        
		if(m_data!=NULL)
			delete []m_data;
		
		try{

			m_data = new char[length+1];

		}catch( const bad_alloc& e ){

			return -1;

		}

		
        
		strcpy(m_data,str);
        
	}
    
}

myString::myString(const myString &other){
    
	if(this==&other)
		return;
    
	if(m_data!=NULL)
		delete []m_data;
    
	int length = strlen(other.m_data);
    
	try{

		m_data = new char[length+1];

	}catch( const bad_alloc& e ){

		return -1;

	}

    
	strcpy(m_data,other.m_data);
    
}

myString::~myString(){
    
    if(m_data!=NULL){
    	delete []m_data;
    	m_data = NULL;
    }
}

myString & myString::operator=(const myString &other){

    if(this!=&ohter){

    	myString strTemp(other);

    	char *pTmp = strTemp.m_data;

    	strTemp.m_data = m_data;

    	m_data = pTmp;

    }

    return *this;
}

