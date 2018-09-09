//第一节 
/*
第一题:有一个长度为整数L(1<=L<=10000)的马路，可以想象成数轴上长度为L的一个线段，起点是坐标原点，在每个整数坐标点有一棵树，即在0,1,2，...，
L共L+1个位置上有L+1棵树。
现在要移走一些树，移走的树的区间用一对数字表示，如 100 200表示移走从100到200之间（包括端点）所有的树。
可能有M(1<=M<=100)个区间，区间之间可能有重叠。现在要求移走所有区间的树之后剩下的树的个数。

//贪心算法 
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
		for (int i=1;i<M;i++)//利用循环对每一个区间判断是否重复 
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
//hash表的使用
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
/*第二题
题目描述
给定两个整数A和B，其表示形式是：从个位开始，每三位数用逗号","隔开。
现在请计算A+B的结果，并以正常形式输出。
输入
输入包含多组数据数据，每组数据占一行，由两个整数A和B组成（-10^9 < A,B < 10^9）。
输出
请计算A+B的结果，并以正常形式输出，每组数据占一行。

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
 //below is example 直接的字符串的大数加减 
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
        if(t.f == this->f)//符号相同
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
第三题：题目描述
写个算法，对2个小于1000000000的输入，求结果。特殊乘法举例：123 * 45 = 1*4 +1*5 +2*4 +2*5 +3*4+3*5
输入
 两个小于1000000000的数

输出
 输入可能有多组数据，对于每一组数据，输出Input中的两个数按照题目要求的方法进行运算后得到的结果。 

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
第四题：题目描述
第一行输入一个数，为n，第二行输入n个数，这n个数中，如果偶数比奇数多，输出NO，否则输出YES。
输入
输入有多组数据。
每组输入n，然后输入n个整数（1<=n<=1000）。
输出
如果偶数比奇数多，输出NO，否则输出YES。 

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
 题目描述
The task is really simple: given N exits on a highway which forms a simple cycle, 
you are supposed to tell the shortest distance between any pair of exits.
输入
Each input file contains one test case. For each case, the first line contains an integer N (in [3, 105]), 
followed by N integer distances D1 D2 ... DN, where Di is the distance between the i-th and the (i+1)-st exits, 
and DN is between the N-th and the 1st exits. All the numbers in a line are separated by a space. 
The second line gives a positive integer M (<=104), with M lines follow, each contains a pair of exit numbers, 
provided that the exits are numbered from 1 to N. It is guaranteed that the total round trip distance is no more than 107.
输出
For each test case, print your results in M lines, each contains the shortest distance between the corresponding given pair of exits.

translate:出租车排成一个圈，求题目要求的车辆之间的最短距离。第一行给出的是共有几辆车，和每辆相邻车之间的间隙，第二行给出的是需要求得车辆距离的个数，
后面的数是需要求的车辆之间的间隙个数。 

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
	int cwdist=0,scwdist=0;//定义顺时针和逆时针的距离 
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
题目描述
给定区间[-231, 231]内的3个整数A、B和C，请判断A+B是否大于C。
输入
输入第1行给出正整数T(<=10)，是测试用例的个数。随后给出T组测试用例，每组占一行，顺序给出A、B和C。整数间以空格分隔。
输出
对每组测试用例，在一行中输出“Case #X: true”如果A+B>C，否则输出“Case #X: false”，其中X是测试用例的编号（从1开始）。

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
