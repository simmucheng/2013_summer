http://www.bnuoj.com/bnuoj/problem_show.php?pid=10282

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN=1e9+1e8;
const double eps=1e-8;

int path[3100];
int mark[3100];
int pre[3100];
int get_ans[3100][3100];
int dp[3100][3100];
int q[3100][3100];
int aa,ss;
vector<int>w[3100];
vector<int>ans[3100];

long long prime(int nn)
{
    for(int ii=0;ii<nn;ii++){path[ii]=MAXN;mark[ii]=0;pre[ii]=-1;}
    long long ret=0;
    int rr=1;
    path[0]=0;
    while(rr!=-1)
    {
        rr=-1;
        int get_min=MAXN;
        for(int ii=0;ii<nn;ii++)
        {
            if(path[ii]<get_min&&!mark[ii])
            {
                get_min=path[ii];
                rr=ii;
            }
        }
        if(rr==-1)break;
        ret+=get_min;
        if(rr!=0)
        {
        ans[rr].push_back(pre[rr]);
        ans[pre[rr]].push_back(rr);
        }
        mark[rr]=1;
        int len=w[rr].size();
        for(int ii=0;ii<len;ii++)
        {
            int son=w[rr][ii];
            if(path[son]>q[rr][son]&&!mark[son])
            {
                path[son]=q[rr][son];
                pre[son]=rr;
            }
        }
    }
    return ret;
}

void input(int nn,int mm)
{
       for(int ii=0;ii<nn;ii++){w[ii].clear();ans[ii].clear();}
       for(int ii=1;ii<=mm;ii++)
       {
           int x,y;
           int t;
           scanf("%d%d%d",&x,&y,&t);
           w[x].push_back(y);
           w[y].push_back(x);
           q[x][y]=q[y][x]=t;
       }
    return ;
}

int dfs1(int nn,int fa,int ff)
{
    int len=ans[nn].size();
    if(pre[ff]!=nn&&pre[nn]!=ff)dp[ff][nn]=q[ff][nn];
    for(int ii=0;ii<len;ii++)
    {
        int son=ans[nn][ii];
        if(son==fa)continue;
        dp[ff][nn]=min(dp[ff][nn],dfs1(son,nn,ff));
    }
    return dp[ff][nn];
}

void dfs2(int nn,int fa,int ff)
{
    int len=ans[nn].size();
    for(int ii=0;ii<len;ii++)
    {
        int son=ans[nn][ii];
        if(son==ff||son==fa)continue;
        get_ans[aa][ss]=min(get_ans[aa][ss],dp[son][ff]);
        dfs2(son,nn,ff);
    }
    return ;
}
void init(int nn)
{
    for(int ii=0;ii<nn;ii++)
    for(int jj=0;jj<nn;jj++)
    {
        get_ans[ii][jj]=MAXN;
        dp[ii][jj]=MAXN;
        q[ii][jj]=MAXN;
    }
    return ;
}
int main()
{
     int n,m;
     while(scanf("%d%d",&n,&m),m||n)
    {
      init(n);
      input(n,m);
      long long tt=prime(n);
      for(int ii=0;ii<n;ii++)
      dfs1(ii,-1,ii);
      for(int ii=0;ii<n;ii++)
      {
          int len=ans[ii].size();
          for(int jj=0;jj<len;jj++)
          {
              int son=ans[ii][jj];
              aa=ii;ss=son;
              dfs2(ii,-1,son);
              get_ans[son][ii]=get_ans[ii][son];
             // cout<<son<<' '<<ii<<' '<<get_ans[son][ii]<<endl;
          }
      }
      int h;
      scanf("%d",&h);
      double total=0;
      for(int ii=1;ii<=h;ii++)
      {
          int x,y,t;
          scanf("%d%d%d",&x,&y,&t);
          if(pre[x]==y||pre[y]==x)total+=(tt+min(get_ans[x][y],t)-q[x][y])*1.0;
          else total+=tt;
      }
      total/=h*1.0;
      printf("%.4f\n",total+eps);
    }
    return 0;
}
