# include <iostream.h>
const int n=3,m=4,p=2;
int A[n][m],E[m][p];

void main()
{
	int B[m][n],F[n][p];
	double C[m],D[m];
	int i,j,l;
	double s=0,ss=0;

    cout<<"Please input A "<<n<<"��"<<m<<"�еľ���:"<<endl;     //����A
	cout<<"(ע�ⰴ������)"<<endl;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			cin>>A[i][j];


	cout<<"Please input E "<<m<<"��"<<p<<"�еľ���:"<<endl;     //����E
	cout<<"(ע�ⰴ������)"<<endl;
	for(i=0;i<m;i++)
		for(j=0;j<p;j++)
			cin>>E[i][j];

	
	for(i=0;i<n;i++)                       //��A��ת��B
		for(j=0;j<m;j++)
			B[j][i]=A[i][j];


	for(j=0;j<m;j++)                       //��A���о�ֵC
	{   s=0;
		for(i=0;i<n;i++)
			s += E[i][j];
		C[j]=s/n;
	}	


	for(j=0;j<m;j++)                       //��A���з���D
	{   ss=0;
		for(i=0;i<n;i++)
			ss += (E[i][j]-C[j])*(E[i][j]-C[j]);
		D[j]=s/n;
	}	


    for(i=0;i<n;i++)                       //F(n*p)=A(n*m)*B(m*p)
		 for(j=0;j<p;j++)
		 {   
			 F[i][j]=0;
			 for(l=0;l<m;l++)
                 F[i][j] += A[i][l]*B[l][j];
		 }

	cout<<"���A��ת��B=:"<<endl;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			cout<<B[i][j]<<"    ";
        cout<<endl;
	}

	cout<<"���A���о�ֵC=:"<<endl;
	for(i=0;i<m;i++)
		cout<<C[i]<<"    ";
    cout<<endl;

	cout<<"���A���з���D=:"<<endl;
	for(i=0;i<m;i++)
		cout<<D[i]<<"    ";
    cout<<endl;
	
	cout<<"���F(n*p)=A(n*m)*B(m*p),F=:"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<p;j++)
			cout<<F[i][j]<<"    ";
        cout<<endl;
	}



}
