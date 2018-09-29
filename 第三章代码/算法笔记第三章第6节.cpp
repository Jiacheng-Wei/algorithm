//第三章第六节 
/*
第一题：
题目描述
不借用任何字符串库函数实现无冗余地接受两个字符串，然后把它们无冗余的连接起来。
输入
每一行包括两个字符串，长度不超过100。
输出
可能有多组测试数据，对于每组数据，
不借用任何字符串库函数实现无冗余地接受两个字符串，然后把它们无冗余的连接起来。
输出连接后的字符串。 
*/ 
#include<stdio.h>
#include<string.h>
int main()
{
	char str1[100],str2[100];
	int lenth,lenth1,lenth2;
	while(scanf("%s %s",str1,str2)!=EOF)
	{
		lenth1=strlen(str1);
		lenth2=strlen(str2);
		lenth=lenth1+lenth2;
		char str[lenth];
		int i,j;
		for (i=0;i<lenth1;i++)
		{
			str[i]=str1[i];
		}
		for(j=0;j<lenth2;j++,i++)
		{
			str[i]=str2[j];
		}
		printf("%s",str);
	}
	return 0;
}
