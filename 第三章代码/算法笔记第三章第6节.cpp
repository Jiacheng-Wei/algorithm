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
