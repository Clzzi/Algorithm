#include<stdio.h>
int main() {
	int n = 0;
	int i = 0;
	int j =0;
	scanf("%d",&n);
	for(i = 0; i<n;i++) {
		for(j = 0;j<i;j++)
		{
			printf(" ");
		}
		printf("**\n");
	}
}
