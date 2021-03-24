#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;

	// [n + 2][m + 2] 크기로 선언
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	sort(puddles.begin(), puddles.end());

	// 갈 수 없는 테두리 영역은 -1 로 두르자. 미리 dp에 체크
	for (int i = 0; i < n + 1; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < m + 1; j++)
				dp[i][j] = -1;
		}
		else
			dp[i][0] = -1;
	}

	// 물 웅덩이 있는 곳은 -1 으로 미리 dp에 체크 
	for (int i = 0; i < puddles.size(); i++)
        dp[puddles[i][1]][puddles[i][0]] = -1;
		

	// dp 채워나가기 
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (dp[i][j] == -1)
				continue;

			// 1 행 1 열(집)까지의 경로 값은 1 로 한다. (0 으로 하면 아래 과정상 계속 0 으로만 업데이트 된다.)
			else if (i == 1 && j == 1)
				dp[i][j] = 1;

			// 현재 좌표 기준 왼쪽, 위쪽 모두에서 올 수 없는 경우 👉 바로 위,왼쪽 모두에 물 웅덩이가 있거나(-1), 바로 위, 왼쪽 좌표까지 올수 있는 경로가 모두 0 이거나(0) 
			else if (dp[i - 1][j] <= 0 && dp[i][j - 1] <= 0)
				dp[i][j] = 0;

			// 현재 좌표 기준 위쪽에서만 올 수 없는 경우 👉 1행이거나, 바로 위에 물 웅덩이가 있거나(-1), 바로 위 좌표까지 올수 있는 경로가 0 이거나(0) 
			else if (dp[i - 1][j] <= 0)
				dp[i][j] = dp[i][j - 1];

			// 현재 좌표 기준 왼쪽에서만 올 수 없는 경우 👉 1열이거나, 바로 왼쪽에 물 웅덩이가 있거나(-1), 바로 왼쪽 좌표까지 올수 있는 경로가 0 이거나(0) 
			else if (dp[i][j - 1] <= 0)
				dp[i][j] = dp[i - 1][j];

			// 현재 좌표 기준 왼쪽, 위쪽 이렇게 2가지 경우 모두에서 올 수 있는 경우 
			else
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
		}
	}

	answer = dp[n][m];
	return answer;
}