/*һԪ���η������ 
#include <stdio.h>
#include <math.h>
int main()
 {
 	double a,b,c;
 	scanf("%lf %lf %lf",&a,&b,&c);
 	double r1,r2;
 	r1=(-b+sqrt(b*b-4*a*c))/(2*a);
 	r2=(-b-sqrt(b*b-4*a*c))/(2*a);
 	printf("r1=%7.2f\n",r1);
 	printf("r2=%7.2f\n",r2);
 	return 0;
 }*/
 /*ð������ 
 #include<stdio.h>
 int main()
 {
 	int a[10]={2,6,4,3,87,91,43,21,6,1};
 	for (int i=1;i<=9;i++)//will last n-i times
 	{
 		for (int j=0;j<10-i;j++)//in n times will compare 10-n times element 
 		{
 			int temp;
			 if (a[j]>a[j+1])
 			{
 				temp=a[j];
 				a[j]=a[j+1];
 				a[j+1]=temp;
			 }
		 }
	 }
	 for (int i=0;i<10;i++)
	 {
	 	printf("%d ",a[i]);
	 }
  } */ 
  /*���������� 
#include <stdio.h>
#include <queue.h>
#incldue <vector.h>
    bool isSymmetric(TreeNode* root) 
    {
        if(root==NULL)return 1;
        queue<TreeNode*> node;
        TreeNode* nodenull=new TreeNode(0);
        int count=0;
        int sum=1;
        node.push(root);
        while(sum!=0)
        {
            sum=0;
            vector<int> round;
            count=node.size();
            for(int i=0;i<count;i++)
            {
                if(node.front()->left!=NULL)node.push(node.front()->left);
                else node.push(nodenull);
                if(node.front()->right!=NULL)node.push(node.front()->right);                
                else node.push(nodenull);
                round.push_back(node.front()->val);
                if(node.front()!=nodenull&&sum==0)sum=1;   
                node.pop();
            }
            for(int i=0;i<=(int)((round.size()-1)/2);i++)
            {
                if(round[i]!=round[round.size()-1-i])return 0;
            }
        }
        return 1;
    }
*/
/*������� 
#include <stdio.h>
int main()
{
	int a[10];
	for (int i=0;i<9;i++)
	{
		scanf("%d",&a[i]);
	}
	int ist;
	scanf("%d",&ist);
	for (int i=0;i<9;i++)
	{
		if (a[i]>=ist)
		{
			for (int k=9;k>i;k--)
			{
				a[k]=a[k-1];
			}
			a[i]=ist;
			break;
		}
	 } 
	 for (int i=0;i<10;i++)
	 {
	 	printf("%d\n",a[i]);
	 }
	 return 0;
}*/
/*����Ԫ������ 
#include <stdio.h>
int main()
{
	int a[10],b[10];
	for (int i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=0,j=9;i<10&&j>=0;i++,j--)
	{
		b[j]=a[i];
	}
	for (int i=0;i<10;i++)
	{
		printf("%d\n",b[i]);
	}
	return 0;
} */ 
/*������� 
#include <stdio.h>
int main()
{
	int pascal[100][100];
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		pascal[i][0]=1;
		pascal[i][i]=1;
	}
	for (int i=0;i<n;i++)
	{
		 for (int j=1;j<i;j++)
		 {
		 	pascal[i][j]=pascal[i-1][ j-1]+pascal[i-1][j];
		 }
	}
	for(int i=0;i<n;i++)
	{
		for (int j=0;j<=i;j++)
		{
			printf("%d ",pascal[i][j]);
		}
		printf("\n");
	}
	return 0;
}
*/
/*���� 
#include <stdio.h>
#include <string.h>
int main()
{
	char a[1000],b[1000];
	scanf("%s",a);
	for (int j=0;j<sizeof(a)/sizeof(char);j++)
	{
		if (a[j]>='a'&&a[j]<='z')
		{
			b[j]='a'+26-(a[j]-'a')-1;
		}
		else if (a[j]>='A'&&a[j]<='Z')
		{
			b[j]='A'+26-(a[j]-'A')-1;
		}
		else
		{
			b[j]=a[j];
		}
	}
	printf("%s",b);
	return 0;
 } 
 */ 
