#include<cstdio>
#include<cstring>
int n;
int tem[1111][1111][2];
int soma[1111][1111][2];
int ent[1111];

inline int fix(int &a) {
  return a%=10007;
}

int go(const int a, const int b,const int c){
	if(a==0) {
    return c^ent[a];
  }
	if(tem[a][b][c]==-1) {
		int ret = 0;
		if((c^ent[a])==0)
			for(int i=1;i<b;i++){
				fix(ret += go(a-1,i,0));
			}
		if((c^ent[a])==1)
			for(int i=b;i<=a;i++){
				fix(ret += go(a-1,i,1));
			}
		tem[a][b][c]=ret;
	}
	return tem[a][b][c];
}
int main()
{
	while(scanf("%d",&n)==1){
		memset(tem,0,sizeof(tem));
		memset(soma,0,sizeof(soma));
		int x = 0;
		for(int i=0;i<n;i++){
			char c;
			scanf(" %c",&c);
			ent[i]=((c=='P')?1:0);
			x+=ent[i];
		}
		ent[n-1]^=1;
		ent[n++]=1;
		tem[0][0][1]=ent[0]^1;
		tem[0][0][0]=ent[0]^0;

		if(x%2==0) {
      printf("0\n");
      continue;
    }
    //	printf("%d %d\n",tem[0][0][0],tem[0][0][1]);
		for(int i=1;i<n;i++){
			soma[i-1][0][0]=tem[i-1][0][0];
			soma[i-1][i][1]=tem[i-1][i][1];
			for(int j=1;j<=i;j++){
				fix(soma[i-1][j][0]=soma[i-1][j-1][0]+tem[i-1][j][0]);
			}
			for(int j=i-1;j>=0;j--){
				fix(soma[i-1][j][1]=soma[i-1][j+1][1]+tem[i-1][j][1]);
			}
			for(int j=0;j<=i;j++){
				if (ent[i]==0) {
					fix(tem[i][j][0]+=soma[i-1][j-1][0]);
					fix(tem[i][j][1]+=soma[i-1][j][1]);

				} else if(ent[i]==1) {
					fix(tem[i][j][0]+=soma[i-1][j][1]);
					fix(tem[i][j][1]+=soma[i-1][j-1][0]);
				}
				//printf("(%d %d) %d %d\n",i,j,tem[i][j][0],tem[i][j][1]);
			}
		}
    for(int i=0; i<n; ++i) {
      for(int j=0; j<=i; ++j)
        printf(" %2d/%-2d", tem[i][j][0], tem[i][j][1]);
      printf("\n");
    }

		printf("%d\n",tem[n-1][0][0]);
	}
	return 0;
}
