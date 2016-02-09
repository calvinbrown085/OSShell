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

#define ARGV_SIZE 10
int *globalArray;

void printPid();
void savePid(int pid);
char *tokenizeUserInput(char userInput[80]);
int executeCommand(char *command1, char *commandList[ARGV_SIZE]);
char printWorkingDirectory();
void changeDirectory(char userInput[80]);
char *grabSecondCommand(char userInput[80]);
char printWorkingDirectoryForInput();

/* This is the main function of your project, and it will be run
 * first before all other functions.
 */
int main(int argc, char *argv[])
{
	globalArray = malloc(5 * sizeof *globalArray);
	char userInput[80] = "";
        while(1){
        	printWorkingDirectoryForInput();
                fgets(userInput, 80, stdin);

		//printf("Compare %i\n",strcmp(userInput,"showpid"));		
                if(strcmp(userInput, "exit") == 10){
                        printf("Exiting!\n");
                        break;
		}
		
		else if (strcmp(userInput, "cd") == 32){
			//grabSecondCommand(userInput);
			changeDirectory(grabSecondCommand(userInput));
			
		}
		else if(strcmp(userInput, "showpid") == 10){
			printPid();
		}
		else{
 			
			tokenizeUserInput(userInput);
		}
		
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
                
                list = strtok(NULL, " ");
                count += 1;

        }
	
	executeCommand(argList[0],argList);

        return *argList;
}

int executeCommand(char *command1, char *commandList[ARGV_SIZE])
{
  char *myArgv[ARGV_SIZE];  // an array of pointers to strings
   
  myArgv[0] = strtok(command1, "\n");;
  myArgv[1] = NULL;  // last element should be a NULL point
  pid_t pid;
  
  if ((pid = fork()) == 0) {
        	
	         	
  	execvp(myArgv[0], myArgv);
	printf("Error: Command Cannot Be Executed\n");        	
        exit(-1);	
  }
//  printf("PID: %i\n",pid);

  savePid(pid);
  waitpid(-1,NULL,0); 
   
  return 0; // should not be reached

}


 
char printWorkingDirectoryForInput()
{
   char cwd[1024];
   if (getcwd(cwd, sizeof(cwd)) != NULL)
       fprintf(stdout, "%s/$ ", cwd);
   else
       perror("getcwd() error");
   return 0;

}


void changeDirectory(char userInput[80])
{
	char *myArgv[ARGV_SIZE];
	myArgv[0] = strtok(userInput, "\n");
  	myArgv[1] = NULL;
	chdir(myArgv[0]);
}

char *grabSecondCommand(char userInput[80])
{
	char *list;
	list = strtok(userInput," ");
        char *argList[ARGV_SIZE];
	int count = 0;
        //This list just increments each time the strtok finds a word and will go until there is none left
        while(list != NULL )
        {

                argList[count] = list;

                list = strtok(NULL, " ");
                count += 1;

        }
   		
	return argList[1];
}

void savePid(int pid)
{
	int count = 0;
	int temp1 = globalArray[0];
	int temp2 = globalArray[1];
	int temp3 = globalArray[2];
	int temp4 = globalArray[3];
	
        	
		
	globalArray[0] = pid;
	globalArray[1] = temp1;
	globalArray[2] = temp2;
	globalArray[3] = temp3;
	globalArray[4] = temp4;
}

void printPid()
{
	int i;
	for(i = 0;i<=4;i++)
	{	
		printf("%i\n",globalArray[i]);
	}	
}

