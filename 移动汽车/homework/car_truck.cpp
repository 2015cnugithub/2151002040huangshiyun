#include <graphics.h>
#include <conio.h>
#include <iostream>


using namespace std;

enum TYPE{CIRCLE,RECTANGLE,TRIANGLE};
class FigureLink;
//static Figure* conents[7];

class Figure
{
	friend class FigureLink;
	friend class Vehicle;
protected:
	TYPE type;
	int cx,cy;         //绘制图形的中心位置坐标
	int linestyle;     //划线样式
	int linewidth;     //划线宽度
	int linecolor;     //划线颜色
	int fillpattern;   //封闭图形的填充样式
	int fillcolor;     //封闭图形的填充颜色
	//static Figure* ptr;
	Figure *next;
public:
	/*Figure(int x,int y,TYPE ty,int style=0,int width=1,int color=BLACK,int fpattern=EMPTY_FILL,int fcolor=BLACK)
	{
		cx=x;
		cy=y;
		type=ty;
		linestyle=style;
		linewidth=width;
		linecolor=color;
		fillpattern=fpattern;
		fillcolor=fcolor;
	}*/
	virtual void draw()=0;
	virtual void hide()=0;
	virtual void move(int i)=0;
	~Figure()
	{
	}
};


class Circle: public Figure
{
private:
	int radius;
	int xstart,ystart;
public:
	Circle(int x,int y,int r)//,TYPE ty,int style,int width,int color,int fpattern,int fcolor)//:Figure(x,y,ty,style,width,color,fpattern,fcolor)
	{
		xstart=x;
		ystart=y;
		radius=r/2;
	}
	void draw()
	{
		//setcolor(WHITE);
		circle(xstart,ystart,radius);
	}
	void hide()
	{
		clearcircle(xstart,ystart,radius);
	}
	void move(int i)
	{
		   xstart=xstart+2*i;
		   /*if(xstart>660)
		   {
			   xstart=0;
		   }*/
	}
	~Circle(){}
};


class Retangle: public Figure
{
private:
	int left;
	int top;
	int right;
	int bottom;
public:
	Retangle(int l,int t,int r,int b)//,TYPE ty,int style=0,int width=1,int color=BLACK,int fpattern=EMPTY_FILL,int fcolor=BLACK):Figure(x,y,ty,style,width,color,fpattern,fcolor)
	{
		left=l;
		top=t;
		right=r;
		bottom=b;
	}
	void draw()
	{
		rectangle(left,top,right,bottom);
	}
	void hide()
	{
		clearrectangle(left,top,right,bottom);
	}
	void move(int i)
	{

		  left=left+2*i;
		  right=right+2*i;
		  /*if(left>660)
		  {
			  left=0;
		  }
		  if(right>660)
		  {
			  right=0;
		  }*/
	}
	~Retangle(){}
};


class Triangle:public Figure
{
private:
	int a_x;
	int a_y;
	int b_x;
	int b_y;
	int c_x;
	int c_y;
public:
	Triangle(int a,int b,int c,int d,int e,int f)//,TYPE ty,int style=0,int width=1,int color=BLACK,int fpattern=EMPTY_FILL,int fcolor=BLACK):Figure(x,y,ty,style,width,color,fpattern,fcolor)
	{
        a_x=a;
		a_y=b;
		b_x=c;
		b_y=d;
		c_x=e;
		c_y=f;
	}
	void draw()
	{
		POINT points[]={{a_x,a_y},{b_x,b_y},{c_x,c_y}};
		polygon(points,3);
	}
	void hide()
	{
		POINT points[]={{a_x,a_y},{b_x,b_y},{c_x,c_y}};
		clearpolygon(points,3);
	}
	void move(int i)
	{
		  a_x=a_x+2*i;
		  b_x=b_x+2*i;
		  c_x=c_x+2*i;
		  /*if(a_x>660)
		  {
			  a_x=0;
		  }
		  if(b_x>660)
		  {
			  b_x=0;
		  }
		   if(b_x>660)
		  {
			  b_x=0;
		  }*/
	}
	~Triangle(){}
};


class FigureLink
{
	friend class Vehicle;
private:
	Figure* head;
	//FigureLink *next;
public:
	FigureLink()
	{
		head=NULL;
	}
	void insert(Figure* figurenode)
	{
		Figure *p,*q;
		q=p=head;
		//q=NULL;
		if(head==NULL)
		{
			head=figurenode;
			head->next=NULL;
		}else
		{
			while(p!=NULL)
			{
			   q=p;
			   p=p->next;
			}
		    p=figurenode;
		    q->next=p;
		    p->next=NULL;
		}

	}

};

class Vehicle
{
protected:
	FigureLink contents;
public:
	void Draw()
	{
		Figure *p;
		p=contents.head;
		while(p!=NULL)
		{
			p->draw();
			p=p->next;
		}
	}
	void Hide()
	{
		Figure *p;
		p=contents.head;
		while(p!=NULL)
		{
			p->hide();
			p=p->next;
		}
	}
	void Move(int i)
	{
		Figure *p;
		p=contents.head;
		while(p!=NULL)
		{
			p->move(i);
			p=p->next;
		}
	}
};


