import matplotlib.pyplot as plt
import numpy as np

class DPTableVisualizer:
    def __init__(self, filename):
        self.filename = filename
        self.dp_table = self.read_dp_table()
    
    def read_dp_table(self):
        dp = []
        with open(self.filename, 'r') as file:
            for line in file:
                dp.append([int(x) for x in line.split()])
        return np.array(dp)
    
    def plot(self):
        fig, ax = plt.subplots()
        cax = ax.matshow(self.dp_table, cmap='coolwarm')
        for (i, j), val in np.ndenumerate(self.dp_table):
            ax.text(j, i, f'{val}', ha='center', va='center', color='black')

        plt.title('Minimum Cost Path DP Table')
        plt.colorbar(cax)
        plt.show()

# Example usage:
if __name__ == "__main__":
    visualizer = DPTableVisualizer('dp_table.txt')
    visualizer.plot()
