import math

def binomial_probability(trials, probability_of_success, successes):
  # Calculate the probability using the binomial probability formula
  probability = (math.factorial(trials) / (math.factorial(successes) * math.factorial(trials - successes))) * (probability_of_success**successes) * ((1 - probability_of_success) ** (trials - successes))
  return probability

def probability_at_least_one_success(trials, probability_of_success):

  # Probability of at least 1 success is 1 minus the probability of 0 successes
  probability_no_success = binomial_probability(trials, probability_of_success, 0)
  probability_at_least_one_success = 1 - probability_no_success
  return probability_at_least_one_success

# Example usage:
trials = 6  # Number of trials
probability_of_success = 0.25  # Probability of success in each trial

# Calculate probability of 4 successes
successes = 4
probability = binomial_probability(trials, probability_of_success, successes)
print("Probability of", successes, "successes in", trials, "trials:", probability)

# Calculate probability of at least 1 success
probability_at_least_one_success = probability_at_least_one_success(trials, probability_of_success)
print("Probability of at least 1 success in", trials, "trials:", probability_at_least_one_success)
