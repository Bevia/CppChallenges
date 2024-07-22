import pandas as pd

# Creating a DataFrame
data = {
    'Name': ['Alice', 'Bob', 'Charlie', 'David'],
    'Age': [24, 27, 22, 32],
    'City': ['New York', 'Los Angeles', 'Chicago', 'Houston']
}
df = pd.DataFrame(data)

# Display the DataFrame
print("DataFrame:")
print(df)

# Selecting a column
print("\nSelecting the 'Name' column:")
print(df['Name'])

# Filtering rows based on a condition
print("\nRows where Age is greater than 25:")
print(df[df['Age'] > 25])

# Adding a new column
df['Salary'] = [50000, 60000, 45000, 70000]
print("\nDataFrame after adding a new column 'Salary':")
print(df)

# Reading from and writing to a CSV file
df.to_csv('people.csv', index=False)
df_from_csv = pd.read_csv('people.csv')
print("\nDataFrame read from 'people.csv':")
print(df_from_csv)
