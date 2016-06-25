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
	vector(int x=4);				//Ĭ�Ϲ�����������Ϊ4
	vector(vector&v);				//���ƹ��캯��
	vector(char*);					//���ļ�����������

	operator double*(){return element;};				//��vectorת��Ϊdouble��ָ��
	double& operator()(int x){return element[x];};		//����(),v(2)=element[2];eg:v(2)

	vector& operator =(vector&);	//eg:v=v1
	//vector& operator =(double&);    //v�е�����Ԫ�ض�Ϊ8��eg:double x=8;v=x;
	vector& operator =(double);		//v�е�����Ԫ�ض�Ϊ8��eg:v=8;����Ҫ�ȸ�ֵx
	vector& operator +=(vector&);	//�������Ȳ�һ��һ�µ�������ӦԪ����ӣ�eg:v+=v1��v1�ӵ�v
	vector& operator -=(vector&);	//�������Ȳ�һ��һ�µ�������ӦԪ�������eg:v-=v1��v1����v
	double& operator *=(vector&);	//���������Ȳ���ȵ���ˣ���ʾErorr0;�����ڻ����㡣eg:(v*=v1)��������һ��ֵ����û�и���v
	vector& operator /=(vector&);	//�������Ȳ�һ��һ�µ�������ӦԪ�������eg:v/=v1��v1����v
	friend vector operator+(vector & m1,vector &m2);// ���ؼӣ�+����eg:v3=v+v1,(v+v1)�����������ֵ��v3��������ı�v��v1��ֵ
	friend vector operator-(vector & m1,vector &m2);// ���ؼ���-��,eg:v3=v-v1,(v-v1)�����������ֵ��v3��������ı�v��v1��ֵ
	friend double operator*(vector & m1,vector &m2); // ���سˣ�*��
	friend vector operator/(vector & m1,vector &m2); // ���س���/��

	double mean();//�������ľ�ֵ��eg:v.mean()Ϊdouble��ֵ;
	double var();//�������ķ��eg:v.var()Ϊdouble��ֵ;
	vector mintomax();//����������С��������eg:v.mintomax(),�����������󣬲��ı�ԭ������������

	friend istream & operator>>(istream & in,vector &m);// ���루>>��
	friend ostream & operator<<(ostream & o, vector &m);// �����<<��
	~vector();				//��������
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
	if (v1.len>v2.len)	//num�Ƕ̵ĳ��ȣ�v�ǳ��ı�����ֵ
		{num=v2.len;
		v=v1;}
    else
        {num=v1.len;
		v=v2;}
    for(int i=0;i<num; i++)
        v(i)=v1.element[i]+ v2.element[i];
    return v;           //���ص�������v�ĵ�һ����ָ��
}
vector operator-(vector &v1,vector &v2)
{   int num;      
    vector v;
	if (v1.len>v2.len)	//num�Ƕ̵ĳ��ȣ�v�ǳ��ı�����ֵ
		{num=v2.len;
		v=v1;}
    else
        {num=v1.len;
		v=v2;}
    for(int i=0;i<num; i++)
        v(i)=v1.element[i]-v2.element[i];
    return v;           //���ص�������v�ĵ�һ����ָ��
}
vector operator/(vector &v1,vector &v2)
{       
    vector v(0);
	for(int i=0;i<v2.len; i++)
		if(v2(i)==0)
		{cout<<"�����������ܺ���0��������ȷ����������!!!";v=0;return v;}
	if (v1.len != v2.len)
	{ cout<<"You're worry.vectors have different lens!!!Erorr";
    return	v;
	abort();}
    for(i=0;i<v1.len; i++)
        v(i)=v1.element[i]/v2.element[i];
    return v;           //���ص�������v�ĵ�һ����ָ��
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
	  vector v(N);						// �ȼ���len=N;element=new double[len];
	  *this=v;							// �ȼ���len=N;element=new double[len];
      file.clear();
      file.seekg(0,ios::beg);
      for(i=0;i<N;i++)
	 file>>element[i];
      }

ostream &operator<<(ostream &o, vector &m)  // �����<<��
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
cout<<"(Ĭ�Ϲ��캯��)v:"<<endl;		//Ĭ�Ϲ��캯��
cout<<v<<endl;

cout<<"(�����ļ������ݵ�����)v3:"<<endl;		//�����ļ������ݵ�����
cout<<v3<<endl;

v2=5;
cout<<"(��v2�е�ÿ��������ֵΪ5)v2:"<<endl;		//��v2�е�ÿ��������ֵΪ5
cout<<v2<<endl;

cout<<"ͨ�����̽�v1�е�ÿ�������ֱ�ֵ:"<<endl;
cin>>v1;
cout<<"v1:"<<endl;		//ͨ�����̽�v1�е�ÿ�������ֱ�ֵ
cout<<v1<<endl;
		
cout<<"v1��ֵ:	"<<v1.mean()<<endl;//��ֵ
cout<<"v1����:	"<<v1.var()<<endl;//����
cout<<"��v1����С��������:	"<<v1.mintomax()<<endl;		//��v1����С��������

cout<<"v3 * v1  :"<<endl;
cout<<(v3 * v1)<<endl;

cout<<"v1 * v2  :"<<endl;
cout<<(v1 * v2)<<endl;

cout<<"v3 / v2  :"<<endl;
cout<<(v3 / v2)<<endl;
v=v1;
v(2)=0;
cout<<"v��v1��ͬ���ȵ���һ��Ԫ��Ϊ0��v1 / v  :"<<endl;
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

//v3=*(v+v1);             //v+v1�ĵ�һ��Ԫ�أ���v3��ÿ��Ԫ�ض�Ϊ��һ��Ԫ��
//v3=vector(v+v1);
//v3=(v+v1);
//cout<<(v/=v1)<<endl;
cout<<v3<<endl;
cout<<(v+v1)<<endl;
//cout<<*(v+v1)<<endl;             //���ص���ָ�룻��Ϊ��������ʱ��ָ�룬���Բ�����ȷ����Ϊ������ʽ��Ӧ��ǿ��ת��,�Զ�������ת��Ϊָ�롣
//cout<<(*((v+v1)+8))<<endl;
*/
}
