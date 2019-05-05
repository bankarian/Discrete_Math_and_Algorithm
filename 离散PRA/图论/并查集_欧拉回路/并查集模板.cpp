//��Ŀhttp://acm.hdu.edu.cn/showproblem.php?pid=1232 
#include <iostream>
#include <cstdio> 
using namespace std;
#define maxn 1005
int N=0,M=0;
int root[maxn]; //�ڵ�
int Len[maxn]; //���ĸ߶� 
int FindRoot(int x)
{	 
	while(root[x]^x){
		root[x] = root[root[x]]; //״̬ѹ�� 
		x = root[x]; //����үү�ڵ㣬ֱ����үү 
	}
	return x; //�ҵ������� 
}
//int FindRoot_2(int x){
//	//�������õݹ�İ취����ֱ�ۣ�������ѭ������Ч
//	if(root[x]^x) return FindRoot(root[x]);
//	return x; 
//} 
void Unite(int x,int y)
{
	int rootx,rooty;
	rootx = FindRoot(x); 
	rooty = FindRoot(y);
	if(rootx == rooty) return; //�Ѿ���ͨ
	if(Len[rootx] > Len[rooty]){
		root[rooty] = rootx; //С���������� 
	}else{
		if(Len[rootx] == Len[rooty]){
			Len[rooty] += 1; //��ͬ�Ļ��������������ߣ� 
		}
		root[rootx] = rooty;
	} 
	
}
int main()
{
	int a=0,b=0;
	while(~scanf("%d",&N) && N){ //һ�õ�ѭ����Ҫע���ظ�ʹ�õ����ݳ�ʼ�� 
		int ans = 0; 
		scanf("%d",&M);
		for(int i=1;i<=N;++i){
			Len[i] = 1;//ÿ�����ʼΪһ�ø�Ϊ1���� 
			root[i] = i;
		} 
		for(int i=0;i<M;++i){
			scanf("%d%d",&a,&b); // 
			Unite(a,b); //��ab��ͨ 
		}
		for(int i=1;i<=N;++i){
			if(root[i] == i)
				ans++; //�ҳ����ڵ������ 
		}
		printf("%d\n",ans-1); //ans����,ans-1���� 
	}
	return 0;
}
