#include <stdio.h>

int main()
{
	int map[19][19];
	int n;

	//바둑알 상황입력받기
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	//몇번 뒤집기를 할것인지 입력받기
	scanf("%d", &n);
	for (int loop = 0; loop < n; loop++) {
		int x, y;
		scanf("%d %d", &x, &y);
		for (int i = 0; i < 19; i++) {
			if (map[x - 1][i] == 0) {
				map[x - 1][i] = 1;
			}
			else if (map[x - 1][i] == 1) {
				map[x - 1][i] = 0;
			}
		}
		for (int i = 0; i < 19; i++) {
			if (map[i][y - 1] == 0) {
				map[i][y - 1] = 1;
			}
			else if (map[i][y - 1] == 1) {
				map[i][y - 1] = 0;
			}
		}
	}

	//뒤집은 결과 출력하기
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
