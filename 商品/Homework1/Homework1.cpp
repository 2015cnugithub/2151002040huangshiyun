#include<iostream>

using namespace std;

class CGoods{
private:
	long no;
	char* p_name;
	double price;
	static int count;
public:
	CGoods(long n, char* p, double pr){
		no = n;
		p_name = p;
		price = pr;
		count++;
	}

	CGoods(CGoods& goods){
		no = goods.getNo();
		p_name = goods.getPName();
		price = goods.getPrice();
		count++;
	}

	long getNo(){
		return no;
	}

	char* getPName(){
		return p_name;
	}

	double getPrice(){
		return price;
	}

	static int getCount(){
		return count;
	}

	~CGoods(){
		cout<<"CGoods over."<<endl;
	}

	void printCGoods(){
		cout<<no<<" "<<p_name<<" "<<price<<endl;
	}

	friend char* getName(CGoods& goods);

	virtual void usedFor(){
		cout<<"CGoods::usedFor()"<<endl;
	}
};


class CClothes: public CGoods{
private:
	char* p_brand;
public:
	CClothes(long n, char* pn, double pr, char* pb):CGoods(n, pn, pr){
		p_brand = pb;
	}

	CClothes(CClothes& clothes):CGoods(clothes){
		p_brand = clothes.getPBrand();
	}

	char* getPBrand(){
		return p_brand;
	}

	void usedFor(){
		cout<<"CClothes::usedFor()"<<endl;
	}

	~CClothes(){
		cout<<"CClothes over."<<endl;
	}
};


class CFood: public CGoods{
private:
	char* p_brand;
public:
	CFood(long n, char* pn, double pr,char* pb):CGoods(n,pn,pr){
		p_brand=pb;
	}

	CFood(CFood& cfood):CGoods(cfood){
		p_brand=cfood.getPbrand();
	}

	char* getPbrand(){
		return p_brand;
	}

	void usedFor(){
		cout<<"CFood::usedfod()"<<endl;
	}

	~CFood(){
		cout<<"CFood over"<<endl;
	}
};

int CGoods::count = 0;


char* getName(CGoods& goods){
	return goods.p_name;
}


bool operator < (CGoods& goods1, CGoods& goods2){
	bool r = false;
	if(goods1.getPrice()<goods2.getPrice()){
		r = true;
	}
	return r;
}


bool operator >= (CGoods& goods1, CGoods& goods2){
	bool flag=false;
	if(goods1.getPrice()>=goods2.getPrice()){
		flag=true;
	}
	return flag;
}


void main(){

	CGoods goods1(1,"goods1",30);
	goods1.printCGoods();

	CGoods goods2(goods1);
	goods2.printCGoods();

	CGoods goods3(3,"goods3",30);
	goods3.printCGoods();

	cout<<getName(goods3)<<endl;

	if(goods1<goods3){
		cout<<"goods1 < goods3"<<endl;
	}else{
		cout<<"goods1 <> goods3"<<endl;
	}

	if(goods1>=goods3){
	    cout<<"goods1 >= goods3"<<endl;
	}else{
		cout<<"goods1 < goods3"<<endl;
	}

	CClothes clothes1(4,"clothes1",40,"wear");
	clothes1.printCGoods();

	CClothes clothes2(clothes1);
	clothes2.printCGoods();
	clothes2.usedFor();

	CFood cfood1(5,"cfood1",50,"eat");
	cfood1.printCGoods();

	CFood cfood2(cfood1);
	cfood2.printCGoods();
	cfood2.usedFor();

	CGoods* pGoods;
	cout<<"Input(1.CClothes 2.CFood):"<<endl;
	int se = 1;
	cin>>se;
	if(se==1){
		pGoods = &clothes1;
	}else{
		pGoods = &cfood1;
	}
	pGoods->usedFor();

	cout<<CGoods::getCount()<<endl;

}