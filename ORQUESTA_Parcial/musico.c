#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Musico.h"
#include "utn.h"

int hardCodearMusicos(eMusico vecMusico[],int tMusic)
{
    int contador = 0;

    //El ultimo cero es su estado isEmpty.
    eMusico bMusico[]=
    {
        //id,nombre, apellido, edad, id orquesta, id instrumento, isempty
        {1001,"Yago","Rodi",21,8,101,0},
        {1002,"Camila","Roy",20,10,5,0},
        {1003,"Facundo","Tedesco",27,18,101,0},
        {1004,"Ban","Demon",30,18,101,0},
        {1005,"Joaquin","Escanor",30,9,105,0},
        {1006,"Elisabeth","Angelita",28,10,106,0},
        {1007,"Napoli","Eufrasia",25,7,104,0},
        {1008,"Cespedes","Nahuel",30,5,107,0},
        {1009,"Filipponi","Juana",18,8,103,0},
        {1010,"Smith","Scott",22,8,104,0},
        {1011,"Gimenez","Oscar",24,10,101,0},
        {1012,"Castania","Cacho",20,10,104,0},
        {1013,"Lozano","Veronica",30,5,114,0},
        {1014,"Arce","Raul",20,10,101,0},
        {1015,"Iglesias","Enrique",30,10,108,0},
        {1016,"Martinez","Ines",28,10,105,0},
        {1017,"Rico","Pedro",18,9,107,0},
        {1018,"Rodriguez","Clara",19,8,103,0},
        {1019,"Ruiz","Fabio",30,4,101,0},
        {1020,"Bill","Gates",23,8,101,0},
        {1021,"Jobs","Steve",29,7,105,0},
        {1022,"Toro","Hugo",25,8,104,0},
        {1023,"Vazques","Julia",18,10,101,0},
        {1024,"Rodi","Joel",18,4,106,0},
        {1025,"Rocha","Jeremias",30,7,105,0},
        {1026,"Quispe","Ignacio",30,7,103,0},
        {1027,"Fancella","Guillermo",30,7,103,0},
        {1028,"Pop","Loli",30,7,113,0}
    };
    for(int i = 0; i<28; i++)
    {
        vecMusico[i] = bMusico[i];
        contador++;
    }

    return contador;
}

void inicializarMusico(eMusico vecMusico[], int tMusic)
{
    for(int i = 0; i < tMusic; i++)
    {
        vecMusico[i].isEmpty = 1;//LIBREEEEEE
    }
}

