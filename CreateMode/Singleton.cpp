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


//C++ 11 �汾�Ժ�Ŀ�ƽ̨ʵ��
std::atomic<Singleton*> Singleton::m_instance;
std::mutex Singleton::m_mutex;
Singleton* Singleton::getInstance() {
	Singleton* tmp = m_instance.load(std::memory_order_relaxed);
	std::atomic_thread_fence(std::memory_order_acquire);//��ȡ�ڴ�fence
	//fence �ڴ������
	if (tmp == nullptr) {
		std::lock_guard<std::mutex> lock(m_mutex);
		tmp = m_instance.load(std::memory_order_relaxed);
		if (tmp == nullptr) {
			tmp = new Singleton;
			std::atomic_thread_fence(std::memory_order_release);//�ͷ��ڴ��fence
			m_instance.store(tmp, std::memory_order_relaxed);
		}
	}
	return tmp;
}

