#include<stdio.h>
#include<string.h>
const int maxn=924;

int E[maxn*2],R[maxn*2],L[maxn*2],d[maxn*2][15];
int tot,visit[maxn];
int len[maxn],g[maxn][maxn],N,m,M,hash[maxn],in[maxn];

void Dfs(int d,int dep)
{
	int i;
	visit[d]=1;
	R[d]=tot;
	E[tot]=d;
	L[tot++]=dep;
	for(i=0;i<len[d];i++) if(!visit[g[d][i]])
	{
		Dfs(g[d][i],dep+1);
		L[tot]=dep;
		E[tot++]=d;
	}
}

void BuildRmq(int root)
{
	int i,j,k;
	tot=0;
	memset(visit,0,sizeof(visit));
	Dfs(root,0);
	for(j=0;(1<<j)<=tot;j++)
		for(i=0;i+(1<<j)<=tot;i++)
		{
			if(j==0) d[i][j]=i;
			else
			{
				if(L[d[i][j-1]]<L[d[i+(1<<(j-1))][j-1]]) d[i][j]=d[i][j-1];
				else d[i][j]=d[i+(1<<(j-1))][j-1];
			}
		}
}

int Rmq(int i,int j)
{
	int k=0;
	while((1<<(k+1))<(j-i+1)) k++;
	if(L[d[i][k]]<L[d[j-(1<<k)+1][k]]) return d[i][k];
	else return d[j-(1<<k)+1][k];
}

int Lca(int u,int v)
{
	if(R[u]<R[v]) return E[Rmq(R[u],R[v])];
	else return E[Rmq(R[v],R[u])];
}

int main()
{
	int i,j,k,l,a,u,v;
//	char ch,s[10];
	while(scanf("%d",&N)!=EOF)
	{
		memset(len,0,sizeof(len));
		memset(in,0,sizeof(in));
		memset(hash,0,sizeof(hash));
		
        for(l=0;l<N;l++)
		{
			scanf("%d",&k); k--;
		    scanf(" : ( %d )",&m);
		    for(i=0;i<m;i++)
			{
				scanf("%d",&a);
			    g[k][len[k]++]=a-1;
				g[a-1][len[a-1]++]=k;
			    in[a-1]++;
			}
		}
		for(i=0;i<N;i++) if(in[i]==0) break;
		BuildRmq(i);
		scanf("%d",&M);
		for(i=0;i<M;i++)
		{
			scanf(" ( %d%d ) ",&u,&v);
			hash[Lca(u-1,v-1)]++;
		}
		for(i=0;i<N;i++) if(hash[i]) printf("%d:%d\n",i+1,hash[i]);
	}
	return 1;
}