int buscarLibreMusico(eMusico vecMusico[], int tMusic)
{
    int indice = -1;

    for(int i=0; i < tMusic; i++)
    {
        if(vecMusico[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarUnMusico(eMusico vecMusico,
                     eOrquesta vecOrquesta[],
                     int tOrq,
                     eInstrumento vecInstrumento[],
                     int tInstru)
{
    /**FALTA ID INSTRUMENTO***/
    char nombreOrquesta[50];
    char nombreInstrumento[50];
    //char nombreTipoOrquesta[20];

    //NO EL TIPO DE ORQUESTA, EL ID DE ORQUESTA.

    cargarNombreOrquesta(vecOrquesta,tOrq,vecMusico.idOrquesta,nombreOrquesta);
    cargarNombreInstrumento(vecInstrumento,tInstru,vecMusico.idInstrumento,nombreInstrumento);


    //cargarDescripcionTipoOrquesta(vecTipoOrquesta,tamTipoOrq,vecOrquesta.idTipoOrquesta,nombreTipoOrquesta);

    printf("%4d  %10s  %13s %7d  %10s    %10s \n\n",
           vecMusico.id,
           vecMusico.nombre,
           vecMusico.apellido,
           vecMusico.edad,
           nombreOrquesta,
           nombreInstrumento);
}

int imprimirMusicos(eMusico vecMusico[],
                    int tMusic,
                    eOrquesta vecOrquesta[],
                    int tOrq,
                    eInstrumento vecInstrumento[],
                    int tInstru)
{
    int flag=0;

    printf("\n\n");
    printf("  ID      NOMBRE       APELLIDO    EDAD    ORQUESTA   INSTRUMENTO\n");
    printf("  --      ------       --------    ----    --------   -----------\n\n");

    for(int i=0; i<tMusic; i++)
    {
        if(vecMusico[i].isEmpty == 0)
        {
            mostrarUnMusico(vecMusico[i],vecOrquesta,tOrq,vecInstrumento,tInstru);
            flag=1;
        }
    }
    if (flag==0)
    {
        printf("\nNo hay --Musicos-- que mostrar.\n\n");
    }
    return flag;
}

int altaMusicoMaestra(eMusico vecMusico[],
                      int tMusic,
                      int lastId,
                      eOrquesta vecOrquesta[],
                      int tOrq,
                      eTipoOrquesta vecTipoOrquesta[],
                      int tamTipoOrq,
                      eInstrumento vecInstrumento[],
                      int tInstru,
                      eTipoInstru vecTipoInstrumento[],
                      int tamTipoInstru)
{
    int todoOk= 0;
    int index;

    system("cls");
    printf("\nAlta --Musico--\n");

    index = buscarLibreMusico(vecMusico,tMusic);

    if(index == -1)
    {
        printf("\n--Sistema completo.--\n\n");
    }
    else
    {
        if(getNombreOApellido(vecMusico[index].nombre,"\n<2-50 caract>\nIngrese nombre: ","\nError. Reingrese",2,50,2)!=-1)
        {
            if(getNombreOApellido(vecMusico[index].apellido,"\n<2-50 caract>\nIngrese apellido: ","\nError. Reingrese",2,50,2)!=-1)
            {
                if(getInt(&vecMusico[index].edad,"\n<18-60>\nIngrese edad: ","\nError. Reingrese",18,60,2)!=-1)
                {
                    imprimirOrquestas(vecOrquesta,tOrq,vecTipoOrquesta,tamTipoOrq);

                    if(getInt(&vecMusico[index].idOrquesta,"\n<1-10>\nIngrese ID de la orquesta a la que pertenece: ","Error.Reingrese",1,50,2)!=-1)
                    {
                        imprimirInstrumentos(vecInstrumento,tInstru,vecTipoInstrumento,tamTipoInstru);

                        if(getInt(&vecMusico[index].idInstrumento,"\n<101-115>\nIngrese ID del instrumento que va a tocar: ","Error.Reingrese",101,121,2)!=-1)//de 01 a 21 (20 instrumentos en total)
                        {
                            vecMusico[index].id = lastId;
                            vecMusico[index].isEmpty = 0;
                            todoOk = 1;
                            printf("\n--Alta de --Musico-- exitosa--\n\n");
                        }
                    }
                }
            }
        }

    }
    if(todoOk != 1)
    {
        printf("\nError en la carga de datos.\n");
    }
    return todoOk;
}

int buscarMusicoId(eMusico vecMusico[],int tMusic,int idABuscar)
{
    int index = -1;

    for(int i = 0; i<tMusic; i++)
    {
        if(vecMusico[i].isEmpty==0 && vecMusico[i].id == idABuscar)
        {
            index = i;
            //Cuando encuentro el id, rompo el for.
            break;
        }
    }
    return index;
}


int menuModificacion()
{
    int option;
    printf("1 - Modificar edad\n");
    printf("2 - Modificar id de orquesta donde toca\n");
    printf("3 - Salir\n");
    getInt(&option,"\nElija opcion: ","\nError. Ingrese un numero valido",1,3,2);
    return option;
}

int modificarMusico(eMusico vecMusico[],
                    int tMusic,
                    eOrquesta vecOrquesta[],
                    int tOrq,
                    eTipoOrquesta vecTipoOrquesta[],
                    int tamTipoOrq,
                    eInstrumento vecInstrumento[],
                    int tInstru)
{
    int index;
    int idAMod;
    int todoOk = 0;


    system("cls");
    printf("\n--Modificar Musico--\n");

    imprimirMusicos(vecMusico,tMusic,vecOrquesta,tOrq,vecInstrumento,tInstru);

    getInt(&idAMod,"\nIngrese ID a modificar: ","\nError. Reingrese un numero de id valido\n",1000,1999,2);

    index = buscarMusicoId(vecMusico,tMusic,idAMod);

    if(index == -1)
    {
        printf("\nNo existe un Musico con ese ID.\n\n");
    }
    else
    {
        printf("\n\n");
        printf("  ID      NOMBRE       APELLIDO    EDAD\n");
        printf("  --      ------       --------    ----\n\n");
        mostrarUnMusico(vecMusico[index],vecOrquesta,tOrq,vecInstrumento,tInstru);

        switch(menuModificacion())
        {
        case 1:
            if(getInt(&vecMusico[index].edad,"\n<18-60>\nIngrese nueva edad: ","\nError. Reingrese",18,60,2)!=-1)
            {
                todoOk = 1;
                printf("\n..Modificacion exitosa..\n\n");
            }
            break;

        case 2:
            printf("\n");
            imprimirOrquestas(vecOrquesta,tOrq,vecTipoOrquesta,tamTipoOrq);
            if(getInt(&vecMusico[index].idOrquesta,"\n<1-10>\nIngrese nueva orquesta: ","\nError. Reingrese",1,10,2)!=-1)
            {
                todoOk = 1;
                printf("\n..Modificacion exitosa..\n\n");

            }
            /**ACA AGREGAR PARA CAMBIAR EL ID DE ORQUESTA**/

            /*if(getString(vecCliente[index].domicilio,"\n<2-35 caract>\nIngrese nuevo domicilio: ","\nError. Reingrese",2,35,2)!=-1)
            {
                todoOk = 1;
                printf("\n..Modificacion exitosa..\n\n");
            }*/
            break;

        case 3:
            printf("\n..Modificacion cancelada..\n\n...Redireccionando al menu...\n\n");
            break;
        }
    }
    return todoOk;
}


int bajaMusico(eMusico vecMusico[],
               int tMusic,
               eOrquesta vecOrquesta[],
               int tOrq,
               eInstrumento vecInstrumento[],
               int tInstru)
{
    int index;
    int idABajar;
    int todoOk = 0;
    char confirma;

    system("cls");
    printf("\n--Baja Musico--\n");

    imprimirMusicos(vecMusico,tMusic,vecOrquesta,tOrq,vecInstrumento,tInstru);

    getInt(&idABajar,"\nIngrese ID a dar de baja: ","\nError. Reingrese un numero de id valido\n",1000,1999,2);

    index = buscarMusicoId(vecMusico,tMusic,idABajar);

    if(index == -1)
    {
        printf("\nNo existe un Musico con ese ID.");
    }
    else
    {
        printf("\n\n");
        printf("  ID      NOMBRE       APELLIDO    EDAD\n");
        printf("  --      ------       --------    ----\n\n");
        mostrarUnMusico(vecMusico[index],vecOrquesta,tOrq,vecInstrumento,tInstru);

        printf("confirma baja? <s/n>: ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma == 's')
        {
            vecMusico[index].isEmpty = 1;
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

void ordenarPorIdOrquesta(eMusico vecMusico[],int tMusic)
{
    eMusico aux;

    for(int i = 0; i<tMusic-1; i++)
    {
        for(int j = i +1 ; j<tMusic; j++)
        {
            if(vecMusico[i].idOrquesta > vecMusico[j].idOrquesta)
            {
                aux = vecMusico[i];
                vecMusico[i] = vecMusico[j];
                vecMusico[j] = aux;
            }
        }
    }
}

