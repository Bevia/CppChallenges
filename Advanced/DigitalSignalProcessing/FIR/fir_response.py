import numpy as np
import matplotlib.pyplot as plt

# Read impulse response
impulse_response = np.loadtxt('impulse_response.txt')

# Read frequency response
frequency_response = np.loadtxt('frequency_response.txt')

# Parameters for plotting
fs = 1000  # Sampling frequency
N = len(impulse_response)
fft_size = len(frequency_response)  # Assuming this is correct

# Time axis for impulse response
time = np.arange(N) / fs

# Frequency axis for frequency response
f = np.linspace(0, fs / 2, fft_size)

# Plot impulse response
plt.figure(figsize=(10, 6))
plt.subplot(2, 1, 1)
plt.stem(time, impulse_response)
plt.title('Impulse Response of the FIR Filter')
plt.xlabel('Time (seconds)')
plt.ylabel('Amplitude')
plt.grid()

# Plot frequency response
plt.subplot(2, 1, 2)
plt.plot(f, frequency_response)
plt.title('Frequency Response of the FIR Filter')
plt.xlabel('Frequency (Hz)')
plt.ylabel('Magnitude (dB)')
plt.grid()

plt.tight_layout()
plt.show()
