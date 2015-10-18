#include <iostream>
#include <iomanip>
using namespace std;

bool Judgeyear(int year)
{
	if((year % 400 ==0) || ((year % 4 ==0) && (year % 100 !=0)))
		return true;
	else
		return false;
}


int Calcuday2(int year,int month)
{
	bool flag;
	int day=0;
	flag=Judgeyear(year);
	for(int i=1;i<month;i++)
	{
		if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
		{
			day=day+31;
		}else if(i==4 || i==6 || i==9 || i==11)
		{
			day=day+30;
		}else if(i==2)
		{
			if(flag==false)
			{
				day=day+28;
			}else
			{
				day=day+29;
			}
		}
	}
	return day;
}


//计算到前一年
int Calcuday(int year,int month)
{
	int d=0; //天数
	int y; //年数
	bool f;
	int Y=1901;
	y=year-1901;
	for(int i=0;i<y;i++)
	{
		f=Judgeyear(Y);
		Y++;
		if(f==false)
			d=d+365;
		else
			d=d+366;
	}
	d=d+Calcuday2(year,month);
	return d;
}


void print(int year,int day,int month)
{
	bool flag;
	int countday;
	int c;
	int count=0;
	flag=Judgeyear(year);
	if(month==1 || month ==3 ||  month ==5 || month ==7 || month == 8 || month==10 || month==12)
		countday=31;
	else if(month==4 || month==6 || month==9 || month==11)
		countday=30;
	else if(month==2)
	{
		if(flag==false)
			countday=28;
		else
			countday=29;
	}
	c=day % 7;
	cout<<"   日   一   二   三   四   五   六"<<endl;
    for(int i=0;i<c+2;i++) //本循环用于输出空格
	{
       cout<<"     ";
       count++;
	}
    for(int j=1;j<=countday;j++) //本循环用于输出日期
	{
       cout<<setw(5)<<j;
       count++;
       if(count%7==0)
           cout<<endl;
	}
}

void main()
{
	int day;
	int year,month;
	cout<<"请输入相应的年份，月份"<<endl;
	cin>>year>>month;
	while (year<1901 || month>12 || month<1)
	{
		cout<<"输入的日期不正确，重新输入"<<endl;
		cin>>year>>month;
	}
	day=Calcuday(year,month);
	//cout<<day;
	print(year,day,month);
	cout<<endl;
}