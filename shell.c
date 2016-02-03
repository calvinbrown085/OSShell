/***********************************************************
 * Name of program: Shell
 * Authors: Chad Gilmer, Calvin Brown
 * Description: This is a program that imitates parts of the linux shell
 **********************************************************/

/* These are the included libraries.  You may need to add more. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>


/* I don't want to see any global variables in this program. -5 pts
 * for any global variable used. */
#define ARGV_SIZE 10

/* Declarations go here for functions that are called before they
 * are defined.  For example, the function named helper is called
 * in main before it is defined, so I declare it here.
 */
char *tokenizeUserInput(char userInput[80]);
int executeCommand(char *command, char *commandList[ARGV_SIZE]);


/* This is the main function of your project, and it will be run
 * first before all other functions.
 */
int main(int argc, char *argv[])
{
	char userInput[80] = "";

	//char workingDirectory[1024] = getCurrentWorkingDirectory();
        // an array of pointers to strings
	char *myArgv[ARGV_SIZE];
  	myArgv[0] = "ls";
  	//myArgv[1] = "-aux";
  	//myArgv[2] = NULL;  // last element should be a NULL pointer

  	execvp(myArgv[0], myArgv);
        //We just have user input and make sure that the user wants to keep entering words until they enter quit
        while(1){
        	printf("prompt$ ");
                fgets(userInput, 80, stdin);


                if(strcmp(userInput, "quit") == 10){
                        printf("Exiting!\n");
                        break;
		}
		tokenizeUserInput(userInput);

	}
	return 0; /* Success */
}


/* Comments describing what each function does must be included on
 * top of each function.  -5 pts for each undocumented function.
 */
char *tokenizeUserInput(char userInput[80])
{
        char *list;
        int count;
        count = 0;
        list = strtok(userInput," ");
	char *argList[ARGV_SIZE];
        //This list just increments each time the strtok finds a word and will go until there is none left
        while(list != NULL )
        {

								argList[count] = list;
                printf("%s\n",list);
                list = strtok(NULL, " ");
                count += 1;

        }

        return *argList;
}

int executeCommand(char *command, char *commandList[ARGV_SIZE])
{
	printf("%s",command);
	pid_t pid;
	printf("%i",pid);
	if ((pid = fork()) == 0) {
		//execvp(command,commandList);
	}
	waitpid();



}
