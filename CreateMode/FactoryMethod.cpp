#include<string>
// ��MianForm�����������������
class MainForm {
	SpliterFactory* m_factory;
public:
	MainForm(SpliterFactory* factory) {
		//���ģʽ����������仯�������ñ仯�ϵ��ֲ��ĵط�
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
// ��������
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



