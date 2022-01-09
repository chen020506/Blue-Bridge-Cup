// 时间：2022.1.9 22点43分 
#include <stdio.h>
#include <string.h>
void StringInGrid(int width, int height, const char* s) {
    int i,k;
    char buf[1000];
    strcpy(buf, s);
    if(strlen(s)>width-2) buf[width-2]=0;//左右居中，如果太长则截断

    printf("+");
    for(i=0;i<width-2;i++) printf("-");
    printf("+\n");

    for(k=1; k<(height-1)/2;k++){
        printf("|");
        for(i=0;i<width-2;i++) printf(" ");
        printf("|\n");
    }

    printf("|");
    //scanf中的*理解为过滤读入
    //printf中的*理解为动态设置输出字符的宽域
    //printf("%*s", 3,"ab");就是把"ab"放入宽域为3的空间中右对齐
    printf("%*s%s%*s",(width-2-strlen(buf))/2,"",
           buf, (width-2-strlen(buf))/2,""); //填空

    printf("|\n");

    for(k=(height-1)/2+1; k<height-1; k++){
        printf("|");
        for(i=0;i<width-2;i++) printf(" ");
        printf("|\n");
    }

    printf("+");
    for(i=0;i<width-2;i++) printf("-");
    printf("+\n");
}

int main() {
    StringInGrid(20,6,"abcd1234");
    return 0;
}
