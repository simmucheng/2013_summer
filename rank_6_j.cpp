http://acm.csu.edu.cn/OnlineJudge/problem.php?id=1307


#include<cstdio>
#include<iostream>
#include<map>
#include<climits>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int a,b,tt,m,n,ans;
const int MAXN=1e8;
struct node
{
    int num;
    int ll;
    int rr;
}s[50100];
struct node1
{
    int num;
    int id;
};
vector<node1>w[2100];
int path[2100];
int mark[2100];
struct cmp1
{
    bool operator()(node aa,node bb)
    {
        return aa.num>bb.num;
    }
};
int cmp2(node aa,node bb)
{
    return aa.num<bb.num;
}
int dij(int limit)
{
    int rr=1;
    path[a]=0;
    while(rr!=-1)
    {
        rr=-1;
        int get_min=MAXN;
        for(int ii=1;ii<=m;ii++)
        {
            if(get_min>path[ii]&&!mark[ii])
            {
                get_min=path[ii];
                rr=ii;
            }
        }
        if(rr==-1)break;
        mark[rr]=1;
        int len=w[rr].size();
        for(int ii=0;ii<len;ii++)
        {
            int son=w[rr][ii].id;
            if(path[son]>path[rr]+w[rr][ii].num&&!mark[son]&&w[rr][ii].num<=limit)path[son]=w[rr][ii].num+path[rr];
        }
    }
    if(path[b]==MAXN)return -1;
    return path[b];
}
void init()
{
    memset(mark,0,sizeof(mark));
    for(int ii=1;ii<=m;ii++)
    path[ii]=MAXN;
}
int binary(int l,int r)
{
   while(l<r)
   {
       init();
       int mid=(l+r)>>1;
       if(dij(s[mid].num)<0)l=mid+1;
       else r=mid;
   }
   init();
   return dij(s[l].num);
}
void init1(int nn)
{
    for(int ii=1;ii<=nn;ii++)
    w[ii].clear();
    return ;
}
int main()
{
    int i,j;
    while(scanf("%d%d%d%d",&m,&n,&a,&b)!=EOF)
    {
        init1(m);
        for(int ii=0;ii<n;ii++)
        {
            int x,y,value;
            scanf("%d%d%d",&x,&y,&value);
            s[ii].ll=x;
            s[ii].rr=y;
            s[ii].num=value;
            node1 tt;
            tt.id=y;
            tt.num=value;
            w[x].push_back(tt);
            tt.id=x;
            w[y].push_back(tt);
        }
        sort(s,s+n,cmp2);
        ans=binary(0,n-1);
        printf("%d\n",ans);
    }
    return 0;
}
