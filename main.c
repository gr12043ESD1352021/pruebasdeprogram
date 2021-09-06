
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 struct Pelicua{
     int Matriz[5][58];
     int MatrizInversa[58][5];
     int MultiploDeMatrices[58][58];
}Peliculas;

int main(int argc, char** argv) {
    // Creamos un obejto para poder abrir archivo de texto
    FILE *Datos = fopen("peliculasFavoritasESD135_2021.csv", "r");
    //Validamos ejecucion de lectura de archivo.
    if (Datos == NULL) {
        perror("Error al abrir archivo.");
        return 1;

    }
    for(int largo=0;largo<=58;largo++){
        for(int ancho=0;ancho<=5;ancho++){
            Peliculas.MatrizInversa[largo][ancho]=0;
            Peliculas.Matriz[ancho][largo]=0;
        }
    }
    int coma = 0, largo=0, ancho=0, aux;
    char caracter[59];
    char *token;
    while (fgets(caracter, sizeof (caracter), Datos)) {

        token = strtok(caracter, ",");
        
        if(coma>1){
        while (token != NULL) {          
            if(ancho==0 ){token = strtok(NULL, ",");}
            else if(ancho>0){
                aux = strtol(token,NULL, 10);
                if(aux!=0){
                Peliculas.Matriz[ancho-1][largo]=aux;
                }
                else{
                Peliculas.Matriz[ancho-1][largo]=0;
                Peliculas.MatrizInversa[largo][ancho-1]=0;}
                token = strtok(NULL, ",");                
            }  
            ancho++;
        }
        
        }else if(coma<=1){token = strtok(NULL, ",");}
        
        coma++;
        
        if(coma>1 && ancho>=6){
            largo++;
            ancho=0;
        }
    }
    for (int a=0; a<=58;a++){
     for(int b=0; b<=5;b++ ){
          printf("%i\t", Peliculas.MatrizInversa[a][b]);
     }
     printf("\n");
}
    fclose(Datos);
    return 0;
}

