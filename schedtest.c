#include "types.h"
#include "user.h"

int
main(int argc, char * argv[])
{
  int num_ps = atoi(argv[1]);
  // input validation
  if(num_ps <= 0)
  {
    printf(1, "Must loop at least 1 time\n");
    exit();
  }
  if(argc <= 2)
  {
    printf(1, "Must have at least 1 process\n");
    exit();
  }
  int i;
  for(i = 2; i < argc; i++)
  {
    int temp = atoi(argv[i]);
    if(temp < 10)
    {
      printf(1, "Ticket value for a process must be at least 10\n");
      exit();
     }
  }
  if(argc > 9)
  {
    printf(1, "Too many processes, must be at most 7\n");
    exit();
  }

  // testing scheduler
  int pid = 0;
  int pids[argc - 2];
  int j;
  for(j = 2; j < argc; j++)
  {
    pid = fork();
    if(pid == 0)
    {
      int temp = atoi(argv[j]);
      settickets(temp);
      while(1);
    } else {
      pids[j - 2] = pid;
    }
  }
  
  int k;
  for(k = 0; k < num_ps; k++)
  {
    ps();
    sleep(3);
  }
  
  int n;
  for(n = 2; n < argc; n++)
  {
    kill(pids[n - 2]);
    wait();
  }
  exit();
}