/*�ַ����Ƚ� 
#include <stdio.h>
int main()
{
	char str1[1000],str2[1000];
	gets(str1);
	gets(str2);
	for (int i=0;i<sizeof(str1)/sizeof(char)||sizeof(str2)/sizeof(char);i++)
	{
		if (str1[i]!=str2[i])
		{
			printf("%d",(int)(str1[i]-str2[i]));
			break;
		}
	}
	return 0;
}*/
/*������� 
#include <stdio.h>
int main() 
{
	int a[10];
	for (int i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=9;i>=0;i--)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}*/
/* 
쳲��������� 
#include<stdio.h>
int main()
{
	int a[20];
	a[0]=1;
	a[1]=1;
	for (int i=2;i<20;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	for(int i=0;i<20;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
 } */
/*����ת�� 
#include<stdio.h>
int main()
{
	int a[2][3];
	for (int i=0;i<2;i++)
	{
		for (int j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<2;j++)
		{
			printf("%d ",a[j][i]);
		}	
		printf("\n");
	}
	return 0;
 } */
 /*�������ַ��� 
 #include <stdio.h>
 
int main()
{
	char str1[1000],str2[1000],str3[1000],str4[1000];
	gets(str1);
	gets(str2);
	gets(str3);	
	for (int i=0;i<sizeof(str1)/sizeof(char)||sizeof(str2)/sizeof(char);i++)
	{
		if (str1[i]>str2[i])
		{
			for(int j=0;j<sizeof(str1)/sizeof(char);j++)
			{
				str4[j]=str1[j];
			}
			break;
		}
		else 
		{
			for(int j=0;j<sizeof(str2)/sizeof(char);j++)
			{
				str4[j]=str2[j];
			}
			break;			
		}
	}
	for (int i=0;i<sizeof(str4)/sizeof(char)||sizeof(str3)/sizeof(char);i++)
	{
		if (str4[i]>str3[i])
		{
			for(int j=0;str4[j]!='\0';j++)
			{
				printf("%c",str4[j]);
			}
			break;
		}
		else 
		{
			for(int j=0;str3[j]!='\0';j++)
			{
				printf("%c",str3[j]);
			}
			break;			
		}
	}
	return 0;
}*/
/*�ַ����򴮴�� 
#include<stdio.h>
void reverse(char *a)
{
	char b[100];
	int step=0;	
	for (int i=0;a[i]!='\0';i++)
	{
		step++;
	}
	for (int i=0,j=step-1;i<step&&j>=0;j--,i++)
	{
		b[j]=a[i];
	}
	puts(b);
 } 
 int main()
 {
 	char a[100];
	gets(a);
	reverse(a);
 	return 0;
 }*/

