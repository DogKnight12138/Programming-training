#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
#include<string.h>
#include<windows.h> 
#include<mmsystem.h>

     //�����ṹ�屣�溺�ָ�����Ӧʱ�� 
struct LRC
{
	int time;
	char lrc[100];
	struct LRC* next;
};
int len=sizeof(struct LRC);

       //����ڵ����
int node_len(struct LRC *head) 
{
	struct LRC *p;
	p=head;
	int m;
	for(m=1;;m++)
	{
	  p=p->next;
	  if(p==NULL)break	;
	}
	return m;
}

       //����������ʱ��� ��ȡÿ�и�ʵ�ʱ�䲿�֣�ת��Ϊ���� 
int time_analysis(char a[])
{
	int t_min[2],t_sec[2],t_msec[2];
	int time;
	int i=0,j=0;
	
	for(i=0;;i++)
	{
		if(a[i]=='[')
		{
			t_min[0]=a[i+1]-'0';
			t_min[1]=a[i+2]-'0';
			t_sec[0]=a[i+4]-'0';
			t_sec[1]=a[i+5]-'0';
			t_msec[0]=a[i+7]-'0';
			t_msec[1]=a[i+8]-'0';
			time=((t_min[0]*10+t_min[1])*60+(t_sec[0]*10+t_sec[1]))*1000+(t_msec[0]*10+t_msec[1]);
		}
		if(a[i]==']')break;	
	}
 return time;
}
      //����������ʱ��� ��ȡÿ�и�ʵĵڶ���ʱ�䲿�֣�ת��Ϊ����
int time_analysis2(char a[])
{
	int t_min[2],t_sec[2],t_msec[2];
	int time;
	int i=0,j=0;
	
	for(i=0;;i++)
	{
		if(a[i]=='[')
		{
			t_min[0]=a[i+11]-'0';
			t_min[1]=a[i+12]-'0';
			t_sec[0]=a[i+14]-'0';
			t_sec[1]=a[i+15]-'0';
			t_msec[0]=a[i+17]-'0';
			t_msec[1]=a[i+18]-'0';
			time=((t_min[0]*10+t_min[1])*60+(t_sec[0]*10+t_sec[1]))*1000+(t_msec[0]*10+t_msec[1]);
		}
		if(a[i]==']')break;	
	}
	return time;
}

     //����������ʱ��� ��ȡÿ�и�ʵĵ�����ʱ�䲿�֣�ת��Ϊ����
int time_analysis3(char a[])
{
	int t_min[2],t_sec[2],t_msec[2];
	int time;
	int i=0,j=0;
	
	for(i=0;;i++)
	{
		if(a[i]=='[')
		{
			t_min[0]=a[i+21]-'0';
			t_min[1]=a[i+22]-'0';
			t_sec[0]=a[i+24]-'0';
			t_sec[1]=a[i+25]-'0';
			t_msec[0]=a[i+27]-'0';
			t_msec[1]=a[i+28]-'0';
			time=((t_min[0]*10+t_min[1])*60+(t_sec[0]*10+t_sec[1]))*1000+(t_msec[0]*10+t_msec[1]);
		}
		if(a[i]==']')break;	
	}
	return time;
}

       //��ȡ����еĺ��ֲ��� 
char* words_analysis(char a[])
{
    int i=0,n=0;
    for(i=0;i<strlen(a);i++)
    {
    	if(a[i]==']')
    	n++;
	}
   // printf("%d\n",n);
    char*p=a;
    for(i=0;i<n;i++)
    {
    	p=strtok(p,"]");
    	p=strtok(NULL,",");  	
	}  
    return p;
}

       //��������������Ϊ�������������
 struct LRC * linkedlist_create(int n)
{
	struct LRC *p1,*head,*p;
	p1=(struct LRC*)malloc(len);
	if(p1==NULL)printf("Create linkedlist fail");
	else p1->next=NULL;
	     head=p1,p=p1;
	for(int i=1;i<n;i++)
	{
		p1=(struct LRC*)malloc(len);
		p1->next=NULL;
		p->next=p1;
		p=p1;		
	}	
	return head;	
}

        //index ������λ�����е�n���ڵ�ĵ�ַ
 struct LRC * node_index(struct LRC * head,int n)
{
	struct LRC *p;
	p=head;
	for(int i=1;i<n;i++)
	{
	    p=p->next;	
	}
	return p;
}

       //swap���� 
struct LRC *node_swap(struct LRC * head,int n)
{
	struct LRC *p1,*p2,*p3;
	if(n==node_len(head))
	printf("Sorry,���������");
	if(n==1) 
	{
    	p1=head;
    	p2=node_index(head,2);
    	p3=node_index(head,3);
		p2->next=p1;
     	p1->next=p3;
    	head=p2; 	
	}
	else
	{
		p1=node_index(head,n);
    	p2=node_index(head,n-1);
    	p3=node_index(head,n+1);
    	p1->next=p3->next;
    	p3->next=p1;
    	p2->next=p3;
	}
	return head; 	 
}

       //������������timeֵ����������
 struct LRC *linkedlist_sort(struct LRC* head) 
{
	struct LRC *p1,*p2;
	int i,j;	
	for(j=0;j<node_len(head);j++)
	{
		for(i=1;i<node_len(head)-j;i++)
		{       
		        p1=node_index(head,i);
		        p2=node_index(head,i+1);
				if(p1->time>=p2->time)
             	{
    	         	head=node_swap(head,i);
             	}    	
        }       
	}
	return head;
}
	

	
   //������ 
           

