#include <iostream>
#include <string>

using namespace std;
class Worker;
ostream& operator <<(ostream& output,Worker& worker);

class Worker
{
private:
	string name;
	int age;
	string sex;
	double pay_per_hour;
	int type;
public:
	Worker(string n,int a,string s,int t,double pay)
	{
		name=n;
		age=a;
		sex=s;
		type=t;
		pay_per_hour=pay;
	}

	string Getname()
	{
		return name;
	}

	int Getage()
	{
		return age;
	}

	string Getsex()
	{
		return sex;
	}

	int Gettype()
	{
		return type;
	}

	double Getpay_per_hour()
	{
		return pay_per_hour;
	}

	void Name()
	{
		cout<<name<<endl;
	}

	virtual double Compute_pay(double hours)
	{
		return 0;
	}

    friend ostream& operator <<(ostream& output,Worker& worker);
	~Worker(){}
};


ostream& operator << (ostream& output,Worker& worker)
{
	output<<"name:"<<worker.Getname()<<endl;
	output<<"age:"<<worker.Getage()<<endl;
	output<<"sex:"<<worker.Getsex()<<endl;
	output<<"type:"<<worker.Gettype()<<endl;
	output<<"pay_per_hour:"<<worker.Getpay_per_hour()<<endl;
	return output;
}


class HourlyWorker:public Worker
{   
//计时工人
private:
	double weeksalary;
public:
	HourlyWorker(string n,int a,string s,int t,double pay):Worker(n,a,s,t,pay){}

	double Compute_pay(double hours)
	{
	  if(hours<40)
	 	 weeksalary=Getpay_per_hour() * hours;
	  else
		 weeksalary=Getpay_per_hour() * 40 + 1.5 * Getpay_per_hour() * (hours - 40);
	  return weeksalary;
	}

};



class SalariedWorker:public Worker
{
//计薪工人
private:
	double weeksalary;
public:
	SalariedWorker(string n,int a,string s,int t,double pay):Worker(n,a,s,t,pay){}
    double Compute_pay(double hours)
    {
	   if (hours-35>=0)
		   weeksalary= Getpay_per_hour() * 40;
	   else
		   weeksalary= Getpay_per_hour() * hours + 0.5 * Getpay_per_hour() * (35 - hours);
	   return weeksalary;
	}
};


void main()
{
	int k=0;
	double hours;
	char c;
	int i;
	Worker* workers[5];
	string n;
	int age;
	string sex;
	double pay_per_hour;
	int type;
	for(i=0;i<5;i++)
	{
		cout<<"name:";
		cin>>n;
		cout<<"age:";
		cin>>age;
		cout<<"sex:";
		cin>>sex;
		cout<<"type:";
		cin>>type;
		cout<<"pay_per_hour:";
		cin>>pay_per_hour;
		if(type==1)
		{
			workers[i]=new HourlyWorker(n,age,sex,type,pay_per_hour);
		}else
		{
			workers[i]=new SalariedWorker(n,age,sex,type,pay_per_hour);
		}  
	}
	do
	{
		for(i=0;i<5;i++)
		{
			cout<<i+1<<":";
		    workers[i]->Name();
		}
		cout<<"0:exit"<<endl;
	    cout<<"选择显示的工人信息"<<endl;
	    cin>>k;
		while(k<=0 || k>5)
		{
			cout<<"error! input again"<<endl;
			cin>>k;
		}
		
		if(k==6)
		{
			break;
		}else
		{
			cout << *workers[k-1];
		    cout<<"计算周薪(y/n):";
		    cin>>c;
		    if(c=='y')
			{
		       cout<<"工作时长:";
	           cin>>hours;
		       cout<<"weeksalary:";
	           cout<<workers[k]->Compute_pay(hours)<<endl;
			}
		}
	}while(k!=6);
}



