/*一元二次方程求解 
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
 /*冒泡排序 
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
  /*镜像树问题 
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
/*有序插入 
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
/*数组元素逆置 
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
/*杨辉三角 
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
/*解密 
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
/*字符串比较 
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
/*逆序输出 
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
斐波拉契数列 
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
/*矩阵转置 
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
 /*求最大的字符串 
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
/*字符逆序串存放 
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
复制字符串中的元音字母
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
 /* 输入a和b两个整数，按先大后小的顺序输出a和b。注意请使用指针变量的方式进行比较和输出。
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
/*输入a、b、c三个整数，按先大后小的顺序输出a、b和c。注意请使用指针变量的方式进行比较和输出。
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
/*给定字符串定义char *a = “I love China!”，读入整数n，输出在进行了a = a + n这个赋值操作以后字符指针a对应的字符串。

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
/*输入3个字符串，按从小到大的顺序输出。要求使用指针的方法进行处理。

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
/*输入10个整数，将其中最小的数与第一个数对换，把最大的数与最后一个数对换。要求用3个函数实现，分别为输入10个数、进行处理、输出10个数。
要求使用指针的方法进行处理。
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
	int incn,incx;//记录最小最大值的下标 
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
/*完成一个对候选人得票的统计程序。假设有3个候选人，名字分别为Li，Zhang和Fun。使用结构体存储每一个候选人的名字和得票数。记录每一张选票的得票人名，
输出每个候选人最终的得票数。结构体可以定义成如下的格式：
struct person {
    char name[20];
    int count;
}leader[3] = {“Li”, 0, “Zhang”, 0, “Fun”, 0};

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
	getchar();//吸收掉scanf末尾的换行符 
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
/*定义一个结构体student，存储学生的学号、名字、性别和年龄，读入每个学生的所有信息，保存在结构体中，并输出。结构体student的定义如下：
struct student {
    int num;
    char name[20];
    char sex;
    int age;
};
本题要求使用指向结构体数组的指针进行输入和输出。 
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
设有若干个人员的数据，其中包含学生和教师。学生的数据中包括：号码、姓名、性别、职业、班级。教师的数据包括：号码、姓名、性别、职业、职务。
可以看出，学生和教师所包含的数据是不同的。现在要求把这些数据放在同一个表格中储存，使用结构体中的共用体实现。结构体定义如下：
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
在以上的结构体中，如果job项为s（学生），则第5项为class（班级）；如果job项是t（教师），则第5项为position（职务）。
输入几个人员的数据，将其保存在以上包含共用体的结构体数组中，并输出。

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
编写两个函数input和print，分别用来输入5个学生的数据记录和打印这5个学生的记录。对于每一个学生，其记录包含了学号、名字、3门课程的成绩共5项。
用主函数分别调用input和print函数进行输入和输出。要求使用结构体数组实现，结构体中包括了每个学生的5项记录。


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

/*有10个学生，每个学生的数据包括学号、姓名、3门课程的成绩。读入这10个学生的数据，要求输出3门课程的总平均成绩，以及个人平均分最高的学生的数据
（包括学号、姓名、3门课程成绩、平均分数）。
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
		//计算单科总成绩 
		sum1=sum1+stu[i].score1;
		sum2=sum2+stu[i].score2;
		sum3=sum3+stu[i].score3;
		//计算个人平均成绩
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
输入
输入包含一系列的a和b对，通过空格隔开。一对a和b占一行。

输出
对于输入的每对a和b，你需要依次输出a、b的和。

如对于输入中的第二对a和b，在输出中它们的和应该也在第二行。
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
输入
第一行是一个整数N，表示后面会有N行a和b，通过空格隔开。

输出
对于输入的每对a和b，你需要在相应的行输出a、b的和。
如第二对a和b，对应的和也输出在第二行。

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
输入
输入中每行是一对a和b。其中会有一对是0和0标志着输入结束，且这一对不要计算。

输出
对于输入的每对a和b，你需要在相应的行输出a、b的和。
如第二对a和b，他们的和也输出在第二行。

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
输入
每行的第一个数N，表示本行后面有N个数。

如果N=0时，表示输入结束，且这一行不要计算。

输出
对于每一行数据需要在相应的行输出和。

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
输入
输入的第一行是一个正数N，表示后面有N行。每一行的第一个数是M，表示本行后面还有M个数。

输出
对于每一行数据需要在相应的行输出和。

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
/*输入
每行的第一个数N，表示本行后面有N个数

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
/*输入
输入包含若干行，每行输入两个整数a和b，由空格分隔。
输出
对于每组输入，输出a和b的和，每行输出后接一个空行。
 
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
输入
输入的第一行为一个整数N，接下来N行每行先输入一个整数M，然后在同一行内输入M个整数。

输出
对于每组输入，输出M个数的和，每组输出之间输出一个空行。

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

