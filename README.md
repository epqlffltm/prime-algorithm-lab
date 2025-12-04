# Prime Algorithm Lab 

**Prime Algorithm Lab**은 고속 소수(Prime Number) 탐색 알고리즘을 연구하고 구현하는 C 프로젝트입니다.
현재 **에라토스테네스의 체(Sieve of Eratosthenes)** 알고리즘을 기반으로, 대량의 소수를 효율적으로 판별하고 실행 속도를 마이크로초(µs) 단위로 측정합니다.

##  주요 기능 (Features)

* **고속 소수 판별:** 에라토스테네스의 체 알고리즘을 사용하여 $O(N \log \log N)$의 시간 복잡도로 빠르게 소수를 찾습니다.
* **정밀한 성능 측정:** `gettimeofday`를 사용하여 알고리즘 수행 시간을 마이크로초 단위로 정밀하게 측정합니다.
* **동적 메모리 관리:** 입력값에 따라 메모리를 동적으로 할당(`malloc`, `calloc`)하여 불필요한 메모리 낭비를 줄입니다.
* **안정성:** 메모리 할당 실패, 잘못된 입력값 등에 대한 예외 처리가 구현되어 있습니다.

## 🛠 기술 스택 (Tech Stack)

* **Language:** C (Standard C99 or later)
* **Compiler:** GCC / Clang
* **Libraries:** `<math.h>` (수학 연산), `<sys/time.h>` (시간 측정)

##  설치 및 실행 방법 (Installation & Usage)

```gcc -o prime main.c -lm
math.h 라이브러리를 링크하기위해 -lm 옵션이 필요할 수도 있습니다.
이 프로젝트는 리눅스/유닉스 환경(macOS 포함)에서 실행하는 것을 권장합니다.

### 1. 리포지토리 클론
```bash
git clone [https://github.com/epqlffltm/prime-algorithm-lab.git](https://github.com/epqlffltm/prime-algorithm-lab.git)
cd prime-algorithm-lab
