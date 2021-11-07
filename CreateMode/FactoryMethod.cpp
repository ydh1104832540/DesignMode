#include<string>
// 让MianForm不产生具体类的依赖
class MainForm {
	SpliterFactory* m_factory;
public:
	MainForm(SpliterFactory* factory) {
		//设计模式并不是消灭变化，而是让变化赶到局部的地方
		this->m_factory = factory;
	}
	void Button_Click() {
		ISpliter* spliter = m_factory->CreateSpliter();
		spliter->split();
	}
};

class ISpliter {
public:
	virtual void split() = 0;
	virtual ~ISpliter(){}
};
// 工厂基类
class SpliterFactory {
public:
	virtual ISpliter* CrateSpliter() = 0;
	virtual ~SpliterFactory() {};
};


class TxtSpliter : public ISpliter{
public:
	virtual void split() {
		//...
	}
};
class TxtSpliterFactory: public SpliterFactory {
public:
	virtual ISpliter* CrateSpliter() {
		return new TxtSpliter();
	}
};


class BinarySpliter : public ISpliter {
public:
	virtual void split() {
		//...
	}
};
class BinarySpliterFactory : public SpliterFactory {
public:
	virtual ISpliter* CrateSpliter() {
		return new BinarySpliter();
	}
};


class VideoSpliter : public ISpliter {
public:
	virtual void split() {
		//...
	}
};
class VideoSpliterFactory : public SpliterFactory {
public:
	virtual ISpliter* CrateSpliter() {
		return new VideoSpliter();
	}
};



