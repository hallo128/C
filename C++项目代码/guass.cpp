# include <iostream.h>
# include <math.h>

const int n=3;
//double A[3][3]={2,2,1,1,2,3,1,2,1};
//double X[3],B[3]={9,14,8};
//double A[n][n]={2,2,1,1,1,1,1,2,3};
//double X[n],B[n]={9,6,14};

void main()
{
	int i,j,k,z;
    double max,m,mm,t,tt;
	double X[n],B[n],A[n][n];

    cout<<"请输入"<<n<<"*"<<n<<"的系数矩阵A："<<endl;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>A[i][j];

    cout<<"等号右边的所有值矩阵B："<<endl;
	for(i=0;i<n;i++)
			cin>>B[i];

	cout<<"其增广矩阵为："<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<A[i][j]<<"   ";
		cout<<B[i]<<endl;
	}

	for(k=0;k<n;k++)      //当前第K行的第一个与所在列以后的每一个做比较，得出最大的A[z][k]与第一个所在行的所有交换。
	{	z=k;
		max=fabs(A[z][k]);	
		for(i=k;i<n;i++)
			if (fabs(A[i][k])>max)
				z=i;
		for(j=k;j<n;j++)
		{
			t=A[k][j];
			A[k][j]=A[z][j];
			A[z][j]=t;
		}	
	    tt=B[k];
		B[k]=B[z];
		B[z]=tt;
	}

	for(k=0;k<n;k++)
	{
		m=A[k][k];
		for(j=k;j<n;j++)
			A[k][j]=A[k][j]/m;
		B[k]=B[k]/m;

		mm=A[k+1][k];
		for(i=k+1;i<n;i++)
		{	for(j=k;j<n;j++)
				A[i][j]=A[i][j]-mm*A[k][j];
			B[i]=B[i]-mm*B[k];
		}
	}


	X[n-1]=B[n-1];	
	for(i=n-2;i>=0;i--)
	{	
		mm=0;
		for(j=i+1;j<n;j++)
			mm += A[i][j]*X[j];
		X[i]=B[i]-mm;
	}   

	cout<<"X[i]的所有取值："<<endl;
	for(j=0;j<n;j++)
	    cout<<X[j]<<"    ";


}




