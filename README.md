 Math Quiz Game Project Requirements


###  Game Flow Requirements:

1.  **Game Setup:** Ask the user to input the **total number of questions** (rounds) they want to answer in the current session.
2.  **Configuration:** Allow the user to select the following options for the quiz:
    * **Question Level:** Choose between Easy (1-10), Medium (1-50), Hard (1-100), or Mixed.
    * **Operation Type:** Choose between Addition, Subtraction, Multiplication, Division, or Mixed.
3.  **Round Start:** Start each round by displaying a math problem generated according to the selected configuration. The round requires a Player **Input** (the answer) versus a **Computer Generated Answer**.
4.  **Show Results (Round-by-Round):** Immediately after the player submits an answer, the results must be displayed.
    * **If Player Wins (Correct Answer):** The program must display "Right Answer :)" and set the console screen color to **Green**.
    * **If Computer Wins (Wrong Answer):** The program must display "Wrong Answer :(" and explicitly show **The right answer**. The screen color must be set to **Red**, and a **bell sound** must be rung.
5.  **Final Result :** After all specified rounds are completed, display a "Final Result Pass /Fail" message.
6.  **Print Game Results:** Print a detailed summary of the game, including:
    * The **Final Result** (Pass if right answers > wrong answers, Fail otherwise).
    * Total number of questions.
    * The chosen Question Level and Operation Type.
    * The count of Right Answers and Wrong Answers.
7.  **Replay:** After displaying all results, ask the user: "Do you want to play again? Y/N?". The game must loop and restart if 'Y' is chosen.
