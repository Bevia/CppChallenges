import matplotlib.pyplot as plt

# Initialize lists to hold the data
inputs = []
outputs = []
errors = []

# Read the data from the file
with open("output.txt", "r") as file:
    for line in file:
        input_val, output_val, error_val = map(float, line.split())
        inputs.append(input_val)
        outputs.append(output_val)
        errors.append(error_val)

# Plot the results
plt.figure(figsize=(12, 6))

plt.subplot(3, 1, 1)
plt.plot(inputs, label="Input")
plt.title("Input Signal")
plt.legend()

plt.subplot(3, 1, 2)
plt.plot(outputs, label="Output")
plt.title("Output Signal")
plt.legend()

plt.subplot(3, 1, 3)
plt.plot(errors, label="Error")
plt.title("Error Signal")
plt.legend()

plt.tight_layout()
plt.show()
