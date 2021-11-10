class Singleton {
private:
	Singleton();
	Singleton(const Singleton& other);
public:
	static Singleton* getInstance();
	static Singleton* m_instance;
};

Singleton* Singleton::m_instance = nullptr;

//线程非安全版本
/* 
Singleton* Singleton::getInstance() {
	if (m_instance == nullptr) {
		m_instance = new Singleton();
	}
	return m_instance;
}
*/

//双检查锁,但由于内存读写reorder不安全
/*
* 正常情况:先分配内存，再调用构造器，最后赋值给m_instance
* （编译器优化）reorder后可能出现的情况：先分配内存，然后把内存地址给m_instance
*                 最后再调用构造器
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


//C++ 11 版本以后的跨平台实现
std::atomic<Singleton*> Singleton::m_instance;
std::mutex Singleton::m_mutex;
Singleton* Singleton::getInstance() {
	Singleton* tmp = m_instance.load(std::memory_order_relaxed);
	std::atomic_thread_fence(std::memory_order_acquire);//获取内存fence
	//fence 内存的屏障
	if (tmp == nullptr) {
		std::lock_guard<std::mutex> lock(m_mutex);
		tmp = m_instance.load(std::memory_order_relaxed);
		if (tmp == nullptr) {
			tmp = new Singleton;
			std::atomic_thread_fence(std::memory_order_release);//释放内存的fence
			m_instance.store(tmp, std::memory_order_relaxed);
		}
	}
	return tmp;
}

