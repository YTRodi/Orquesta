#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "Instrumento.h"

int hardCodearInstrumento(eInstrumento vecInstru[],int tInstru)
{
    int contador = 0;

    //El ultimo cero es su estado isEmpty.
    eInstrumento bInstrumento[]=
    {
        /**AGREGAR TIPO DESCRIPCION
        1-CUERDAS
        2-VIENTO MADERA
        3-VIENTO METAL
        4-PERCUSION
        **/

        //id,nombre, apellido, tipo y isempty
        {101,"Guitarra",1,0},
        {102,"Bajo",1,0},
        {103,"Bateria",4,0},
        {104,"Trombon",3,0},
        {105,"Chelo",1,0},
        {106,"Flauta",2,0},
        {107,"Trompeta",3,0},
    };

    for(int i = 0; i<7;i++)
    {
        vecInstru[i] = bInstrumento[i];
        contador++;
    }

    return contador;
}

void inicializarInstrumento(eInstrumento vecInstru[], int tInstru)
{
    for(int i = 0; i < tInstru; i++)
    {
        vecInstru[i].isEmpty = 1;//LIBREEEEEE
    }
}

int buscarLibreInstrumento(eInstrumento vecInstru[], int tInstru)
{
    int indice = -1;

    for(int i=0; i < tInstru; i++)
    {
        if(vecInstru[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarUnIstrumento(eInstrumento vecInstru,eTipoInstru vecTipoInstrumento[],int tamTipoInstru)
{
    char nombreInstrumento[50];

    cargarDescripcionTipoInstrumento(vecTipoInstrumento,tamTipoInstru,vecInstru.tipo,nombreInstrumento);

    /**FALTA ---> MOSTRAR EL TIPO CON UN TEXTO, NO CON NUMEROS.***/

    printf("%4d  %10s %15s\n\n",
           vecInstru.id,
           vecInstru.nombre,
           nombreInstrumento);

}

int imprimirInstrumentos(eInstrumento vecInstrumento[],int tInstru, eTipoInstru vecTipoInstrumento[],int tamTipoInstru)
{
    int flag=0;

    printf("\n\n");
    printf("  ID      NOMBRE            TIPO\n");
    printf("  --      ------            ----\n\n");

    for(int i=0; i<tInstru; i++)
    {
        if(vecInstrumento[i].isEmpty == 0)
        {
            mostrarUnIstrumento(vecInstrumento[i],vecTipoInstrumento,tamTipoInstru);
            flag=1;
        }
    }
    if (flag==0)
    {
        printf("\nNo hay --Instrumentos-- que mostrar.\n\n");
    }
    return flag;
}

int altaInstrumentoMaestra(eInstrumento vecInstrumento[],
                           int tInstru,
                           int lastId,
                           eTipoInstru vecTipoInstrumento[],
                           int tamTipoInstru)
{
    int todoOk= 0;
    int index;

    system("cls");
    printf("\nAlta --Instrumento--\n");

    index = buscarLibreInstrumento(vecInstrumento,tInstru);

    if(index == -1)
    {
        printf("\n--Sistema completo.--\n\n");
    }
    else
    {

        if(getNombreOApellido(vecInstrumento[index].nombre,"\n<2-50 caract>\nIngrese nombre: ","\nError. Reingrese",2,50,2)!=-1)
        {
            imprimirTiposInstrumentos(vecTipoInstrumento,tamTipoInstru);

            if(getInt(&vecInstrumento[index].tipo,"\n<1-4>\nIngrese ID del tipo: ","\nError.Reingrese",1,4,2)!=-1)
            {
                vecInstrumento[index].id = lastId;
            vecInstrumento[index].isEmpty = 0;
            todoOk = 1;
            printf("\n--Alta de --Instrumento-- exitosa--\n\n");
            }

        }
    }
    if(todoOk != 1)
    {
        printf("\nError en la carga de datos.\n");
    }
    return todoOk;
}

int cargarNombreInstrumento(eInstrumento vecInstrumento[],int tInstru,int id,char descripcion[])
{
    int todoOk = 0;

    for(int i = 0;i<tInstru;i++)
    {
        if(vecInstrumento[i].id == id)
        {
            strcpy(descripcion,vecInstrumento[i].nombre);
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}


/****TIPO DE INSTRUMENTOS****/

void hardCodearTipoInstrumento(eTipoInstru vecTipoInstrumento[],int tamTipoInstru)
{
    eTipoInstru bTipoInstru[]=
    {
        //id y nombre (descripcion)
        {1,"Cuerdas"},
        {2,"Viento-madera"},
        {3,"Viento-metal"},
        {4,"Percusion"}
    };

    for(int i = 0; i<tamTipoInstru; i++)
    {
        vecTipoInstrumento[i] = bTipoInstru[i];
    }
}

void mostrarTipoInstrumento(eTipoInstru vecTipoInstrumento)
{
    printf("%4d %15s\n\n",vecTipoInstrumento.id,vecTipoInstrumento.descripcion);
}

void imprimirTiposInstrumentos(eTipoInstru vecTipoInstrumento[],int tamTipoInstru)
{
    printf("\n");
    printf("  ID       CATEGORIA\n");
    printf("  --       ---------\n\n");

    for(int i=0; i<tamTipoInstru; i++)
    {
        mostrarTipoInstrumento(vecTipoInstrumento[i]);
    }
}

int cargarDescripcionTipoInstrumento(eTipoInstru vecTipoInstrumento[],int tamTipoInstru,int id,char descripcion[])
{
    int todoOk = 0;

    for(int i = 0; i<tamTipoInstru; i++)
    {
        if(vecTipoInstrumento[i].id == id)
        {
            strcpy(descripcion,vecTipoInstrumento[i].descripcion);
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}



