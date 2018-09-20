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
 第五题 
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
第六题 
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
/*
第七题：
题目描述
给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：

A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。
输入
每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。
输出
对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出“N”。 

#include <stdio.h>
#include <string.h>
int main()
{
	int N;
	while (scanf("%d",&N)!=EOF)
	{
		int a;
		int flag=1;
		int A[5]={0,0,0,0,0};
		int a3=0;
		for (int i=0;i<N;i++)
		{
			scanf("%d",&a);
			if (a%5==0&&a%2==0)
			{
				A[0]=A[0]+a;
			}
			else if (a%5==1)
			{
				if (flag)
				{
					A[1]=A[1]+a;
					flag=0;
				}
				else
				{
					A[1]=A[1]-a;
					flag=1;
				}
			}
			else if (a%5==2)
			{
				A[2]++;
			}
			else if (a%5==3)
			{
				A[3]=A[3]+a;
				a3++;
			}
			else if (a%5==4)
			{
				if (a>A[4])
				{
					A[4]=a;
				}
			}
		}
		for (int i=0;i<3;i++)
		{
			if (A[i]==0) printf("N ");
			else printf("%d ",A[i]);
		}
		if (A[3]==0) printf("N ");
		else printf("%.1f ",(float)A[3]/(float)a3);
		if (A[4]==0) printf("N\n");
		else printf("%d\n",A[4]);	
	}
	return 0; 
 } 
 //below is example
 #include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int n, num;
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
    bool existA1 = false, existA2 = false;
    int countA4 = 0;
    scanf("%d", &n);
    for(int i = 0, j = 0; i < n; i++){
        scanf("%d", &num);
        if(num % 5 == 0){
            if(num % 2 == 0){
                existA1 = true;
                a1 += num;
            }
        }
        else if(num % 5 == 1){
            existA2 = true;
            a2 += num * pow((double)(-1), j);
            j++;
        }
        else if(num % 5 == 2){
            a3++;
        }
        else if(num % 5 == 3){
            a4 += num;
            countA4++;
        }
        else{
            a5 = (num > a5 ? num : a5);
        }
    }
    if(existA1){
        printf("%d", a1);
    }
    else{
        printf("%c", 'N');
    }
    if(existA2){
        printf(" %d", a2);
    }
    else{
        printf(" %c", 'N');
    }
    if(a3 != 0){
        printf(" %d", a3);
    }
    else{
        printf(" %c", 'N');
    }
    if(countA4 != 0){
        printf(" %.1f", (double)a4 / countA4);
    }
    else{
        printf(" %c", 'N');
    }
    if(a5 != 0){
        printf(" %d\n", a5);
    }
    else{
        printf(" %c\n", 'N');
    }
    return 0;
}
 */
 /*
 第八题： 
 题目描述
正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。

现给定A、DA、B、DB，请编写程序计算PA + PB。

输入
输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。
输出
在一行中输出PA + PB的值。
 
 
 
 #include <stdio.h>
 #include <string.h>
 
 int main()
 {
 	char A[1010],DA,B[1010],DB;
 	while (scanf("%s %c %s %c",A,&DA,B,&DB)!=EOF)
 	{
 	 	getchar(); 
		int lenth1,lenth2,num1=0,num2=0;
 		lenth1=strlen(A);
 		lenth2=strlen(B);
 		int sum1=0,sum2=0;
		for (int i=0;i<lenth1;i++)
 		{
 			if (A[i]==DA)
 			{
 				num1++;
			 }
		 }
		 for (int i=0;i<lenth2;i++)
		 {
		 	if (B[i]==DB)
		 	{
		 		num2++;
			 }
		 }
		 for (int i=0;i<num1;i++)
		 {
			sum1=(sum1+DA-'0')*10;
		 }
		 for (int i=0;i<num2;i++)
		 {
		 	sum2=(sum2+DB-'0')*10;
		 }
		 printf("%d\n",(sum1+sum2)/10);	
	} 
	 return 0;
 }
 //below is example
 #include <iostream>
using namespace std;
int main()
{
    int numA, numB;
    int Da, Db;

    cin >> numA >> Da >> numB >> Db;

    int tempNumA = 0;
    int tempNumB = 0;
    while (numA != 0)
    {
        if (numA % 10 == Da)
        {
            tempNumA = tempNumA * 10 + Da;
        }
        numA =numA/ 10;
    }
    while (numB != 0)
    {
        if (numB%10 == Db)
        {
            tempNumB = tempNumB * 10 + Db;
        }
        numB =numB/ 10;
    }
    long long relt = tempNumA + tempNumB;
    cout << relt << endl;
    return 0;
}
 */
 
 /*
 第九题 
 题目描述
大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：
现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。
输入
输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，
即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。
输出
输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，
分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。

#include <stdio.h>
#include <string.h>

int judge(char x,char y)
{
	if ((x=='C'&&y=='J')||(x=='J'&&y=='B')||(x=='B'&&y=='C')) return 1;
	else if (x==y) return 0;
	else return -1;
}
int main()
{
	int N;
	scanf("%d",&N);
	getchar();
	char player1,player2;
	int C1=0,J1=0,B1=0,C2=0,J2=0,B2=0; 
	int win1=0,win2=0,balance=0,loss1=0,loss2=0;
	for (int i=0;i<N;i++)
	{
		
		scanf("%c %c",&player1,&player2);
		getchar();
		int flag=judge(player1,player2);
		if (flag==1)
		{
			win1++;
			loss2++;
			if(player1=='C') C1++;
			else if (player1=='J') J1++;
			else B1++;
		}
		else if(flag==0) balance++;	
		else if(flag==-1)
		{
			win2++;
			loss1++;
			if(player2=='C') C2++;
			else if (player2=='J') J2++;
			else B2++;
		}
	}
	printf("%d %d %d\n",win1,balance,loss1);
	printf("%d %d %d\n",win2,balance,loss2);
	if (C1>=J1&&C1>B1) printf("C ");
	else if (J1>B1&&J1>C1) printf("J ");
	else if (B1>=C1&&B1>=J1) printf("B ");
	if (C2>=J2&&C2>B2) printf("C");
	else if (J2>B2&&J2>C2) printf("J");
	else if (B2>=C2&&B2>=J2) printf("B");	
	return 0;
}*/
//第二节
/*
第一题： 
题目描述
读入N名学生的成绩，将获得某一给定分数的学生人数输出。
输入
测试输入包含若干测试用例，每个测试用例的格式为
第1行：N
第2行：N名学生的成绩，相邻两数字用一个空格间隔。
第3行：给定分数
当读到N=0时输入结束。其中N不超过1000，成绩分数为（包含）0到100之间的一个整数。
输出
对每个测试用例，将获得给定分数的学生人数输出。
样例输入
4
70 80 90 100
80
3
65 75 85
55
5
60 90 90 90 85
90
0
样例输出
1
0
3

#include <stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	while (N)
	{
		int score[1000];
		getchar();
		for (int i=0;i<N;i++)
		{
			scanf("%d",&score[i]);
		}
		getchar();
		int mscore;
		int num=0;
		scanf("%d",&mscore);
		for (int i=0;i<N;i++)
		{
			if(score[i]==mscore)
			{
				num++;
			}
		}
		printf("%d\n",num);
		getchar();
		scanf("%d",&N);
	} 
	return 0;
 } 
 */
 /*
 第二题：
 题目描述
输入一个数n，然后输入n个数值各不相同，再输入一个值x，输出这个值在这个数组中的下标（从0开始，若不在数组中则输出-1）。

输入
测试数据有多组，输入n(1<=n<=200)，接着输入n个数，然后输入x。

输出
对于每组输入,请输出结果。

样例输入
4
1 2 3 4
3
样例输出
2 

#include <stdio.h> 
const int maxn=210;
int a[maxn];
int main()
{
	int n,x;
	while (scanf("%d",&n)!=EOF)
	{
		for (int i=0;i<n;i++)
		{
			scanf("%d",&a[i]); 
		}
		scanf("%d",&x);
		int k=0; //下标
		for (k;k<n;k++)
		{
			if (a[k]==x)
			{
				printf("%d\n",k);
				break;
			}
		} 
		if (k==n) 
		{
			printf ("-1\n");
		}
	}
	return 0;
} */
/*
第三题 
题目描述
输入N个学生的信息，然后进行查询。

输入
输入的第一行为N，即学生的个数(N<=1000)

接下来的N行包括N个学生的信息，信息格式如下：
01 李江 男 21
02 刘唐 男 23
03 张军 男 19
04 王娜 女 19
然后输入一个M(M<=10000),接下来会有M行，代表M次查询，每行输入一个学号，格式如下：
02
03
01
04
输出
输出M行，每行包括一个对应于查询的学生的信息。

如果没有对应的学生信息，则输出“No Answer!”

#include <stdio.h>
#include <string.h>
struct student{
	char num[100];
	char name[200];
	char sex[10];
	int age; 
}stu[1010];
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	for (int i=0;i<n;i++)
	{
		scanf("%s %s %s %d",&stu[i].num,&stu[i].name,&stu[i].sex,&stu[i].age);
	}
	getchar();
	int m;
	scanf("%d",&m);
	char match[10000][100];
	for (int i=0;i<m;i++)
	{
		scanf("%s",match[i]);
	}
	
	for (int i=0;i<m;i++)
	{

		int flag=0;
		for (int j=0;j<n;j++)
		{
			if(!strcmp(stu[j].num,match[i]))
			{
				printf("%s %s %s %d\n",stu[j].num,stu[j].name,stu[j].sex,stu[j].age);
				flag=1;
				break;
			} 
		}
		if (!flag) printf("No Answer!\n"); 
	}
	return 0;
}*/
/*
第四题 
题目描述
输入数组长度 n 
输入数组      a[1...n] 
输入查找个数m 
输入查找数字b[1...m] 
输出 YES or NO  查找有则YES 否则NO 。
输入
输入有多组数据。
每组输入n，然后输入n个整数，再输入m，然后再输入m个整数（1<=m<=n<=100）。
输出
如果在n个数组中输出YES否则输出NO。

#include <stdio.h>
int main()
{
	int a[1000],b[1000];
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		for (int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int m;
		scanf("%d",&m);
		for (int i=0;i<m;i++)
		{
			scanf("%d",&b[i]);
		}
		for (int i=0;i<m;i++)
		{
			int flag=0;
			for (int j=0;j<n;j++)
			{
				if(b[i]==a[j]) 
				{
					flag=1;
					break;
				}
			}
			if (flag==1) printf("YES\n");
			else printf("NO\n");
		}	
	}
	return 0;
}
//below is example
#include <stdio.h>
int main() {
    int n;
    int m;
    int buf[101];
    int search[101];
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &buf[i]);
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &search[i]);
        }
        for (int i = 0; i < m; i++) {
            int j;
            for (j = 0; j < n; j++) {
                if (buf[j] == search[i]) {
                    printf("YES\n");
                    break;
                }
            }
            if (j == n) {
                printf("NO\n");
            }
        }

    }
    return 0;
}*/
/*
第五题 
题目描述
输入n个学生的信息，每行包括学号、姓名、性别和年龄，每一个属性使用空格分开。最后再输入一学号，将该学号对应的学生信息输出。
输入
测试数据有多组，第一行为样例数m。对于每个样例，第一行为学生人数n(n不超过20)，加下来n行每行4个整数分别表示学号、姓名、性别和年龄，
最后一行表示查询的学号。
输出
输出m行，每行表示查询的学生信息，格式参见样例。

#include <stdio.h> 
struct student{
	int num;
	char name[200];
	char sex[10];
	int age; 
}stu[1010];

int main()
{
	int m;
	scanf("%d",&m);
	for(int j=0;j<m;j++)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d %s %s %d",&stu[i].num,&stu[i].name,&stu[i].sex,&stu[i].age);
		}
		int search;
		scanf("%d",&search);
		printf("%d %s %s %d\n",stu[search-1].num,stu[search-1].name,stu[search-1].sex,stu[search-1].age);	
	}
	return 0;
}

//below is example
#include <stdlib.h>
#include <stdio.h>
#include<string.h>
 
typedef struct Student{
	int ID;//学号
	char name[100];//姓名
	char sex[100];//性别
	int age;//年龄
}Student;
int main()
{
    int i,N,n,j,SID;
	Student student[21];
    scanf("%d",&n);
	//n组测试用例
	for(i = 0;i < n;i++){
		scanf("%d",&N);
		//输入n个学生的信息，每行包括学号、姓名、性别和年龄
		for(j = 0;j < N;j++){
			scanf("%d %s %s %d\n",&student[j].ID,student[j].name,student[j].sex,&student[j].age);
		}
		//最后再输入一学号
		scanf("%d",&SID);
		//将该学号对应的学生信息输出。
		for(j = 0;j < N;j++){
			if(student[j].ID == SID){
				printf("%d %s %s %d\n",student[j].ID,student[j].name,student[j].sex,student[j].age);
				break;
			}
		}
	}//for
    return 0;
}*/
//第三章 
/*
第一题：
输入一个高度h，输出一个高为h，上底边为h的梯形。
输入
一个整数h(1<=h<=1000)。
输出
h所对应的梯形。 

#include <stdio.h>
int main()
{
	int h;
	while (scanf("%d",&h)!=EOF)
	{
		int n=h;
		int m=h+2*(h-1);
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m-h;j++)
			{
				printf(" ");
			}
			for (int j=0;j<h;j++)
			{
				printf("*");
			}
			printf("\n");
			h+=2;
		}	
	}
	return 0;
 } 
*/ 
/*
第二题 
Given any string of N (>=5) characters, you are asked to form the characters into the shape of U. For example, "helloworld" can be printed as:
h  d
e  l
l  r
lowo
That is, the characters must be printed in the original order, starting top-down from the left vertical line with n1 characters, 
then left to right along the bottom line with n2 characters, and finally bottom-up along the vertical line with n3 characters. 
And more, we would like U to be as squared as possible -- that is, it must be satisfied that n1 = n3 = max { k| k <= n2 for all 3 <= n2 <= N } 
with n1 + n2 + n3 - 2 = N.
输入
Each input file contains one test case. Each case contains one string with no less than 5 and no more than 80 characters in a line.
The string contains no white space.
输出
For each test case, print the input string in the shape of U as specified in the description.
由线性规划可以知道
k>=1；k<=(N+2) /3;k<=(N-1)/2;

#include<stdio.h>
#include<string.h>
#include <math.h>
int min(int x)
{
	int a,b;
	a=(x+2)/3;
	b=(x-1)/2;
	if (a>=b) return b;
	if (a<b) return a;
}
int maxn1(int x)
{
	int k=min(x);
	int n1=floor(k);
	return n1;
 } //以上都是计算k的值的函数，通过线性规划知道k的范围（k<=(N+2) /3;k<=(N-1)/2;），然后取两个范围的最小值的向下取整就是k的值 
int main()
{
	char N[100];
	scanf("%s",N);
	getchar();
	int lenth=strlen(N);
	//printf("%d\n",lenth);
	int n1,n2;
	n1=maxn1(lenth);
	n2=lenth-2*n1+2;
	//printf("%d %d",n1,n2);
	char n[n1][n2]; 
	for (int b=0;b<n1;b++)
	{
		for (int c=0;c<n2;c++)
		{
			n[b][c]=' ';
		}
	}
	int i,j,k;
	for (i=0;i<n1;i++)
	{
		n[i][0]=N[i];
	}
	int a=i-1;
	for(j=1;j<n2;j++)
	{
		n[a][j]=N[i];
		i++;
	}
	a=a-1;
	for (a;a>=0;a--)
	{
		n[a][j-1]=N[i];
		i++;
	}
	for (int b=0;b<n1;b++)
	{
		for (int c=0;c<n2;c++)
		{
			printf("%c",n[b][c]);
		}
		printf("\n");
	}
	return 0;
 } 
*/
/*
第三题 
请输入高度h，输入一个高为h，上底边长为h 的等腰梯形（例如h=4，图形如下）。
   ****
  ******
 ********
**********
输入
输入第一行表示样例数m，接下来m行每行一个整数h，h不超过10。
输出
对应于m个case输出要求的等腰梯形。

#include <stdio.h>
int main()
{
	int m;
	scanf("%d",&m);
	for (int i=0;i<m;i++)
	{
		int h;
		scanf("%d",&h);
		if (h<=10)
		{
			int n=h;
			int max=3*h-2;
			for (int k=0;k<n;k++)
			{
				for (int j=0;j<h-1-k;j++)
				{
					printf(" ");
				}
				for (int j=0;j<h+2*k;j++)
				{
					printf("*");
				}
				for (int j=0;j<h-1-k;j++)
				{
					printf(" ");
				}
				printf("\n");
			}
		}
	}
	return 0;
}
*/
/*
第四题 
问题：输入n，输出正倒n层星号三角形。首行顶格，星号间有一空格，效果见样例 
输入样例： 
3 
输出样例：
* * *
 * * 
  *
 * * 
* * *
数据规模 1<= n <=50 

#include <stdio.h>
#include <string.h>

int main()
{
    int num;
    scanf("%d",&num);
    int cnt = num;
    for(int i = 0;i < 2 * num - 1;i++)
	{
        for(int k = cnt;k < num;k++)
		{
            printf(" ");//cnt用以控制"*"前空格的个数 
        }
        for(int j = cnt;j > 0;j--)
		{
            if(j == 1) printf("*\n");//当输出到最后一个*号时不输出空格 
            else
			{
                printf("* ");   
            }
        }
        if(i < num - 1)//翻转输出，以使其成为倒三角形 
		{
            cnt--;
        }
		else
		{
            cnt++;
        } 
    }
    return 0;
}*/ 
//第三章
/*
第一题： 
有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天。为了满足这个条件只需要设置ans的初始值为1即可 
输入
有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD
输出
每组数据输出一行，即日期差值

#include <stdio.h>
int month[13][2]={{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};//闰年和平年每月分别的天数 
bool isLeap(int year)
{
	return (year%4==0&&year%100!=0)||(year%400==0);
}//判断是否是闰年 

int main()
{
	int time1,y1,m1,d1;
	int time2,y2,m2,d2;
	while (scanf("%d%d",&time1,&time2)!=EOF) 
	{
		if (time1>time2)
		{
			int temp=time1;
			time1=time2;
			time2=temp;
		}//保证第一个日期小于第二个日期 
		y1=time1/10000,m1=time1%10000/100,d1=time1%100;
		y2=time2/10000,m2=time2%10000/100,d2=time2%100;
		int ans=1;//相差的天数 
		while (y1<y2||m1<m2||d1<d2)
		{
			d1++;
			if (d1==month[m1][isLeap(y1)]+1)//满月则进一月 
			{
				m1++;//月数增加 
				d1=1;//日期重置为1 
			}
			if (m1==13)//满年则进一年 
			{
				y1++;//年数增加 
				m1=1;//月数重置为1 
			}
			ans++;//每次循环日期加一 
		}
		printf("%d\n",ans);
	}
	return 0;
*/
/*
第二题：
题目描述
We now use the Gregorian style of dating in Russia. The leap years are years with number divisible 
by 4 but not divisible by 100, or divisible by 400.For example, years 2004, 2180 and 2400 are leap. 
Years 2004, 2181 and 2300 are not leap.Your task is to write a program which will compute the day 
of week corresponding to a given date in the nearest past or in the future using today’s agreement 
about dating.
输入
There is one single line contains the day number d, month name M and year number y(1000≤y≤3000). 
The month name is the corresponding English name starting from the capital letter.
输出
Output a single line with the English name of the day of week corresponding to the date, starting 
from the capital letter. All other letters must be in lower case. 

//以2018年9月18日星期三为计算起点，计算每一个日期所对应的day of week 
#include<stdio.h>
#include <string.h>
int month[13][2]={{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
char bigweek[7][20]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
char smallweek[7][20]={"Monday","Sunday","Saturday","Friday","Thursday","Wednesday","Tuesday"};
char year[13][20] = { "","January","February","March","April","May","June","July","August","September","October","November","December" };
bool isLeap(int year)
{
	return (year%4==0&&year%100!=0)||(year%400==0);
}

int calculate(int time1,int time2)
{
	int temp;	
	if (time1>time2)
	{
		time1=temp;
		time1=time2;
		time2=temp;
	 } 	
	int y1,y2,m1,m2,d1,d2;
	y1=time1/10000,m1=time1%10000/100,d1=time1%100;
	y2=time2/10000,m2=time2%10000/100,d2=time2%100;
	int ans=1;
	while (y1<y2||m1<m2||d1<d2)
	{
		d1++;
		if(d1==month[m1][isLeap(y1)]+1)
		{
			m1++;
			d1=1;
		}
		if(m1==13)
		{
			y1++;
			m1=1;
		}
		ans++;
	}
	return ans;
}

void judgeday(int time1,int ans)
{
	int judge;
	if (time1>=20180918)
	{
		judge=ans%7;
		printf("%s\n",bigweek[judge]);
	}
	else
	{
		judge=(ans-2)%7;
		printf("%s\n",smallweek[judge]);
	}
}
int main()
{
	int time1,time2;
	time2=20180918;
	char mon[20];
	int y,m,d;
	while (scanf("%d %s %d",&d,mon,&y)!=EOF)
	{
		for (int i=1;i<13;i++)
		{
			if (strcmp(mon,year[i])==0)
			{
				m=i;
				break;
			}
		}
		time1=y*10000+m*100+d;
		//printf("%d %d",time1,time2);//调试代码 
		int ans=calculate(time1,time2);
		judgeday(time1,ans);
	}
	return 0;
 } 
 
 //below is example
 #include <stdio.h>
#include <string.h>
#include<algorithm>
using namespace std;
 
int month[13][2] = { { 0,0 },{ 31,31 },{ 28,29 },{ 31,31 },{ 30,30 },{ 31,31 },{ 30,30 },{ 31,31 },{ 31,31 },{ 30,30 },{ 31,31 },{ 30,30 },{ 31,31 } };
 
char daybig[7][20] = { "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };//日期比今天大，正向输出
char daysmall[7][20] = { "Monday","Sunday","Saturday","Friday","Thursday","Wednesday","Tuesday" };//日期比今天小，反向输出
 
char year[13][20] = { "","January","February","March","April","May","June","July","August","September","October","November","December" };//这个技巧用好多次了，字符和下标/数字的转换
 
bool isleap(int y) {
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); //返回是否闰年
}
int caldays(int y1, int m1, int d1, int y, int m, int d) { //计算两个日期之间的间距的天数
	int days = 0;
	while (y1 < y || m1 < m || d1 < d) {
		d1++;
		if (d1 == month[m1][isleap(y1)] + 1) {
		d1 = 1;
		m1++;
		}
		if (m1 == 13) {
		m1 = 1;
		y1++;
		}
		days++;
	}
	return days;
}
int main() {
	int d, m, y;
	char mon[20];
	while (scanf("%d %s %d", &d, mon, &y) != EOF) {//字母月数转换为数字
		for (int i = 1; i <= 12; i++) {
			if (strcmp(mon, year[i]) == 0) {
				m = i;
				break;
			}
		}
		int y1 = 2018, m1 = 6, d1 = 6;//今天周三
		int time1 = 10000 * y1 + 100 * m1 + d1;
		int time = 10000 * y + 100 * m + d;
		int ans;
		if (time < time1) { //反向
			swap(y1, y), swap(m1, m), swap(d1, d);
			ans = caldays(y1, m1, d1, y, m, d);
			printf("%s\n", daysmall[(ans - 2) % 7]);//小小的数学推导
		}
		else { //正向
			ans = caldays(y1, m1, d1, y, m, d);
			printf("%s\n", daybig[(ans + 2) % 7]);
		}
	}
	return 0;
}*/ 
/*
第三题： 
给出年分m和一年中的第n天，算出第n天是几月几号。
输入
输入包括两个整数y(1<=y<=3000)，n(1<=n<=366)。
输出
可能有多组测试数据，对于每组数据，按 yyyy-mm-dd的格式将输入中对应的日期打印出来。
//自己犯错容易出的问题是输出格式问题，次题就是当年份小于四位数时，输出结果中的年份前要用0占位 
#include <stdio.h>
int month[13][2]={{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
//char mon[13][10]={"00","01","02","03","04","05","06","07","08","09","10","11","12"};
//char day[32][10]={"00","01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31"};
bool isLeap(int year)
{
	return (year%4==0&&year%100!=0)||(year%400==0);
}
int main()
{
	int m,n;
	while (scanf("%d %d",&m,&n)!=EOF)
	{
		int a=1,b=1,sum=1;
		while (sum!=n)
		{
			sum++;
			b++;
			if (b==month[a][isLeap(m)]+1)
			{
				a++;
				b=1;
			}
		}
		printf("%04d-%02d-%02d\n",m,a,b);
	}
	return 0;
}

#include<iostream> 
#include<stdio.h> 
using namespace std; 
    
int main() 
{ 
    int n,m; 
    int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; 
    while(cin>>n>>m) 
    { 
        if(n%4==0&&n%100!=0||n%400==0)//判断闰年，闰年2月29天，平年28天
            month[1]+=1; 
    
        int mm=1; 
        for(int i=0;i<12;i++) 
            if(m>month[i]) 
            { 
                m-=month[i]; 
                mm++; 
            } 
            else 
                break; 
    
            printf("%.4d-%.2d-%.2d\n",n,mm,m); 
            month[1]=28; 
    } 
} 
*/


