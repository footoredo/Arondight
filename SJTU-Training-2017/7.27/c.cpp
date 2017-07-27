#include <bits/stdc++.h>
using namespace std;
struct point{
	double x,y,z;
} a[300];
int f[300][300],x,y,n,m,q;
double d[300][300];
char st[30];
double dis(point x,point y){
	return sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y) + (x.z - y.z) * (x.z - y.z));
}
void shuchu(int x,int y){
	if (f[x][y] != -1){
		shuchu(x,f[x][y]);
		printf("%d ",f[x][y]);
		shuchu(f[x][y],y);
	};
}
int main(){
	int ca=0;
	while (scanf("%d%d",&n,&m) == 2){
		ca++;
		if (ca!=1)	printf("\n");
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				f[i][j] = -1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				d[i][j] = 1e18;
		for (int i = 0; i < n; i++){
			scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z);
			a[i].x *= 5;
		}
//		printf("%lf\n",d[3][5]);
		for (int i = 1; i <= m; i++){
//			printf("%d %lf\n",i,d[3][5]);
			scanf("%d%d%s",&x,&y,st);
//			printf("%d %d %s\n",x,y,st);
			if (st[0] == 'w' || st[0] == 's'){
				d[x][y] = min(d[x][y],dis(a[x],a[y]));
				d[y][x] = min(d[y][x],dis(a[x],a[y]));
			}
			if (st[0] == 'l'){
				d[x][y] = min(d[x][y],1.0);
				d[y][x] = min(d[y][x],1.0);
			}
			if (st[0] == 'e'){
				d[x][y] = min(d[x][y],1.0);
				d[y][x] = min(d[y][x],3 * dis(a[x],a[y]));
			}
		}
//		printf("%lf\n",d[3][5]);
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++){
					if (d[i][j] > d[i][k] + d[k][j]){
						d[i][j] = d[i][k] + d[k][j];
						f[i][j] = k;
					}
				}
//		printf("%lf\n",d[3][5]);
//		printf("%lf\n",d[3][4]);
//		printf("%lf\n",d[4][5]);
		scanf("%d",&q);
		for (int i = 1; i <= q; i++){
			scanf("%d%d",&x,&y);
			printf("%d ",x);
			shuchu(x,y);
			printf("%d\n",y);
		}
	}
}
