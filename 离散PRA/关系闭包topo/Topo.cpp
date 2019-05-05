//TOPOSORT
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int maxn= 50;
vector<int> Graph[maxn]; //��ͼ�Ļ����㣬��δ��ͨ 
int in[maxn],n=0,m=0; //ÿ�������� 
queue<int> head;//���Ϊ���ͷ�ڵ�
bool TopoSort(int n) //Ҫ����ĵ��� 
{
	for(int i=0;i<n;++i)
	{
		if(in[i]==0) head.push(i);//���Ϊ��ĵ���Ϊ��ʼ 
	} 
	int sum=0;
	while(!head.empty())
	{
		int now= head.front();
		head.pop();
		++sum;
		int cnt= Graph[now].size();//��ͨ�ı��� 
		for(int i=0;i<cnt;++i)
		{
			--in[Graph[now][i]];//nowɾȥ��������ͨ�ĵ���ȼ�һ
			if(!in[Graph[now][i]]){ //��ȱ�Ϊ0 
				head.push(Graph[now][i]);
				//�����µ�ͷ�ڵ� 
			} 
		}
	}
	return sum!=n; //�л�
	//���ǵ����޻�����Ӧ��ʱǡ�� sum==n; 
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
			Graph[a].push_back(b); //a->b������ͨ
			++in[b]; 
		} 
		if(TopoSort(n)) printf("has circle\n");
		else printf("no circle\n");
	} 
	return 0;
} 
