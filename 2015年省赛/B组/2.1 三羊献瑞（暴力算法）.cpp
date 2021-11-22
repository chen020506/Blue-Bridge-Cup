//  时间：2021.11.22  16点51分
//  思路：将每个汉字用字符代替进行计算
//a:三 b:羊 c:生 d:瑞 e:气 f:祥 g:辉 h:献 
//由于a涉及了进位所以a必然为1,由于每个字母代表的数字都不相同所以除了a以外的其他数字不为1
//   输出：1085
#include<iostream>
using namespace std;
int main()
{
	int a=1, b, c, d, e, f, g, h;//每个字母代表一个汉字
	int n, m, sum;//n代表加数，m代表被加数，sum表示和
	  for (b = 0; b <= 9; b++)
	    for (c = 0; c <= 9; c++)
		  for (d = 0; d <= 9; d++)
		    for (e = 0; e <= 9; e++)
			  for (f = 0; f <= 9; f++)
			    for (g = 0; g <= 9; g++)
				  for (h = 0; h <= 9; h++)
					{
					  if (b!= c && b != d && b != e && b != f&& b != g && b != h
						  && c != d && c != e && c != f && c != g && c != h
						  && d != e && d != f && d != g && d != h
						  && e != f && e !=g & e != h
						  && f != g && f != h
						  && g!=h
						  && b != 1 && c != 1 && d != 1 && e != 1 && f != 1 && g != 1 && h != 1)
					  {
						n = f * 1000 + d * 100 + c * 10 + g;
						m = 1000 + b * 100 + h * 10 + d;
						sum = 10000+ b * 1000 + c * 100 + d * 10 + e;
						if (n + m == sum)
							printf("%d\n", m);
					  }
				  }
	return 0;
}