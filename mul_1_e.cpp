#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>
using namespace std;
int up[101000];
int down[101000];
int s[101000];
const int MAXN=1e8;
const int MINN=-1;
vector<int>q;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        memset(up,0,sizeof(up));
        memset(down,0,sizeof(down));
        q.clear();
        int m;
        scanf("%d",&m);
        for(int i=m;i>=1;i--)
        scanf("%d",&s[i]);
        q.push_back(s[1]);
        up[1]=1;
        for(int i=2;i<=m;i++)
        {
            int len=q.size();
            int sta=len;
            if(q[len-1]<s[i])
            q.push_back(s[i]);
            else if(q[len-1]==s[i]){up[i]=len;continue;}
            else
            {
                #define FIND(v)(upper_bound(q.begin(),q.end(),v)-q.begin())
                sta=FIND(s[i]);
                q[sta]=s[i];
               // cout<<"sta = "<<sta<<endl;
                #undef FIND
            }
            up[i]=sta+1;
           // cout<<sta<<endl;
        }
        q.clear();
        q.push_back(-s[1]);
        down[1]=1;
        for(int i=2;i<=m;i++)
        {
            int len=q.size();
            int sta=len;
            if(q[len-1]<=-s[i])
            q.push_back(-s[i]);
            else
            {
                #define FIND(v)(upper_bound(q.begin(),q.end(),v)-q.begin())
                sta=FIND(-s[i]);
                q[sta]=-s[i];
                #undef FIND
            }
            down[i]=sta+1;
        }
        int get_max=-1;
        for(int i=1;i<=m;i++)
        {
            if(up[i]+down[i]>get_max)
              get_max=up[i]+down[i];
        }
        printf("%d\n",get_max-1);
    }
    return 0;
}
/*
7
1 2 3 4 5 6 7
5
4 3 2 1 5
5
5 4 1 2 3
*/
