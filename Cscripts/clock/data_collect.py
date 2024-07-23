import serial
import time
import csv
from tqdm import tqdm

# 設定串列埠參數
ser = serial.Serial('COM4', 115200, timeout=1)  
time.sleep(2) 

# 打開CSV文件以寫入
with open('timing_data.csv', mode='w', newline='') as file:
    writer = csv.writer(file)
    writer.writerow(['Measurement', 'Difference (us)']) 

    # 使用進度條顯示進度
    measurement_count = 0
    for _ in tqdm(range(1000)):
        try:
            line = ser.readline().decode('utf-8', errors='ignore').strip() 
            if line and line.replace('.', '', 1).isdigit():
                measurement_count += 1
                writer.writerow([measurement_count, line])
                #print(f'Measurement {measurement_count}: {line} us')
        except UnicodeDecodeError:
            print("Unicode decode error encountered.")
        except serial.SerialTimeoutException:
            print("Serial read timeout.")

ser.close()
print("Data collection complete. Saved to timing_data.csv")
