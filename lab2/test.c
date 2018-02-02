#include <stdio.h>
#include <string.h>

int main(void)
{
  char s[256];
  char cmd[25];
  char arg[25];
  strcpy(s, "cd two three");
  char *token = strtok(s, " ");

  int i = 0;
  while (token)
  {
    if (i == 0)
    {
      strcpy(cmd, token);
    }
    else
    {
      strcpy(arg, token);
    }
    printf("token: %s\n", token);
    token = strtok(NULL, " ");
    i++;
  }

  printf("cmd: %s\n", cmd);
  for (int j = 0; j < 2; j++)
  {
    printf("%d: %s\n", j, arg[j]);
  }

  return 0;
}