#include <stdio.h>

#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b
#define NA -999999999


int cache[51][51];

int dp(int* data, int left, int right)
{
	if (left == right)
		return data[left];
	else if (right - left == 1)
	{
		int more = max(data[left], data[right]);
		int less = min(data[left], data[right]);
		return more - less;
	}

	if (cache[left][right] != NA)
		return cache[left][right];

	int val = max(data[left] - dp(data, left + 1, right), data[right] - dp(data, left, right - 1));

	if (right - left >= 1)
	{
		val = max(-dp(data, left + 2, right), val);
		val = max(val, -dp(data, left, right - 2));
	}

	cache[left][right] = val;
	return val;
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