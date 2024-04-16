#include<stdio.h>
#include<sys/wait.h>
#include <sys/types.h> // Se define el tipo de dato pid_t
#include <unistd.h> // Contiene las definiciones de fork() y sleep().
#include <math.h>
#include<stdlib.h>
void potencia(double num, double numpow);
int main(int argc, char *argv[])
{

  pid_t pid=0;
  pid_t pid1=0;
  pid_t pid2=0;
  double numero=0;
  printf("Ingrese un numero:");
  scanf("%lf",&numero);

  pid=fork();
  if(pid==0){
    potencia(numero,2);
  }else{
    potencia(numero,3);
    pid1=fork();
    if(pid1==0){
      potencia(numero,5);
    }else{
      pid2=fork();
      if(pid2==0){
        potencia(numero,7);
      }
    }
  }
  waitpid(pid,NULL,0);
  waitpid(pid1,NULL,0);
  waitpid(pid2,NULL,0);
  
  return 0;
}

void potencia(double num, double numpow){
  double i=0;
  double aux=0;
  double result=2;
  while(result<num){
    aux=result;
    result=pow(numpow,i);
    i++;
  }

  if( (num-aux) > ((num-result)*-1) ){
    printf("La potencia de %lf mas cercana a %lf es %lf \n",numpow,num,result);
  }else{
    printf("La potencia de %lf mas cercana a %lf es %lf \n",numpow,num,aux);

  }
}

