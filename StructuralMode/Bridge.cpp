class Messager {
public:
	virtual void Login(string username, string password) = 0;
	virtual void SendMessage(string message) = 0;
	virtual void SendPicture(Image image) = 0;

	virtual void PlaySound() = 0;
	virtual void DrawShape() = 0;
	virtual void WriteText() = 0;
	virtual Connect() = 0;

	virtual ~Message(){}
};

//平台实现 n
class PcMeessagerBase :public Messager {
public:
	virtual void PlaySound() {
		//*****
	}
	virtual void DrawShape() {
		//*****
	}
	virtual void WriteText() {
		//*****
	}
	virtual Connect() {
		//*****
	}
};
class MobileMeessagerBase :public Messager {
public:
	virtual void PlaySound() {
		//=======
	}
	virtual void DrawShape() {
		//=======
	}
	virtual void WriteText() {
		//=======
	}
	virtual Connect() {
		//=======
	}
};


//业务抽象 m
class PcMessagerLite :public PcMeessagerBase {
public:
	virtual void Login(string username, string password) {
		PcMeessagerBase::Connect();
		// ........
	}
	virtual void SendMessage(string message) {
		PcMeessagerBase::WriteText();
		// ........
	}
	virtual SendPicture(Image image) {
		PcMeessagerBase::DrawShape();
		// ........
	}
};
class PcMessagerPerfect :public PcMeessagerBase {
public:
	virtual void Login(string username, string password) {
		PcMeessagerBase::PlaySound();
		// *******
		PcMeessagerBase::Connect();
		// ........
	}
	virtual void SendMessage(string message) {
		PcMeessagerBase::PlaySound();
		// *******
		PcMeessagerBase::WriteText();
		// ........
	}
	virtual SendPicture(Image image) {
		PcMeessagerBase::PlaySound();
		// *******
		PcMeessagerBase::DrawShape();
		// ........
	}
};

class MobileMessagerLite :public MobileMeessagerBase {
public:
	virtual void Login(string username, string password) {
		MobileMeessagerBase::Connect();
		// ........
	}
	virtual void SendMessage(string message) {
		MobileMeessagerBase::WriteText();
		// ........
	}
	virtual SendPicture(Image image) {
		MobileMeessagerBase::DrawShape();
		// ........
	}
};
class MobileMessagerPerfect :public MobileMeessagerBase {
public:
	virtual void Login(string username, string password) {
		MobileMeessagerBase::PlaySound();
		// *******
		MobileMeessagerBase::Connect();
		// ........
	}
	virtual void SendMessage(string message) {
		MobileMeessagerBase::PlaySound();
		// *******
		MobileMeessagerBase::WriteText();
		// ........
	}
	virtual SendPicture(Image image) {
		MobileMeessagerBase::PlaySound();
		// *******
		MobileMeessagerBase::DrawShape();
		// ........
	}
};
// 以上类的数目：1 +n + m*n

// ---------------------------------------------------------
//改进为桥接模式
class Messager {
protected:
	MessagerImp* messagerImp;
public:
	virtual void Login(string username, string password) = 0;
	virtual void SendMessage(string message) = 0;
	virtual void SendPicture(Image image) = 0;
	virtual ~Message() {}
};
class MessagerImp {
public:
	virtual void PlaySound() = 0;
	virtual void DrawShape() = 0;
	virtual void WriteText() = 0;
	virtual Connect() = 0;

	virtual ~MessageImp() {}
};

//平台实现 n
class PcMeessagerBase :public MessagerImp {
public:
	virtual void PlaySound() {
		//*****
	}
	virtual void DrawShape() {
		//*****
	}
	virtual void WriteText() {
		//*****
	}
	virtual Connect() {
		//*****
	}
};
class MobileMeessagerBase :public MessagerImp {
public:
	virtual void PlaySound() {
		//=======
	}
	virtual void DrawShape() {
		//=======
	}
	virtual void WriteText() {
		//=======
	}
	virtual Connect() {
		//=======
	}
};

// 业务抽象
class PcMessagerLite:public Messager {
public:
	virtual void Login(string username, string password) {
		MessagerImp* messagerImp;
		->Connect();
		// ........
	}
	virtual void SendMessage(string message) {
		messagerImp->WriteText();
		// ........
	}
	virtual SendPicture(Image image) {
		messagerImp->DrawShape();
		// ........
	}
};
class MessagerPerfect：public Messager{
public:
	virtual void Login(string username, string password) {
		messagerImp->PlaySound();
		// *******
		messagerImp->Connect();
		// ........
	}
	virtual void SendMessage(string message) {
		messagerImp->PlaySound();
		// *******
		messagerImp->WriteText();
		// ........
	}
	virtual SendPicture(Image image) {
		messagerImp->PlaySound();
		// *******
		messagerImp->DrawShape();
		// ........
	}
};

void Process() {
	//运行时装配
	MessagerImg* mImp = new PcMeessagerImg();
	Messager* m = new Messager(mImp);
}