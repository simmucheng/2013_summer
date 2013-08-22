#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[60][60000];
int DP(int nn,int mm)
{
    if(dp[nn][mm]!=-1)return dp[nn][mm];
    dp[nn][mm]=0;
    if(mm==1)return dp[nn][mm]=DP(nn+1,0);
    if(nn>=1&&!DP(nn-1,mm))dp[nn][mm]=1;
    if(nn>=2&&((!DP(nn-2,mm+2)&&mm==0)||(!DP(nn-2,mm+3)&&mm>=1)))dp[nn][mm]=1;
    if(mm>0&&!DP(nn,mm-1))dp[nn][mm]=1;
    if(nn>0&&mm>0&&!DP(nn-1,mm+1))dp[nn][mm]=1;
    return dp[nn][mm];
}
int main()
{
    int n;
    scanf("%d",&n);
    memset(dp,-1,sizeof(dp));
    for(int jj=1;jj<=n;jj++)
    {
        int m,k,l;
        l=0;
        k=0;
        scanf("%d",&m);
        for(int ii=1;ii<=m;ii++)
        {
            int x;
            scanf("%d",&x);
            if(x==1)k++;
            else l+=x+1;
        }
        if(l)l--;
        printf("Case #%d: ",jj);
        if(DP(k,l))printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
