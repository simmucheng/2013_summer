#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;

queue<int>q;
int hus[30][30];
int next[30];
int wife[30][30];
int ans[30];
int choose[30][30];
int get_marry[30];
int male[30];
int famale[30];
int main()
{
    int n;
    scanf("%d",&n);
    for(int kk=1;kk<=n;kk++)
    {
        memset(get_marry,-1,sizeof(get_marry));
        memset(next,0,sizeof(next));
        int m;
        scanf("%d",&m);
        char s[10];
        int step=0;
        for(int ii=1;ii<=m;ii++)
        {
            scanf("%s",s);
            male[step++]=s[0]-'a';
        }
        step=0;
        for(int ii=1;ii<=m;ii++)
        {
            scanf("%s",s);
            famale[step++]=s[0]-'A';
        }
        for(int ii=1;ii<=m;ii++)
        {
            char w[100];
            scanf("%s",w);
            int sta=0;
            for(int jj=2;jj<=m+1;jj++)
            choose[w[0]-'a'][sta++]=w[jj]-'A';
        }
        for(int ii=1;ii<=m;ii++)
        {
            char w[100];
            scanf("%s",w);
            int sta=0;
            for(int jj=2;jj<=m+1;jj++)
            wife[w[0]-'A'][w[jj]-'a']=sta++;
        }
        for(int ii=0;ii<m;ii++)
        {
        q.push(male[ii]);
       // printf("%c ",male[ii]+'a');
        }
        while(!q.empty())
        {
            int tt=q.front();
            q.pop();
            int ww=choose[tt][next[tt]];
           // printf("%c ",ww+'A');
           // cout<<endl;
            if(get_marry[ww]!=-1)
            {
                if(wife[ww][tt]<wife[ww][get_marry[ww]])
                {
                    q.push(get_marry[ww]);
                    get_marry[ww]=tt;
                }
                else q.push(tt);
            }
            else get_marry[ww]=tt;
            next[tt]++;
        }
        for(int ii=0;ii<m;ii++)
            ans[get_marry[famale[ii]]]=famale[ii];
        for(int ii=0;ii<m;ii++)
            printf("%c %c\n",male[ii]+'a',ans[male[ii]]+'A');
        if(kk!=n)printf("\n");
    }
    return 0;
}
