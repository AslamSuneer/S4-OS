import numpy as np
import matplotlib.pyplot as plt

def plot_graph(x, y, label):
    plt.figure()
    plt.plot(x, y,'r-',label=label)
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title(label)
    plt.legend()
    plt.grid(True)
    plt.show()

print("Choose a function to plot:")
print("1. y = x")
print("2. y = x^2")
print("3. y = 2^x")
print("4. y = sin(x)")
print("5. y = cos(x)")
print("6. y = e^x")
print("7. Exit")


while True:

	choice = input("Enter your choice: ")

	if choice == '1':
		x = np.linspace(-10, 10, 400)
		y = x
		plot_graph(x, y, "y = x")
	elif choice == '2':
		x = np.linspace(-10, 10, 400)
		y = x**2
		plot_graph(x, y, "y = x^2")
	elif choice == '3':
		x = np.linspace(-2, 2, 400)
		y = 2**x
		plot_graph(x, y, "y = 2^x")
	elif choice == '4':
		x = np.linspace(-2*np.pi, 2*np.pi, 400)
		y = np.sin(x)
		plot_graph(x, y, "y = sin(x)")
	elif choice == '5':
		x = np.linspace(-2*np.pi, 2*np.pi, 400)
		y = np.cos(x)
		plot_graph(x, y, "y = cos(x)")
	elif choice == '6':
		x = np.linspace(-2, 2, 400)
		y = np.exp(x)
		plot_graph(x, y, "y = e^x")
	elif choice == '7':
		print("Exiting...")
		break
	else:
		print("Invalid choice. Please enter a number between 1 and 7.")
