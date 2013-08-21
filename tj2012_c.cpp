#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<fstream>
using namespace std;

//ofstream oo("1.txt");
const int MAXN=1e8;
int ss[1100];
int dp[1100][10][10];
int MOD(int nn)
{
    return (nn%10+10)%10;
}
void init(int nn)
{
    for(int ii=0;ii<=nn;ii++)
        for(int jj=0;jj<=9;jj++)
            for(int kk=0;kk<=9;kk++)
                dp[ii][jj][kk]=MAXN;
    return ;
}
int main()
{
    char s[1100],w[1100];
    while(scanf("%s%s",s,w)!=EOF)
    {
        int len=strlen(s);
        init(len);
        //cout<<len<<endl;
        for(int ii=0;ii<len;ii++)ss[ii+1]=MOD(w[ii]-s[ii]);
        dp[0][0][0]=0;
        for(int ii=1;ii<=len;ii++)
        {
            for(int jj=0;jj<=9;jj++)
            {
                for(int kk=0;kk<=9;kk++)
                {
                    int ans2=MOD(jj-ss[ii]);//down
                    int ans1=MOD(ss[ii]-jj);//up
                    for(int i=0;i<=ans1;i++)
                        for(int j=0;j<=i;j++)
                            {
                                dp[ii][MOD(kk+i)][j]=min(dp[ii-1][jj][kk]+ans1,dp[ii][MOD(kk+i)][j]);
                                //if(ii==3&&MOD(jj+i)==1&&MOD(kk+j)==0)
                                //oo<<ii<<' '<<MOD(jj+i)<<' '<<MOD(kk+j)<<' '<<dp[ii][MOD(jj+i)][MOD(kk+j)]<<"TTTTT"<<jj<<' '<<kk<<' '<<dp[ii-1][jj][kk]<<endl;
                            }
                    for(int i=0;i<=ans2;i++)
                        for(int j=0;j<=i;j++)
                            dp[ii][MOD(kk-i)][MOD(-j)]=min(dp[ii-1][jj][kk]+ans2,dp[ii][MOD(kk-i)][MOD(-j)]);
                }
            }
        }
        int get_ans=MAXN;
        for(int ii=0;ii<=9;ii++)
        for(int jj=0;jj<=9;jj++)
        get_ans=min(dp[len][ii][jj],get_ans);
        printf("%d\n",get_ans);
    }
    return 0;
}
