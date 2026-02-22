// Name: Kajal Kamble

#include <stdio.h>
#include <string.h>

// Player object
typedef struct {
    char name[50];
    int runs;
    int balls;
} Player;

int main() {

    FILE *fp;
    char line[300];
    char search[50];
    Player p = {"",0,0};

    printf("Enter player name: ");
    scanf(" %[^\n]", search);

    fp = fopen("64891.yaml","r");
    if(fp==NULL){
        printf("File not found\n");
        return 1;
    }

    while(fgets(line,300,fp)) {

        // Batsman match
        if(strstr(line,"batsman:") && strstr(line,search)){
            strcpy(p.name, search);
            p.balls++;

            // next lines contain runs
            for(int i=0;i<4;i++){
                if(fgets(line,300,fp)){
                    int r;
                    if(sscanf(line," total: %d",&r)==1){
                        p.runs += r;
                        printf("Runs in this ball: %d\n", r);
                    }
                }
            }
        }

        // Bowler info
        if(strstr(line,"bowler:") && strstr(line,search)){
            printf("Bowling record found\n");
        }

        // Wicket info
        if(strstr(line,"wicket") && strstr(line,search)){
            printf("Wicket involved\n");
        }
    }

    fclose(fp);

    if(strlen(p.name)>0){
        printf("\n=== Player Summary ===\n");
        printf("Name  : %s\n", p.name);
        printf("Balls : %d\n", p.balls);
        printf("Runs  : %d\n", p.runs);
    }
    else{
        printf("Player not found\n");
    }

    return 0;
}

