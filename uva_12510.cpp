#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int MINX=-1;
int get_max,x,y;
char s[12][12];
int mark[12][12];
int dir[4][2]={1,0,-1,0,0,1,0,-1};
struct node
{
    int xx;
    int yy;
    int dd[4];
    int num;
}start,oo[10];
struct node1
{
    int ff[6][4];
};
struct node2
{
    char hh[12][12];
};
int get[10];
int zhidao[12][12];
int bfs(node2 &tt)
{
    int sum=0;
    queue<node>q;
    q.push(start);
    while(!q.empty())
    {
        node rr=q.front();
        q.pop();
        if(tt.hh[rr.xx][rr.yy]=='C'){sum++;tt.hh[rr.xx][rr.yy]='.';}
        for(int ii=0;ii<4;ii++)
        {
            node ee;
            ee.xx=rr.xx+dir[ii][0];
            ee.yy=rr.yy+dir[ii][1];
            if(tt.hh[ee.xx][ee.yy]=='O'&&!get[zhidao[ee.xx][ee.yy]])oo[zhidao[ee.xx][ee.yy]].dd[ii]=1;
            if(ee.xx<0||ee.xx>=x||ee.yy<0||ee.yy>=y||mark[ee.xx][ee.yy]||tt.hh[ee.xx][ee.yy]=='X'||tt.hh[ee.xx][ee.yy]=='O')continue;
            q.push(ee);
            mark[ee.xx][ee.yy]=1;
        }
    }
    return sum;
}
void dfs(node2 tt,int rel)
{
    node1 pp;
    memset(mark,0,sizeof(mark));
   for(int ii=1;ii<=5;ii++)
        for(int jj=0;jj<4;jj++)
            oo[ii].dd[jj]=0;
    int ans=bfs(tt);
   // cout<<ans<<endl;
     for(int ii=1;ii<=5;ii++)
        for(int jj=0;jj<4;jj++)
            pp.ff[ii][jj]=oo[ii].dd[jj];
    get_max=max(ans+rel,get_max);
    for(int ii=1;ii<=oo[0].num;ii++)
    {
        if(get[ii])continue;
        for(int jj=0;jj<4;jj++)
        {
            if(pp.ff[ii][jj])
            {
                node ee;
                ee.xx=oo[ii].xx+dir[jj][0];
                ee.yy=oo[ii].yy+dir[jj][1];
                if(tt.hh[ee.xx][ee.yy]=='X'||tt.hh[ee.xx][ee.yy]=='O'||ee.xx<0||ee.xx>=x||ee.yy<0||ee.yy>=y||tt.hh[ee.xx][ee.yy]=='C')continue;
                char next;
                next=tt.hh[ee.xx][ee.yy];
                tt.hh[ee.xx][ee.yy]='O';
                tt.hh[oo[ii].xx][oo[ii].yy]='.';
                get[ii]=1;
                dfs(tt,ans+rel);
                tt.hh[ee.xx][ee.yy]=next;
                tt.hh[oo[ii].xx][oo[ii].yy]='O';
                get[ii]=0;
            }
        }
    }

    return ;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        memset(oo,0,sizeof(oo));
        memset(get,0,sizeof(get));
        get_max=0;
        scanf("%d%d",&x,&y);
        for(int ii=0;ii<x;ii++)
        scanf("%s",s[ii]);
        for(int ii=0;ii<x;ii++)
        {
            for(int jj=0;jj<y;jj++)
            {
                if(s[ii][jj]=='O')
                {
                    zhidao[ii][jj]=++oo[0].num;
                    oo[oo[0].num].xx=ii;
                    oo[oo[0].num].yy=jj;
                }
                if(s[ii][jj]=='S')
                   {
                       start.xx=ii;
                       start.yy=jj;
                       s[ii][jj]='.';
                   }
            }
        }
        node2 tt;
        for(int ii=0;ii<x;ii++)
            for(int jj=0;jj<y;jj++)
                tt.hh[ii][jj]=s[ii][jj];
        dfs(tt,0);
        printf("%d\n",get_max);
    }
    return 0;
}
