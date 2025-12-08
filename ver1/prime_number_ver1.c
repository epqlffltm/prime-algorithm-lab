/*
2025-11-14
단순 반복으로 소수 찾기 (최적화 없음)
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAX 100000000

long long get_micro_time() 
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
  return (long long)tv.tv_sec * 1000000 + tv.tv_usec;
}

int main(void)
{
    int n = 0;//최댓갑 2,147,483,647
    int *p = malloc(MAX * sizeof(int));
    int idx = 0;


    printf("정수 입력: ");
    if (scanf("%d", &n) != 1) {
        puts("숫자만 입력하세요.");
        free(p);
        return 1;
    }

    if (n < 2) {
        puts("2 이상의 정수만 입력하세요.");
        free(p);
        return 1;
    }

    long long start = get_micro_time();

    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;

        // 1부터 i까지 전부 나눠보는 최악의 방법
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
                cnt++;
        }

        if (cnt == 2)   // 약수가 2개면 소수
        {
            if (idx < MAX)
                p[idx++] = i;
        }
    }

    long long end = get_micro_time();

    // 시간 출력
    printf("걸린 시간: %lld microseconds\n", end - start);

    // 소수 출력
    //printf("소수 목록: ");
    //for (int i = 0; i < idx; i++)
        //printf("%d ", p[i]);
    //putchar('\n');

    free(p);
    return 0;
}
