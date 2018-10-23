#include<stdio.h>
#include<math.h>
#include<stdlib.h>
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
	
	return 0;//问题：数据较小可以正常跑，数据较大出错，比如n=20就会出错，可能是数据类型的问题 
}


