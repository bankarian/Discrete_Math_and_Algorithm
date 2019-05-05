//传递闭包应用
//Bankarian, HNU 
#include <iostream>
#include <cstring>
#define Out freopen("output.txt","w",stdout)
#define Fin freopen("input.txt","r",stdin)
#define IO ios::sync_with_stdio(false), cin.tie(0);
using namespace std;
int relation[105][105]={0}; 
int main()
{
//	Fin; 
	int N=0, M=0;
	int win=0, los=0;
	while(cin>> N>> M)  //while(scanf("%d%d",&N,&M)==2) 
	{
		//遇到循环就要记得初始化 
		memset(relation,0,sizeof(relation)); 
		while(M--)
		{
			cin>> win>> los;
			relation[win][los]=1;
		}
		//floyd 传递关系 
		for(int k=1;k<=N;++k)
			for(int i=1;i<=N;++i)
				for(int j=1;j<=N;++j)
				{
					if(i==j || i==k || j==k) continue;  
					if(relation[i][k] && relation[k][j]){
						relation[i][j]= 1; //关系的传递 
					}
					//another way
					//relation[i][j] |= relation[i][k] & relation[k][j]
				}
		int ans=0,j=0;
		for(int i=1;i<=N;++i){
			for( j=1;j<=N;++j){
				if(i==j) continue;
				if(!relation[i][j] && !relation[j][i]) break;
				// i和j 没有关系 所以i 和j 的排名不能确定
				// 若 i 能够确定排名，则其跟所有的人的关系都确定 
			}
			if(j>N) ++ans; //统计关系能够确定的 
		}
		cout << ans<< endl; 
	} 
	return 0;
 } 
