import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# Read the CSV file
data = pd.read_csv('lms_results.csv')

# Extract the signals
input_signal = data['Input'].values
desired_signal = data['Desired'].values
output_signal = data['Output'].values

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
