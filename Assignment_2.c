#include <stdio.h>
#include <stdlib.h>

//Line object
typedef struct {
    unsigned short index;
    unsigned char length;
} Line;

//Team object 
typedef struct {
    Line *lines;          
    unsigned char nlines; 
} Team;

//Cricket file object 
typedef struct {
    Team *teams;          
    unsigned char nteams;  
} CricketFile;

int main() {
    int i, j;

    CricketFile file;

    //Only teams that play the game
    file.nteams = 4;  
    file.teams = (Team *)malloc(file.nteams * sizeof(Team));

    //Construct teams and players
    for (i = 0; i < file.nteams; i++) {
        file.teams[i].nlines = 11;   // each team has 11 players
        file.teams[i].lines = (Line *)malloc(11 * sizeof(Line));

        for (j = 0; j < 11; j++) {
            file.teams[i].lines[j].index  = j + 1;
            file.teams[i].lines[j].length = (unsigned char)(j + 5);
        }
    }

    // Example: Print data
    for (i = 0; i < file.nteams; i++) {
        printf("Team %d:\n", i+1);
        for (j = 0; j < file.teams[i].nlines; j++) {
            printf(" Player %d, Length: %d\n", 
                   file.teams[i].lines[j].index, 
                   file.teams[i].lines[j].length);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < file.nteams; i++) {
        free(file.teams[i].lines);
    }
    free(file.teams);

    return 0;
}