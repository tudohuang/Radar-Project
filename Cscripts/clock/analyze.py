import pandas as pd

# 讀取CSV文件
data = pd.read_csv(r'C:\Users\Tudo\Desktop\Radar-Project\Cscripts\clock\timing_data.csv')

print(data.head())

stats = data['Difference (us)'].describe()
print("\n統計資料:")
print(stats)

mean = data['Difference (us)'].mean()
std = data['Difference (us)'].std()
print(f"\n平均值: {mean} 微秒")
print(f"標準差: {std} 微秒")

import matplotlib.pyplot as plt

plt.hist(data['Difference (us)'], bins=20, edgecolor='black')
plt.title('Difference (us) Histogram')
plt.xlabel('Difference (us)')
plt.ylabel('Frequency')
plt.show()
