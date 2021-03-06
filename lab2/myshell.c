/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "utility.h"
#include "myshell.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256

// Put global environment variables here
char cwd[BUFFER_LEN];

// Define functions declared in myshell.h here

int main(int argc, char *argv[],char * envp[])
{
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };
    char command[BUFFER_LEN] = { 0 };
    char arg[BUFFER_LEN] = { 0 };

    getcwd(cwd, sizeof(cwd));
    char shellpath[BUFFER_LEN];
    strcpy(shellpath, cwd);
    strcat(shellpath, "/myshell");
    setenv("shell", shellpath, 1);
    // printf("\t\t****I WILL SHELL YOU DE VEY****\n");
    printf("%s:", cwd);
    // Parse the commands provided using argc and argv

    // Perform an infinite loop getting command input from users
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Perform string tokenization to get the command and argument
        char *token = strtok(buffer, " \n");
        int i = 0;
        while(token)
        {
            if (i == 0)
            {
                strcpy(command, token);
            }
            else
            {
                strcpy(arg, token);
            }
            token = strtok(NULL, " \n");
            i++;
        }
        // Check the command and execute the operations for each command
        // cd command -- change the current directory
        if (strcmp(command, "cd") == 0)
        {
            // your code here
            getcwd(cwd, sizeof(cwd));
            char *path = arg;
            // strcpy(path, cwd);
            // strcat(path, arg);
            chdir(path);
            getcwd(cwd, sizeof(cwd));
            setenv("PWD", cwd, 1);

        }

        // other commands here...
        else if (strcmp(command, "help") == 0)
        {
            display_help();
        }
        // quit command -- exit the shell
        else if (strcmp(command, "quit") == 0)
        {
            return EXIT_SUCCESS;
        }
        else if (strcmp(command, "clr") == 0){
            clearScreen();
        }
        else if (strcmp(command, "dir") == 0){
            print_directory();
        }
        else if (strcmp(command, "environ") == 0){
            Show_Environ(envp);
        }
        else if (strcmp(command, "echo") == 0){
            printf("%s\n", arg);
            // printf("Display <comment> on the display followed by a newline");
        }
        else if (strcmp(command, "pause") == 0){
            printf("Pause operation of the shell until 'Enter' is pressed");
            getchar();
        }
        // Unsupported command
        else
        {
            fputs("Unsupported command, use help to display the manual\n", stderr);
        }
        printf("%s:", cwd);
    }
    return EXIT_SUCCESS;
}
