import numpy as np
import matplotlib.pyplot as plt

def calculate_frequency(file_path):
    data = np.genfromtxt(file_path, delimiter=',', skip_header=1)

    t = data[:, 0]
    v = data[:, 1]

    step = round(t[-1] - t[0])
    size = data.shape[0]

    digits = size / step

    X = np.fft.fft(v)

    fs = np.arange(size) * digits / size

    index = np.argmax(np.abs(X[1:size//4]))
    freq = fs[index]

    plt.figure()
    plt.plot(fs[1:size//4], np.abs(X[1:size//4]))
    plt.title('Frequency vs Amplitude')
    plt.xlabel('Frequency (Hz)')
    plt.ylabel('Amplitude')
    plt.savefig('frequency_vs_amplitude.png')  
    plt.close()

    plt.figure()
    plt.plot(t, v)
    plt.title('Time vs Value')
    plt.xlabel('Time (s)')
    plt.ylabel('Value')
    plt.savefig('time_vs_value.png')  
    plt.close()
    
    return freq

