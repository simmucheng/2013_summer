#include<iostream>
#include<algorithm>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

const __int64 INF=(((long long)(1))<<32);
struct node
{
    __int64 a;
    __int64 b;
    __int64 c;
}s[20100];
__int64 aa;
bool judge(__int64 ll,__int64 rr,int nn)
{
    aa=0;
    for(int ii=1;ii<=nn;ii++)
    {
        if(s[ii].b<ll||s[ii].a>rr)continue;
        __int64 get_l,get_r;

        if(s[ii].a>=ll)get_l=s[ii].a;
        else if((ll-s[ii].a)%s[ii].c==0)get_l=ll;
        else get_l=(ll-s[ii].a)/s[ii].c*s[ii].c+s[ii].a+s[ii].c;

        get_r=min(s[ii].b,rr);

        if(get_r<get_l)continue;
        aa+=(get_r-get_l)/s[ii].c+1;
    }
    if(aa%2==1)return true;
    return false;
}
__int64 binary(__int64 ll,__int64 rr,int nn)
{
    if(ll==rr&&judge(ll,rr,nn))return ll;
    else if(ll==rr&&!judge(ll,rr,nn))return -1;
    while(ll<rr)
    {
        __int64 mid=(ll+rr)>>1;
        if(judge(ll,mid,nn))rr=mid;
        else if(judge(mid+1,rr,nn))ll=mid+1;
        else return -1;
    }
    judge(ll,ll,nn);
    return ll;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        __int64 get_ll=INF;
        __int64 get_rr=-1;
        for(int ii=1;ii<=n;ii++)
        {
            scanf("%I64d%I64d%I64d",&s[ii].a,&s[ii].b,&s[ii].c);
            get_ll=min(get_ll,s[ii].a);
            get_rr=max(get_rr,s[ii].b);
        }
        get_ll=max(get_ll,(__int64)1);
        get_rr=max(get_rr,(__int64)1);
        __int64 ans=binary(get_ll,get_rr,n);
        if(ans==-1)printf("DC Qiang is unhappy.\n");
        else printf("%I64d %I64d\n",ans,aa);
    }
    return 0;
}