//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//struct Pelicua{
//    char Carnet[6];
//    int TheGodfather, TokyoDrift, SpiritedAway, Tenet, TheGrandBudapestHotel, Frozen;
//}Peliculas[6][58], *puntero;
//int main(int argc, char** argv) {
//    // Creamos un obejto para poder abrir archivo de texto
//    FILE *Datos = fopen("peliculasFavoritasESD135_2021.csv", "r");
//    //Validamos ejecucion de lectura de archivo.
//    if (Datos == NULL) {
//        perror("Error al abrir archivo.");
//        return 1;
//
//    }
//    int ancho = 0, largo = 0, aux;
//    char caracter[20];
//    while (fgets(caracter, sizeof (caracter), Datos)) {
//        char *token;
//        token = strtok(caracter, ",");
//        if (ancho > 3) {
//            while (token != NULL) {
//                
//                switch (ancho){
//                   case 0:
//                        strcpy(Peliculas[ancho][largo].Carnet, token);
//                        break;
//                    case 1:
//                        aux = (int) strtol(token, NULL, 10);
//                        Peliculas[ancho][largo].TheGodfather = aux;
//                        printf("Sea intruducido % s \n", Peliculas[ancho][largo].TheGodfather);
//                        break;
//                    case 2:
//                        aux = (int) strtol(token, NULL, 10);
//                        Peliculas[ancho][largo].TokyoDrift = aux;
//                        break;
//                    case 3:
//                        aux = (int) strtol(token, NULL, 10);
//                        Peliculas[ancho][largo].SpiritedAway = aux;
//                        break;
//                    case 4:                        
//                        aux = (int) strtol(token, NULL, 10);
//                        Peliculas[ancho][largo].Tenet = aux;
//                        break;
//                    case 5: 
//                        aux = (int) strtol(token, NULL, 10);
//                        Peliculas[ancho][largo].TheGrandBudapestHotel = aux;
//                        break;
//                    case 6:
//                        aux = (int) strtol(token, NULL, 10);
//                        Peliculas[ancho][largo].Frozen = aux;
//                        break;
//                    default:
//                        break;                        
//                }
//                printf("%s \n", token);
//                token = strtok(NULL, ",");
//                ancho++;
//            }
//            printf("\n");
//        } else {
//            token = strtok(NULL, ",");
//        }
//        printf(" anhcho%d \n", ancho );
//        ancho++;
//        if(ancho > 4){
//            ancho =0;
//            largo++;
//         }
//    }
//    fclose(Datos);
//
//    printf("\n\nSe ha leido el archivo.");
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct Pelicua{
//    char Carnet[6];
//    int TheGodfather, TokyoDrift, SpiritedAway, Tenet, TheGrandBudapestHotel, Frozen;
//}Peliculas[6][58], *puntero;
//
//int main(int argc, char** argv) {
//    // Creamos un obejto para poder abrir archivo de texto
//    FILE *Datos  = fopen("peliculasFavoritasESD135_2021.csv", "r");
//    //Validamos ejecucion de lectura de archivo.
//    if(Datos == NULL){
//        perror("Error al abrir archivo."); 
//        return 1;
//        
//    }
////    char *Carnet;
////    int *TheGodfather, *TokyoDrift, *SpiritedAway, *Tenet, *TheGrandBudapestHotel, *Frozen;
//    int comas = 0, largo = 0, ancho = 0;
//    char caracter[20];
//    while (fgets(caracter, sizeof (caracter), Datos)) {
//        char *token;
//        token = strtok(caracter, ",");
//        if (comas > 3) {
//            while (token != NULL) {
//                //printf("%s \n ", token);
//                if (ancho == 0) {
//                    printf("valor %s   %d", Peliculas[ancho][largo].Carnet, ancho);
//                    strcpy(Peliculas[ancho][largo].Carnet, token);
//                    }
//                else {
//                    int aux = (int) strtol(token, NULL, 10);
//                    if (ancho == 1) {
//                        Peliculas[ancho][largo].TheGodfather = aux;
//                    }
//                    if (ancho == 2) {
//                        Peliculas[ancho][largo].TokyoDrift = aux;
//                    }
//                    if (ancho == 3) {
//                        Peliculas[ancho][largo].SpiritedAway = aux;
//                    }
//                    if (ancho == 4) {
//                        Peliculas[ancho][largo].Tenet = aux;
//                    }
//                    if (ancho == 5) {
//                        Peliculas[ancho][largo].TheGrandBudapestHotel = aux;
//                    }
//                    if (ancho == 6) {
//                        Peliculas[ancho][largo].Frozen = aux;
//                    }
//
//                }
//                token = strtok(NULL, ",");
//                ancho = ancho + 1;
//            }
//            printf("\n");
//        } else {
//            token = strtok(NULL, ",");
//        }
//        
//        comas++;
//        //ancho = 0;
//        largo++;
//    }
//    fclose(Datos);
//
//    printf("\n\nSe ha leido el archivo.");
//    return 0;
//}


/*int main(int argc, char** argv) {
// Creamos un obejto para poder abrir archivo de texto
FILE *Datos  = fopen("peliculasFavoritasESD135_2021.csv", "r");
//Validamos ejecucion de lectura de archivo.
if(Datos == NULL){
perror("Error al abrir archivo."); 
return 1;
        
}
char caracter[200];
int ancho=0, largo=0;
while(fgets(caracter, sizeof(caracter), Datos)){
char *token;
token = strtok(caracter, ",");
if(ancho>0){
while(token!=NULL){
 printf("%s", token);
 if(largo==0){strcpy(Peliculas[ancho][largo].Carnet, token);}
 int aux=(int) strtol(token, NULL, 10);
 //strcpy(Peliculas[ancho][largo].TheGodfather, aux);
 printf(Peliculas[ancho][largo].TheGodfather, "%s \t %d", Peliculas[ancho][largo].Carnet);
 token =strtok(NULL, ",");
 printf("\t");
 largo++;
}
}
printf("\n");
ancho++;
largo=0;
}
fclose(Datos);
 
printf("\n\nSe ha leido el archivo.");
    
    
    
    
return 0;
}*/
