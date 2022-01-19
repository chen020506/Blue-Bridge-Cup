// 时间：2022.1.11 22点35分
// 注意这种方法只能得到30%的分数，当骰子数比较大的时候，将会超时 

#include<iostream>
#include<algorithm>

using namespace std;
#define MOD 1000000007
int op[7];//这个数组用来存储骰子的面对应关系
bool conflict[7][7];
int n,m;

void init(){
    op[1]=4;
    op[4]=1;
    op[2]=5;
    op[5]=2;
    op[3]=6;
    op[6]=3;
}
//ans代表的是上一层定好了朝上的数字为up的情况下，垒好cnt个骰子的方案数
long long int dfs(int up,int cnt){
    long long ans=0;
    if(cnt==0)//骰子已经递归处理完成
        return 4;
    for(int upp=1;upp<=6;upp++){
        if(conflict[op[up]][upp]) continue;//如果上一层骰子的下面和此时冲突，则进行下次循环
        ans=(ans+dfs(upp,cnt-1))%MOD;
    }
    return ans;
}

int main()
{
    init();
    cin>>n>>m;
    
    for(int i=0;i<m;i++){//记录冲突
        int x,y;
        cin>>x>>y;
        conflict[x][y]=true;
        conflict[y][x]=true;
    }
    long long ans=0;
    for(int up=1;up<=6;up++){//up代表第一层递归时最上面的面的点数，从1到6
        ans=(ans+4*dfs(up,n-1))%MOD;
//这里乘4的原因是当第一层的上下两面的点数确定好之后，侧面可以旋转四次所以乘4
    }
   printf("%lli",ans);
    return 0;
}
