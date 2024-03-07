import csv
from sys import argv


def main():

    # Check for command-line usage
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return


    # Read database file into a variable
    database = []
    with open(argv[1]) as file:
        database_file = csv.reader(file, delimiter = ",")
        for row in database_file:
            database.append(row)

    # Read DNA sequence file into a variable
    with open(argv[2]) as file:
        sequence = file.read()

    # Find longest match of each STR in DNA sequence
    STR_list = []
    for sub_sequence in database[0][1:]:
        longest_run = longest_match(sequence, sub_sequence)
        STR_list.append(str(longest_run))

    # Check database for matching profiles
    flag = False
    for i in range(len(database)):
        # If the same STR count present in the database then print the individual's name
        if STR_list == database[i][1:]:
            print(database[i][0])
            flag = True
            break
        else:
            flag = False

    # If not present in the database then print No match
    if flag == False:
        print("No match")




def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
