#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "Musico.h"
#include "Orquesta.h"


int hardCodearOrquestas(eOrquesta vecOrquesta[],int tOrq)
{
    int contador = 0;

    //El ultimo cero es su estado isEmpty.
    eOrquesta bOrquesta[]=
    {
        //id,nombre,lugar,idtipoorq,isempty

        {1,"Yaki's","Argentina",2,0},
        {2,"Camu's","UK",3,0},
        {3,"Facu's","Finlandia",2,0},
        {4,"Bansi","Roma",1,0},
        {5,"Juaku","UK",1,0},
        {6,"Eliz","Bolivia",3,0},
        {7,"Napoli","Italia",2,0},
        {8,"Fave","Francia",2,0},
        {9,"Filips","Filipinas",1,0},
        {10,"Smith's","USA",3,0}
    };

    for(int i = 0; i<10;i++)
    {
        vecOrquesta[i] = bOrquesta[i];
        contador++;
    }

    return contador;
}



void inicializarOrquesta(eOrquesta vecOrquesta[], int tOrq)
{
    for(int i = 0; i < tOrq; i++)
    {
        vecOrquesta[i].isEmpty = 1;//LIBREEEEEE
    }
}

int buscarLibreOrquesta(eOrquesta vecOrquesta[], int tOrq)
{
    int indice = -1;

    for(int i=0; i < tOrq; i++)
    {
        if(vecOrquesta[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarUnaOrquesta(eOrquesta vecOrquesta,eTipoOrquesta vecTipoOrquesta[],int tamTipoOrq)
{
    char nombre[20];

    cargarDescripcionTipoOrquesta(vecTipoOrquesta,tamTipoOrq,vecOrquesta.idTipoOrquesta,nombre);

    printf("%4d  %10s  %10s    %11s\n\n",
           vecOrquesta.id,
           vecOrquesta.nombre,
           vecOrquesta.lugar,
           nombre);
}

int imprimirOrquestas(eOrquesta vecOrquesta[],int tOrq,eTipoOrquesta vecTipoOrquesta[],int tamTipoOrq)
{
    int flag=0;


    printf("\n\n");
    printf("         ..::LAS ORQUESTAS SON::..\n\n");
    printf("  ID      NOMBRE       LUGAR           TIPO\n");
    printf("  --      ------       -----           ----\n\n");

    for(int i=0; i<tOrq; i++)
    {
        if(vecOrquesta[i].isEmpty == 0)
        {
            mostrarUnaOrquesta(vecOrquesta[i],vecTipoOrquesta,tamTipoOrq);
            flag=1;
        }
    }
    if (flag==0)
    {
        printf("\nNo hay --Orquestas-- que mostrar.\n\n");
    }
    return flag;
}

int altaOrquestaMaestra(eOrquesta vecOrquesta[],int tOrq,int lastId,eTipoOrquesta vecTipoOrquesta[],int tamTipoOrq)
{
    int todoOk= 0;
    int index;

    system("cls");
    printf("\nAlta --Orquesta--\n");

    index = buscarLibreOrquesta(vecOrquesta,tOrq);

    if(index == -1)
    {
        printf("\n--Sistema completo.--\n\n");
    }
    else
    {
        if(getNombreOApellido(vecOrquesta[index].nombre,"\n<2-50 caract>\nIngrese nombre de Orquesta: ","\nError. Reingrese",2,50,2)!=-1)
        {
            if(getNombreOApellido(vecOrquesta[index].lugar,"\n<2-50 caract>\nIngrese lugar de Orquesta: ","\nError. Reingrese",2,50,2)!=-1)
            {
                imprimirTiposOrquestas(vecTipoOrquesta,tamTipoOrq);

                if(getInt(&vecOrquesta[index].idTipoOrquesta,"\n<1-3 numero>\nIngrese tipo de Orquesta: ","\nError. Reingrese",1,3,2)!=-1)
                {
                    vecOrquesta[index].id = lastId;
                    vecOrquesta[index].isEmpty = 0;//Cambia su estado de libre a ocupado.
                    todoOk = 1;
                    printf("\n--Alta de --Orquesta-- exitosa--\n\n");
                }
            }
        }    }
    if(todoOk != 1)
    {
        printf("\nError en la carga de datos.\n");
    }
    return todoOk;
}

int buscarOrquestaId(eOrquesta vecOrquesta[],int tOrq,int idABuscar)
{
    int index = -1;

    for(int i = 0; i<tOrq;i++)
    {
        if(vecOrquesta[i].isEmpty==0 && vecOrquesta[i].id == idABuscar)
        {
            index = i;
            //Cuando encuentro el id, rompo el for.
            break;
        }
    }
    return index;
}

int bajaOrquesta(eOrquesta vecOrquesta[],int tOrq,eTipoOrquesta vecTipoOrquesta[],int tamTipoOrq)
{
    /**AGREGAR QUE CUANDO SE DA DE BAJA UN ORQUESTA SE ELIMINAN LOS MUSICOS TAMBIEN VECMUSICO.ISEMPTY =1??****/
    int index;
    int idABajar;
    int todoOk = 0;
    char confirma;

    system("cls");
    printf("\n--Baja Orquesta--\n");

    imprimirOrquestas(vecOrquesta,tOrq,vecTipoOrquesta,tamTipoOrq);

    getInt(&idABajar,"\nIngrese ID a dar de baja: ","\nError. Reingrese un numero de id valido\n",1,10,2);

    index = buscarOrquestaId(vecOrquesta,tOrq,idABajar);

    if(index == -1)
    {
        printf("\nNo existe una orquesta con ese ID.");
    }
    else
    {
        printf("\n\n");
        printf("  ID      NOMBRE       LUGAR    TIPO\n");
        printf("  --      ------       -----    ----\n\n");
        mostrarUnaOrquesta(vecOrquesta[index],vecTipoOrquesta,tamTipoOrq);

        printf("confirma baja? <s/n>: ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma == 's')
        {
            vecOrquesta[index].isEmpty = 1;
            printf("\n..Baja exitosa..\n\n");
            todoOk = 1;
        }
        else if(confirma == 'n')
        {
            printf("\nSe ha cancelado la operacion.\n\n");
        }
    }
    return todoOk;
}

int cargarNombreOrquesta(eOrquesta vecOrquesta[],int tOrq,int id,char descripcion[])
{
    int todoOk = 0;

    for(int i = 0;i<tOrq;i++)
    {
        if(vecOrquesta[i].id == id)
        {
            strcpy(descripcion,vecOrquesta[i].nombre);
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}


/****TIPO DE ORQUESTA****/

void hardCodearTipoOrquesta(eTipoOrquesta vecTipoOrquesta[],int tamTipoOrq)
{
    eTipoOrquesta bTipoOrq[]=
    {
        //id y nombre (descripcion)
        {1,"Sinfonica"},
        {2,"Filarmonica"},
        {3,"Camara"}
    };

    for(int i = 0; i<tamTipoOrq; i++)
    {
        vecTipoOrquesta[i] = bTipoOrq[i];
    }
}

void mostrarTipoOrquesta(eTipoOrquesta vecTipoOrquesta)
{
    printf("%4d %15s\n\n",vecTipoOrquesta.id,vecTipoOrquesta.descripcion);
}

void imprimirTiposOrquestas(eTipoOrquesta vecTipoOrquesta[],int tamTipoOrq)
{
    printf("\n");
    printf("  ID       CATEGORIA\n");
    printf("  --       ---------\n\n");

    for(int i=0; i<tamTipoOrq; i++)
    {
        mostrarTipoOrquesta(vecTipoOrquesta[i]);
    }
}

int cargarDescripcionTipoOrquesta(eTipoOrquesta vecTipoOrquesta[],int tamTipoOrq,int id,char descripcion[])
{
    int todoOk = 0;

    for(int i = 0; i<tamTipoOrq; i++)
    {
        if(vecTipoOrquesta[i].id == id)
        {
            strcpy(descripcion,vecTipoOrquesta[i].descripcion);
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}









