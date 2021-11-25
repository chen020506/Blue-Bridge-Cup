#include <bits/stdc++.h>
using namespace std;
 
int cnt;
 
void dfs(int i, int j) { // 发到第 i种牌 手里有 j张 
     if(i > 13) return; 
     if(j > 13) return; // 剪枝 当手里的牌数大于13张时，肯定不符合。 
     if(j == 13) {
         cnt ++;
         return ;
     }
     dfs(i+1, j);
     dfs(i+1, j+1);
     dfs(i+1, j+2);
     dfs(i+1, j+3);
     dfs(i+1, j+4);
} 
 
 int main() {
     dfs(0, 0);
     printf("%d\n", cnt);
     return 0;
}

