http://172.16.120.250:8081/problem_show.php?pid=16867

#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
int m,n;
struct node
{
    int sta;
    int num;
} number[101000],s[101000];
struct node1
{
    int lazy;
    int ll;
    int rr;
    int large;
} tree[101000<<2];
bool  cmp(node aa,node bb)
{
    return aa.num<bb.num;
}
int FIND(int nn)
{
    int ll=1;
    int rr=m;
    while(ll<rr)
    {
        int mid=(ll+rr)>>1;
        if(s[mid].num<nn)
        {
            ll=mid+1;
        }
        else
        {
            rr=mid;
        }
    }
    return ll;
}
void build_tree(int l,int r,int nn)
{
    tree[nn].ll=l;
    tree[nn].rr=r;
    tree[nn].lazy=1;
    tree[nn].large=1;
    if(l==r)return ;
    int mid=(l+r)>>1;
    build_tree(l,mid,nn<<1);
    build_tree(mid+1,r,(nn<<1)+1);
}
void add(int l,int r,int nn,int add_num)
{
    int mid=(tree[nn].ll+tree[nn].rr)>>1;

    tree[nn].large=max(tree[nn].large,add_num);
   // cout<<"l = "<<l<<' '<<"r = "<<r<<' '<<add_num<<endl;
    if(tree[nn].ll==l&&tree[nn].rr==r)
    {
        if(add_num>=tree[nn].lazy&&add_num>=tree[nn].large)
        {
            tree[nn].lazy=add_num;
            tree[nn].large=add_num;
        }
        else if(add_num<tree[nn].large&&add_num>tree[nn].lazy)
        {
            add(l,mid,nn<<1,add_num);
            add(mid+1,r,(nn<<1)+1,add_num);
        }
    }
    else
    {
     add(tree[nn].ll,mid,nn<<1,tree[nn].lazy);
     add(mid+1,tree[nn].rr,(nn<<1)+1,tree[nn].lazy);
     tree[nn].lazy=1;
     if(r<=mid)add(l,r,nn<<1,add_num);
     else if(l>mid)add(l,r,(nn<<1)+1,add_num);
     else
     {
        add(l,mid,nn<<1,add_num);
        add(mid+1,r,(nn<<1)+1,add_num);
     }
    }
    return ;
}
int get_num(int sta,int nn)
{
    if(tree[nn].lazy>1||tree[nn].ll==tree[nn].rr)return tree[nn].lazy;
    int mid=(tree[nn].ll+tree[nn].rr)>>1;
    if(sta<=mid)get_num(sta,nn<<1);
    else get_num(sta,(nn<<1)+1);
}
int main()
{
//    freopen("d.txt", "r", stdin);
//    freopen("cz.txt", "w", stdout);

    while(scanf("%d%d",&m,&n)!=EOF)
    {
        for(int ii=1; ii<=m; ii++)
        {
            scanf("%d",&s[ii].num);
            s[ii].sta=ii;
            number[ii].num=s[ii].num;
        }
        sort(s+1,s+m+1,cmp);
       // for(int ii=1;ii<=m;ii++)
        //    cout<<s[ii].num<<' ';
       // cout<<endl
        int get_max=1;
        build_tree(1,m,1);
        for(int ii=1; ii<=m; ii++)
            number[s[ii].sta].sta=ii;
        for(int ii=1; ii<=m; ii++)
        {
            int dd=max(s[1].num,number[ii].num-n);
            int ll=FIND(dd);
            int pp=min(s[m].num,number[ii].num+n);
            int rr;
            if(pp>=s[m].num)
            {
                rr=m+1;
            }
            else
            {
                rr=FIND(pp+1);
            }
            int add_num=get_num(number[ii].sta,1);
            get_max=max(get_max,add_num);
            //cout<<"ii = "<<number[ii].num<<' '<<number[ii].sta<<' '<<"ll =  "<<ll<<' '<<"rr-1 = "<<rr-1<<' '<<add_num<<endl;
            add(ll,rr-1,1,add_num+1);
        }
        printf("%d\n",get_max);
    }
    return 0;
}