/*
�����ַ����е�Ԫ����ĸ
#include <stdio.h>
void vowels(char s1[], char s2[])
{
	int j=0;
	for (int i=0;s1[i]!='\0';i++)
	{
		if (s1[i]=='A'||s1[i]=='E'||s1[i]=='I'||s1[i]=='O'||s1[i]=='U'||s1[i]=='a'||s1[i]=='e'||s1[i]=='i'||s1[i]=='o'||s1[i]=='u')
		{
			s2[j]=s1[i];
			j++;
		}
	}
	puts(s2);
}
int main()
{
	char s1[100],s2[100];
	gets(s1);
	vowels(s1, s2);
	return 0;
 } */
 /* ����a��b�������������ȴ��С��˳�����a��b��ע����ʹ��ָ������ķ�ʽ���бȽϺ������
#include <stdio.h>
int main()  
{
	int *a,*b;
	int c,d;
	scanf("%d %d",&c,&d);
	a=&c;
	b=&d;
	if (*a>=*b)
	{
		printf("%d %d",*a,*b);
	}
	else printf("%d %d",*b,*a);
	return 0;
}*/
/*����a��b��c�������������ȴ��С��˳�����a��b��c��ע����ʹ��ָ������ķ�ʽ���бȽϺ������
#include <stdio.h>
int main()
{
	int a[3];
	for (int i=0;i<3;i++)
	{
		scanf("%d",a+i);
	}
	for (int i=1;i<3;i++)
	{
		for (int j=0;j<3-i;j++)
		{
			int temp=0;
			if (*(a+j)>*(a+j+1))
			{
				temp=*(a+j);
				*(a+j)=*(a+j+1);
				*(a+j+1)=temp;
			}
		}
	}
	for (int i=2;i>=0;i--)
	{
		printf("%d ",*(a+i));
	}
	return 0;
}*/
/*�����ַ�������char *a = ��I love China!������������n������ڽ�����a = a + n�����ֵ�����Ժ��ַ�ָ��a��Ӧ���ַ�����

#include <stdio.h>
int main()
{
	char *a="I love China!";
	int n;
	scanf("%d",&n);
	for (char* i=a+n;i!=a+13;i++)
	{
		printf("%c",*i);
	}
	return 0;
}*/
/*����3���ַ���������С�����˳�������Ҫ��ʹ��ָ��ķ������д���

#include <stdio.h>
#include <string.h>
int main()
{
	char str[3][20];
	for (int i=0;i<3;i++)
	{
		scanf("%s",&str[i]);
	}
	for (int i=1;i<3;i++)
	{
		for (int j=0;j<3-i;j++)
		{
			if (strcmp(str[j],str[j+1])>=0)
			{
				char temp[20];
				strcpy(temp,str[j]);
				strcpy(str[j],str[j+1]);
				strcpy(str[j+1],temp);
			}			
		}
	}
	for (int i=0;i<3;i++)
	{
		printf("%s\n",str[i]);
	}
	return 0;
}*/
/*����10����������������С�������һ�����Ի����������������һ�����Ի���Ҫ����3������ʵ�֣��ֱ�Ϊ����10���������д������10������
Ҫ��ʹ��ָ��ķ������д���
#include<stdio.h>
void input(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}

void operate(int a[],int n)
{
	int min=a[0],max=a[0];
	int incn,incx;//��¼��С���ֵ���±� 
	//search for the min and max
	for (int i=1;i<n;i++)
	{
		if (a[i]>=max)
		{
			max=a[i];
			incx=i;
		} 
		else if (a[i]<=min)
		{
			min=a[i];
			incn=i;
		}
	}
	//exchang
	
	a[incn]=a[0];
	a[0]=min;
	a[incx]=a[n-1];
	a[n-1]=max;
}

void output(int a[],int n)
{
	for (int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
int main()
{
	int a[10];
	input(a,10);
	operate(a,10);
	output(a,10);
	return 0;
}*/
/*���һ���Ժ�ѡ�˵�Ʊ��ͳ�Ƴ��򡣼�����3����ѡ�ˣ����ֱַ�ΪLi��Zhang��Fun��ʹ�ýṹ��洢ÿһ����ѡ�˵����ֺ͵�Ʊ������¼ÿһ��ѡƱ�ĵ�Ʊ������
���ÿ����ѡ�����յĵ�Ʊ�����ṹ����Զ�������µĸ�ʽ��
struct person {
    char name[20];
    int count;
}leader[3] = {��Li��, 0, ��Zhang��, 0, ��Fun��, 0};

#include<stdio.h>
#include<string.h>
 
struct  person
{
    char name[20];
    int count;
}leader[3]={"Li",0,"Zhang",0,"Fun",0};
 
int main()
{
    int n,i,j;
    char mingzi[20];
    scanf("%d",&n);
    person *p;
    if(n>0&&n<=100)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",mingzi);
             for(p=leader,j=0;j<3;j++,p++)
            {
              if(strcmp(p->name,mingzi)==0)
                {
                    leader[j].count=leader[j].count+1;
                }
            }
        }
        printf("%s:%d\n%s:%d\n%s:%d\n",leader[0].name,leader[0].count,leader[1].name,leader[1].count,leader[2].name,leader[2].count);
    }
 
}
#include <stdio.h>
#include <string.h>
int main()
{
	 struct person{
		char name[10];
		int count ;
	}leader[3]={"Li",0,"Zhang",0,"Fun",0};
	int n;
	scanf("%d",&n);
	getchar();//���յ�scanfĩβ�Ļ��з� 
	char str[n][10];
	for(int i=0;i<n;i++)
	{
		gets(str[i]);
		if(strcmp(str[i],leader[0].name)==0) leader[0].count++;
		else if(strcmp(str[i],leader[1].name)==0) leader[1].count++;
		else if(strcmp(str[i],leader[2].name)==0) leader[2].count++;
	}
 
	printf("Li:%d\nZhang:%d\nFun:%d\n",leader[0].count,leader[1].count,leader[2].count);
	//for(int i=0;i<n;i++)
	//{
	//	printf("%s\n",str[i]);
	//}
	return 0;
 } 


//above is exanple
#include <stdio.h>
#include <string.h>

struct person {
    char name[20];
    int count;
}leader[3] = {"Li", 0, "Zhang", 0, "Fun", 0};

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	if (n>0&&n<=100)
	{
		
		char s[100][20];
		for (int i=0;i<n;i++)
		{
			scanf("%s",s[i]);
		}
		for (int i=0;i<10;i++)
		{
			for (int j=0;j<3;j++)
			{
				gets(s[i]);
				if(strcmp(s[i],leader[j].name)==0)
				{
					leader[j].count++;
				}
			}		
		}	
	}	
	for (int i=0;i<3;i++)
	{
		printf("%s:%d\n",leader[i].name,leader[i].count); 
	}
	return 0;
}
/*����һ���ṹ��student���洢ѧ����ѧ�š����֡��Ա�����䣬����ÿ��ѧ����������Ϣ�������ڽṹ���У���������ṹ��student�Ķ������£�
struct student {
    int num;
    char name[20];
    char sex;
    int age;
};
����Ҫ��ʹ��ָ��ṹ�������ָ��������������� 
#include <stdio.h>
#include <string.h>

struct student {
    int num;
    char name[20];
    char sex;
    int age;
};

int main()
{
	int n;
	scanf("%d",&n);
	if(n>=0&&n<=20)
	{
		student stu[20];
		student *person=stu;
		for (int i=0;i<n;i++)
		{
			scanf("%d %s %c %d",&(person+i)->num,(person+i)->name,&(person+i)->sex,&(person+i)->age);
		}
		for (int i=0;i<n;i++)
		{
			printf("%d %s %c %d\n",(person+i)->num,(person+i)->name,(person+i)->sex,(person+i)->age);
		}	
	}
	return 0;
}
*/

