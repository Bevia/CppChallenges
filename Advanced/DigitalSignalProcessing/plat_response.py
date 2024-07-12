import numpy as np
import matplotlib.pyplot as plt

# Read impulse response
impulse_response = np.loadtxt('impulse_response.txt')

# Read frequency response
frequency_response = np.loadtxt('frequency_response.txt')

# Plot impulse response
plt.figure()
plt.stem(impulse_response, basefmt=" ", use_line_collection=True)
plt.title('Impulse Response of the FIR Filter')
plt.xlabel('Sample index')
plt.ylabel('Amplitude')
plt.grid()
plt.show()

# Plot frequency response
fs = 1000  # Sampling frequency
fft_size = 1024
f = np.linspace(0, fs / 2, fft_size // 2)

plt.figure()
plt.plot(f, frequency_response)
plt.title('Frequency Response of the FIR Filter')
plt.xlabel('Frequency (Hz)')
plt.ylabel('Magnitude (dB)')
plt.grid()
plt.show()
