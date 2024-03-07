import cs50

def main():
    # Get cents from the user
    cents = get_cents()

    # Calculate the number of quarters
    quarters = calculate_quarters(cents)
    cents -= quarters * 25

    # Calculater the number of dimes
    dimes = calculate_dimes(cents)
    cents -= dimes * 10

    # Calculater the number of nickels
    nickels = calculate_nickels(cents)
    cents -= nickels * 5

    # Calculate the number of pennies
    pennies = calculate_pennies(cents)
    cents -= pennies * 1

    # Sum all the coins to calculate total number of coins
    total_coins = quarters + dimes + nickels + pennies

    # Display the total coins
    print(total_coins)

def get_cents():
    # Get input in the form of dollars
    dollars = cs50.get_float("Change owed: ")

    # If dollars less than 0 than again ask for input
    while dollars < 0:
        dollars = cs50.get_float("Change owed: ")

    # Convert the dollars into cents and return
    return dollars * 100


def calculate_quarters(cents):
    ''' Calculate number of quarters'''
    quarters = 0
    while cents >= 25:
        quarters += 1
        cents -= 25

    return quarters


def calculate_dimes(cents):
    ''' Calculate number of dimes'''
    dimes = 0
    while cents >= 10:
        dimes += 1
        cents -= 10

    return dimes


def calculate_nickels(cents):
    ''' Calculate number of nickels'''
    nickels = 0
    while cents >= 5:
        nickels += 1
        cents -= 5

    return nickels


def calculate_pennies(cents):
    ''' Calculate number of pennies'''
    pennies = 0
    while cents >= 1:
        pennies += 1
        cents -= 1

    return pennies

main()
