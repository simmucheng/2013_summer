link->http://www.bnuoj.com/bnuoj/contest_show.php?cid=2998#problem/33112


#include<cstdio>
#include<cstring>
#include<iostream>
#define inf 1<<30
using namespace std;
int dir[4][2]={1,0,-1,0,0,-1,0,1};
int mark[1100][1100],x,y;
char s[1100][1100];
int ans_x,ans_y,get_max;
void dfs(int xx,int yy,int step)
{
    mark[xx][yy]=1;
    if(step>get_max)
    {
        get_max=step;
        ans_x=xx;
        ans_y=yy;
    }
    for(int ii=0;ii<4;ii++)
    {
        int x1=xx+dir[ii][0];
        int y1=yy+dir[ii][1];
        if(s[x1][y1]=='#'||x1<0||y1<0||x1>=x||y1>=y||mark[x1][y1])continue;
        dfs(x1,y1,step+1);
    }
    return ;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&y,&x);
        for(int ii=0;ii<x;ii++)
            scanf("%s",s[ii]);
        int tt=0,mark_x,mark_y;
        for(int ii=0;ii<x;ii++)
        {
            for(int jj=0;jj<y;jj++)
            {
                if(s[ii][jj]=='.')
                {
                    mark_x=ii;
                    mark_y=jj;
                    tt=1;
                    break;
                }
            }
            if(tt==1)break;
        }
        get_max=-inf;
        dfs(mark_x,mark_y,0);
        memset(mark,0,sizeof(mark));
        get_max=-inf;
        dfs(ans_x,ans_y,0);
        memset(mark,0,sizeof(mark));
        get_max=-inf;
        dfs(ans_x,ans_y,0);
        printf("Maximum rope length is %d.\n",get_max);
    }
    return 0;
}
/*
7 6
#######
#.#.###
#.#.###
#.#.#.#
#.....#
#######
*/
