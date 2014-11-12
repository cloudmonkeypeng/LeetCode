class single{

public:

	static single* getInstance(){

		if(m_pInstance==NULL){

			lock();

			if(m_pInstance==NULL){


				m_pInstance = new single();
			}

			unlock();

		}

		return m_pInstance;

	}

private:

	static single* m_pInstance;

	~single();
	single();
	single(const single& temp);
	single& operator = (const single& temp);

	class sinlgeDel{

	public:
		~sinlgeDel(){

			if(single::m_pInstance){

				delete m_pInstance;
			}
		}

	};


	static singleDel del;


}