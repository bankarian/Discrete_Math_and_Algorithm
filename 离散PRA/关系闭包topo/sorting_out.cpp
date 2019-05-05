//���������⣬û�п���ȷ������󣬺�ߵ�����ʹԭ��������ì��
//�ҿ��ˣ����tm��ĥ���Ҷ���ʱ�䣡���� 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm> 
using namespace std;
#define Fin freopen("input.txt","r",stdin)
int relation[30][30]={0};
int pos[30]={0};
int n=0,m=0;
char a,b;
inline void initial()
{
	memset(relation,0,sizeof(relation));
	for(int i=0;i<n;++i){
		pos[i]=i;	
	}
}
int expand_relation()
{
	//floyd ��ϵ���� 
	for(int k=0;k<n;++k)
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
			{
				if(i==j || j==k || i==k) continue;
				relation[i][j] |= relation[i][k]&relation[k][j];
				if(relation[i][j] && relation[j][i]){
					return -1; //����ì�� 
				} 
			}
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
		{
			if(i==j) continue;
			if(!relation[i][j] && !relation[j][i]){
				return 0; //��ϵ��ȷ�� 
			}
		}
	return 1; //��ϵȷ�� 
}
bool Comp(const int &a,const int &b)
{
	return relation[a][b];
}
int main()
{
//	Fin; 
	while(cin>> n>> m)
	{
		if(n==0) break;
	 	initial(); //��ʼ�� 
		int judge=0;
		for(int i=1;i<=m;++i)
		{
			cin>> a; cin.get();
			cin>> b;
			if(judge==-1 || judge==1) continue;//�Ѿ�����ì�� 
			
			int u= a-'A', v= b-'A';
			relation[u][v]=1;
			if(relation[v][u]){
				judge= -1;
				printf("Inconsistency found after %d relations.\n",i);
			}
			if(judge==-1) continue;
			judge= expand_relation(); 
			if(judge==-1){
				printf("Inconsistency found after %d relations.\n",i);
				continue;	
			}
			else if(judge==1){
				sort(pos,pos+n,Comp);
				printf("Sorted sequence determined after %d relations: ",i);
				for(int i=0;i<n;++i)
					printf("%c",pos[i]+'A');
				puts(".");
			} 
			else continue;
		}
		if(judge==0)	//puts�Դ��س� 
			puts("Sorted sequence cannot be determined.");
		
	}
	return 0;
}
