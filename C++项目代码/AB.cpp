# include <iostream.h>
//int n=3,m=4,p=2;                  //F(n*p)=A(n*m)*B(m*p)
int n=1,m=2,p=3;   

//r�Ǿ���x��������c�Ǿ���x������
void input(double **x,int r,int c);
void output(double **x,int r,int c);    //�涨���һά����ʱ����Ϊ0,output(x,0,c); 

void tr(double **x,double **y,int r,int c);   //y�Ǿ���x��ת��

void counst_column(double **x,int r,int c);//�Ѱ�����ʱ������c��Ϊһ��ֵ�ľ���N[0][0]
void mean_column(double **x,double **y,double **z,int r,int c);//mean_column(x,C,N,r,c);y��x������ľ�ֵ�ľ���C��z������cһ��ֵ�ľ���N
void var_column(double **x,double **y,double **z,double **w,int r,int c);//var_column(x,C,N,D,r,c);w��x������ķ���ľ���D

void multiply(double **x,double **y,double **z,int n,int m,int p );//z(n*p)=x(n*m)*y(m*p)

void main()
{   int i;
	double **A,**E,**F,**B,**C,**D,**N;//B��ת�ã�C�Ǿ�ֵ��D�Ƿ��N���е���Ŀ����
    //����ָ�룺A(n*m),E(m*p),F(n*p),B(m*n),C(0*m),D(0*m),N(0*0)
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
		D[i]=new double[m];         //C,D��������ʱ���Բ���ȫƥ�䣬��������ʵ���������̫��
		
	}
	for(i=0;i<m;i++)
	{E[i]=new double[p];	
	 B[i]=new double[n];
	}                                 

    
    input(A,n,m);                     //����A,E
	input(E,m,p);

	tr(A,B,n,m);                      //��A��ת��B
	mean_column(E,C,N,m,p);           //��E�ľ�ֵC
	var_column(E,C,N,D,m,p);          //��E�ķ���D
	multiply(A,E,F,n,m,p );           //��F(n*p)=A(n*m)*B(m*p)

	output(A,n,m);                    //���A,E
	output(E,m,p); 
	output(B,m,n);                    //���ת��B
	output(C,0,p);                    //���E�ľ�ֵC
	output(D,0,p);                    //���E�ķ���D	
    output(F,n,p);                    //���F(n*p)=A(n*m)*B(m*p)

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
    cout<<"Please input "<<r<<"��"<<c<<"�еľ���"<<num<<":"<<endl;
	cout<<"(ע�ⰴ������)"<<endl;
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