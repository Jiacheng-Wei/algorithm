//��һ�� 
/*
��һ��:��һ������Ϊ����L(1<=L<=10000)����·����������������ϳ���ΪL��һ���߶Σ����������ԭ�㣬��ÿ�������������һ����������0,1,2��...��
L��L+1��λ������L+1������
����Ҫ����һЩ�������ߵ�����������һ�����ֱ�ʾ���� 100 200��ʾ���ߴ�100��200֮�䣨�����˵㣩���е�����
������M(1<=M<=100)�����䣬����֮��������ص�������Ҫ�����������������֮��ʣ�µ����ĸ�����

//̰���㷨 
#include <stdio.h>
#include <algorithm>
using namespace std; 
struct inteval
{
	int x;
	int y;
}I[100];

bool cmp(inteval a,inteval b)
{
	if (a.x!=b.x) return a.x<b.x;
	else a.y>b.y;
 } 
int main()
{
	int L,M;
	while (scanf("%d %d",&L,&M)&&L<=1000&&L>0&&M>0&&M<=100)
	{
		for (int i=0;i<M;i++)
		{
			scanf("%d %d",&I[i].x,&I[i].y);
		}
		sort(I,I+M,cmp);
		int num=L+1,lasty=I[0].y;	
		int ymax=I[0].y,xstart=I[0].x;	
		for (int i=1;i<M;i++)//����ѭ����ÿһ�������ж��Ƿ��ظ� 
		{
			if(I[i].x<=ymax&&ymax<I[i].y)
			{
				ymax=I[i].y;
			}
			else if (I[i].x>ymax)
			{
				num=num-ymax+xstart-1;
				xstart=I[i].x;
				ymax=I[i].y;
			}
		}
		num=num-ymax+xstart-1;
		printf("%d\n",num);
	 } 
	 return 0;
}
//hash���ʹ��
#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
	int L,M,sum,left,right,i;//sum is the sum of the trees
	while(scanf("%d%d",&L,&M),L!=0)
	{
		int road[10001]={};
		sum=0;
		while(M--)
		{
			scanf("%d%d",&left,&right);
			fill(road+left,road+right+1,1);
		}
		for(i=0;i<=L;i++)
		{
			if(road[i]==0)
				sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}
*/
/*�ڶ���
��Ŀ����
������������A��B�����ʾ��ʽ�ǣ��Ӹ�λ��ʼ��ÿ��λ���ö���","������
���������A+B�Ľ��������������ʽ�����
����
������������������ݣ�ÿ������ռһ�У�����������A��B��ɣ�-10^9 < A,B < 10^9����
���
�����A+B�Ľ��������������ʽ�����ÿ������ռһ�С�
*/
#include <stdio.h>
#include <string.h>
void caculator(char a[],char b[])
{
	
}

int main()
{
	
 } 
 
