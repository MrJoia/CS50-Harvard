#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp((name), candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
    

}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Ordenação do arrray com o método Bubblesort em ordem decrescente
    for (int contador = 1; contador < candidate_count; contador++)
    {
        for (int i = 0; i < candidate_count; i++)
        {
            if (candidates[i].votes < candidates[i + 1].votes)
            {
                // Ordenando a variável "name" do array de candidatos
                string name_aux = candidates[i].name;
                candidates[i].name = candidates[i + 1].name;
                candidates[i + 1].name = name_aux;
                                // Ordenando a variável "votes" do array de candidatos
                int votes_aux = candidates[i].votes;
                candidates[i].votes = candidates[i + 1].votes;
                candidates[i + 1].votes = votes_aux;
            }
        }
    }
    // Verifica se o maior número de votos não se repete entre candidatos
    int maior = candidates[0].votes;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i + 1].votes == maior)
        {
            printf("%s\n", candidates[i + 1].name);
        }
    }
    printf("%s\n", candidates[0].name);
    return;
}
