import random
import requests
from rich import print as rprint

# [CR] MOVE COMMENTS <3

# [CR] there is no need for this
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Define the URL for the wordlist website and the file for the wordlist file
wordlist_url = "https://www.mit.edu/~ecprice/wordlist.10000"
wordlist_file = "wordlist.txt"

# Function to fetch words from the website and store them in a file
def fetch_words_from_website(url, file):
    try:
        response = requests.get(url)
        if response.status_code == 200:
            with open(file, 'w') as file:
                file.write(response.text)
        else:
            rprint("[bold red]Failed to fetch words from the website.[/bold red]")
    except requests.exceptions.RequestException as e:
        rprint("[bold red]An error occurred:[/bold red] " + str(e))
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# Read words from a file and store them in a list
def get_words_from_file(file):
    try:
        with open(file, 'r') as file:
            words = file.read().split('\n')
            return [word.strip() for word in words if is_valid_word(word.strip())]
    except Exception as e:
        rprint("[bold red]An error occurred:[/bold red] " + str(e))
        return []

# Checks if a word is valid (5 letters and all in English)
def is_valid_word(word):
    return len(word) == 5 and word.isalpha() and word.islower()

# Checks the correctness of the guessed word
def check_word(guess):
    result = []  # Set a default empty list
    
    if guess == target_word:
        result.append("[bold green]Congrats! You found the word.[/bold green]")
    else:
        correct_letters = [guess[i] for i in range(5) if guess[i] == target_word[i]]
        partially_correct_letters = []

        for i in range(5):
            if guess[i] in target_word and guess[i] != target_word[i]:
                partially_correct_letters.append(guess[i])

        if correct_letters:
            result.append(f"[bold green]Correct letters in the right place:[/bold green] {' '.join(correct_letters)}")
        if partially_correct_letters:
            result.append(f"[bold yellow]Correct letters in the wrong place:[/bold yellow] {' '.join(partially_correct_letters)}")

    if not result:
        result.append("[bold red]None of the letters are correct.[/bold red]")

    return result

# Fetch words from the website and store them in a file
fetch_words_from_website(wordlist_url, wordlist_file)

# Fetch words from the file and store them in a list
wordlist = get_words_from_file(wordlist_file)

if not wordlist:
    rprint("[bold red]No valid words were fetched from the file.[/bold red]")
    exit()

# Choose a random word from the fetched list
target_word = random.choice(wordlist)

# Main game loop
attempts = 0
max_attempts = 6

while attempts < max_attempts:
    guess = input(f"Enter a 5-letter word (Attempt {attempts + 1}): ").lower()

    if is_valid_word(guess):
        result = check_word(guess)
        for msg in result:
            rprint(msg)
        if "[bold green]Congrats! You found the word.[/bold green]" in result:
            break
    else:
        rprint("[bold red]Invalid input. Please enter a valid 5-letter English word.[/bold red]")
    
    attempts += 1

if attempts == max_attempts:
    rprint(f"[bold red]Out of attempts. The correct word was '{target_word}'.[/bold red]")
