import serial
import time
import csv
from tqdm import tqdm

# 設定串列埠參數
ser = serial.Serial('COM4', 115200, timeout=1)  
time.sleep(2)  # 等待串口穩定

# 打開CSV文件以寫入
with open(r'timing_data.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    writer.writerow(['Measurement', 'Real Time (us)', 'Elapsed Time (us)'])  # 寫入表頭

    # 使用進度條顯示進度
    measurement_count = 0
    for _ in tqdm(range(1000)):  # 進行1000次測量
        try:
            line = ser.readline().decode('utf-8', errors='ignore').strip()  # 讀取串口數據
            if line and "," in line:
                parts = line.split(",")
                if len(parts) == 2:
                    real_time = parts[0].strip()
                    elapsed_time = parts[1].strip()
                    if real_time.replace('.', '', 1).isdigit() and elapsed_time.isdigit():
                        measurement_count += 1
                        writer.writerow([measurement_count, real_time, elapsed_time])  # 寫入CSV文件
                        # print(f'Measurement {measurement_count}: Real Time {real_time} us, Elapsed Time {elapsed_time} us')
        except UnicodeDecodeError:
            print("Unicode decode error encountered.")
        except serial.SerialTimeoutException:
            print("Serial read timeout.")

ser.close()  # 關閉串口
print("Data collection complete. Saved to timing_data.csv")  # 提示數據收集完成
