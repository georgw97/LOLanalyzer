#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<unistd.h>
#include<conio.h>


char databasehead[][20] = {"W/L", "Kills", "Deaths", "Assists","Map Awareness", "CS"};

char mainmenutext[] = "---WELCOME TO THE LOL ANALYZER.---\n\n\n"
                    "Press one of the following keys to continue:\n\n"
                    "1.Add Game to Database\n"
                    "2.Change output path\n"
                    "3.Credits\n"
                    "4.Exit\n\n\n";

char validkeymenutext[] = "Please enter a valid Key.\n";

char notyetimplmenutext[] = "Not yet implemented...\n";

char inputdata[10][20];

char filename[] = "Loldb.csv";

char outputpath[200] = ""; //default path is inside folder of the program

int nrofparams = sizeof(databasehead)/sizeof(databasehead[0]);

void clrscr() //clears the console
{
    system("@cls||clear");
}

void credits()
{
    int x; double y;
    char text1[]=    "\n\n \t\t\t #####LOLANALYZER##### ";
    char text2[]=    "\n\n \t\t\t MADE By ";
    char text3[]=    "\n\n \t\t\t GEORG WOLLERT ";
    printf("\n\n");
    for(x=0; text1[x]!=NULL; x++)
    {
        printf("%c",text1[x]);
        for(y=0; y<=8888888; y++)
        {
        }
    }
        printf("\n\n");
        for(x=0; text2[x]!=NULL; x++)
        {
            printf("%c",text2[x]);
            for(y=0; y<=8888888; y++)
            {
            }
        }
    printf("\n\n");
    for(x=0; text3[x]!=NULL; x++)
    {
        printf("%c",text3[x]);
        for(y=0; y<=8888888; y++)
        {
        }
    }
    getch();
    clrscr();
}


void flashmenu(char menu[])
{
    clrscr();
    printf(menu);
    getch();
    clrscr();
}

int checkentry(char checkchar, char option)
{
    //Function to check if the Input is a valid one (e.g. Alpha letters in for numeric Parameter like CS)
}

int fileexists(const char * filenamestr) //Check if a file exist using fopen() function, return 1 if the file exist otherwise return 0
{
    FILE *file; //try to open file to read
    if (file = fopen(filenamestr, "r")){
        fclose(file);
        return 1;
    }
    return 0;
}

void addtodb()
{
    //Start questioning the user for input data
    for (int i = 0; i < nrofparams; i++)
    {
        clrscr();
        printf("%s?\n", databasehead[i]);
        scanf("%s", inputdata[i]);
        clrscr();
    }
}

void writetodb(char data[])
{
    strcat(outputpath, filename);
    FILE * fp;
    //check if file exists, if not then write head columns
    if(fileexists(filename) == 0)
    {
        fp = fopen(outputpath, "w");
        for(int i = 0; i < nrofparams; i++)
        {
            if(i != nrofparams-1)
            {
                fprintf(fp, "%s,", databasehead[i]);
            }
            else
            {
                fprintf(fp, "%s\n", databasehead[i]); // last entry should have no comma and new line
            }
        }
        fclose(fp);
    }
    // open the file
    fp = fopen(outputpath, "a+"); //copy together the filename and the path KÖNNTE PROBLEME GEBEN


    // print data into file
    for(int i = 0; i < nrofparams; i++)
    {
        if(i != nrofparams-1)
        {
            fprintf(fp, "%s,", inputdata[i]);
        }
        else
        {
            fprintf(fp, "%s\n", inputdata[i]); // last entry should have no comma and new line
        }
    }
    fclose(fp);
}

void printlast5entrys()
{

}

int main(void)
{
	for(;;)
    {
        printf(mainmenutext);
        char c;
        c = getch();
        char test[100];

        switch(c)
        {
            case '1':
                addtodb();
                writetodb(inputdata);
                break;
            case '2':
                clrscr();
                printf("Paste new Path: \n");
                scanf("%s",outputpath);
                clrscr();
                break;
            case '3':
                clrscr();
                credits();
                break;
            case '4':
                exit(0);
                break;
            default:
                flashmenu(validkeymenutext);
        }
    }
}


