//�����µ����� 
/*
��һ�⣺
��Ŀ����
�������κ��ַ����⺯��ʵ��������ؽ��������ַ�����Ȼ������������������������
����
ÿһ�а��������ַ��������Ȳ�����100��
���
�����ж���������ݣ�����ÿ�����ݣ�
�������κ��ַ����⺯��ʵ��������ؽ��������ַ�����Ȼ������������������������
������Ӻ���ַ����� 

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
		//str[lenth]='\0';//Ҫ��printf��"%s"�����ʱ����Ҫ����"\0"���ַ����������������ַ���������������⣬��oj�ϲ���ͨ��
		//strlen���ص��ַ������Ȳ�����'\0'�ĳ��� 
		//printf("%s\n",str);
		for(int k=0;k<lenth;k++)
		{
			printf("%c",str[k]);
		}//��������� printf��"%s"����ʽ������Ͳ��ü� str[lenth]='\0'��oj��ͨ�� 
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
/*�ַ����Ľ�������"\0"��ASCII����0�������ַ�NULL��ռ��һ���ַ�λ����˿��ַ�����ʱ��ǧ��Ҫ�ǵ��ַ�����ĳ���һ��Ҫ��ʵ�ʴ洢�ַ����ĳ������ٶ�1��
ע�⣺int�����ĩβ����Ҫ��\0��ֻ��char��������Ҫ������Ҫע��\0���ո���ͬһ���������ո��ASCII����32�����������
�����ʹ��scanf������%s��ʽ��gets���������ַ���������ʹ��getchar����һ��Ҫ�������ÿ���ַ��������"\0",����printf��puts����ַ�������Ϊ�޷�ʶ��
�ַ���ĩβ�����һ������롣������������µ����ڵ�һ�⣩*/ 
/*
�ڶ��⣺ 
��Ŀ����
��һ���ַ����е����е��ʣ�������ʵ�����ĸ���Ǵ�д��ĸ����ѵ��ʵ�����ĸ��ɴ�д��ĸ��
���ַ����У�����֮��ͨ���հ׷��ָ����հ׷��������ո�(' ')���Ʊ��('\t')���س���('\r')�����з�('\n')��
����
����һ�У���������ַ���������С��100����
���
�����ж���������ݣ�����ÿ�����ݣ�
���һ�У�ת������ַ�����

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
