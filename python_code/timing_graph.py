import pandas as pd
import matplotlib.pyplot as plt
import math

csv_path = "../benchmarks/timeing.cvs"
df = pd.read_csv(csv_path)

x = df["N"]
y1 = df["ver1_us"]
y2 = df["ver2_us"]
y3 = df["ver3_us"]

plt.figure(figsize=(9, 5))

plt.plot(x, y1, marker="o", label="ver1_us")
plt.plot(x, y2, marker="o", label="ver2_us")
plt.plot(x, y3, marker="o", label="ver3_us")

plt.xlabel("N")
plt.ylabel("Time (microseconds)")
plt.title("Prime number versions execution time")

plt.legend()
plt.grid(True)

# 🔥 여기부터 x축을 "10배씩" 이라는 느낌에 맞게 세팅

# 1) x축 로그 스케일 (10배씩 커지는 패턴을 직선으로 보이게)
plt.xscale("log", base=10)

# 2) 눈금 위치를 네가 측정한 N 값에 딱 맞게만
ticks = x
# tick 라벨을 10^2, 10^3 ... 이런 식으로 표시하고 싶다면:
tick_labels = [f"10^{int(math.log10(v))}" for v in ticks]
plt.xticks(ticks, tick_labels)

plt.yscale("log")  # y축도 값 차이가 크니까 계속 로그로 두는 걸 추천

plt.tight_layout()

plt.savefig("../benchmarks/prime_timing.png", dpi=200, bbox_inches="tight")
plt.show()
