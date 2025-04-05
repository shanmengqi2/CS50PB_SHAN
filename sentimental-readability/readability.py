
from cs50 import get_string

text = get_string("Text: ").lower()

countLetters = 0
countWords = 1
countSentences = 0
isBlank = False

for c in text:
    if c.isalpha():
        countLetters += 1
        isBlank = False
    elif (c.isspace() and (not isBlank)):
        countWords += 1
        isBlank = True
    elif (c == '.' or c == '!' or c == '?'):
        countSentences += 1
        isBlank = False


L = countLetters / countWords * 100
S = countSentences / countWords * 100
index = round(0.0588 * L - 0.296 * S - 15.8)
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
