/*문제
알리바바라는 도둑이 보석가게에서 보석을 훔치려고 한다.
알리바바는 n무게를 넣을 수 있는 크기의 가방을 메고 있다.
여러개 보석을 가방에 넣을 때 n무게보다 커지면 가방이 찢어져 쓸 수가 없다.
그리고 보석은 단단해서 적당한 크기로 쪼갤 수 없고 종류당 1개씩만 있다.
예를 들어 30kg을 가져갈 수 있는 가방과
보석 종류가 3가지가 있다고 가정하자.
A보석 5kg, 50억, B보석 10kg, 60억
C보석 20kg, 140억일 때 알리바바가 가져갈 수 있는 최대이익은
B와 C보석을 가져가 200억이 된다.
우리는 알리바바가 가장 큰 이익이 날때의 값을 출력하는 프로그램을 작성할 것이다.

첫 줄에는 도둑이 가져갈 수 있는 무게를,
다음 줄에는 보석의 개수,
다음 줄 부터는 각 보석의 무게와 값이 한 줄에 하나씩 입력된다.
가방의 크기는 10000 이하이고 , 보석의 개수는 100 개 이하
무게와 가격은 200 이하의 정수이다.

입력
30
3
5 50
10 60
20 140

출력
200

30
3
5 50
15 60
20 140

출력
190
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define R 100 // 보석 개수
#define C 10000 // 가방 크기

int bag[R + 1][C + 1];
int w[R + 1]; // 보석 무게, weight
int p[R + 1]; // 보석 가격, price

int main() {
	int thiefBag = 0; // 도둑 가방 크기
	int nJewels = 0; // 보석 개수
	int i, j;

	scanf("%d", &thiefBag); // 도둑의 가방 무게
	scanf("%d", &nJewels); // 보석의 개수
	
	for (i = 1; i <= nJewels; i++) {
		scanf("%d %d", &w[i], &p[i]);
	}

	for (i = 1; i <= nJewels; i++) // 보석 종류만큼 반복
		for (j = 1; j <= thiefBag; j++) // 도둑 가방 사이즈만큼 반복 즉, 모든경우의 수를 다 해보는 셈
			if ((j >= w[i]) && (bag[i - 1][j] <= bag[i - 1][j - w[i]] + p[i]))
				bag[i-1][j] = bag[i - 1][j - w[i]] + p[i]; // 조건을 만족할때는 bag[i][j]에 
			else
				bag[i][j] = bag[i - 1][j]; // 해당 조건 만족을 못할때는 b[i][j]에 0 을 넣어줌

	printf("%d\n", bag[nJewels][thiefBag]); // 최대 이익 출력
	return 0;
}
