class House {
public:
	void Init() {
		this->BuliderPart1();
		for (int i = 0; i < 4; i++) {
			this->BuliderPart2();
		}
		bool flag = this->BuildPart3();
		if (flag)
		{
			this->BuliderPart4();
		}
		this->BuliderPart5();
	}
	virtual ~House() {}
protected:
	virtual void BuliderPart1()=0;
	virtual void BuliderPart2()=0;
	virtual void BuliderPart3()=0;
	virtual void BuliderPart4()=0;
	virtual void BuliderPart5()=0;
};

class StoneHouse :public House {
protected:
	virtual void BuliderPart1(){
	}
	virtual void BuliderPart2() {

	}
	virtual void BuliderPart3() {

	}
	virtual void BuliderPart4() {

	}
	virtual void BuliderPart5() {

	}
};

int main() {
	House* pHouse = new StoneHouse();
	pHouse->Init();
}






// ²ð·Ö---------------------------------
class House {

};
class HouseBulider {
protected:
	House* pHouse;
	virtual void BuliderPart1() = 0;
	virtual void BuliderPart2() = 0;
	virtual void BuliderPart3() = 0;
	virtual void BuliderPart4() = 0;
	virtual void BuliderPart5() = 0;
public:
	House* getResult() {
		return pHouse;
	}
	virtual ~HouseBulider(){}
};

class HouseDirector {
public:
	HouseBulider* pHouseBulider;
	HouseDirector(HouseBulider* pHouseBulider) {
		this->pHouseBulider = pHouseBulider;
	}

	House* Construct() {
		pHouseBulider->BuliderPart1();
		for (int i = 0; i < 4; i++) {
			pHouseBulider->BuliderPart2();
		}
		bool flag = pHouseBulider->BuildPart3();
		if (flag)
		{
			pHouseBulider->BuliderPart4();
		}
		pHouseBulider->BuliderPart5();
		return  pHouseBulider->getResult();
	}
	virtual ~HouseDirector() {}
};

class StoneHouse :public House {

};

class StoneHouseBulider :public HouseBulider {
protected:
	virtual void BuliderPart1() {
	}
	virtual void BuliderPart2() {

	}
	virtual void BuliderPart3() {

	}
	virtual void BuliderPart4() {

	}
	virtual void BuliderPart5() {

	}
};