/*
�������ɸ���Ա�����ݣ����а���ѧ���ͽ�ʦ��ѧ���������а��������롢�������Ա�ְҵ���༶����ʦ�����ݰ��������롢�������Ա�ְҵ��ְ��
���Կ�����ѧ���ͽ�ʦ�������������ǲ�ͬ�ġ�����Ҫ�����Щ���ݷ���ͬһ������д��棬ʹ�ýṹ���еĹ�����ʵ�֡��ṹ�嶨�����£�
struct {
    int num;
    char name[10];
    char sex;
    char job;
    union {
        int class;
        char position[10];
    }category;
};
�����ϵĽṹ���У����job��Ϊs��ѧ���������5��Ϊclass���༶�������job����t����ʦ�������5��Ϊposition��ְ�񣩡�
���뼸����Ա�����ݣ����䱣�������ϰ���������Ľṹ�������У��������

#include <stdio.h>
#include <string.h>

 struct person{
    int num;
    char name[10];
    char sex;
    char job;
    union {
        int classes;
        char position[10];
    }category;
};

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	person per[100];
	if (n>=0&&n<=100)
	{
		for (int i=0;i<n;i++)
		{
			scanf("%d %s %c %c",&per[i].num,per[i].name,&per[i].sex,&per[i].job);
			if (per[i].job=='s') scanf("%d",&per[i].category.classes);
			else scanf("%s",per[i].category.position);
		}
	}
	for (int i=0;i<n;i++)
	{
		if (per[i].job=='s') printf("%d %s %c %c %d\n",per[i].num,per[i].name,per[i].sex,per[i].job,per[i].category.classes);
		else printf("%d %s %c %c %s\n",per[i].num,per[i].name,per[i].sex,per[i].job,per[i].category.position);
	}
	return 0;
}
*/
/*
��д��������input��print���ֱ���������5��ѧ�������ݼ�¼�ʹ�ӡ��5��ѧ���ļ�¼������ÿһ��ѧ�������¼������ѧ�š����֡�3�ſγ̵ĳɼ���5�
���������ֱ����input��print������������������Ҫ��ʹ�ýṹ������ʵ�֣��ṹ���а�����ÿ��ѧ����5���¼��


#include <stdio.h>
#include <string.h>
struct student{
	int num;
	char name[10];
	int score1;
	int score2;
	int score3;
}stu[5];

void input(student str[])
{
	for (int i=0;i<5;i++)
	{
		scanf("%d %s %d %d %d",&stu[i].num,stu[i].name,&stu[i].score1,&stu[i].score2,&stu[i].score3);
	}
}
void print(student str[])
{
	for (int i=0;i<5;i++)
	{
		printf("%d %s %d %d %d\n",stu[i].num,stu[i].name,stu[i].score1,stu[i].score2,stu[i].score3);
	}
}
int main()
{
	input(stu);
	print(stu);
	return 0;
}*/

