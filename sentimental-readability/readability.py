import cs50

def main():
    # Get text from the user
    text = cs50.get_string("Text: ")

    # Count number of letters in the text
    letters = count_letters(text)

    # Count number of words in the text
    words = count_words(text)

    # Count number of sentences in the text
    sentences = count_sentences(text)

    # Calculate the average number of letters per 100 words
    L = letters / words * 100

    # Calculate the average number of sentences per 100 words
    S = sentences / words * 100

    # Find the index value
    index = round(0.0588 * L - 0.296 * S - 15.8)

    # Display the readability level
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")

def count_letters(text):
    '''Count the number of letters in the text'''
    letters = 0
    for i in text:
        if i.isalpha():
            letters += 1
    return letters


def count_words(text):
    '''Count the number of words in the text'''
    words = 1
    for i in text:
        if i == " ":
            words += 1
    return words


def count_sentences(text):
    '''Count the number of sentences in the text'''
    sentences = 0
    for i in text:
        if i == "!" or i == "." or i == "?":
            sentences += 1
    return sentences

main()
