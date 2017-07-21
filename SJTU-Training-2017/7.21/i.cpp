#include <bits/stdc++.h>
using namespace std;
int n;
char a[20][20],b[20][20],ans[20][20],st[200];
int main(){
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
		scanf(" %s",a[i] + 1);
	scanf(" %s",st);
	int top = 0;
	bool pd = true;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n;j++)
			ans[i][j] = ' ';
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n;j++)
			if (a[i][j] == '.'){
				if (ans[i][j] != ' ')
					if (ans[i][j] != st[top]) pd = false;
					else;
				else ans[i][j] = st[top];
				top++;
			}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n;j++)
			b[j][n + 1 - i] = a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n;j++)
			a[i][j] = b[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n;j++)
			if (a[i][j] == '.'){
				if (ans[i][j] != ' ')
					if (ans[i][j] != st[top]) pd = false;
					else;
				else ans[i][j] = st[top];
				top++;
			}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n;j++)
			b[j][n + 1 - i] = a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n;j++)
			a[i][j] = b[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n;j++)
			if (a[i][j] == '.'){
				if (ans[i][j] != ' ')
					if (ans[i][j] != st[top]) pd = false;
					else;
				else ans[i][j] = st[top];
				top++;
			}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n;j++)
			b[j][n + 1 - i] = a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n;j++)
			a[i][j] = b[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n;j++)
			if (a[i][j] == '.'){
				if (ans[i][j] != ' ')
					if (ans[i][j] != st[top]) pd = false;
					else;
				else ans[i][j] = st[top];
				top++;
			}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (ans[i][j] == ' ')
				pd = false;
	if (pd) 
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				printf("%c",ans[i][j]);
	else
		printf("invalid grille");
	printf("\n");
}
