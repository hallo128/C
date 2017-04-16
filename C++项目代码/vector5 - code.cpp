/*#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
using namespace std ;*/
#include <iostream.h>
#include <fstream.h>
#include <math.h>
#include <stdlib.h>


class vector
{    int len;
     double *element;
public:
	vector(int x=4);				//默认构造向量长度为4
	vector(vector&v);				//复制构造函数
	vector(char*);					//将文件读入向量中

	operator double*(){return element;};				//由vector转换为double的指针
	double& operator()(int x){return element[x];};		//重载(),v(2)=element[2];eg:v(2)

	vector& operator =(vector&);	//eg:v=v1
	//vector& operator =(double&);    //v中的所有元素都为8，eg:double x=8;v=x;
	vector& operator =(double);		//v中的所有元素都为8，eg:v=8;不需要先赋值x
	vector& operator +=(vector&);	//两个长度不一定一致的向量对应元素相加，eg:v+=v1将v1加到v
	vector& operator -=(vector&);	//两个长度不一定一致的向量对应元素相减，eg:v-=v1将v1减到v
	double& operator *=(vector&);	//若两个长度不相等的相乘，提示Erorr0;否则内积计算。eg:(v*=v1)单独返回一个值，并没有更新v
	vector& operator /=(vector&);	//两个长度不一定一致的向量对应元素相除，eg:v/=v1将v1除到v
	friend vector operator+(vector & m1,vector &m2);// 重载加（+），eg:v3=v+v1,(v+v1)是向量，最后赋值给v3；但不会改变v和v1的值
	friend vector operator-(vector & m1,vector &m2);// 重载减（-）,eg:v3=v-v1,(v-v1)是向量，最后赋值给v3；但不会改变v和v1的值
	friend double operator*(vector & m1,vector &m2); // 重载乘（*）
	friend vector operator/(vector & m1,vector &m2); // 重载除（/）

	double mean();//求向量的均值，eg:v.mean()为double数值;
	double var();//求向量的方差，eg:v.var()为double数值;
	vector mintomax();//将向量按从小到大排序，eg:v.mintomax(),但函数结束后，不改变原来向量的排序

	friend istream & operator>>(istream & in,vector &m);// 输入（>>）
	friend ostream & operator<<(ostream & o, vector &m);// 输出（<<）
	~vector();				//析构函数
};
vector::vector(int x)
{    len=x;
     element=new double[len];
	 for(int i=0;i<len;i++)
		 element[i]=0;
}
vector::vector(vector &v){
	 len=v.len;
     element=new double[len];
	 for(int i=0;i<len;i++)
		 element[i]=v.element[i];
}
double vector::mean()
{  double m,s=0;
   for(int i=0;i<len;i++)
	   s += element[i];
   m=s/len;
   return m;
}
double vector::var()
{  double var,s=0;
   for(int i=0;i<len;i++)
	   s += (element[i]-(*this).mean())*(element[i]-(*this).mean());
   var=s/len;
   return var;
}
vector vector::mintomax()
{	int i,j;
	vector v,v1;
	v=*this;
	v1=*this;
	for(i=0;i<len;i++)
		for(j=i+1;j<len;j++)
			if(v.element[i]>v.element[j])
			{	v1(i)=v.element[j];
				v.element[j]=v.element[i];
				v.element[i]=v1(i);}
	return v;
}
vector::~vector()
{ delete []element;}

vector& vector::operator =(vector &v)
{	len=v.len;
	element=new double[len];
	for(int i=0;i<len;i++)
		 element[i]=v.element[i];
	return *this;
}
/*vector& vector::operator =(double &x)
{	for(int i=0;i<len;i++)
		 element[i]=x;
	return *this;
}*/
vector& vector::operator =(double x)
{	for(int i=0;i<len;i++)
		 element[i]=x;
	return *this;
}
vector& vector::operator +=(vector &v)
{	int num;
	if (len>v.len)
		num=v.len;
	for(int i=0;i<num;i++)
		 element[i]+=v.element[i];
	return *this;
}
vector& vector::operator -=(vector &v)
{	int num;
	if (len>v.len)
		num=v.len;
	for(int i=0;i<num;i++)
		 element[i]-=v.element[i];
	return *this;
}
double& vector::operator *=(vector &v)
{	double m=0;
	if (len != v.len)
	{ cout<<"You're worry.vectors have different lens!!!Erorr";
    return	m;
	abort();}
	else
	{double s=0;
	for(int i=0;i<len;i++)
		 s += element[i] * v.element[i];
	return s;}
}
vector& vector::operator /=(vector &v)
{	int num;
	if (len>v.len)
		num=v.len;
	for(int i=0;i<num;i++)
		 element[i] /= v.element[i];
	return *this;
}

double operator*(vector & m1,vector &m2)
{
	double m=0;
	if (m1.len != m2.len)
	{ cout<<"You're worry.vectors have different lens!!!Erorr";
    return	m;
	abort();}
	else
	{	double s=0;
		for(int i=0;i<m1.len;i++)
			s += m1.element[i] * m2.element[i];
		return s;}
}


