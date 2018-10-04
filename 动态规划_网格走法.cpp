题目描述
有一个X*Y的网格，小团要在此网格上从左上角到右下角，只能走格点且只能向右或向下走。请设计一个算法，计算小团有多少种走法。给定两个正整数int x,int y，请返回小团的走法数目。
输入描述:
输入包括一行，逗号隔开的两个正整数x和y，取值范围[1,10]。
输出描述:
输出包括一行，为走法的数目。
示例1
输入
3 2
输出
10
/*动态规划：
     对于x*Y网格，dp[i][j]表示(i,j)位置一共有多少种走法,
     由于只能向左和向右走，所以第一列和第一行所有位置的走法都是1，即dp[i][0]=1,dp[0][j]=1(0=<i<=x,0<=j<=y)，
     对于其他位置，走法应该等于其左边格点的走法和其上面格点的走法之和，dp[i][j]=dp[i-1][j]+dp[i][j-1]，
     画个图比较容易理解。
*/  
/*例如题目中的输入3 2 其实就是一个4*3的格子，至于为什么是4*3是因为小团是从左上角走到右下角，即小团
并不在这个格子里，这个是整个问题理解的关键。3*2网络的各个点的走法数目如下：
10 6 3 1
4  3 2 1
1  1 1 1
3*2的走法就是格子中4*3的那个格子的走法数目
*/
#include<iostream>
using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;
	int array[11][11];
	for (int i = 0; i <=x; i++)
	{
		array[i][0] = 1;
	}
	for (int i = 0; i <=y; i++)
	{
		array[0][i] = 1;
	}
	for(int i=1;i<=x;i++)
		for (int j = 1; j <=y; j++)
		{
			array[i][j] = array[i - 1][j] + array[i][j - 1];
		}
	cout << array[x][y] << endl;//这里的数组下标是从0开始的，所以array[x][y]，就是x和y都增加了1
	return 0;
}