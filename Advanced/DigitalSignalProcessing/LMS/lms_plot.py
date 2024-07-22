import numpy as np
import matplotlib.pyplot as plt

def dot_product(a, b):
    return np.dot(a, b)

def lms_filter(input_signal, desired_signal, mu, filter_length):
    n = len(input_signal)
    weights = np.zeros(filter_length)
    buffer = np.zeros(filter_length)
    output_signal = np.zeros(n)
    
    for i in range(n):
        buffer[1:] = buffer[:-1]
        buffer[0] = input_signal[i]
        
        y = dot_product(weights, buffer)
        error = desired_signal[i] - y
        
        weights += 2 * mu * error * buffer
        
        output_signal[i] = y
    
    return output_signal

# Example input signal
input_signal = np.array([0.1, 0.2, 0.3, 0.4, 0.5, 0.4, 0.3, 0.2, 0.1, 0.0])
# Desired output signal (for demonstration purposes, let's assume it's a delayed version of the input)
desired_signal = np.array([0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.4, 0.3, 0.2, 0.1])

# LMS parameters
mu = 0.01  # Step size
filter_length = 3  # Length of the adaptive filter

# Apply LMS filter
output_signal = lms_filter(input_signal, desired_signal, mu, filter_length)

# Plotting the signals
plt.figure(figsize=(12, 6))
plt.plot(input_signal, label='Input Signal')
plt.plot(desired_signal, label='Desired Signal')
plt.plot(output_signal, label='Output Signal')
plt.title('LMS Filter Response')
plt.xlabel('Sample Index')
plt.ylabel('Amplitude')
plt.legend()
plt.grid(True)
plt.show()
