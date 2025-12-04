/*
2025-11-19
에러 검출 버전
에라토스테네스의 체 버전
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

#define MAX 100000000  // 저장할 수 있는 소수 개수의 최대값

long long get_micro_time(void);

int main(void)
{
    int n = 0;                 // 최댓값 2,147,483,647
    int *p = malloc(MAX * sizeof(int));   // 소수 저장용
    int idx = 0;               // 실제 저장한 소수 개수

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

    // 에라토스테네스의 체용 배열: 0 ~ n
    // 0 = 소수 후보, 1 = 합성수(소수 아님)
    unsigned char *is_composite = calloc(n + 1, sizeof(unsigned char));
    if (is_composite == NULL)
    {
        fprintf(stderr, "체 배열 메모리 할당 실패\n");
        free(p);
        exit(1);
    }

    long long start = get_micro_time();

    // --- 에라토스테네스의 체 시작 ---

    // 0과 1은 소수 아님
    is_composite[0] = 1;
    is_composite[1] = 1;

    // 2 ~ sqrt(n) 까지 기준 숫자로 사용
    for (int i = 2; (long long)i * i <= n; i++)
    {
        if (!is_composite[i])   // 아직 안 지워졌으면 -> 소수
        {
            // i*i부터 i의 배수들을 모두 합성수로 표시
            for (long long j = (long long)sqrt((double)i); j <= n; j += i)
            {
                is_composite[j] = 1;
            }
        }
    }

    // 체를 통과한 수들(= is_composite == 0)만 p 배열에 저장
    for (int i = 2; i <= n && idx < MAX; i++)
    {
        if (!is_composite[i])
        {
            p[idx++] = i;
        }
    }

    long long end = get_micro_time();

    // 시간 출력
    printf("걸린 시간: %lld microseconds\n", end - start);

    // 소수 출력
    printf("소수 목록 (%d개, 최대 %d개까지만 저장): ", idx, MAX);
    for (int i = 0; i < idx; i++)
        printf("%d ", p[i]);
    putchar('\n');

    free(is_composite);
    free(p);
    return 0;
}

long long get_micro_time(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)tv.tv_sec * 1000000LL + (long long)tv.tv_usec;
}
