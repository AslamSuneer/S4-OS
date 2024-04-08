import matplotlib.pyplot as plt

# Continent names and their corresponding areas (in millions of square miles)
continents = ["Africa", "Asia", "Europe", "North America", "Oceania", "South America", "Soviet Union"]
areas = [11.7, 10.4, 1.9, 9.4, 3.3, 6.9, 7.9]

# Create a bar chart
plt.figure(figsize=(10, 6))  # Adjust figure size for better visualization
plt.bar(continents, areas, color=['green', 'blue', 'orange', 'red', 'purple', 'yellow', 'gray'])
plt.xlabel("Continents")
plt.ylabel("Area (Million Square Miles)")
plt.title("Areas of Continents (Million Square Miles)")

# Add data labels above bars (optional)
for i, v in enumerate(areas):
    plt.text(i, v + 0.1, f"{v:.1f}", ha='center', va='bottom')  # Adjust offset for data labels

# Rotate x-axis labels for better readability (optional)
plt.xticks(rotation=45)

# Show the plot
plt.grid(axis='y', linestyle='--', alpha=0.7)  # Add grid lines for better readability
plt.tight_layout()  # Adjust spacing between elements
plt.show()
