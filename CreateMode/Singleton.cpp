class Singleton {
private:
	Singleton();
	Singleton(const Singleton& other);
public:
	static Singleton* getInstance();
	static Singleton* m_instance;
};

Singleton* Singleton::m_instance = nullptr;

//�̷߳ǰ�ȫ�汾
/* 
Singleton* Singleton::getInstance() {
	if (m_instance == nullptr) {
		m_instance = new Singleton();
	}
	return m_instance;
}
*/

//˫�����,�������ڴ��дreorder����ȫ
/*
* �������:�ȷ����ڴ棬�ٵ��ù����������ֵ��m_instance
* ���������Ż���reorder����ܳ��ֵ�������ȷ����ڴ棬Ȼ����ڴ��ַ��m_instance
*                 ����ٵ��ù�����
*/
Singleton* Singleton::getInstance() {
	if (m_instance == nullptr) {
		Lock lock;
		if(m_instance == nullptr){
			m_instance = new Singleton();
		}
	}
	return m_instance;
}


