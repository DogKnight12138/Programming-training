#include<stdio.h>
#include<math.h>
int main()
{
	 long long  n;
	 long long  K=1, Q=0;
	scanf("%d",&n);
	for( int i=n;i>0;i--)
	{
		for( int j=i;j>0;j--)
		{
			K=K*j;
		}
	    
	    Q=Q+K;
	    printf("%d\n",K);
	    K=1; 
	}
	
	printf("%d",Q);
	
	return 0;//���⣺���ݽ�С���������ܣ����ݽϴ��������n=20�ͻ�����������������͵����� 
}


