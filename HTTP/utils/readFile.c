#include "readFile.h"
#include <stdio.h>
#include <stdlib.h>

char *BASE_PATH = "/home/alejo/Universidad/ProyectoTelematica1";

char *readFile(const char *filePath){

    char fullpath[256];
    snprintf(fullpath, sizeof(fullpath), "%s%s", BASE_PATH, filePath);

    FILE *file = fopen(fullpath , "r");

    if(file == NULL){
        printf("No se pudo abrir %s\n" , fullpath);
        return NULL;
    }

    fseek(file, 0, SEEK_END); // Ir al final para saber el tamano del archivo
    long size = ftell(file); // Retorna la posicion en la que estamos parados
    fseek(file , 0 , SEEK_SET); // Volvemos al incio

    char *content = malloc(size + 1);

    fread(content, 1, size, file);
    content[size] = '\0';

    fclose(file);
    return content;
}