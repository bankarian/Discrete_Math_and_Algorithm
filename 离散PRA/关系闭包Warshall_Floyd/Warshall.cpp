//Warshall_Floyd
//Bankarian,HNU 
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define Fin freopen("input.txt","r",stdin)
const int maxn= 4;
class Warshall_Floyd{
	private:
		int Graph[maxn][maxn]; //��ͼ 
	public:
		void SetGraph();
		void Warshall();
		void Floyd();
		void Print();
		
};
void Warshall_Floyd::SetGraph()
{
	memset(Graph,0,sizeof(Graph)); //��ʼ��  
	for(int i=0;i<maxn;++i)
		for(int j=0;j<maxn;++j)
			scanf("%1d",&Graph[i][j]);
}
void Warshall_Floyd::Warshall()
{
	cout<<"Warshall, ";
	for(int i=0;i<maxn;++i) //�� 
	for(int j=0;j<maxn;++j) //�� 
	{
		if(Graph[i][j]){
			for(int k=0;k<maxn;++k){//�ڵ�i������
				//������
				if(Graph[k][i])
					Graph[k][j]=1;
			} 
		}
	}
}
void Warshall_Floyd::Floyd()
{
	cout<< "Floyd, ";
	for(int k=0;k<maxn;++k) //�����ڵ� 
		for(int i=0;i<maxn;++i)
			for(int j=0;j<maxn;++j)
			{
				Graph[i][j] |= Graph[i][k]&Graph[k][j];
//				if(Graph[i][k] && Graph[k][j]) Graph[i][j]=1; 
			}
}
void Warshall_Floyd::Print()
{
	cout<<"After function:"<<endl;
	for(int i=0;i<maxn;++i){
		for(int j=0;j<maxn;++j){
			cout<< Graph[i][j];
		}
		cout<< endl;	
	}
		
}
int main() 
{
	Warshall_Floyd a;
	a.SetGraph();
	a.Warshall();
	a.Print();
	
	a.SetGraph();
	a.Floyd();
	a.Print();
	return 0;
}
