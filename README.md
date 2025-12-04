# Prime Algorithm Lab 

**Prime Algorithm Lab**은 고속 소수(Prime Number) 탐색 알고리즘을 연구하고 구현하는 C 프로젝트입니다.  
여러 가지 소수 판별 알고리즘(완전 탐색, sqrt 최적화, 에라토스테네스의 체)을 비교하면서, 대량의 소수를 효율적으로 판별하고 실행 속도를 마이크로초(µs) 단위로 측정하는 것을 목표로 합니다.

---

## 주요 기능 (Features)

- **고속 소수 판별**
  - 에라토스테네스의 체(Sieve of Eratosthenes)를 사용하여 `O(N log log N)` 시간 복잡도로 빠르게 소수를 찾습니다.
- **정밀한 성능 측정**
  - `gettimeofday`를 사용하여 알고리즘 수행 시간을 마이크로초 단위로 정밀하게 측정합니다.
- **동적 메모리 관리**
  - 소수 저장 배열 및 체(마스크) 배열을 `malloc`, `calloc`으로 동적 할당하여 입력값에 따라 메모리를 사용할 수 있습니다.
- **안정성**
  - 메모리 할당 실패, 잘못된 입력값(`scanf` 실패, 2 미만의 정수 입력) 등에 대한 예외 처리가 구현되어 있습니다.

---

## 🧱 폴더 구조 (Project Structure)

```text
.
├── ver1/                         # 최적화 거의 없는 기본 버전 (naive)
│   └── prime_number_ver1.c
├── ver2/                         # sqrt 최적화 + 에러 처리 버전
│   └── prime_number_nonerror.c
├── ver3/                         # 에라토스테네스의 체 버전
│   └── prime_number_sieve.c     # (예: 에라토스테네스 구현 파일)
├── test/                         # 실행 결과 / 로그 등 (필요시 사용)
└── .vscode/                      # VSCode 빌드/디버그 설정

## 📦 설치 및 실행 방법 (Installation & Usage)

이 프로젝트는 리눅스/유닉스 환경(macOS 포함)에서 실행하는 것을 권장합니다.

```gcc -o prime main.c -lm