/*��10��ѧ����ÿ��ѧ�������ݰ���ѧ�š�������3�ſγ̵ĳɼ���������10��ѧ�������ݣ�Ҫ�����3�ſγ̵���ƽ���ɼ����Լ�����ƽ������ߵ�ѧ��������
������ѧ�š�������3�ſγ̳ɼ���ƽ����������
#include <stdio.h>
#include <string.h>

struct student{
	int num;
	char name[20];
	int score1;
	int score2;
	int score3;
}stu[10];

void input(student str[])
{
	for (int i=0;i<10;i++)
	{
		scanf("%d %s %d %d %d",&stu[i].num,stu[i].name,&stu[i].score1,&stu[i].score2,&stu[i].score3);
	}
}
void print(student str[])
{
	double averscr1,averscr2,averscr3;
	double sum1=0,sum2=0,sum3=0;
	int allscr[10];
	for (int i=0;i<10;i++)
	{
		//���㵥���ܳɼ� 
		sum1=sum1+stu[i].score1;
		sum2=sum2+stu[i].score2;
		sum3=sum3+stu[i].score3;
		//�������ƽ���ɼ�
		allscr[i]=(stu[i].score1+stu[i].score2+stu[i].score3)/3; 
	}
	averscr1=sum1/10;
	averscr2=sum2/10;
	averscr3=sum3/10;
	int max=0,maxinch[10];
	int j=0;
	for (int i=0;i<10;i++)
	{
		if (allscr[i]>max)
		{
			max=allscr[i];
		}
	}
	for (int i=0;i<10;i++)
	{
		if (allscr[i]==max)
		{
				maxinch[j]=i;
				j++;
		}
	}
	printf("%.2f %.2f %.2f\n",averscr1,averscr2,averscr3);
	for (int i=0;i<j;i++)
	{
		printf("%d %s %d %d %d\n",stu[maxinch[i]].num,stu[maxinch[i]].name,stu[maxinch[i]].score1,stu[maxinch[i]].score2,stu[maxinch[i]].score3);
	}
}
int main()
{
		input(stu);
		print(stu);
		return 0;
}
*/
/*
����
�������һϵ�е�a��b�ԣ�ͨ���ո������һ��a��bռһ�С�

���
���������ÿ��a��b������Ҫ�������a��b�ĺ͡�

����������еĵڶ���a��b������������ǵĺ�Ӧ��Ҳ�ڵڶ��С�
#include<iostream>
using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		cout<<a+b<<endl;
	}
	return 0;
}
//above is example
#include <stdio.h>
int main()
{
	int a,b;
	while (scanf("%d %d",&a,&b))
	{
		printf("%d\n",a+b);
	}
	return 0;
}
*/
/*
����
��һ����һ������N����ʾ�������N��a��b��ͨ���ո������

���
���������ÿ��a��b������Ҫ����Ӧ�������a��b�ĺ͡�
��ڶ���a��b����Ӧ�ĺ�Ҳ����ڵڶ��С�

#include <stdio.h>
int main()
{
	int n;
	int a,b;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",a+b);
	 } 
	 return 0;
}*/

