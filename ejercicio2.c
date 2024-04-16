#include <stdio.h>
#include <sys/wait.h> //Se define la función waitpid(pid_t pid)
#include <string.h>
#include <sys/types.h> // Se define el tipo de dato pid_t
#include <unistd.h> // Contiene las definiciones de fork() y sleep().
struct Persona {
  int legajo;
  char nombre[50];
  int edad;
};

int buscar(struct Persona buffer[]);
int contar(struct Persona buffer[]);
int main() {
  // Abrir el archivo en modo de escritura binaria ("wb")
  FILE *archivo = fopen("empleados.bin", "rb");

  if (archivo == NULL) {
    // Error al abrir el archivo
    fprintf(stderr, "Error al abrir el archivo\n");
    return 1;
  }
  struct Persona buffer[3];
  fread(buffer, sizeof(struct Persona), 3, archivo);
  pid_t pid_devuelto=0;
  pid_devuelto=fork();
  if(pid_devuelto!=0){
    contar(buffer);
  }else{
    buscar(buffer);
  }
  fclose(archivo);
  waitpid(pid_devuelto,NULL,0);
  return 0;
}

int buscar(struct Persona buffer[]) {
  int legajo = 0;
  int i = 0;
  do {
    printf("Ingrese un legajo");
    scanf("%d", &legajo);
    for (int j = 0; j < 3; j++) {
      if (buffer[j].legajo == legajo) {
        printf("%s", buffer[j].nombre);
        printf("%d", buffer[j].edad);
        printf("%d", buffer[j].legajo);
      }
    }
    i++;
  } while (legajo != 0);
  return 0;
}

int contar(struct Persona buffer[]) {

  int cont = 0;
  for (int i = 0; i < 3; i++) {
    if (buffer[i].edad >= 50) {
      cont++;
    }
  }
  printf("La cantidad de empleados con edad mayor a 50 es de: %d", cont);
  return 0;
}
