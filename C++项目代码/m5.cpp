/*#include <iostream.h>
#include <fstream.h>
#include <math.h>
#include <stdlib.h>*/
//using namespace std ;
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
using namespace std ;
class matrix
{       int r,c;
        double **element;
        public:
        matrix(int r1=2,int	c1=2);// 构造函数
//        matrix(char* name);// 构造函数
        matrix(matrix &);//复制构造函数

		operator double**(){return element;};
		double& operator()(int x,int y){return element[x][y];};// 矩阵元素圆括号（）；

		 double det();
		 double mean();
		 //double cov();

	  matrix& operator=(matrix &m);				//重载等号
	  matrix& operator=(double m1);// 重载矩阵赋值号“=”
      matrix& operator+=(matrix &m1);// 重载加（+=）
      matrix& operator-=(matrix &m1);// 重载减（-=）
      matrix& operator*=(matrix &m1); // 重载乘（*=）
      matrix& operator/=(matrix &m1); // 重载除（/=）
 friend matrix operator+(matrix & m1,matrix &m2);// 重载加（+）
 friend matrix operator-(matrix & m1,matrix &m2);// 重载减（-）
 friend matrix operator*(matrix & m1,matrix &m2); // 重载乘（*）
 friend matrix operator/(matrix & m1,matrix &m2); // 重载除（/）
 friend istream & operator>>(istream & in,matrix &m);// 输入（>>）
 friend ostream & operator<<(ostream & o, matrix &m);// 输出（<<）
 double max( ); //求矩阵元素最大值
 double min( ); //求矩阵元素最小值
~matrix();//析构造函数
};

matrix :: matrix(int r1,int c1)  // 构造函数
{	r=r1;c=c1;
    element=new double*[r];
    int i;
    for(i=0;i<r; i++)
		element[i]=new double[c];
	for(i=0;i<r;i++)
		for(int j=0;j<c;j++)
			element[i][j]=0;}

matrix::matrix(matrix &m) //复制构造函数
{   r=m.r;c=m.c;
    element=new double*[r];
    int i;
    for(i=0;i<r; i++)
       element[i]=new double[c];
	for(i=0;i<r;i++)
      for(int j=0;j<c;j++)
       element[i][j]=m.element[i][j];
}
matrix& matrix::operator=(matrix &m1) // 重载矩阵赋值号"="
{ for(int i=0;i<m1.r; i++)
      for(int j=0;j<m1.c;j++)
       element[i][j]= m1.element[i][j];
       return *this;
}
matrix& matrix::operator=(double m1) // 重载矩阵赋值号"="
{for(int i=0;i<r; i++)
      for(int j=0;j<c;j++)
		element[i][j]= m1;
	return *this;
}
matrix& matrix::operator+=(matrix &m1)   // 重载（+=）
 {  for(int i=0;i<r; i++)
       for(int j=0;j<c;j++)
			element[i][j]=element[i][j]+ m1.element[i][j];
	return *this;}
matrix& matrix::operator-=(matrix & m1)// 重载（-=）
 {for(int i=0;i<r; i++)
      for(int j=0;j<c;j++)
			element[i][j]=element[i][j]-m1.element[i][j];
	return *this;}

matrix& matrix::operator*=(matrix &m1)// 重载（*=）
{	matrix aa(r,m1.c);
if (c != m1.r)
{	matrix z(r,c);
	z=*this;
	cout<<"You're worry.这两个矩阵不能相乘!!!Erorr";
	return z;}
else
{
  for(int i=0;i<r; i++)
      for(int j=0;j<m1.c;j++)
		{aa(i,j)=0;
		for(int k=0;k<c;k++)
			aa(i,j)=aa(i,j)+element[i][k]*m1.element[k][j];
		}
}
*this=aa;
return *this;  }

matrix& matrix::operator/=(matrix & m1)// 重载（/=）
{for(int i=0;i<r; i++)
      for(int j=0;j<c;j++)
			element[i][j] /= m1.element[i][j];
return *this; }

matrix operator+(matrix &m1,matrix &m2)  // 重载加（+）
{matrix aa(m1.r,m2.c);
 for(int i=0;i<m1.r; i++)
      for(int j=0;j<m2.c;j++)
			aa(i,j)=m1(i,j)+ m2(i,j);
return aa;}

