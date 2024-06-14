Explanation

    ### WaveletTransform: 
    This function performs the Haar wavelet transform on the input vector data. 
    It repeatedly halves the size of the data being transformed until only one pair remains. 
    At each step, it computes the averages and differences of adjacent pairs of data points, 
    storing them in a temporary vector and then copying them back to the original vector.

    ### printVector: 
    This helper function prints the contents of a vector to the console, 
    which is useful for displaying the data before and after the transformation.

    ### main: 
    This is the entry point of the program. It defines a vector of 
    sample data (which should have a size that is a power of 2 for simplicity), prints the original data, 
    performs the Haar wavelet transform, and then prints the transformed data.
