#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int k = 0; k < candidate_count; k++)
    {
        if (candidates[k].eliminated == false)
        {
            if (strcmp(candidates[k].name, name) == 0)
            {
                preferences[voter][rank] = k;
                return true;
            }
        }
    }
    return false;
}
// 0 = true and 1 = false

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    int n = 0;
    for (int m = 0; m < voter_count; m++)
    {
        for (int o = 0; o < candidate_count; o++)
        {
            n = preferences[m][o];
            if (candidates[n].eliminated == false)
            {
                candidates[n].votes++;
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int vote_no = 0;
    for (int x = 0; x < candidate_count; x++)
    {
        if (candidates[x].votes > vote_no)
        {
            vote_no = candidates[x].votes;
        }
    }
    if (vote_no <= voter_count / 2)
    {
        return false;
    }
    else
    {
        for (int y = 0; y < candidate_count; y++)
        {
            if (vote_no == candidates[y].votes)
            {
                printf("%s\n", candidates[y].name);
            }
        }
        return true;
    }
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int vote_no = MAX_CANDIDATES;

    for (int min = 0; min < candidate_count; min++)
    {
        if (candidates[min].votes < vote_no && candidates[min].eliminated == false)
        {
            vote_no = candidates[min].votes;
        }
    }
    return vote_no;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int not_elimin = 0;
    for (int b = 0; b < candidate_count; b++)
    {
        if (candidates[b].eliminated == false)
        {
            not_elimin = not_elimin + 1;
        }
    }
    int min_elimin = 0;
    for (int c = 0; c < not_elimin; c++)
    {
        if (min == candidates[c].votes)
        {
            min_elimin = min_elimin + 1;
        }
    }
    if (min_elimin != not_elimin)
    {
        return false;
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    int lowest = 0;
    for (int d = 0; d < candidate_count; d++)
    {
        if (candidates[d].eliminated == false)
        {
            if (candidates[d].votes == min)
            {
                candidates[d].eliminated = true;
            }
        }
    }

    return;
}
