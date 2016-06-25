# include <iostream.h>
//int n=3,m=4,p=2;                  //F(n*p)=A(n*m)*B(m*p)
int n=1,m=2,p=3;   

//r是矩阵x的行数，c是矩阵x的列数
void input(double **x,int r,int c);
void output(double **x,int r,int c);    //规定输出一维数组时行数为0,output(x,0,c); 

void tr(double **x,double **y,int r,int c);   //y是矩阵x的转置

void counst_column(double **x,int r,int c);//把按列求时，行数c赋为一个值的矩阵N[0][0]
void mean_column(double **x,double **y,double **z,int r,int c);//mean_column(x,C,N,r,c);y是x按列求的均值的矩阵C；z是行数c一个值的矩阵N
void var_column(double **x,double **y,double **z,double **w,int r,int c);//var_column(x,C,N,D,r,c);w是x按列求的方差的矩阵D

void multiply(double **x,double **y,double **z,int n,int m,int p );//z(n*p)=x(n*m)*y(m*p)

void main()
{   int i;
	double **A,**E,**F,**B,**C,**D,**N;//B是转置，C是均值，D是方差，N是行的数目矩阵
    //定义指针：A(n*m),E(m*p),F(n*p),B(m*n),C(0*m),D(0*m),N(0*0)
	A=new double * [n];
    E=new double * [m];
	F=new double * [n];
	B=new double * [m];
    C=new double * [0];
	D=new double * [0];

	N=new double * [0];
	N[0]=new double[0];

	for(i=0;i<n;i++)
	{
		A[i]=new double[m];
		F[i]=new double[p];
		C[i]=new double[m];
		D[i]=new double[m];         //C,D定义列数时可以不完全匹配，但不能与实际所用相差太大
		
	}
	for(i=0;i<m;i++)
	{E[i]=new double[p];	
	 B[i]=new double[n];
	}                                 

    
    input(A,n,m);                     //输入A,E
	input(E,m,p);

	tr(A,B,n,m);                      //求A的转置B
	mean_column(E,C,N,m,p);           //求E的均值C
	var_column(E,C,N,D,m,p);          //求E的方差D
	multiply(A,E,F,n,m,p );           //求F(n*p)=A(n*m)*B(m*p)

	output(A,n,m);                    //输出A,E
	output(E,m,p); 
	output(B,m,n);                    //输出转置B
	output(C,0,p);                    //输出E的均值C
	output(D,0,p);                    //输出E的方差D	
    output(F,n,p);                    //输出F(n*p)=A(n*m)*B(m*p)

	delete []A;
	delete []B;
	delete []C;
	delete []D;
	delete []E;
	delete []F;
	delete []N;
}





void counst_column(double **x,int r,int c)
{   
	x[0][0]=r;
}

void tr(double **x,double **y,int r,int c)
{   int i,j;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			y[j][i]=x[i][j];
}

void input(double **x,int r,int c)
{   int i,j;
    static num=1;
    cout<<"Please input "<<r<<"行"<<c<<"列的矩阵"<<num<<":"<<endl;
	cout<<"(注意按行输入)"<<endl;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cin>>x[i][j];
		}
	}
	num += 1;
}

void output(double **x,int r,int c)
{   int i,j;
    static num2=1;
    cout<<"Now output matrix"<<num2<<":"<<endl;
	if (r==0){
		for(j=0;j<c;j++)
			cout<<x[0][j]<<"    ";
		cout<<endl;
	} 
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			cout<<x[i][j]<<"    ";
        cout<<endl;
	}
	num2 +=1;
}

void mean_column(double **x,double **y,double **z,int r,int c)
{   int i,j;
    counst_column(z,r,c);
	for(j=0;j<c;j++)
	{   y[0][j]=0;
		for(i=0;i<r;i++)
			y[0][j] += x[i][j]/z[0][0];
	}	
}

void var_column(double **x,double **y,double **z,double **w,int r,int c)
{	int i,j;
    mean_column(x,y,z,r,c);
	for(j=0;j<c;j++)
	{   w[0][j]=0;
		for(i=0;i<r;i++)
			w[0][j] += (x[i][j]-y[0][j])*(x[i][j]-y[0][j])/z[0][0];
	}	

}

void multiply(double **x,double **y,double **z,int n,int m,int p )
{   int i,j,l;
    for(i=0;i<n;i++)
		 for(j=0;j<p;j++)
		 {   
			 z[i][j]=0;
			 for(l=0;l<m;l++)
                 z[i][j] += x[i][l]*y[l][j];
		 }
}