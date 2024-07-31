import serial
import time
import matplotlib.pyplot as plt

# Wait for the Arduino to initialize
time.sleep(2)

# Initialize the serial connection
try:
    ser = serial.Serial('COM4', 9600)  # Replace 'COM4' with the appropriate serial port
except serial.SerialException as e:
    print(f"Error opening serial port: {e}")
    exit()

# Create empty lists to store the data
x_data = []
y_data = []
time_counter = 0

# Create a figure and axis for the plot
fig, ax = plt.subplots()

# Create an empty line object for the plot
line, = ax.plot([], [], lw=2)

# Set the plot limits
ax.set_xlim(0, 100)  # Adjust the limits as needed
ax.set_ylim(0, 1024)  # Adjust the limits as needed

# Function to update the plot
def update_plot(x, y):
    x_data.append(x)
    y_data.append(y)
    
    # Limit the list size
    if len(x_data) > 100:
        x_data.pop(0)
        y_data.pop(0)
    
    line.set_data(x_data, y_data)
    ax.relim()
    ax.autoscale_view()
    plt.draw()
    plt.pause(0.001)

# Start an infinite loop to continuously update the plot
try:
    while True:
        # Read a line of data from the serial port
        data = ser.readline().decode('latin-1').strip()  # Specify the appropriate encoding

        # Check if the data contains a comma
        if ',' in data:
            try:
                x, y = map(int, data.split(','))
                update_plot(x, y)
            except ValueError:
                print(f"Received malformed data: {data}")
        else:
            try:
                y = int(data)
                time_counter += 1  # Increment the time counter
                update_plot(time_counter, y)
            except ValueError:
                print(f"Received malformed data: {data}")
except KeyboardInterrupt:
    print("Plotting stopped by user.")
finally:
    # Close the serial connection
    ser.close()
