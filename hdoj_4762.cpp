#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define MOD 10000
using namespace std;
int ans,sum[110];
void xx(int nn)
{
    sum[100]=1;
    while(nn--)
    {
        int sta=0;
        for(int ii=100;ii>=0;ii--)
        {
            int tt=sum[ii];
            sum[ii]=(sum[ii]*ans+sta)%MOD;
            sta=(tt*ans+sta)/MOD;
        }
    }
    return ;
}
bool judge(int nn)
{
    int kk=0;
    for(int ii=0;ii<=100;ii++)kk=(sum[ii]+kk*10000)%nn;
    if(kk==0)return true;
    return false;
}
void dd(int nn)
{
    int uu=0;
    for(int ii=0;ii<=100;ii++)
    {
        int tt=uu;
        uu=(sum[ii]+uu*MOD)%nn;
        sum[ii]=(sum[ii]+tt*MOD)/nn;
    }
    return ;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        memset(sum,0,sizeof(sum));
        int x,y;
        scanf("%d%d",&x,&y);
        ans=x;
        xx(y-1);
        int pp=y;
        for(int ii=2;ii<=pp;ii++)
        {
            while(y%ii==0)
            {
                if(judge(ii)){y/=ii;dd(ii);}
                else break;
            }
        }
        printf("%d/",y);
        for(int ii=0;ii<=100;ii++)
        {
            if(sum[ii]!=0)
            {
                printf("%d",sum[ii]);
                for(int jj=ii+1;jj<=100;jj++)printf("%04d",sum[jj]);
                break;
            }
        }
        printf("\n");
    }
    return 0;
}

/*
输入：m,n
answer:n/(m^(n-1))
*/
