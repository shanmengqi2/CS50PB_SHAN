import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("arguments error!")

    # TODO: Read database file into a variable
    rows = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            rows.append(row)
        # print(rows)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], 'r', encoding='utf-8') as file2:
        content = file2.read().strip()
    # print(content)

    # TODO: Find longest match of each STR in DNA sequence
    AGATC = str(longest_match(content, "AGATC"))
    AATG = str(longest_match(content, "AATG"))
    TATC = str(longest_match(content, "TATC"))
    TTTTTTCT = str(longest_match(content, "TTTTTTCT"))
    GATA = str(longest_match(content, "GATA"))
    GAAA = str(longest_match(content, "GAAA"))
    TCTAG = str(longest_match(content, "TCTAG"))
    TCTG = str(longest_match(content, "TCTG"))

    # print(AGATC,AATG,TATC,TTTTTTCT)

    # TODO: Check database for matching profiles
    for row in rows:
        if "TTTTTTCT" not in reader.fieldnames:
            # print("simple")
            if row['AGATC'] == AGATC and row['AATG'] == AATG and row['TATC'] == TATC:
                print(row['name'])
                return
        else:
            if row['AGATC'] == AGATC and row['AATG'] == AATG and row['TATC'] == TATC and row['TTTTTTCT'] == TTTTTTCT and row['GATA'] == GATA and row['GAAA'] == GAAA and row['TCTAG'] == TCTAG and row['TCTG'] == TCTG:
                print(row['name'])
                return
    print("No match")

    return


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
