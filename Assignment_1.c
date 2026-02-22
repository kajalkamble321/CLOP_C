typedef struct player
{
    unsigned short index;
    unsigned char length;
} Player;

typedef struct team
{
    char *teamName;
    Player *players;
} Team;
