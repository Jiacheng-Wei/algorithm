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
 
#include<stdio.h>
#include<string.h>
int main()
{
	char str1[101],str2[101];
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
		for(j=0;j<lenth2&&i<lenth;j++,i++)
		{
			str[i]=str2[j];
		}
		//str[lenth]='\0';//要用printf（"%s"）输出时必须要加上"\0"的字符串结束符，否则字符串输出会遇到问题，在oj上不能通过
		//strlen返回的字符串长度不包括'\0'的长度 
		//printf("%s\n",str);
		for(int k=0;k<lenth;k++)
		{
			printf("%c",str[k]);
		}//如果不采用 printf（"%s"）形式输出，就不用加 str[lenth]='\0'，oj能通过 
		printf("\n");
	}
	return 0;
}

//below is example 
#include <stdio.h>
#include <string.h>

int main()
{
    int lena,lenb,i;
    char a[101];
    char b[101];
    char c[210];
    while((scanf("%s %s",a,b))!=EOF)
    {
        lena=strlen(a);
        lenb=strlen(b);
        for(i=0; i<lena+lenb; i++)
        {
            if(i<lena)  c[i]=a[i];
            else   c[i]=b[i-lena];
        }
        c[lena+lenb]='\0';
        printf("%s\n",c);
    }
    return 0;
}
*/
