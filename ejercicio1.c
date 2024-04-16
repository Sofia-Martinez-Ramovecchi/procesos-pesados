#include <stdio.h>
#include <sys/types.h> // Se define el tipo de dato pid_t
#include <unistd.h> // Contiene las definiciones de fork() y sleep().
#include <sys/wait.h> //Se define la función waitpid(pid_t pid)
#include <math.h>

double factorial(double num, double result);
double potencia(double num1, double num2);

int main() {
  double num1, num2, result = 0;
  pid_t pid_devuelto=0;
  pid_t pid1_devuelto=0;
  pid1_devuelto=fork();
  if(pid1_devuelto==0){
    result=potencia(3,5);
    printf("La potencia es %lf . ",result);
  }else{
    pid_devuelto=fork();
    if(pid_devuelto!=0) {
      num2=factorial(3,1);
      printf("El factorial del primer numero es %lf . ",num2);
    } else {
      num1=factorial(5,3);
      printf("El factorial del segundo numero es %lf . ",num1);
    }


  }

  waitpid(pid1_devuelto,NULL,0);
  waitpid(pid_devuelto,NULL,0);
  return 0;
}

double factorial(double num, double result) {

  result = result * num;
  if (num == 1) {
    return result;
  }
  factorial(num - 1, result);
}

double potencia(double num1, double num2) {
  double result = 0;
  result = pow(num1, num2);
  return result;
}
