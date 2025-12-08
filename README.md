# Prime Algorithm Lab

**Prime Algorithm Lab**은 고속 소수(Prime Number) 탐색 알고리즘을 연구하고 구현하는 C 기반 실험 프로젝트입니다.  
세 가지 소수 판별 알고리즘(나이브, `sqrt(n)` 최적화, 에라토스테네스의 체)을 구현하고,  
입력 범위를 점점 키워가며 **실행 속도를 마이크로초(µs) 단위로 측정 및 비교**하는 것을 목표로 합니다.

---

## ✨ 주요 목표

- 서로 다른 소수 판별 알고리즘을 단계적으로 구현
- 입력 `N` 을 10배씩 증가시키며 각 버전의 성능(실행 시간) 비교
- `gettimeofday` 등을 이용해 **마이크로초(µs)** 단위의 정밀한 시간 측정
- C 언어 / WSL(리눅스) 환경에서의 시스템 프로그래밍 연습  
  (시간 측정, 동적 메모리, 예외 처리 등)

---

## 🧩 구현 버전 개요

### 🔹 ver1 — 나이브(naive) 버전

- 디렉터리: `ver1/`
- 특징:
  - 1부터 `n`까지의 모든 수에 대해, 약수를 전부(or 거의 전부) 확인하는 **가장 단순한 방식**
  - 큰 입력값에 대해 가장 느리지만, 나머지 버전과 비교할 **기준선(baseline)** 역할

---

### 🔹 ver2 — `sqrt(n)` 최적화 버전

- 디렉터리: `ver2/`
- 특징:
  - 어떤 수 `x`가 소수인지 판별할 때,  
    **2부터 `sqrt(x)`까지만** 나누어 보는 방식으로 최적화
  - 이론적으로 약 `O(N √N)` 정도로 줄어, ver1보다 훨씬 빠름
  - `math.h` 의 `sqrt()` 를 사용 → 컴파일 시 **`-lm` 링크 필요**
  - 입력 검증 및 에러 처리(잘못된 입력값, `scanf` 실패 등)를 포함할 수 있음

---

### 🔹 ver3 — 에라토스테네스의 체(Sieve of Eratosthenes) 버전

- 디렉터리: `ver3/`
- 특징:
  - **에라토스테네스의 체** 알고리즘을 사용하여  
    1부터 `N`까지의 소수를 한 번에 구하는 방식
  - 시간 복잡도: `O(N log log N)` 수준
  - `malloc`/`calloc` 등을 사용한 동적 메모리 할당으로, 입력 `N` 에 따라 유동적으로 메모리 사용
  - 큰 `N` 에서 특히 좋은 성능을 보이는 고속 버전

---

## 🧱 프로젝트 구조 (Project Structure)

```text
prime_number/
├── benchmarks/                 # 벤치마크 결과 & 그래프
│   ├── prime_timing.png        # 실행 시간 그래프 (N vs time)
│   ├── timeing.cvs             # 각 버전별 측정 데이터 (CSV, us 단위)
│   ├── ver1.txt                # ver1 실행 로그/결과
│   ├── ver2.txt                # ver2 실행 로그/결과
│   └── ver3.txt                # ver3 실행 로그/결과
├── bin/                        # 빌드된 실행 파일 (git에서 제외)
│   ├── ver1
│   ├── ver2
│   └── ver3
├── python_code/                # 벤치마크 시각화 파이썬 코드
│   ├── timing_graph.py         # timeing.cvs → prime_timing.png 생성 스크립트
│   └── venv/                   # 파이썬 가상환경 (git에서 제외)
├── screenshots/                # 입력값별 실행 결과 캡처
│   ├── input_100.png
│   ├── input_1000.png
│   ├── input_10000.png
│   ├── input_1000000.png
│   ├── input_10000000.png
│   └── input_1000000000.png
├── ver1/                       # 나이브 버전 소스
├── ver2/                       # sqrt 최적화 버전 소스
└── ver3/                       # 에라토스테네스의 체 버전 소스
```

bin/, python_code/venv/, *.o, core 등 빌드 결과물 및 가상환경은
.gitignore 로 관리하고 있음.

---

빌드 & 실행 방법 (Build & Run)

WSL/리눅스 환경 기준 예시입니다.
프로젝트 루트 디렉터리(prime_number/)에서 다음 명령을 실행합니다.

# 빌드 (ver1 디렉터리의 C 파일들을 모두 컴파일)
```
gcc ver1/*.c -o bin/ver1
```
# 실행
```
./bin/ver1
```

ver2 — sqrt 최적화 버전 (math.h / sqrt 사용 → -lm 필요)
# 빌드
```
gcc ver2/*.c -o bin/ver2 -lm
```
# 실행
```
./bin/ver2
```

ver3 — 에라토스테네스의 체 버전
# 빌드
```
gcc ver3/*.c -o bin/ver3
```
# 실행
```
./bin/ver3
```

각 디렉터리(ver1, ver2, ver3)에 C 파일이 하나씩만 있다는 전제에서
verX/*.c 형태로 빌드하고 있습니다.
파일 이름이 바뀌더라도 디렉터리 안에 하나만 있다면 그대로 동작합니다.

---

벤치마크 (Benchmarks)
입력 크기

각 버전은 다음과 같은 입력 N 에 대해 실행 시간을 측정했습니다.

N = 100

N = 1,000

N = 10,000

N = 100,000

N = 1,000,000

N = 10,000,000

N = 100,000,000

각 N에 대해:

1부터 N까지 소수 판별 / 개수 계산 수행

gettimeofday 등을 사용해 마이크로초(µs) 단위로 실행 시간 측정

결과는 benchmarks/timeing.cvs 에 저장

CSV 예시는 다음과 같습니다.

```
N,ver1_us,ver2_us,ver3_us
100,31,3,2
1000,761,13,7
10000,74503,135,91
100000,7015384,2575,547
1000000,723676494,56780,6080
10000000,,1318428,66482
100000000,,35512093,1259140
```

ver1_us : 나이브 버전

ver2_us : sqrt 최적화 버전

ver3_us : 에라토스테네스의 체 버전

일부 ver1_us 값이 비어 있는 구간은, 너무 느려서 측정을 생략했거나
아직 측정하지 않은 상태를 의미할 수 있습니다.

---

실행 시간 그래프

benchmarks/timeing.cvs 를 기반으로, python_code/timing_graph.py로
각 버전의 실행 시간을 시각화했습니다.

![Prime timing graph](benchmarks/prime_timing.png)


---

실행 예시 스크린샷

각 입력 크기별 실행 결과를 screenshots/ 디렉터리에 캡처해 두었습니다.

screenshots/input_100.png

screenshots/input_1000.png

screenshots/input_10000.png

screenshots/input_1000000.png

screenshots/input_10000000.png

screenshots/input_1000000000.png (추가 실험 시)

보고서/발표 및 비교용 자료로 사용할 수 있습니다.

---

개발 환경 메모

C 컴파일러: gcc (WSL/리눅스 환경 기준)

파이썬: Python 3.12+

---

#향후 계획 (TODO)

c++의 멀티스레드 기능을 사용한 ver4 코딩

밀러-라빈 판정법을 사용한 ver5코딩과 이를 활용한 RSA 암호화 학습(실사용 용도 아님!)

Makefile 도입으로 make ver1, make ver2, make ver3, make bench 등 자동화
