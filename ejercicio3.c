#include <sys/types.h> // Se define el tipo de dato pid_t
#include <sys/wait.h> //Se define la función waitpid(pid_t pid)
#include <unistd.h> // Contiene las definiciones de fork() y sleep().
#include <stdio.h>
#include <stdlib.h>
void main()
{

  int status;
  pid_t pid_devuelto;
  pid_t pid_devuelto1;
  pid_t pid_devuelto2;
  pid_t pid_devuelto3;
  pid_t pid_devuelto4;
  pid_t pid_devuelto5;
  pid_devuelto=fork();
  if(pid_devuelto==0){
    printf("Soy el proceso %d \n",getpid());
  }else{
    pid_devuelto1=fork();
    if(pid_devuelto1==0){
      printf("Soy el proceso %d \n",getpid());
    }else{
      pid_devuelto2=fork();
      if(pid_devuelto2==0){
        printf("Soy el proceso %d \n",getpid());
      }else{
        printf("En proceso");

        pid_devuelto3=fork();
        if(pid_devuelto3==0){
          printf("Soy el proceso %d \n",getpid());
        }else{
          pid_devuelto4=fork();
          if(pid_devuelto4==0){
            printf("Soy el proceso %d \n",getpid());
          }else{
            pid_devuelto5=fork();
            if(pid_devuelto5==0){
              printf("Soy el proceso %d \n",getpid());
            }else{
              waitpid(pid_devuelto3,NULL,0);
              waitpid(pid_devuelto4,NULL,0);
              waitpid(pid_devuelto5,NULL,0);
              printf("Fin.");
            }
          }
        }
      }
    }
    waitpid(pid_devuelto,NULL,0);
    waitpid(pid_devuelto1,NULL,0);
    waitpid(pid_devuelto2,NULL,0);
  
  }

}
