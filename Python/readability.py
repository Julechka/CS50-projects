from cs50 import get_string

# Coleman-Liau constants
CLI1 = 5.88
CLI2 = 29.6
CLI3 = 15.8

# Prompting input text
text_input = get_string("Text: ")

word_count = len(text_input.split())
letters_count = sum(1 for char in text_input if char.isalpha())
sentences_count = sum(1 for char in text_input if char in ".!?")

# compute Coleman-Liau Index
index = round(CLI1 * letters_count / word_count - CLI2 * sentences_count / word_count - CLI3)

# print readability score
if index >= 16:
    print("Grade 16+")

elif index <= 1:
    print("Before Grade 1")

else:
    print(f"Grade {index}")
