#include <stdio.h>

#define max(a, b) a>b?a:b
#define NA -999999999


int cache[51][51];

int dp(int* data, int left, int right)
{
	if (left > right)
		return 0;

	if (cache[left][right] != NA)
		return cache[left][right];

	cache[left][right] = max(data[left] - dp(data, left + 1, right), data[right] - dp(data, left, right - 1));

	if (right - left >= 1)
	{
		cache[left][right] = max(-dp(data, left + 2, right), cache[left][right]);
		cache[left][right] = max(cache[left][right], -dp(data, left, right - 2));
	}
	return cache[left][right];
}




int main()
{

	int T;
	scanf("%d", &T);

	while (T--)
	{
		int data[51] = { 0, };
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &data[i]);
		}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cache[i][j] = NA;

		int ret = dp(data, 0, N - 1);
		printf("%d\n", ret);

	}
	

	
	return 0;
}