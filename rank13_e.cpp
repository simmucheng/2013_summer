link->http://www.bnuoj.com/bnuoj/contest_show.php?cid=2998#problem/33109


#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
queue<int>q;
int s[51000],mm[51000],sta[51000];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(!q.empty())q.pop();
        for(int ii=1;ii<=n;ii++)scanf("%d",&s[ii]);
        mm[n]=s[n];
        sta[n]=n;
        for(int ii=n-1;ii>=1;ii--)
        {
            if(mm[ii+1]>s[ii])
            {
                mm[ii]=mm[ii+1];
                sta[ii]=sta[ii+1];
            }
            else
            {
                mm[ii]=s[ii];
                sta[ii]=ii;
            }
        }
        int top=s[1],topp=1;
        int get_max=s[1],get_len=1;
        int ss=1;
        q.push(s[1]);
        for(int ii=2;ii<=n;ii++)
        {
            if(s[ii]>top&&ii<=sta[topp])
                {
                    q.push(s[ii]);
                    if(s[ii]>get_max)
                    {
                        get_max=s[ii];
                        ss=q.size();
                        get_len=max(get_len,ss);
                    }
                }
            else
            {
                get_len=max(get_len,ss);
                while(!q.empty())q.pop();
                q.push(s[ii]);
                top=s[ii];
                topp=ii;
                get_max=s[ii];
            }
        }
        if(get_len>=2)printf("%d\n",get_len-1);
        else printf("-1\n");
    }
    return 0;
}
