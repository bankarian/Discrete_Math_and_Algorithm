//���鼯��ͨ +������ŷ��·�ж�:http://poj.org/problem?id=1386 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int maxn = 30;
int N=0,T=0;
int Root[maxn]={0},out[maxn]={0},in[maxn]={0};
char str[1005]={0};
bool vis[maxn]={false};
int Id(char x){
	return x-'a'+1;
}
int FindRoot(int x)
{
	//�Ҹ�+·��ѹ�� 
	while(x^Root[x]){//δ�ҵ��� 
		Root[x] = Root[Root[x]];
		x = Root[x];
	}
	return x;
}
inline void Unite(int x,int y)
{
	int rootX = FindRoot(x);
	int rootY = FindRoot(y);
	if(rootX == rootY) return ;//�Ѿ���ͨ
	else{ //����ֻ��26����ĸ�������ֱ����,���ж����ĸ߶� 
		Root[rootX] = rootY;
	} 
}
inline void Initial()
{
	memset(out,0,sizeof(out));
	memset(in,0,sizeof(in));
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=26;++i) Root[i] = i;
}
bool HaveEuler()
{	//ע���������жϣ�ŷ��· && ŷ����·�� 
	int st=0,en=0,node=0;
	for(int i=1;i<=26;++i)
	{
		if(out[i]-in[i] == 1){
			st += 1;
		}
		else if(in[i]-out[i] == 1){
			en += 1;
		}
		else if(in[i] == out[i]) node += 1; 
		else return false; //����������>1���Ȼû��ŷ��· 
		if(en>1 || st>1) return false;//����һ��ͨ· 
	} 
	if((en==1&&st==1) || (node==26)) return true;
	return false;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		Initial();
		for(int i=0;i<N;++i){//���������ͨ 
			scanf("%s",str); getchar();
//			gets(str);
			int head = Id(str[0]);
			int tail = Id(str[strlen(str)-1]);
			++out[head], ++in[tail];
			vis[head]= vis[tail]= true;//�����Щ��ĸ���ֹ� 
			Unite(head,tail);
		}
		int cnt=0;
		for(int i=1;i<=26;++i){
			if(vis[i] && Root[i]==i) cnt += 1;
		}
		if(cnt^1){//���ж��,����ͨ
			puts("The door cannot be opened.");
			continue; //�ض� 
		}
		//��ͨ���ж��Ƿ���ŷ��·
		if(HaveEuler()){//����ŷ��·���ɹ����ӣ� 
			puts("Ordering is possible.");
		}
		else puts("The door cannot be opened.");
	}
	return 0;
}
