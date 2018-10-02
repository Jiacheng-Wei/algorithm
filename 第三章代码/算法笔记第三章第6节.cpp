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
		char str[lenth+1];
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
/*字符串的结束符是"\0"的ASCII码是0，即空字符NULL，占用一个字符位，因此开字符串的时候千万要记得字符数组的长度一定要比实际存储字符串的长度至少多1。
注意：int型组的末尾不需要加\0，只有char型数组需要。还需要注意\0跟空格不是同一个东西，空格的ASCII码是32，切勿混淆。
如果不使用scanf函数的%s格式或gets函数输入字符串（例如使用getchar），一定要在输入的每个字符串后加入"\0",否则printf和puts输出字符串会因为无法识别
字符串末尾而输出一大堆乱码。（例题见第三章第六节第一题）*/ 
/*
第二题： 
题目描述
对一个字符串中的所有单词，如果单词的首字母不是大写字母，则把单词的首字母变成大写字母。
在字符串中，单词之间通过空白符分隔，空白符包括：空格(' ')、制表符('\t')、回车符('\r')、换行符('\n')。
输入
输入一行：待处理的字符串（长度小于100）。
输出
可能有多组测试数据，对于每组数据，
输出一行：转换后的字符串。

#include<stdio.h>
#include<string.h>


int main()
{
	char str[101];
	while(gets(str)!=NULL)
	{
		
		int lenth=strlen(str);
		if (str[0]>='a'&&str[0]<='z')
		{
			str[0]=str[0]-32;
		}
		for (int i=1;i<lenth;i++)
		{
			if ((str[i]==' '||str[i]=='\t'||str[i]=='\r'||str[i]=='\n')&&(str[i+1]>='a'&&str[i+1]<='z'))
			{
				str[i+1]=str[i+1]-32;
			}
		}
		puts(str);
	 } 
 } 
 */
