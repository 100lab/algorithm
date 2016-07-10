#include <stdio.h>






int main()
{

	int T;
	scanf("%d", &T);
	while (T--)
	{
		int N;
		int history[501] = { 0, };
		int data[501] = { 0, };
		scanf("%d", &N);

		int max_max_history = 0;
		for (int i = 0; i < N; i++)
		{
			int val;
			scanf("%d", &val);
			data[i] = val;

			int max_history = 0;
			for (int j = i-1; j >= 0; j--)
			{
				if (data[j] < val && history[j] >= max_history)
				{
					max_history = history[j];
				}
			}
			max_history++;
			history[i] = max_history;
			if (max_history > max_max_history)
				max_max_history = max_history;
		}

		
		printf("%d\n", max_max_history);

	}


	return 0;
}