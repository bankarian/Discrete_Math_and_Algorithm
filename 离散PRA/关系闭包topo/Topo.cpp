//TOPOSORT
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int maxn= 50;
vector<int> Graph[maxn]; //建图的基础点，尚未连通 
int in[maxn],n=0,m=0; //每个点的入度 
queue<int> head;//入度为零的头节点
bool TopoSort(int n) //要排序的点数 
{
	for(int i=0;i<n;++i)
	{
		if(in[i]==0) head.push(i);//入度为零的点作为起始 
	} 
	int sum=0;
	while(!head.empty())
	{
		int now= head.front();
		head.pop();
		++sum;
		int cnt= Graph[now].size();//连通的边数 
		for(int i=0;i<cnt;++i)
		{
			--in[Graph[now][i]];//now删去后，与其连通的点入度减一
			if(!in[Graph[now][i]]){ //入度变为0 
				head.push(Graph[now][i]);
				//增加新的头节点 
			} 
		}
	}
	return sum!=n; //有环
	//若是单向无环，则应该时恰好 sum==n; 
}
inline void initial()
{
	for(int i=0;i<n;++i){
		Graph[i].clear();
		vector<int>().swap(Graph[i]);
	}
	while(!head.empty()) head.pop();
	memset(in,0,sizeof(in));
}
int main()
{
	int a=0,b=0; 
	while(scanf("%d%d",&n,&m)!= EOF)
	{
		initial();
		for(int i=0;i<m;++i)
		{
			scanf("%d%d",&a,&b);
			Graph[a].push_back(b); //a->b单向连通
			++in[b]; 
		} 
		if(TopoSort(n)) printf("has circle\n");
		else printf("no circle\n");
	} 
	return 0;
} 
