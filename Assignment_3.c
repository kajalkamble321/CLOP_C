
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {

    FILE *file;
    char c;
    char buffer[1024];

    int bytes = 0;
    int rows = 0;
    int colons = 0;
    int dashes = 0;
    int spaces = 0;
    int tabs = 0;
    int invalid = 0;
    int minLen = 9999, maxLen = 0;

    // BYTE SEQUENCE ANALYSIS 

    file = fopen("64827.yaml","r");

    if(!file){
        printf("Cannot open file\n");
        return 1;
    }

    printf("\n### BYTE SEQUENCE OUTPUT ###\n");

    while((c=fgetc(file))!=EOF){

        putchar(c);
        bytes++;

        if(c==':') colons++;
        if(c=='-') dashes++;
        if(c==' ') spaces++;
        if(c=='\t') tabs++;

        // validation: printable text file
        if(!isprint(c) && c!='\n' && c!='\t')
            invalid++;
    }

    fclose(file);

    //LINE SEQUENCE ANALYSIS 

    file = fopen("64827.yaml","r");

    printf("\n\n### LINE SEQUENCE OUTPUT ###\n");

    while(fgets(buffer,sizeof(buffer),file)){

        int len = strlen(buffer);

        if(buffer[len-1]=='\n') len--;

        if(len < minLen) minLen = len;
        if(len > maxLen) maxLen = len;

        printf("Line %d (%d chars): %s", ++rows, len, buffer);
    }

    fclose(file);

    

    printf("\n\n### FILE REPORT ###\n");

    printf("Bytes Count   : %d\n", bytes);
    printf("Lines Count   : %d\n", rows);
    printf("Min Line Size : %d\n", minLen);
    printf("Max Line Size : %d\n", maxLen);
    printf("Colons (:)    : %d\n", colons);
    printf("Dashes (-)    : %d\n", dashes);
    printf("Spaces        : %d\n", spaces);
    printf("Tabs          : %d\n", tabs);
    printf("Invalid Bytes : %d\n", invalid);



    printf("\n### RESULT ###\n");

    if(colons>5 && dashes>2 && invalid==0)
        printf("This appears to be a YAML structured text file\n");
    else
        printf("File format uncertain\n");

    return 0;
}

