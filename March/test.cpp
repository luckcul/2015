#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <set>

#define ll long long
int const N = 200005;
int const M = 205;
int const inf = 1000000000;
ll const mod = 1000000007;

using namespace std;

int n;
int xnow,wnow;
int ans;

typedef struct
{
    int x;
    int w;
}PP;

PP p[N];

bool cmp(PP a,PP b)
{
    return a.x<b.x;
}

void ini()
{
    ans=0;
    int i;
    for(i=1;i<=n;i++){
        scanf("%d%d",&p[i].x,&p[i].w);
    }
    sort(p+1,p+1+n,cmp);
}

void solve()
{
    int i;
    ans=1;
    xnow=p[1].x;
    wnow=p[1].w;
    for(i=2;i<=n;i++){
        if(p[i].x-xnow>=p[i].w+wnow){
            xnow=p[i].x;
            wnow=p[i].w;
            ans++;
        }
        else{
            if(p[i].x+p[i].w<xnow+wnow){
                xnow=p[i].x;
                wnow=p[i].w;
            }
        }
    }
}

void out()
{
    printf("%d\n",ans);
}

int main()
{
  //  freopen("data.in","r",stdin);
    //scanf("%d",&T);
    //for(cnt=1;cnt<=T;cnt++)
    while(scanf("%d",&n)!=EOF)
    {
        ini();
        solve();
        out();
    }
    
}

贪心，先按x排序。设xj<xi<xk

若xi-xj>=wi+wj;

xk-xi>=wk+wi;

则xk-xj>=wk+wj+2*wi>=wk+wj。

故相邻的点之间满足条件，则所有点均满足条件。

继续，xi-xj>=wi+wj; 等价于 xi-wi>=xj+wj;

即前一个点的x+w的和要尽可能小。

1.若当前点与前一个点满足条件，则ans++,xnow=x[i],wnow=w[i]；

2.若与前一个点不满足条件，则看 x+w的和的关系，若x+w<xnow+wnow，由于x是递增关系，x-w必然更大，
    则与前一个点满足条件的集合，肯定也与当前点满足。

故舍弃前一个点，取当前点xnow=x[i],wnow=w[i]；  反之，舍弃当前点。