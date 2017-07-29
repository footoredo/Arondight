#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
struct rec{
	char op;
	int x,l,v;
} a[N];
map <string,int> M;
int fr[N],to[N],n;
char st[1000],va[1000];
bool cmp(const rec &a, const rec &b){
	if (a.l == b.l)
		if (a.v == b.v)
			if ((a.op == '=') == (b.op == '='))
				return a.x < b.x;
			else return (a.op == '=') < (b.op == '=');
		else return a.v < b.v;
	else return a.l < b.l;
}
int main(){
	for (scanf("%d",&n); n != 0; scanf("%d",&n)){
		int top = 0;
		M.clear();
		for (int i = 1; i <= n; i++){
			scanf("%s %s %c %d %s %s %d %s",st,va,&a[i].op,&a[i].x,st,st,&a[i].l,st);
			if (M[(string)va] == 0){
				M[(string)va] = ++top;
			}
			a[i].v = M[(string)va];
		}
		sort(a + 1,a + n + 1,cmp);
//		for (int i = 1; i <= n; i++)
//			printf("%d %c %d %d\n",a[i].v,a[i].op,a[i].x,a[i].l);
		fr[1] = 1;
		for (int i = 2; i <= n; i++){
			if (a[i].l == a[i - 1].l)
				fr[i] = fr[i - 1];
			else fr[i] = i;
		}
		for (int i = 1; i <= n; i++)
			to[fr[i]] = i;
		int ans = 0;
		for (int i = 1; i <= n; i++){
			bool pd = false;
			int mi,ma;
			for (int j = i; j <= to[i]; j++){
				if (a[j].v != a[j - 1].v || i == j){
					mi = - ((1u << 31) - 1);
					ma = ((1u << 31) - 1);
				}
				if (a[j].op == '>'){
					if (a[j].x < ma) ma = a[j].x;
				} else
				if (a[j].op == '<'){
					if (a[j].x > mi) mi = a[j].x;
				} else{
					if (a[j].x == ma) ma--;
					if (a[j].x == mi) mi++;
				}
				if (ma < mi) pd = true;
			}
			if (pd){
				int s = 0;
				int mins = to[i] - i + 1;
				int mi,ma;	
				for (int j = i; j <= to[i]; j++){
					if (a[j].v != a[j - 1].v || i == j){
						mi = - ((1u << 31) - 1);
						ma = ((1u << 31) - 1);
						s = 2;
					}
					if (a[j].op == '>'){
						if (a[j].x < ma) ma = a[j].x;
					} else
					if (a[j].op == '<'){
						if (a[j].x > mi) mi = a[j].x;
					} else{
						if (a[j].x == mi){
							mi++;
							s++;
						}
					}
					if (ma < mi){
						mins = min(s,mins);
//						printf("!! %d %d\n",j,s);
					}
				}
//				printf("! %d\n",ans);
//				printf("! %d\n",mins);
				ans += to[i] - i + 1 - mins;
//				printf("! %d\n",ans);
			} else{
				for (int j = i; j <= to[i]; j++){
					int s = 0;
					for (int k = i; k <= to[i]; k++)
						if(k != j && a[k].v == a[j].v){
							if (a[j].op == '='){
								if (a[k].op == '=')
									if (a[j].x == a[k].x)
										if (j < k)
											s = 1;
								if (a[k].op == '>')
									if (a[j].x > a[k].x)
										s = 1;
								if (a[k].op == '<')
									if (a[j].x < a[k].x)
										s = 1;
							} else 
							if (a[j].op == '>'){
								if (a[k].op == '>'){
									if (a[j].x > a[k].x)
										s = 1;
									if (a[j].x == a[k].x)
										if (j < k)
											s = 1;
								}
							} else
							if (a[j].op == '<'){
								if (a[k].op == '<'){
									if (a[j].x < a[k].x)
										s = 1;
									if (a[j].x == a[k].x)
										if (j < k)
											s = 1;
								}
							}
						}
					ans += s;
				}
			}
//			printf("%d\n",pd);
			i = to[i];
		}
		printf("%d\n",ans);
//		printf("\n");
	}
}
