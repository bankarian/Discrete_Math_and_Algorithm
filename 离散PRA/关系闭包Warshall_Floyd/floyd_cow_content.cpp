//���ݱհ�Ӧ��
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
		//����ѭ����Ҫ�ǵó�ʼ�� 
		memset(relation,0,sizeof(relation)); 
		while(M--)
		{
			cin>> win>> los;
			relation[win][los]=1;
		}
		//floyd ���ݹ�ϵ 
		for(int k=1;k<=N;++k)
			for(int i=1;i<=N;++i)
				for(int j=1;j<=N;++j)
				{
					if(i==j || i==k || j==k) continue;  
					if(relation[i][k] && relation[k][j]){
						relation[i][j]= 1; //��ϵ�Ĵ��� 
					}
					//another way
					//relation[i][j] |= relation[i][k] & relation[k][j]
				}
		int ans=0,j=0;
		for(int i=1;i<=N;++i){
			for( j=1;j<=N;++j){
				if(i==j) continue;
				if(!relation[i][j] && !relation[j][i]) break;
				// i��j û�й�ϵ ����i ��j ����������ȷ��
				// �� i �ܹ�ȷ����������������е��˵Ĺ�ϵ��ȷ�� 
			}
			if(j>N) ++ans; //ͳ�ƹ�ϵ�ܹ�ȷ���� 
		}
		cout << ans<< endl; 
	} 
	return 0;
 } 
