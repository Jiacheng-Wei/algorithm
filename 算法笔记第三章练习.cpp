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
 ������ 
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
������ 
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
/*
�����⣺
��Ŀ����
����һϵ�����������밴Ҫ������ֽ��з��࣬���������5�����֣�

A1 = �ܱ�5����������������ż���ĺͣ�
A2 = ����5������1�����ְ�����˳����н�����ͣ�������n1-n2+n3-n4...��
A3 = ��5������2�����ֵĸ�����
A4 = ��5������3�����ֵ�ƽ��������ȷ��С�����1λ��
A5 = ��5������4��������������֡�
����
ÿ���������1������������ÿ�����������ȸ���һ��������1000��������N��������N��������1000�Ĵ�����������������ּ��Կո�ָ���
���
�Ը�����N��������������ĿҪ�����A1~A5����һ����˳����������ּ��Կո�ָ�������ĩ�����ж���ո�

������ĳһ�����ֲ����ڣ�������Ӧλ�������N���� 

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
 �ڰ��⣺ 
 ��Ŀ����
������A�ġ�DA��Ϊ1λ���������֡�����Ϊ��A������DA��ɵ�������PA�����磺����A = 3862767��DA = 6����A�ġ�6���֡�PA��66����ΪA����2��6��

�ָ���A��DA��B��DB�����д�������PA + PB��

����
������һ�������θ���A��DA��B��DB���м��Կո�ָ�������0 < A, B < 1010��
���
��һ�������PA + PB��ֵ��
 
 
 
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
 �ھ��� 
 ��Ŀ����
���Ӧ�ö����桰���Ӽ�����������Ϸ������ͬʱ�������ƣ�ʤ��������ͼ��ʾ��
�ָ������˵Ľ����¼����ͳ��˫����ʤ��ƽ�������������Ҹ���˫���ֱ��ʲô���Ƶ�ʤ�����
����
�����1�и���������N��<=105������˫������Ĵ��������N�У�ÿ�и���һ�ν������Ϣ��
���ס���˫��ͬʱ�����ĵ����ơ�C�������ӡ���J������������B������������1����ĸ����׷�����2�������ҷ����м���1���ո�
���
�����1��2�зֱ�����ס��ҵ�ʤ��ƽ�������������ּ���1���ո�ָ�����3�и���������ĸ��
�ֱ����ס��һ�ʤ�����������ƣ��м���1���ո�����ⲻΨһ�����������ĸ����С�Ľ⡣

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
//�ڶ���
/*
��һ�⣺ 
��Ŀ����
����N��ѧ���ĳɼ��������ĳһ����������ѧ�����������
����
��������������ɲ���������ÿ�����������ĸ�ʽΪ
��1�У�N
��2�У�N��ѧ���ĳɼ���������������һ���ո�����
��3�У���������
������N=0ʱ�������������N������1000���ɼ�����Ϊ��������0��100֮���һ��������
���
��ÿ����������������ø���������ѧ�����������
��������
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
�������
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
 �ڶ��⣺
 ��Ŀ����
����һ����n��Ȼ������n����ֵ������ͬ��������һ��ֵx��������ֵ����������е��±꣨��0��ʼ�������������������-1����

����
���������ж��飬����n(1<=n<=200)����������n������Ȼ������x��

���
����ÿ������,����������

��������
4
1 2 3 4
3
�������
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
		int k=0; //�±�
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
������ 
��Ŀ����
����N��ѧ������Ϣ��Ȼ����в�ѯ��

����
����ĵ�һ��ΪN����ѧ���ĸ���(N<=1000)

��������N�а���N��ѧ������Ϣ����Ϣ��ʽ���£�
01 � �� 21
02 ���� �� 23
03 �ž� �� 19
04 ���� Ů 19
Ȼ������һ��M(M<=10000),����������M�У�����M�β�ѯ��ÿ������һ��ѧ�ţ���ʽ���£�
02
03
01
04
���
���M�У�ÿ�а���һ����Ӧ�ڲ�ѯ��ѧ������Ϣ��

���û�ж�Ӧ��ѧ����Ϣ���������No Answer!��

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
������ 
��Ŀ����
�������鳤�� n 
��������      a[1...n] 
������Ҹ���m 
�����������b[1...m] 
��� YES or NO  ��������YES ����NO ��
����
�����ж������ݡ�
ÿ������n��Ȼ������n��������������m��Ȼ��������m��������1<=m<=n<=100����
���
�����n�����������YES�������NO��

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
������ 
��Ŀ����
����n��ѧ������Ϣ��ÿ�а���ѧ�š��������Ա�����䣬ÿһ������ʹ�ÿո�ֿ������������һѧ�ţ�����ѧ�Ŷ�Ӧ��ѧ����Ϣ�����
����
���������ж��飬��һ��Ϊ������m������ÿ����������һ��Ϊѧ������n(n������20)��������n��ÿ��4�������ֱ��ʾѧ�š��������Ա�����䣬
���һ�б�ʾ��ѯ��ѧ�š�
���
���m�У�ÿ�б�ʾ��ѯ��ѧ����Ϣ����ʽ�μ�������

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
	int ID;//ѧ��
	char name[100];//����
	char sex[100];//�Ա�
	int age;//����
}Student;
int main()
{
    int i,N,n,j,SID;
	Student student[21];
    scanf("%d",&n);
	//n���������
	for(i = 0;i < n;i++){
		scanf("%d",&N);
		//����n��ѧ������Ϣ��ÿ�а���ѧ�š��������Ա������
		for(j = 0;j < N;j++){
			scanf("%d %s %s %d\n",&student[j].ID,student[j].name,student[j].sex,&student[j].age);
		}
		//���������һѧ��
		scanf("%d",&SID);
		//����ѧ�Ŷ�Ӧ��ѧ����Ϣ�����
		for(j = 0;j < N;j++){
			if(student[j].ID == SID){
				printf("%d %s %s %d\n",student[j].ID,student[j].name,student[j].sex,student[j].age);
				break;
			}
		}
	}//for
    return 0;
}*/
//������ 
/*
��һ�⣺
����һ���߶�h�����һ����Ϊh���ϵױ�Ϊh�����Ρ�
����
һ������h(1<=h<=1000)��
���
h����Ӧ�����Ρ� 

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
�ڶ��� 
Given any string of N (>=5) characters, you are asked to form the characters into the shape of U. For example, "helloworld" can be printed as:
h  d
e  l
l  r
lowo
That is, the characters must be printed in the original order, starting top-down from the left vertical line with n1 characters, 
then left to right along the bottom line with n2 characters, and finally bottom-up along the vertical line with n3 characters. 
And more, we would like U to be as squared as possible -- that is, it must be satisfied that n1 = n3 = max { k| k <= n2 for all 3 <= n2 <= N } 
with n1 + n2 + n3 - 2 = N.
����
Each input file contains one test case. Each case contains one string with no less than 5 and no more than 80 characters in a line.
The string contains no white space.
���
For each test case, print the input string in the shape of U as specified in the description.
�����Թ滮����֪��
k>=1��k<=(N+2) /3;k<=(N-1)/2;

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
 } //���϶��Ǽ���k��ֵ�ĺ�����ͨ�����Թ滮֪��k�ķ�Χ��k<=(N+2) /3;k<=(N-1)/2;����Ȼ��ȡ������Χ����Сֵ������ȡ������k��ֵ 
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
������ 
������߶�h������һ����Ϊh���ϵױ߳�Ϊh �ĵ������Σ�����h=4��ͼ�����£���
   ****
  ******
 ********
**********
����
�����һ�б�ʾ������m��������m��ÿ��һ������h��h������10��
���
��Ӧ��m��case���Ҫ��ĵ������Ρ�

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
������ 
���⣺����n���������n���Ǻ������Ρ����ж����Ǻż���һ�ո�Ч�������� 
���������� 
3 
���������
* * *
 * * 
  *
 * * 
* * *
���ݹ�ģ 1<= n <=50 

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
            printf(" ");//cnt���Կ���"*"ǰ�ո�ĸ��� 
        }
        for(int j = cnt;j > 0;j--)
		{
            if(j == 1) printf("*\n");//����������һ��*��ʱ������ո� 
            else
			{
                printf("* ");   
            }
        }
        if(i < num - 1)//��ת�������ʹ���Ϊ�������� 
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
//������
/*
��һ�⣺ 
���������ڣ�����������֮�������������������������������ǹ涨����֮�������Ϊ���졣Ϊ�������������ֻ��Ҫ����ans�ĳ�ʼֵΪ1���� 
����
�ж������ݣ�ÿ�����������У��ֱ��ʾ�������ڣ���ʽΪYYYYMMDD
���
ÿ���������һ�У������ڲ�ֵ

#include <stdio.h>
int month[13][2]={{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};//�����ƽ��ÿ�·ֱ������ 
bool isLeap(int year)
{
	return (year%4==0&&year%100!=0)||(year%400==0);
}//�ж��Ƿ������� 

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
		}//��֤��һ������С�ڵڶ������� 
		y1=time1/10000,m1=time1%10000/100,d1=time1%100;
		y2=time2/10000,m2=time2%10000/100,d2=time2%100;
		int ans=1;//�������� 
		while (y1<y2||m1<m2||d1<d2)
		{
			d1++;
			if (d1==month[m1][isLeap(y1)]+1)//�������һ�� 
			{
				m1++;//�������� 
				d1=1;//��������Ϊ1 
			}
			if (m1==13)//�������һ�� 
			{
				y1++;//�������� 
				m1=1;//��������Ϊ1 
			}
			ans++;//ÿ��ѭ�����ڼ�һ 
		}
		printf("%d\n",ans);
	}
	return 0;
*/
/*
�ڶ��⣺
��Ŀ����
We now use the Gregorian style of dating in Russia. The leap years are years with number divisible 
by 4 but not divisible by 100, or divisible by 400.For example, years 2004, 2180 and 2400 are leap. 
Years 2004, 2181 and 2300 are not leap.Your task is to write a program which will compute the day 
of week corresponding to a given date in the nearest past or in the future using today��s agreement 
about dating.
����
There is one single line contains the day number d, month name M and year number y(1000��y��3000). 
The month name is the corresponding English name starting from the capital letter.
���
Output a single line with the English name of the day of week corresponding to the date, starting 
from the capital letter. All other letters must be in lower case. 

//��2018��9��18��������Ϊ������㣬����ÿһ����������Ӧ��day of week 
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
		//printf("%d %d",time1,time2);//���Դ��� 
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
 
char daybig[7][20] = { "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };//���ڱȽ�����������
char daysmall[7][20] = { "Monday","Sunday","Saturday","Friday","Thursday","Wednesday","Tuesday" };//���ڱȽ���С���������
 
char year[13][20] = { "","January","February","March","April","May","June","July","August","September","October","November","December" };//��������úö���ˣ��ַ����±�/���ֵ�ת��
 
bool isleap(int y) {
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); //�����Ƿ�����
}
int caldays(int y1, int m1, int d1, int y, int m, int d) { //������������֮��ļ�������
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
	while (scanf("%d %s %d", &d, mon, &y) != EOF) {//��ĸ����ת��Ϊ����
		for (int i = 1; i <= 12; i++) {
			if (strcmp(mon, year[i]) == 0) {
				m = i;
				break;
			}
		}
		int y1 = 2018, m1 = 6, d1 = 6;//��������
		int time1 = 10000 * y1 + 100 * m1 + d1;
		int time = 10000 * y + 100 * m + d;
		int ans;
		if (time < time1) { //����
			swap(y1, y), swap(m1, m), swap(d1, d);
			ans = caldays(y1, m1, d1, y, m, d);
			printf("%s\n", daysmall[(ans - 2) % 7]);//СС����ѧ�Ƶ�
		}
		else { //����
			ans = caldays(y1, m1, d1, y, m, d);
			printf("%s\n", daybig[(ans + 2) % 7]);
		}
	}
	return 0;
}*/ 
/*
�����⣺ 
�������m��һ���еĵ�n�죬�����n���Ǽ��¼��š�
����
���������������y(1<=y<=3000)��n(1<=n<=366)��
���
�����ж���������ݣ�����ÿ�����ݣ��� yyyy-mm-dd�ĸ�ʽ�������ж�Ӧ�����ڴ�ӡ������
//�Լ��������׳��������������ʽ���⣬������ǵ����С����λ��ʱ���������е����ǰҪ��0ռλ 
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
        if(n%4==0&&n%100!=0||n%400==0)//�ж����꣬����2��29�죬ƽ��28��
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
�����⣺ 
��дһ�������࣬Ҫ��xxxx-xx-xx �ĸ�ʽ������ڣ�ʵ�ּ�һ��Ĳ�����
����
�����һ�б�ʾ���������ĸ���m��������m��ÿ����3���ÿո�������������ֱ��ʾ�����ա��������ݲ��������ꡣ 
���
���m�С���xxxx-xx-xx�ĸ�ʽ�������ʾ�������ڵĺ�һ������ڡ�

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
�����⣺ 
���һ�������ܼ���һ�����ڼ������������ʲô���ڡ�
����
�����һ�б�ʾ��������m��������m��ÿ���ĸ������ֱ��ʾ�����պ��ۼӵ�������
���
���m�У�ÿ�а�yyyy-mm-dd�ĸ��������

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
//������
/*
��һ�� 
��Ŀ����
�����������������Ͷ���ķǸ�10��������A��B(<=231-1)�����A+B��m (1 < m <10)��������
����
�����ʽ����������������ɲ���������ÿ����������ռһ�У�����m��A��B��ֵ��
��mΪ0ʱ���������
���
�����ʽ��ÿ���������������ռһ�У����A+B��m��������

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