class Car:public Vehicle
{
public:
	Car(int xstart,int ystart,int wheel_size)
	{	
		Figure* p;
		p=new Circle(xstart,ystart,wheel_size);//,CIRCLE,0,1,BLACK,EMPTY_FILL,BLACK);
		contents.insert(p);

		p=new Circle(xstart+4.5*wheel_size,ystart,wheel_size);//,CIRCLE,0,1,BLACK,EMPTY_FILL,BLACK);
		contents.insert(p);

		p=new Retangle(xstart-1.5*wheel_size,ystart-1.5*wheel_size,xstart+6.5*wheel_size,ystart-0.5*wheel_size);//CIRCLE,0,1,BLACK,EMPTY_FILL,BLACK);
		contents.insert(p);

		p=new Retangle(xstart+0.5*wheel_size,ystart-2.5*wheel_size,xstart+4*wheel_size,ystart-1.5*wheel_size);//CIRCLE,0,1,BLACK,EMPTY_FILL,BLACK);
		contents.insert(p);

		p=new Triangle(xstart-0.5*wheel_size,ystart-1.5*wheel_size,xstart+0.5*wheel_size,ystart-1.5*wheel_size,xstart+0.5*wheel_size,ystart-2.5*wheel_size);
		contents.insert(p);

		p=new Triangle(xstart+4*wheel_size,ystart-1.5*wheel_size,xstart+4*wheel_size,ystart-2.5*wheel_size,xstart+5*wheel_size,ystart-1.5*wheel_size);
		contents.insert(p);

	}
	~Car(){}
};

class Truck:public Vehicle
{
private:
public:
	Truck(int xstart,int ystart,int wheel_size)
	{
		Figure* p;
		p=new Circle(xstart,ystart,wheel_size);
		contents.insert(p);

		p=new Circle(xstart+1.25*wheel_size,ystart,wheel_size);
		contents.insert(p);

		p=new Circle(xstart+5.75*wheel_size,ystart,wheel_size);
		contents.insert(p);

		p=new Circle(xstart+7*wheel_size,ystart,wheel_size);
		contents.insert(p);

		p=new Circle(xstart+9*wheel_size+2,ystart,wheel_size);
		contents.insert(p);

		p=new Retangle(xstart-wheel_size,ystart-4.5*wheel_size,xstart+8*wheel_size,ystart-0.5*wheel_size);
		contents.insert(p);

		p=new Retangle(xstart+8*wheel_size+2,ystart-3.5*wheel_size,xstart+10*wheel_size+2,ystart-0.5*wheel_size);
		contents.insert(p);


	}
	~Truck(){}
};

void main()
{

	int d;
	FigureLink *head;


	cout<<"请输出车轮尺寸"<<endl;
	cin>>d;

	int move=1;
	int flag=0;
	int z=0;
	//POINT point1[]={{35,420},{55,420},{55,400}};
	//POINT point2[]={{80,420},{100,420},{80,400}};
	initgraph(1100,500);
	//绘制图形界面
	outtextxy(10,10,_T("1 car  2 Truck  3 Exit"));
	
	outtextxy(10,30,_T("Press <S> key to start moving"));
	outtextxy(10,50,_T("Press <P> key to pause/continue moving"));
	outtextxy(10,70,_T("Press <E> key to end moving"));
	outtextxy(10,90,_T("Press <+> key to speed up"));
	outtextxy(10,110,_T("Press <-> key to speed down"));
	//绘制汽车图形
	Vehicle *v;
	int k;
	while(1)
	{
		if(kbhit())
		{
			int j=getch();
			if(j=='1')
			{
				Car c(30,450,d);
	            v=&c;
  	            v->Draw();
				flag=0;
				z=1;
			}
			if(j=='2')
			{
				Truck c(30,450,d);
	            v=&c;
 	            v->Draw();
				flag=0;
				z=1;
			}
			if(j=='3')
			{
				break;
			}
			k=getch();
			while((z==1))
			{
				//k=getch();
				if((k=='s') || (k=='S'))
				{
					 while(flag==0)
					 {
						 v->Hide();
						 v->Move(move);
						 v->Draw();
						 Sleep(50);
						 //flag=1;
						 if(kbhit())
						 {
							k=getch();
							 flag=1;
							 break;
						  }
					  }
				}
				//k=getch();
				if(((k=='p') || (k=='P')) && (flag!=0))
				{
					//v->Draw();
					while(flag!=0)
					{
						v->Draw();
				        if(kbhit())
						{
						    flag=0;
						    //break;
						    k=getch();
						}
					}
						
				}
					//k=getch();
				if(((k=='p') || (k=='P'))&&(flag==0))
				{
					while(true)
					{
						v->Hide();
						v->Move(move);
						v->Draw();
						Sleep(50);
						if(kbhit())
						{
							flag=1;
							k=getch();
							break;
						}
					}
				}
				//k=getch();
				if(k=='+')
				{
					move++;
					while(true)
					{
					    v->Hide();
						v->Move(move);
						v->Draw();
						Sleep(20);
						if(kbhit())
						{
							flag=0;
							k=getch();
							break;
						}
					}
				}
				//k=getch();
				if(k=='-')
				{
					move--;
					if(move<=1)
					{
						move=1;
					}
					while(true)
					{
						v->Hide();
						v->Move(move);
						v->Draw();
					    Sleep(20);
						if(kbhit())
						{
							flag=0;
							k=getch();
							break;
						}
					}
				}
				if((k=='e') || (k=='E'))
				{
					v->Hide();
					break;
				}
			}
		}
	}
	closegraph();
}