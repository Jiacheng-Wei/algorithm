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

#include <stdio.h>
#include <string.h>

long long  element(char a[])
{
	long long num=0;
	int lenth=strlen(a);
	if (a[0]=='-')
	{
		for (int i=1;i<lenth;i++)
		{
			if (a[i]==',') continue;
			else num=(num+(long long)(a[i]-'0'))*10;
		}
		return -num/10;
	}
	else 
	{
		for (int i=0;i<lenth;i++)
		{
			if (a[i]==',') continue;
			else num=(num+(long long)(a[i]-'0'))*10;
		}
		return num/10;
	}
}

int main()
{
	char a[100],b[100];
	while (scanf("%s %s",a,b)!=EOF)
	{
		printf("%lld\n",element(a)+element(b));
	}
	return 0;
 } 
 //below is example ֱ�ӵ��ַ����Ĵ����Ӽ� 
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string.h>
#include <set>
#include <stack>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Node
{
    int d[10009];
    int len;
    bool f;

    Node() {memset(d, 0, sizeof(d));}
    Node(char *s)
    {
        memset(d, 0, sizeof(d));
        if(s[0] == '-')
            f = 1, s++;
        else
            f = 0;
        int i = 0;
        while(s[i] != '\0')
        {
            d[i] = s[i] - '0';
            ++i;
        }
        len = i;
        for(int i=0,j=len-1; i<j; i++,j--)
            swap(d[i],d[j]);
    }

    bool operator < (const Node &t) const
    {
        if(this->len == t.len)
        {
            for(int i=t.len-1; i>=0; i--)
            {
                if(this->d[i] < t.d[i])
                    return true;
                else if(this->d[i] > t.d[i])
                    return false;
            }
        }
        return this->len <= t.len;
    }

    Node operator + (const Node &t) const
    {
        Node ans;
        if(t.f == this->f)//������ͬ
        {
            ans.f = this->f;
            int len = max(t.len, this->len);
            ans.len = len;
            for(int i=0;i<len;i++)
            {
                ans.d[i] += this->d[i] + t.d[i];
                ans.d[i+1] += ans.d[i] / 10;
                ans.d[i] %= 10;
            }
            if(ans.d[len] != 0)
                ans.len++;
            while(ans.len > 1 && ans.d[ans.len-1] == 0)
                ans.len--;
        }
        else
        {
            if(t < (*this))
                ans = (*this) - t;
            else
                ans = t - (*this);
        }
        return ans;
    }

    Node operator - (const Node &t) const
    {
        Node ans;
        ans.f = this->f;
        int len = this->len;
        ans.len = len;
        for(int i=0;i<len;i++)
        {
            ans.d[i] += this->d[i] - t.d[i];
            if(ans.d[i] < 0)
            {
                ans.d[i] += 10;
                ans.d[i+1]--;
            }
        }
        while(ans.len > 1 && ans.d[ans.len-1] == 0)
            ans.len--;
        return ans;
    }
};

char str[10009];

int main()
{
    cin>>str;
    Node a(str);
    cin>>str;
    Node b(str);
    Node ans = a + b;
    if(ans.f)
        cout<<"-";
    for(int i=ans.len-1; i>=0; i--)
        cout<<ans.d[i];
    return 0;
}*/

/*
�����⣺��Ŀ����
д���㷨����2��С��1000000000�����룬����������˷�������123 * 45 = 1*4 +1*5 +2*4 +2*5 +3*4+3*5
����
 ����С��1000000000����

���
 ��������ж������ݣ�����ÿһ�����ݣ����Input�е�������������ĿҪ��ķ������������õ��Ľ���� 

#include <stdio.h>
#include <string.h>
void input(char a[],char b[])
{
	int lenth1,lenth2;
	lenth1=strlen(a);
	lenth2=strlen(b);
	int sum=0;
	for (int i=0;i<lenth1;i++)
	{
		for (int j=0;j<lenth2;j++)
		{
			sum=sum+(a[i]-'0')*(b[j]-'0');
		}
	}
	printf("%d\n",sum);
}

int main()
{
	char a[10000],b[10000];
	while (scanf("%s %s",a,b)!=EOF)
	{
		input(a,b);
	}
	return 0;
}
*/ 

