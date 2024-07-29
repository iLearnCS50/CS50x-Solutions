#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

//the points for each alphabet(given){missed when solving}
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int compute_score(string player);

int main(void)
{
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");
    int score1 = compute_score(player1);
    int score2 = compute_score(player2);
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string player)
{
    int score = 0;
    int total = 0;
    for (int i = 0; i < strlen(player); i++)
    {
        //checks if the letter is upper-case
        if (isupper(player[i]))
        {
            score = points[player[i] - 'A'];
            total = total + score;
        }
        //checks if the letter is lower-case
        else if (islower(player[i]))
        {
            score = points[player[i] - 'a'];
            total = total + score;
        }
        //if none, it is ignored.
    }
    score = total;
    return score;
}