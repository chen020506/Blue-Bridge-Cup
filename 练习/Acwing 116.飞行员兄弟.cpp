//  时间：2022.07.21 23点46分
//  算法：递推 枚举 位运算
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define x first
#define y second

typedef pair<int,int> PII;

const int N=5;
char g[N][N],backup[N][N];

int get(int x,int y)
{
    return x*4+y;
}
void turn_one(int x,int y)
{
    if(g[x][y]=='+') g[x][y]='-';
    else g[x][y]='+';
}
void turn_all(int x,int y)
{
    for(int i=0;i<4;i++) 
    {
        turn_one(x,i);
        turn_one(i,y);
    }
    turn_one(x,y);
}
int main ()
{
    for(int i=0;i<4;i++) cin>>g[i];
    vector<PII>res;
    for(int op=0;op< 1<<16;op++)
    {
        vector<PII>temp;
        memcpy(backup,g,sizeof g);
        
        
        //进行操作
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                if(op>>get(i,j)&1)
                {
                    temp.push_back({i,j});
                    turn_all(i,j);
                }
        //判断所有把手是否打开
        bool has_closed=false;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                if(g[i][j]=='+')
                    has_closed=true;
        if(has_closed==false)
        {
            if(res.empty()||res.size()>temp.size()) res=temp;
        }
        memcpy(g,backup,sizeof g);
    }
    cout<<res.size()<<endl;
    for(auto op:res) cout<<op.x+1<<" "<<op.y+1<<endl;
}