/*
�����⣺��Ŀ����
��һ������һ������Ϊn���ڶ�������n��������n�����У����ż���������࣬���NO���������YES��
����
�����ж������ݡ�
ÿ������n��Ȼ������n��������1<=n<=1000����
���
���ż���������࣬���NO���������YES�� 

#include <stdio.h>
int main()
{
	int n,num;
	;
	int oddnum=0,evennum=0;
	while (scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf ("%d",&num);
			if (num%2) oddnum++;
			else evennum++;
		}		
		if (oddnum>evennum) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
 } */
 
 /*
 ��Ŀ����
The task is really simple: given N exits on a highway which forms a simple cycle, 
you are supposed to tell the shortest distance between any pair of exits.
����
Each input file contains one test case. For each case, the first line contains an integer N (in [3, 105]), 
followed by N integer distances D1 D2 ... DN, where Di is the distance between the i-th and the (i+1)-st exits, 
and DN is between the N-th and the 1st exits. All the numbers in a line are separated by a space. 
The second line gives a positive integer M (<=104), with M lines follow, each contains a pair of exit numbers, 
provided that the exits are numbered from 1 to N. It is guaranteed that the total round trip distance is no more than 107.
���
For each test case, print your results in M lines, each contains the shortest distance between the corresponding given pair of exits.

translate:���⳵�ų�һ��Ȧ������ĿҪ��ĳ���֮�����̾��롣��һ�и������ǹ��м���������ÿ�����ڳ�֮��ļ�϶���ڶ��и���������Ҫ��ó�������ĸ�����
�����������Ҫ��ĳ���֮��ļ�϶������ 

#include <stdio.h>
void distance(int dist[],int allsum,int a,int b)
{
	int min,max;
	if (a>b) 
	{
		max=a;
		min=b;
	}
	else if(a<b)
	{
		max=b;
		min=a;
	}
	else printf("%d",0);
	int cwdist=0,scwdist=0;//����˳ʱ�����ʱ��ľ��� 
	for (int i=min-1;i<=max-2;i++)
	{
		cwdist+=dist[i];
	}
	scwdist=allsum-cwdist;
	if (scwdist>=cwdist) printf("%d\n",cwdist);
	else printf("%d\n",scwdist);
}
int main()
{
	int N,M;
	int dist[106];
	scanf("%d",&N);
	int allsum=0;
	for (int i=0;i<N;i++)
	{
		scanf("%d",&dist[i]);
		allsum+=dist[i];
	} 
 	scanf("%d",&M);
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		distance(dist,allsum,a,b);
	}
	return 0; 
 }  
 //below is example
 #include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
 
using namespace std;
 
vector<int> dis;
vector<int> disToOrigin;
int sum = 0;
 
int computeMinDis(int s, int e){
    int minDist1 = 0,minDist2 = 0;
    int start, end;
    if(s < e) { start = s; end = e; }
    else if( s == e ) return 0;
    else { start = e; end = s; }
    minDist1 = disToOrigin[end] - disToOrigin[start];
    minDist2 = sum - minDist1;
    return minDist1 < minDist2 ? minDist1 : minDist2;
}
 
int main()
{
    int N,M;
    cin >> N;
    dis.resize(N+1);
    disToOrigin.resize(N+1);
    disToOrigin[1] = 0;
    int value;
    for(int i = 1; i <= N; i++){
        scanf("%d",&value);
        dis[i] = value;
        if(i > 1) disToOrigin[i] = sum;
        sum += value;
    }
    cin >> M;
    int x,y;
    for(int i = 0; i < M; i++){
        scanf("%d%d",&x,&y);
        printf("%d\n",computeMinDis(x,y));
    }
    return 0;
}
*/
/*
��Ŀ����
��������[-231, 231]�ڵ�3������A��B��C�����ж�A+B�Ƿ����C��
����
�����1�и���������T(<=10)���ǲ��������ĸ�����������T�����������ÿ��ռһ�У�˳�����A��B��C���������Կո�ָ���
���
��ÿ�������������һ���������Case #X: true�����A+B>C�����������Case #X: false��������X�ǲ��������ı�ţ���1��ʼ����

#include <stdio.h>
#include <string.h>
long long StringtoInt(char a[])
{
	int lenth=strlen(a);
	long long sum=0;
	if(a[0]!='-')
	{
		for (int i=0;i<lenth;i++)
		{
			sum=sum+(a[i]-'0');
			sum=sum*10;
		}
		return sum/10;	
	}
	else 
	{
		for (int i=1;i<lenth;i++)
		{
			sum=sum+(a[i]-'0');
			sum=sum*10;
		}
		return -sum/10;	
	}

}
bool compare(long long a,long long b,long long c)
{
	if (a+b>c) return true;
	else return false; 
}

int main()
{
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++)
	{
		char a[40],b[40],c[40];
		scanf("%s %s %s",a,b,c);
		bool flag;
		flag=compare(StringtoInt(a),StringtoInt(b),StringtoInt(c)); 		
		if (flag) printf("Case #%d: true\n",i+1);
		else printf("Case #%d: false\n",i+1);
	}
	return 0;	
}
*/