//ȫ�ֱ���
 FILE *fp=NULL;
 int n=1,i=0,j=0;
 char temp[1000];
 char ch;
 //main function
int main()
{
	system("pause");
//�򿪸���ı��ļ� 
	if((fp=fopen("lrc.txt","r+"))==NULL)
	{
		printf("can not open this file\n");
		exit(0);
	}	
	printf("���Զ�ȡ����ļ�\n");
	::Sleep(1500);
/*	for(i=0;i<2048;i++)//���Ŵ�ӡһ�¿����ļ���Ŀ 
	{
		temp[i]=fgetc(fp);
		printf("%c",temp[i]);
		if(feof(fp)!=0)break; 
	}							*/
	printf("\n�ļ��Զ��ɹ�\n"); 
	::Sleep(1000);
	
	
//�жϸ���ļ��м���
rewind(fp);
for(i=0;ch!=EOF;i++)
{
	ch=fgetc(fp);
	if(ch==']')n++;
}
printf("������Ϣ������ı���%d��\n",n);
rewind(fp);	
::Sleep(300);


//�����������������Ƿ񴴽��ɹ� 
printf("\n���Դ�������\n");
struct LRC* p,*head,*p1;
head=linkedlist_create(n-3);
p=head;
do
{
	
	strcpy(p->lrc,"�����ı�");
	p->time=1234567890;
	p=p->next; 
 } while(p->next!=NULL);
 
    p=head;
	 do
 	{
 		printf("%d %s\n",p->time,p->lrc);
 		p=p->next;
 		::Sleep(30);
	 }while (p!=NULL);	 
 ::Sleep(100);
 printf("������ɣ��������ɹ�\n\n");
  printf("�����ø���ļ��������и���\n\n");
 ::Sleep(1000) ;
 
//��ʽ�������ı������ǵ�������Ϣ ����ӡ��������Ƿ񸲸ǳɹ� 
rewind(fp);
p=head;
  char t[n][100];
    
    fgets(t[0],100,fp);	
    fgets(t[1],100,fp);	
    fgets(t[2],100,fp);	
    n=0;
	i=0;
	do
	{
		fgets(t[i],100,fp);	
		
			for(j=0;j<100;j++)
			{
				if(t[i][j]==']')
				{
					n++;	//�ж��м���ʱ���
				}						 
			}
			
		if(n==1)
		{
			p->time=time_analysis(t[i]);
	  	    strcpy(p->lrc,words_analysis(t[i]));
			p=p->next;
	    	i++;
		}
		if(n==2)
		{
			p->time=time_analysis2(t[i]);
	        strcpy(p->lrc,words_analysis(t[i]));
	        p->next;
	        p->time=time_analysis2(t[i]);
	        strcpy(p->lrc,words_analysis(t[i]));
	        p->next;
	        i++;
		 } 
		 if(n==3)
		 {
		 	p->time=time_analysis3(t[i]);
	        strcpy(p->lrc,words_analysis(t[i]));
	        p->next;
	        p->time=time_analysis3(t[i]);
	        strcpy(p->lrc,words_analysis(t[i]));
	        p->next;
	        p->time=time_analysis3(t[i]);
	        strcpy(p->lrc,words_analysis(t[i]));
	        p->next;
	        i++;
     	}
		n=0;		
		
	
	}while(p->next!=NULL);
	
//printf("������ϣ���ʼ����\n"); 

::Sleep(500);	
 p=head;
 
 //��timeֵ��������
p=linkedlist_sort(head);
head=p;
	 do
 	{
 		printf("ʱ�䣨ms����%d    ����ı���%s\n",p->time,p->lrc);
 		::Sleep(100);
 		p=p->next;
	 }while (p!=NULL);
	 printf("\n\n");
printf("���ǳɹ�,׼�����ţ�\n\n\n");
	 system("pause");
	 
 //������ϼ����ӳ٣���ʼ��ӡ
 
 
 //������Ϣ��ȡ����ӡ 
 rewind(fp);
 fgets(t[0],100,fp);
 printf("%s\n",t[0]);
 fgets(t[1],100,fp);
  printf("%s\n",t[1]);	
 fgets(t[2],100,fp);
  printf("%s\n",t[2]);	
 mciSendString("play ���.mp3",0,0,0);
p=node_index(head,2);
p1=node_index(head,1);
::Sleep(p->time);
	 do
 	{
		printf("%s\n",p->lrc); 
		 p=p->next;
		 p1=p1->next;
 		::Sleep(p->time-p1->time);
 	
	 }while (p!=NULL);
	 printf("\n\n");	
	return 0;
}