matrix operator-(matrix & m1,matrix &m2)  // 重载加（-）
{ matrix aa(m1.r,m2.c);
  for(int i=0;i<m1.r; i++)
      for(int j=0;j<m2.c;j++)
		aa(i,j)=m1(i,j)- m2(i,j);
return aa;  }
matrix operator/(matrix & m1,matrix &m2)  // 重载加（/）
{ matrix aa(m1.r,m2.c);
  for(int i=0;i<m1.r; i++)
      for(int j=0;j<m2.c;j++)
       aa(i,j)=m1.element[i][j]/ m2.element[i][j];
return aa;  }
matrix operator*(matrix &m1,matrix &m2)  // 重载加（*）
{ matrix aa(m1.r,m2.c);
if (m1.c != m2.r)
{	matrix z(0,0);
	cout<<"You're worry.这两个矩阵不能相乘!!!Erorr";
	return z;}
else
{  for(int i=0;i<m1.r; i++)
      for(int j=0;j<m2.c;j++)
			{aa(i,j)=0;
			 for(int k=0;k<m1.c;k++)
				aa(i,j)=aa(i,j)+m1.element[i][k]* m2.element[k][j]; };
			 return aa;}
}

istream& operator>>(istream & in,matrix &m)  // 输入（>>）
{  for(int i=0;i<m.r; i++)
      for(int j=0;j<m.c;j++)
         in>>m(i,j);
         return  in;}
ostream& operator<<(ostream & o, matrix &m)  // 输出（<<）
{for(int i=0;i<m.r; i++)
    {for(int j=0;j<m.c;j++)
         o<<m(i,j)<<"  ";
     o<<endl;}
     return o ;}
double matrix::max( )  //求矩阵元素最大值
{double max1;
    max1=element[0][0];
     for(int i=0;i<r; i++)
      for(int j=0;j<c;j++)
        if(max1<element[i][j])
          max1= element[i][j];
return  max1;}

double matrix::min( )  //求矩阵元素最小值
{  double  min1;
   min1=element[0][0];
     for(int i=0;i<r; i++)
      for(int j=0;j<c;j++)
        if(min1>element[i][j])
          min1= element[i][j];
         return  min1;}

double matrix::mean()
{double m,s=0;
	for(int i=0;i<r; i++)
      for(int j=0;j<c;j++)
          s += element[i][j];
	  m=s/(r*c);
	  return m;
}


double matrix::det()    //行列式
{	int i,j,z,l=0;
	int n=r;
	//double *m;
	double max,t,mm=0;
	//m=new double[n];
	matrix M(0,0);
	M.r=r;M.c=c;
    M.element=new double*[r];
    for(i=0;i<r; i++)
       M.element[i]=new double[c];
    for( i=0;i<r; i++)
      for(int j=0;j<c;j++)
        M.element[i][j]=element[i][j];


	for(int k=0;k<n;k++)      //当前第K行的第一个与所在列以后的每一个做比较，得出最大的A[z][k]与第一个所在行的所有交换。
	{	z=k;
		max=fabs(M(z,k));
		for(i=k;i<n;i++)
			if (fabs(M(i,k))>max)
				z=i;
		for(j=k;j<n;j++)
		{
			t=M(k,j);
			M(k,j)=M(z,j);
			M(z,j)=t;
			l += 1;
		}
	}
//cout<<M;
	double cm,s=1;

	for(int kk=0;kk<n;kk++)
	{
		cm=M(kk,kk);
		for(j=kk;j<n;j++)
			M(kk,j)=M(kk,j)/cm;
		s *= cm;

		mm=M(kk+1,kk);

		for(i=kk+1;i<n;i++)
		{	for(j=kk;j<n;j++)
				M(i,j)=M(i,j)-mm*M(kk,j);
		}
	}

	s*=M(r-1,r-1);
	if ((l/2)!=0)
		s=-1*s;
	return s ;
}


matrix::~matrix() //析构造函数
{for(int i=0;i<r; i++)
    delete element[i];
delete element; }

int main()
  {
	  matrix m4,m5,m7,m6(1,2),m1(2,2),m2=m1,m3(m1);
	  m1(0,0)=1;m1(0,1)=2;
	  m1(1,0)=3;m1(1,1)=4;
	  m2(0,0)=4;m2(0,1)=3;
	  m2(1,0)=2;m2(1,1)=1;
	  //cout<<m3<<endl;
	  m4=4;
	  m6=6;
	  cout<<m4<<endl;
	  cout<<m2.det()<<endl;
	  //m6*=m4;
	  //cout<<(m4/=m2)<<endl;
	  //cout<<m4<<endl;
	 // m7=m4*m2;
	  //cout<<(m7)<<endl;
	  cout<<(m2.mean())<<endl;
	  cout<<m6<<endl;
	  cout<<(m4*=m6)<<endl;
	  cout<<(m2.max())<<endl;
	  //cout<<*(m1+m2);
	  /*cin>>m2;
	  m3=m1+m2;
	  cout<<m3;
	  m3=m1*m2;
	  cout<<m3;
	  m3+=m1;
	  cout<<m3<<"\n"<< m3.max();*/

  }