/*
第四题： 
编写一个日期类，要求按xxxx-xx-xx 的格式输出日期，实现加一天的操作。
输入
输入第一行表示测试用例的个数m，接下来m行每行有3个用空格隔开的整数，分别表示年月日。测试数据不会有闰年。 
输出
输出m行。按xxxx-xx-xx的格式输出，表示输入日期的后一天的日期。

#include <stdio.h>
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	int m;
	scanf("%d",&m);
	for (int i=0;i<m;i++)
	{
		int y,m,d;
		scanf("%d %d %d",&y,&m,&d);
		d++;
		if (d==month[m]+1)
		{
			m++;
			d=1;
		}
		if(m==13)
		{
			y++;
			m=1;
		}
		printf("%04d-%02d-%02d\n",y,m,d);	
	}
	return 0;
 } 
*/
/*
第四题： 
设计一个程序能计算一个日期加上若干天后是什么日期。
输入
输入第一行表示样例个数m，接下来m行每行四个整数分别表示年月日和累加的天数。
输出
输出m行，每行按yyyy-mm-dd的个数输出。

#include <stdio.h>
int month[13][2]={{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
bool isLeap(int year)
{
	return (year%4==0&&year%100!=0)||(year%400==0);
}
int main()
{
	int m;
	scanf("%d",&m);
	for (int i=0;i<m;i++)
	{
		int y,m,d,dist;
		scanf("%d %d %d %d",&y,&m,&d,&dist);
		while (dist>0)
		{
			dist--;
			d++;
			if (d==month[m][isLeap(y)]+1)
			{
				m++;
				d=1;
			} 
			if (m==13)
			{
				y++;
				m=1;
			}
		}
		printf("%04d-%02d-%02d\n",y,m,d);
	}
	return 0;
}
*/
//第四章
/*
第一题 
题目描述
输入两个不超过整型定义的非负10进制整数A和B(<=231-1)，输出A+B的m (1 < m <10)进制数。
输入
输入格式：测试输入包含若干测试用例。每个测试用例占一行，给出m和A，B的值。
当m为0时输入结束。
输出
输出格式：每个测试用例的输出占一行，输出A+B的m进制数。

#include <stdio.h>
int main()
{
	int m;
	while (1)
	{
		scanf("%d",&m);
		if (m!=0)
		{
			long long A,B,C;
			scanf("%lld %lld",&A,&B);
			C=A+B;
			int num[100];
			int i=0;
			while (C)
			{
				num[i]=(int)(C%m);
				C=C/m;
				i++;
			}
			if(i==0)
			{
				printf("0\n");
			} 
			else 
			{
			 	for (int j=i-1;j>=0;j--)
				{
					printf("%d",num[j]);
				}
				printf("\n");
			}
		}
		else break;
	}
	return 0;
 } 
 */ 
