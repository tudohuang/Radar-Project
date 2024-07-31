import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score

# 從CSV文件中讀取數據
data = pd.read_csv('timing_data.csv')

# 檢查數據是否正確讀取
print(data.head())

# 準備數據
# x 是測量編號，y_hat 是真值
x = data['Elapsed Time (us)'].values.reshape(-1, 1)  # 假設Measurement是設置的延遲時間
y_hat = data['Real Time (us)'].values.reshape(-1, 1)

# 建立線性回歸模型
model = LinearRegression()
model.fit(x, y_hat)

# 提取係數
beta_0 = model.intercept_[0]
beta_1 = model.coef_[0][0]

# 預測
y_hat_pred = model.predict(x)

# 評估模型
mse = mean_squared_error(y_hat, y_hat_pred)
r2 = r2_score(y_hat, y_hat_pred)

print(f'Mean Squared Error: {mse}')
print(f'R^2 Score: {r2}')
print(f'Regression Equation: y = {beta_0:.4f} + {beta_1:.4f}x')

# 繪製回歸線
plt.scatter(x, y_hat, color='blue', label='Real Time')
plt.plot(x, y_hat_pred, color='red', linewidth=2, label='Regression Line')
plt.xlabel('Measurement')
plt.ylabel('Real Time (us)')
plt.title('Linear Regression')
plt.legend()
plt.show()
