import math

def poisson_probability(lambda_param, k):
  # Calculate the probability using the Poisson probability formula
  probability = (math.exp(-lambda_param) * (lambda_param**k)) / math.factorial(k)
  return probability

# Example usage:
lambda_param = 3.4  # Rate parameter of the Poisson distribution
k = 6  # Number of occurrences we're interested in

# Calculate the probability
probability = poisson_probability(lambda_param, k)
print("Probability of", k, "occurrences:", probability)