vector operator+(vector &v1,vector &v2)
{   int num;      
    vector v;
	if (v1.len>v2.len)	//num是短的长度，v是长的变量的值
		{num=v2.len;
		v=v1;}
    else
        {num=v1.len;
		v=v2;}
    for(int i=0;i<num; i++)
        v(i)=v1.element[i]+ v2.element[i];
    return v;           //返回的是向量v的第一个的指针
}
vector operator-(vector &v1,vector &v2)
{   int num;      
    vector v;
	if (v1.len>v2.len)	//num是短的长度，v是长的变量的值
		{num=v2.len;
		v=v1;}
    else
        {num=v1.len;
		v=v2;}
    for(int i=0;i<num; i++)
        v(i)=v1.element[i]-v2.element[i];
    return v;           //返回的是向量v的第一个的指针
}
vector operator/(vector &v1,vector &v2)
{       
    vector v(0);
	for(int i=0;i<v2.len; i++)
		if(v2(i)==0)
		{cout<<"被除向量不能含有0，请重新确定被除向量!!!";v=0;return v;}
	if (v1.len != v2.len)
	{ cout<<"You're worry.vectors have different lens!!!Erorr";
    return	v;
	abort();}
    for(i=0;i<v1.len; i++)
        v(i)=v1.element[i]/v2.element[i];
    return v;           //返回的是向量v的第一个的指针
}

vector::vector(char* fname)
    {
      int N,i;
      double buf;
      ifstream file(fname);
      if( file.fail())
       return;
       N=0;
      file.seekg(0,ios::beg);
      while(!file.eof()){
      file>>buf;
      N=N+1;
      };
      //N=N-1;
	  vector v(N);						// 等价于len=N;element=new double[len];
	  *this=v;							// 等价于len=N;element=new double[len];
      file.clear();
      file.seekg(0,ios::beg);
      for(i=0;i<N;i++)
	 file>>element[i];
      }

ostream &operator<<(ostream &o, vector &m)  // 输出（<<）
{		for(int i=0;i<m.len; i++)			
			o<<m(i)<<"  ";					//o<<m.element[i]<<"  ";
         return o ;
}
istream & operator>>(istream &in,vector &m)
{		for(int i=0;i<m.len; i++)
			in>>m(i);						//in>>m.element[i];
        return in ;
}

void main()
{
	vector v,v1(8),v2(6),v3("e:\\cj.txt");
cout<<"(默认构造函数)v:"<<endl;		//默认构造函数
cout<<v<<endl;

cout<<"(读入文件的数据的向量)v3:"<<endl;		//读入文件的数据的向量
cout<<v3<<endl;

v2=5;
cout<<"(将v2中的每个数都赋值为5)v2:"<<endl;		//将v2中的每个数都赋值为5
cout<<v2<<endl;

cout<<"通过键盘将v1中的每个数都分别赋值:"<<endl;
cin>>v1;
cout<<"v1:"<<endl;		//通过键盘将v1中的每个数都分别赋值
cout<<v1<<endl;
		
cout<<"v1均值:	"<<v1.mean()<<endl;//均值
cout<<"v1方差:	"<<v1.var()<<endl;//方差
cout<<"将v1按从小到大排序:	"<<v1.mintomax()<<endl;		//将v1按从小到大排序

cout<<"v3 * v1  :"<<endl;
cout<<(v3 * v1)<<endl;

cout<<"v1 * v2  :"<<endl;
cout<<(v1 * v2)<<endl;

cout<<"v3 / v2  :"<<endl;
cout<<(v3 / v2)<<endl;
v=v1;
v(2)=0;
cout<<"v与v1相同长度但有一个元素为0；v1 / v  :"<<endl;
cout<<(v1 / v)<<endl;

/*
v1=10;
v3=v+v1;
cout<<v3<<endl;
double m;
m=v1.mean();
cout<<m<<endl;
cout<<v1.var()<<endl;
v5(3)=2;v5(2)=1;v5(1)=2;v5(0)=6;
cout<<v5.mintomax()<<endl;
cout<<v5<<endl;
cout<<v5 * (v5.mintomax())<<endl;
cout<<(v5*=v5)<<endl;
cout<<v5<<endl;*/
//v3=v/v4;
//cout<<v3<<endl;
/*
//v1=v;
//double x=8;
v=8;
cout<<v1<<endl;
cout<<v<<endl;
cout<<v(8)<<endl;

//cout<<(v-=v1)<<endl;

double m=(v*=v1);
cout<<m<<endl;

//v3=*(v+v1);             //v+v1的第一个元素，即v3的每个元素都为第一个元素
//v3=vector(v+v1);
//v3=(v+v1);
//cout<<(v/=v1)<<endl;
cout<<v3<<endl;
cout<<(v+v1)<<endl;
//cout<<*(v+v1)<<endl;             //返回的是指针；因为定义向量时有指针，所以不能正确返回为向量形式。应该强制转换,自动由向量转换为指针。
//cout<<(*((v+v1)+8))<<endl;
*/
}
