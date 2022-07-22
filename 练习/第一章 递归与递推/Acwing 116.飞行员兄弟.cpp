//  时间：2022.07.21 23点46分
//  算法：递推 枚举 位运算

//这位兄弟写的太详细，所以借鉴一下
//参考链接：https://www.acwing.com/solution/content/80128/
//一个把手改变，会使所在行列的所有把手全部反转
//特点：①在最优解里面每个把手只按一次，按两次没有区别，
//②按的顺序无关紧要，最终取决于这个把手按的次数！！！
//思考这个题可以递推出来吗？  答案是：很难
//可以想一想，前面的题都是通过某种顺序，每一次都是影响一个灯泡，但是这个题
//不能使用前面的办法，因为操作一次会影响好多灯泡。所以想一想朴素做法

//我们发现这个题的数据范围很小，所以尝试用暴力解决ac
//暴力思路：①16个开关，所有开关的状态数量想一想是多少？ 答案是2^16！这个我感觉
//我这么笨还是可以想出来的，往后怎么想呢？
//状态数量即最大操作次数2^16（65536）,既然也不大，那就①枚举所有的方案，
//然后按照这个方案来操作
//②如果可以实现把手全开，证明此方案合法
//③然后统计这个方案里面需要操作的把手数量
//④在所有能按的开关数量里取一个最小值
//ac
//输出方案注意:若两种方案步数相同，按字典序（先按横坐标排序，再按纵坐标排序）


#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>

//这个宏定义其实也就最后输出的时候应用了（如果我没猜错的话），但是y总的习惯就是好习惯！
#define x first
#define y second

using namespace std;

typedef pair<int,int> PII;

const int N=5;

char g[N][N],backup[N][N];


//映射函数
int get(int x,int y)
{
    return x*4+y;//返回第x行第y列上的数是多少
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

int main()
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            cin>>g[i][j];

    vector<PII> res;//这是记录方案所需要的结构

    //枚举所有的方案
    for(int op=0;op<1<<16;op++)
    {
        vector<PII> temp;//temp里面存的是方案
        //先备份一下，为什么？因为这又不是最终方案，我们要把所有方案都试一遍，求最少的
        memcpy(backup,g,sizeof g);

        //枚举16个位置,进行操作
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                if(op>>get(i,j)&1) //如果当前位置是1的话--get的作用就是返回二进制数中那一位是第几位，从而判断是否为1
                {
                    temp.push_back({i,j});
                    //按一下开关
                    turn_all(i,j);
                }


        //判断所有灯泡是否全亮
        bool has_closed=false;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                if(g[i][j]=='+') has_closed=true;

        if(has_closed==false)
        {
            //如果方案为空或者他的操作数大于我们刚存好的新的方案，那么就修改它
            if(res.empty()||res.size()>temp.size()) res=temp;
        }
        //还原回来，供下一个方案操作
        memcpy(g,backup,sizeof g);
    }
    //因为没说无解，所以可以猜想一下一定有解
    cout<<res.size()<<endl;
    //这里的迭代函数就是一种简便写法，不要误解
    //另外原题下标从1开始，所以下面加1了
    for(auto op:res) cout<<op.x+1<<" "<<op.y+1<<endl;

    return 0;
}


