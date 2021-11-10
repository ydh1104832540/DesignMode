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

//ƽ̨ʵ�� n
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


//ҵ����� m
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
// ���������Ŀ��1 +n + m*n

// ---------------------------------------------------------
//�Ľ�Ϊ�Ž�ģʽ
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

//ƽ̨ʵ�� n
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

// ҵ�����
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
class MessagerPerfect��public Messager{
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
	//����ʱװ��
	MessagerImg* mImp = new PcMeessagerImg();
	Messager* m = new Messager(mImp);
}