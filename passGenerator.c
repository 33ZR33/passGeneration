#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifdef _WIN32 // Si se usa Windows
#include <conio.h>
#else //Si se usa Linux
void clear_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);  /* flush stdin */ 
}
#endif

#define MAX_LENGTH 25
#define MIN_LENGTH 5

char *generate_password(int length) {
    // Definir los caracteres que serán usados
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char numbers[] = "0123456789";
    char special[] = "!@#$%^&*()-_=+";

    char all_chars[128];  // Tamaño suficientemente grande para albergar todos los caracteres
    strcpy(all_chars, uppercase);
    strcat(all_chars, lowercase);
    strcat(all_chars, numbers);
    strcat(all_chars, special);

    char *password = (char *)malloc((length + 1) * sizeof(char));

    int hasUppercase, hasNumber, hasSpecial, hasLowercase;

    do {
        hasUppercase = 0;
        hasNumber = 0;
        hasSpecial = 0;
        hasLowercase = 0;

        // Llenar la contraseña con caracteres aleatorios
        for (int i = 0; i < length; i++) {
            char randomChar = all_chars[rand() % strlen(all_chars)];
            password[i] = randomChar;

            if (strchr(uppercase, randomChar)) hasUppercase = 1;
            if (strchr(numbers, randomChar)) hasNumber = 1;
            if (strchr(special, randomChar)) hasSpecial = 1;
            if (strchr(lowercase, randomChar)) hasLowercase = 1;
        }

        password[length] = '\0';

    } while (!hasUppercase || !hasNumber || !hasSpecial || !hasLowercase);

    return password;
}


int main() {
    int length;

    // Seed para la función rand
    srand((unsigned int)time(NULL));

    printf("Ingrese la longitud de la contraseña");
    printf("Se recomienda mas de 15 caracteres");
    printf("entre %d y %d: ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);

    #ifdef _WIN32 // Si se usa Windows
    //En windows no es necesario limpiar el buffer con conio.h
    #else // Si se usa Linux
    // En linux hay que limpiar el buffer antes de leer una nueva linea
    clear_stdin(); //Limpia el buffer despues de scanf()
    #endif

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Longitud no válida. Debe ser entre %d y %d.\n", MIN_LENGTH, MAX_LENGTH);
        return 1;
    }

    char *password = generate_password(length);
    printf("Contraseña generada: %s\n", password);
        
    free(password);
    
    printf("Presione Enter para continuar...");

    #ifdef _WIN32 // Si se usa Windows
    while (getch() != 13); //Espera hasta que se presione enter con conio.h
    #else // Si se usa Linux   
    getchar(); // Espera por un nuevo Enter
    #endif

    return 0;
}
