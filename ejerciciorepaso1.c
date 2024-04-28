#include<stdio.h>
#include<sys/wait.h>
#include <sys/types.h> // Se define el tipo de dato pid_t
#include <unistd.h> // Contiene las definiciones de fork() y sleep().
#include <math.h>
#include<stdlib.h>

void comando(char comando []){
  int result = system(comando);
  if(result !=0){
    printf("Error al ejecutar el comando.\n");
  }else{
    printf("Comando realizado con exito");
  }
}

void opciones(int opc){
  switch (opc) {
    case 0:
      exit(0);
      break;
    case 1:
      comando("free > memoria.log");
      break;
    case 2:
      comando("ping -c 4 8.8.8.8 > ping.log");
      break;
    case 3:
      comando("df > disco.log");
      break;
    default: 
      printf("Ingrese un numero valido");
      break;

  }
}
void loop(){
  pid_t pid_1=0;
  int opc=0;
  int loop=1;
  int cont=0;
  do{
printf("Ingrese 0 si quiere finalizar el proceso principal, 1 para indicar la memoria utilizada, 2 para hacer un ping y 3 para para informar espacio de disco\n");
      scanf("%d",&opc);

    pid_1=fork();
    if(pid_1 > 0){
      continue; 
    }else if(pid_1==0){
         opciones(opc);
      exit(0);
    }    
  }while(loop==1);

}
int main(int argc, char *argv[])
{
  loop(); 

  return 0;
}
