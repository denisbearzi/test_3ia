Functions:

int main(): The main function of the program.

Responsible for the overall control flow of the game.
Displays a welcome message and game instructions.
Manages game rounds, allowing multiple rounds if the player desires.
Handles file operations to read words from parole.txt.
Implements the game logic, including word selection, guessing, feedback, and win/lose conditions.
Provides options for replay or termination based on player input.
Returns 0 to indicate successful program execution.
Execution Flow:

The program starts by displaying a welcome message and instructions for the Hangman game.
It opens the file parole.txt to read a list of words for the game.
The main loop allows the player to play multiple rounds if desired (while (num == 1)).
For each round:
It reads the list of words from parole.txt to determine the available words.
Chooses a random word from the list for the current round.
Initializes variables for the current round, including the hidden word, guessed letters, and remaining attempts.
Displays the hidden word with underscores representing unguessed letters.
Enters a loop where the player guesses letters until they either complete the word or run out of attempts.
Converts uppercase letters entered by the player to lowercase for case-insensitive matching.
Provides feedback on each guess, indicating whether the guessed letter is correct or incorrect.
Updates the guessed letters and remaining attempts accordingly.
Breaks out of the loop if the word is completed or all attempts are exhausted.
Displays a win or loss message based on the outcome of the round.
Asks the player if they want to play another round.
If the player chooses to continue, a new round starts with a different hidden word.
If the player decides to end the session, the program terminates with an appropriate message.