/*
����
������ÿ����һ��a��b�����л���һ����0��0��־���������������һ�Բ�Ҫ���㡣

���
���������ÿ��a��b������Ҫ����Ӧ�������a��b�ĺ͡�
��ڶ���a��b�����ǵĺ�Ҳ����ڵڶ��С�

#include <stdio.h>
int main()
{
	int a,b;
	while (scanf("%d %d",&a,&b))
	{
		if (a!=0&&b!=0)
		{
			printf("%d\n",a+b);
		}
		else break;
	}
	return 0;
}*/

/*
����
ÿ�еĵ�һ����N����ʾ���к�����N������

���N=0ʱ����ʾ�������������һ�в�Ҫ���㡣

���
����ÿһ��������Ҫ����Ӧ��������͡�

#include <stdio.h>
int main()
{
	int n;
	int a;
	while (1)
	{
		int sum=0;
		scanf("%d",&n);
		if(n!=0)
		{

			for (int i=0;i<n;i++)
			{
				scanf("%d",&a);
				sum=sum+a;
			}
			printf("%d\n",sum);
			getchar();		
		}
		else break;
	}
	return 0;
}
*/
 
/*
����
����ĵ�һ����һ������N����ʾ������N�С�ÿһ�еĵ�һ������M����ʾ���к��滹��M������

���
����ÿһ��������Ҫ����Ӧ��������͡�

#include <stdio.h>
int main()
{
	int m;
	
	scanf("%d",&m);
	for (int j=0;j<m;j++)
	{
		int a;
		int n;
		int sum=0;
		scanf("%d",&n);
		if(n!=0)
		{

			for (int i=0;i<n;i++)
			{
				scanf("%d",&a);
				sum=sum+a;
			}
			printf("%d\n",sum);
			getchar();		
		}
		else break;
	}
	return 0;	
}*/
/*����
ÿ�еĵ�һ����N����ʾ���к�����N����

#include <stdio.h>
int main()
{
	int n;
	int a;
	while (scanf("%d",&n)!=EOF)
	{
		int sum=0;
		
		for (int i=0;i<n;i++)
		{
			scanf("%d",&a);
			sum=sum+a;
		}
		printf("%d\n",sum);
		getchar();		
	}
	return 0;
}*/
/*����
������������У�ÿ��������������a��b���ɿո�ָ���
���
����ÿ�����룬���a��b�ĺͣ�ÿ��������һ�����С�
 
#include<stdio.h> 
int main()
{   
    int a,b;

    while(scanf("%d%d",&a,&b) != EOF){
        printf("%d\n",a+b);
        printf("\n");
    }
    return 0;
 } 
*/
/*
����
����ĵ�һ��Ϊһ������N��������N��ÿ��������һ������M��Ȼ����ͬһ��������M��������

���
����ÿ�����룬���M�����ĺͣ�ÿ�����֮�����һ�����С�

#include <stdio.h>
int main()
{
	int m;
	scanf("%d",&m);
	for (int j=0;j<m;j++)
	{
		int a;
		int n;
		int sum=0;
		scanf("%d",&n);
		if(n!=0)
		{
			for (int i=0;i<n;i++)
			{
				scanf("%d",&a);
				sum=sum+a;
			}
			printf("%d\n",sum);
			printf("\n");	
		}
		else break;
	}
	return 0;	
}
*/

