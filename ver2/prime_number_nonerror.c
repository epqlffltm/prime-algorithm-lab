/*
2025-11-19
에러 검출 버전
검색 반으로 줄인 버전 (math.h sqrt 사용)
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

#define MAX 100000000

long long get_micro_time(void);

int main(void)
{
    int n = 0;                 // 최댓값 2,147,483,647
    int *p = malloc(MAX * sizeof(int));
    int idx = 0;

    if (p == NULL)
    {
        fprintf(stderr, "메모리 할당 실패\n");
        exit(1);
    }

    printf("정수 입력: ");
    if (scanf("%d", &n) != 1)
    {
        fprintf(stderr, "숫자만 입력하세요.\n");
        free(p);
        exit(1);
    }

    if (n < 2)
    {
        fprintf(stderr, "2 이상의 정수만 입력하세요.\n");
        free(p);
        exit(1);
    }

    long long start = get_micro_time();

    // --- 소수 계산 시작 ---

    // 2는 예외 처리
    if (n >= 2 && idx < MAX)
        p[idx++] = 2;

    // 홀수들만 검사 (3, 5, 7, ...)
    for (int i = 3; i <= n && idx < MAX; i += 2)
    {
        int is_prime = 1;

        // sqrt(i)까지 홀수만 나눠봄
        int limit = (int)sqrt((double)i);
        for (int j = 3; j <= limit; j += 2)
        {
            if (i % j == 0)
            {
                is_prime = 0;
                break;
            }
        }

        if (is_prime)
            p[idx++] = i;
    }

    long long end = get_micro_time();

    // 시간 출력
    printf("걸린 시간: %lld microseconds\n", end - start);

    // 소수 출력
    //printf("소수 목록 (%d개, 최대 %d개까지만 저장): ", idx, MAX);
    //for (int i = 0; i < idx; i++)
        //printf("%d ", p[i]);
    //putchar('\n');

    free(p);
    return 0;
}

long long get_micro_time(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)tv.tv_sec * 1000000LL + (long long)tv.tv_usec;
}
