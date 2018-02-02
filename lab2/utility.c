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

// Define your utility functions here, these will most likely be functions that you call
// in your myshell.c source file


void display_help(void){
  FILE *fp;
  int c;
  fp = fopen("README.md", "r+");
  while ((c = getc(fp)) != EOF)
  {
      putchar(c);
  }
  printf("\n");
  fclose(fp);
}
void Show_Environ(char * envp[])
{
    int i;

    for (i = 0; envp[i] != NULL; i++)
    {
        printf("\n%s", envp[i]);
    }
}
void clearScreen(void)
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}
// void change_directory(void){
//   getcwd(cwd, sizeof(cwd));
// }
