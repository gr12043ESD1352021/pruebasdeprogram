#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pelicula {
    /*arreglando matriz*/
    int Matriz[6][59];
} Peliculas;

int main(int argc, char** argv) {
    Integrantes();
    // Creamos un obejto para poder abrir archivo de texto.
    FILE *Datos = fopen("peliculasFavoritasESD135_2021.csv", "r");
    //Validamos ejecucion de lectura de archivo.
    if (Datos == NULL) {
        perror("Error al abrir archivo.");
        return 1;
    }
    LlenandoMatriz(*Datos);
    LlenandoInversa();
    printf("\n\n");
    fclose(Datos);
    return 0;
}

void LlenandoMatriz(FILE *Datos) {
    //Iniciamos a llenar matriz con los datos del CSV.
    int coma = 0, largo = 0, ancho = 0, aux;
    char caracter[60];
    char *token;
    while (fgets(caracter, sizeof (caracter), Datos)) {
        token = strtok(caracter, ",");
        if (coma > 1) {
            while (token != NULL) {
                if (ancho == 0) {
                    token = strtok(NULL, ",");
                } else if (ancho > 0) {
                    aux = strtol(token, NULL, 10);
                    if (aux != 0) {
                        Peliculas.Matriz[ancho - 1][largo] = aux;
                    } else {
                        Peliculas.Matriz[ancho - 1][largo] = 0;
                    }
                    token = strtok(NULL, ",");
                }
                ancho++;
            }
        } else if (coma <= 1) {
            token = strtok(NULL, ",");
        }
        coma++;
        if (coma > 1 && ancho >= 6) {
            largo++;
            ancho = 0;
        }
    }
    for (int a = 0; a < 59; a++) {
        for (int b = 0; b < 6; b++) {
            printf("%i\t", Peliculas.Matriz[b][a]);
        }
        printf("\n");
    }
    printf("\n\n");
    free(token);
}

void LlenandoInversa() {
    int **MatrizInversa;
    MatrizInversa = (int**) malloc(58 * sizeof (int*));
    if (MatrizInversa == NULL) {
        printf("Error al reservar meroria.");
        return 1;
    }
    for (int largo = 0; largo < 59; largo++) {
        for (int ancho = 0; ancho < 6; ancho++) {
            MatrizInversa[largo] = (int*) malloc(ancho * sizeof (int));
            if (MatrizInversa[largo] == NULL) {
                printf("Error al reservar meroria.");
                return 1;
            }
        }
    }
    for (int a = 0; a < 59; a++) {
        for (int b = 0; b < 6; b++) {
            MatrizInversa[a][b] = Peliculas.Matriz[b][a];
        }
    }
    for (int b = 0; b < 6; b++) {
        for (int a = 0; a < 59; a++) {
            printf("%i ", Peliculas.Matriz[b][a]);
        }
        printf("\n");
    }
    printf("\n\n");
    MultiplicandoMatriz(MatrizInversa);
    //Liberamos memoria de puntero.
    for (int b = 0; b < 59; b++) {
        for (int a = 0; a < 6; a++) {
            free(MatrizInversa[a][b]);
        }
    }
}

void MultiplicandoMatriz(int **MatrizInversa) {
    int **MultiploDeMatrices;
    MultiploDeMatrices = (int**) malloc(58 * sizeof (int*));
    if (MultiploDeMatrices == NULL) {
        printf("Error al reservar meroria.");
        return 1;
    }
    for (int largo = 0; largo < 59; largo++) {

        for (int ancho = 0; ancho < 59; ancho++) {
            MultiploDeMatrices[largo] = (int*) malloc(ancho * sizeof (int));
            if (MultiploDeMatrices[largo] == NULL) {
                printf("Error al reservar meroria.");
                return 1;
            }
        }
    }
    for (int largoMult = 0; largoMult < 59; largoMult++) {
        for (int largo = 0; largo < 59; largo++) {
            for (int ancho = 0; ancho < 6; ancho++) {
                MultiploDeMatrices[largoMult][largo] += Peliculas.Matriz[ancho][largoMult] * MatrizInversa[largo][ancho];
            }
        }
    }
    for (int b = 0; b < 59; b++) {
        for (int a = 0; a < 59; a++) {
            if (a == b) {
                printf("NL ");
            } else {
                printf("%i  ", MultiploDeMatrices[b][a]);
            }
        }
        printf("\n");
    }
    //Liberamos memoria de los punteros.
    for (int b = 0; b < 59; b++) {
        for (int a = 0; a < 6; a++) {
            free(MatrizInversa[a][b]);
        }
    }
    for (int b = 0; b < 59; b++) {
        for (int a = 0; a < 59; a++) {
            free(MultiploDeMatrices[a][b]);
        }
    }
}

void Integrantes() {
    const char *Carnet1 = "GR12043";
    const char *Carnet2 = "PC19060";
    printf("Estudiantes: %s       %s\n", Carnet1, Carnet2);
}