#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "Musico.h"
#include "Orquesta.h"
#include "Instrumento.h"

#define TAMORQ 11
#define TAMMUSIC 28
#define TAMINSTRU 15
#define TAMTIPOORQ 3
#define TAMTIPOINSTRU 4


int menuGeneralTeatro();

void listarOrquestasConMasDe5Musicos(eOrquesta vecOrquesta[],int tOrq,eTipoOrquesta vecTipoOrquesta[],int tamTipoOrq,eMusico vecMusico[],int tMusic);

int pedirMusicos(int idAIgualar,eMusico vecMusico[],int tMusic);

void listarMusicosMayoresA30(eOrquesta vecOrquesta[],int tOrq,eMusico vecMusico[],int tMusic,eInstrumento vecInstrumento[],int tInstru);

void listarOrquestaLugarSeleccionado(eOrquesta vecOrquesta[],int tOrq,eTipoOrquesta vecTipoOrquesta[],int tamTipoOrq);

void listarOrquestasCompletas(eOrquesta vecOrquesta[],int tOrq,
                              eTipoOrquesta vecTipoOrquesta[],int tamTipoOrq,
                              eMusico vecMusico[],int tMusic,
                              eInstrumento vecInstrumento[],int tInstru,
                              eTipoInstru vecTipoInstru[],int tamTipoInstru);

int buscarOrquestaLugar(eOrquesta vecOrquesta[],int tOrq,char lugarABuscar[]);

void listarMusicosDeUnaOrquestaSeleccionada(eOrquesta vecOrquesta[],int tOrq,
                                           eTipoOrquesta vecTipoOrquesta[],int tamTipoOrq,
                                           eMusico vecMusico[],int tMusic,
                                           eInstrumento vecInstrumento[],int tInstru,
                                           eTipoInstru vecTipoInstrumento[],int tamTipoInstrru);

void orquestaConMasMusicos(eOrquesta vecOrquesta[],int tOrq,
                           eTipoOrquesta vecTipoOrquesta[],int tamTipoOrq,
                           eMusico vecMusico[],int tMusic,
                           eInstrumento vecInstrumento[],int tInstru,
                           eTipoInstru vecTipoInstrumento[],int tamTipoInstrru);

int cantidadMusicosOrquesta(eMusico vecMusico[], int tMusic,int idOrquesta);

void listarMusicosGuitarra(eMusico vecMusico[],int tMusic,
                           eOrquesta vecOrquesta[],int tOrq,
                           eInstrumento vecInstrumento[],int tInstru,
                           eTipoInstru vecTipoInstrumento[],int tamTipoInstru);

void ordenarGuitarristasPorApellidoOApellidoYNombre(eMusico vecMusico[],int tMusic);

void imprimirPromedioDeMusicosPorOrquesta(eMusico vecMusico[], int tMusic, eOrquesta vecOrquesta[], int tOrq);

void totalMusicos(eMusico vecMusico[],int tMusic);

int main()
{
    eOrquesta arrayOrquesta[TAMORQ];
    eTipoOrquesta arrayTipoOrquesta[TAMTIPOORQ];
    eMusico arrayMusico[TAMMUSIC];
    eInstrumento arrayInstrumento[TAMINSTRU];
    eTipoInstru arrayTipoInstrumento[TAMTIPOINSTRU];

    char exit = 'n';

    int idOrquesta = 1;
    int idMusico = 1000;
    int idInstrumento = 100;

    inicializarOrquesta(arrayOrquesta,TAMORQ);
    inicializarMusico(arrayMusico,TAMMUSIC);
    inicializarInstrumento(arrayInstrumento,TAMINSTRU);

    idOrquesta = idOrquesta + hardCodearOrquestas(arrayOrquesta,TAMORQ);
    hardCodearTipoOrquesta(arrayTipoOrquesta,TAMTIPOORQ);
    idMusico = idMusico + hardCodearMusicos(arrayMusico,TAMMUSIC);
    idInstrumento = idInstrumento + hardCodearInstrumento(arrayInstrumento,TAMINSTRU);
    hardCodearTipoInstrumento(arrayTipoInstrumento,TAMTIPOINSTRU);

    do
    {
        switch(menuGeneralTeatro())
        {
            case 1:
                if(altaOrquestaMaestra(arrayOrquesta,TAMORQ,idOrquesta,arrayTipoOrquesta,TAMTIPOORQ))
                {
                    idOrquesta++;
                }
                break;

            case 2:
                bajaOrquesta(arrayOrquesta,TAMORQ,arrayTipoOrquesta,TAMTIPOORQ);
                break;

            case 3:
                imprimirOrquestas(arrayOrquesta,TAMORQ,arrayTipoOrquesta,TAMTIPOORQ);
                break;

            case 4:
                if(altaMusicoMaestra(arrayMusico,TAMMUSIC,idMusico,arrayOrquesta,TAMORQ,arrayTipoOrquesta,TAMTIPOORQ,arrayInstrumento,TAMINSTRU,arrayTipoInstrumento,TAMTIPOINSTRU))
                {
                    idMusico++;
                }
                break;

            case 5:
                modificarMusico(arrayMusico,TAMMUSIC,arrayOrquesta,TAMORQ,arrayTipoOrquesta,TAMTIPOORQ,arrayInstrumento,TAMINSTRU);
                break;

            case 6:
                bajaMusico(arrayMusico,TAMMUSIC,arrayOrquesta,TAMORQ,arrayInstrumento,TAMINSTRU);
                break;

            case 7:
                ordenarPorIdOrquesta(arrayMusico,TAMMUSIC);
                imprimirMusicos(arrayMusico,TAMMUSIC,arrayOrquesta,TAMORQ,arrayInstrumento,TAMINSTRU);
                break;

            case 8:
                if(altaInstrumentoMaestra(arrayInstrumento,TAMINSTRU,idInstrumento,arrayTipoInstrumento,TAMTIPOINSTRU))
                {
                    idInstrumento++;
                }
                break;

            case 9:
                imprimirInstrumentos(arrayInstrumento,TAMINSTRU,arrayTipoInstrumento,TAMTIPOINSTRU);
                break;

            case 10:
                listarOrquestasConMasDe5Musicos(arrayOrquesta,TAMORQ,arrayTipoOrquesta,TAMORQ,arrayMusico,TAMMUSIC);
                break;
            case 12:
                listarMusicosMayoresA30(arrayOrquesta,TAMORQ,arrayMusico,TAMMUSIC,arrayInstrumento,TAMINSTRU);
                break;

            case 13:
                listarOrquestaLugarSeleccionado(arrayOrquesta,TAMORQ,arrayTipoOrquesta,TAMTIPOORQ);
                break;

            case 14:
                listarOrquestasCompletas(arrayOrquesta,TAMORQ,arrayTipoOrquesta,TAMTIPOORQ,arrayMusico,TAMMUSIC,arrayInstrumento,TAMINSTRU,arrayTipoInstrumento,TAMTIPOINSTRU);
                break;

            case 15:
                listarMusicosDeUnaOrquestaSeleccionada(arrayOrquesta,TAMORQ,arrayTipoOrquesta,TAMTIPOORQ,arrayMusico,TAMMUSIC,arrayInstrumento,TAMINSTRU,arrayTipoInstrumento,TAMTIPOINSTRU);
                break;

            case 16:
                orquestaConMasMusicos(arrayOrquesta,TAMORQ,arrayTipoOrquesta,TAMTIPOORQ,arrayMusico,TAMMUSIC,arrayInstrumento,TAMINSTRU,arrayTipoInstrumento,TAMTIPOINSTRU);
                break;

            case 17:
                listarMusicosGuitarra(arrayMusico,TAMMUSIC,arrayOrquesta,TAMORQ,arrayInstrumento,TAMINSTRU,arrayTipoInstrumento,TAMTIPOINSTRU);
                break;

            case 18:
                imprimirPromedioDeMusicosPorOrquesta(arrayMusico,TAMMUSIC,arrayOrquesta,TAMORQ);
                break;

            case 11:
                printf("Confirma salir? <s/n>: ");
                fflush(stdin);
                exit = getche();
                printf("\n\n");
                break;

            case 20:
                imprimirTiposOrquestas(arrayTipoOrquesta,TAMTIPOORQ);
                break;

            default:
                printf("\n\n...Usted no ingreso una opcion valida...");
                printf("\n\n...--Redireccionando al menu--...\n\n");
        }
        system("pause");

    }
    while(exit == 'n');

    return 0;
}

int menuGeneralTeatro()
{
    int option;
    system("cls");
    printf("..::Bienvenido al menu de teatro::..\n\n");
    printf("1 - Alta Orquesta\n");
    printf("2 - Eliminar Orquesta\n");
    printf("3 - Imprimir Orquestas\n");
    printf("4 - Alta Musico\n");
    printf("5 - Modificar Musico\n");
    printf("6 - Baja Musico\n");
    printf("7 - Imprimir Musicos\n");
    printf("8 - Alta Instrumento\n");
    printf("9 - Imprimir Instrumentos\n");
    printf("10 - imprimir orquesta con mas de 5 musicos\n");
    printf("12 - imprimir musicos con mas de 30 anios\n");
    printf("13 - imprimir orquestas lugar seleccionado\n");
    printf("14 - imprimir orquestas completas\n");
    printf("15 - imprimir musicos de una orquesta seleccionada\n");
    printf("16 - imprimir orquesta con mas musicos\n");
    printf("17 - listar musicos que toquen instrumentos de cuerdas\n");
    printf("18 - imprimir promedio de musicos por orquesta\n");
    printf("11 - Salir\n");
    printf("20 - Imprimir tipo de orquesta\n");
    getInt(&option,"\nIngrese opcion: ","\nError.Opcion no valida",1,99,2);
    return option;
}


void listarOrquestasConMasDe5Musicos(eOrquesta vecOrquesta[],int tOrq,eTipoOrquesta vecTipoOrquesta[],int tamTipoOrq,eMusico vecMusico[],int tMusic)
{
    //int contador;
    int todoOk = 0;
    printf("\n");
    printf("..::LAS ORQUESTAS CON MAS DE 5 MUSICOS SON::..\n\n");
    printf("  ID      NOMBRE       LUGAR           TIPO\n");
    printf("  --      ------       -----           ----\n\n");

    for(int i = 0; i<tOrq;i++)
    {
        if(vecOrquesta[i].isEmpty == 0)
        {
            if(pedirMusicos(vecOrquesta[i].id,vecMusico,tMusic)>=5)
            {
                mostrarUnaOrquesta(vecOrquesta[i],vecTipoOrquesta,tamTipoOrq);
                todoOk = 1;
            }
        }
    }
    if(todoOk == 0)
    {
        printf("\nNo hay orquestas con mas de 5 musicos\n\n");
    }

}

int pedirMusicos(int idAIgualar,eMusico vecMusico[],int tMusic)
{
    int contador = 0;

    for(int i = 0; i<tMusic;i++)
    {
        //aca estoy relacionando el idAigualar con el ID de quien mechear.

        if(idAIgualar == vecMusico[i].idOrquesta && vecMusico[i].isEmpty == 0)
        {
            contador++;
        }
    }
    return contador;
}


void listarMusicosMayoresA30(eOrquesta vecOrquesta[],int tOrq,eMusico vecMusico[],int tMusic,eInstrumento vecInstrumento[],int tInstru)
{
    /*
    -recorrer los musicos,
    -verifico si isemtpy == 0
    -recorro orquestas
    -virifico si el vecMusico[i].idOrquesta es igual al vecOrquesta[j].id && vecOrquesta[j].isempty == 0 (osea si esta dado de alta)
    -recorro instrrumentos
    -verifico si el vecMusico[i].idInstrumento  es igual al vecInstrumento[k].id && vecInstrumento[k].isempty == 0
    -si vecMusico[i].edad >= 30
    -si se cumple todo eso llamo a mostrarunmusico
    */

    int flag = 0;

    printf("\n");
    printf("  ID      NOMBRE       APELLIDO    EDAD    ORQUESTA   INSTRUMENTO\n");
    printf("  --      ------       --------    ----    --------   -----------\n\n");

    for(int i = 0; i<tMusic;i++)
    {
        if(vecMusico[i].isEmpty==0)
        {
            for(int j = 0;j<tOrq;j++)
            {
                if(vecMusico[i].idOrquesta == vecOrquesta[j].id && vecOrquesta[j].isEmpty == 0)
                {
                    for(int k = 0; k<tInstru;k++)
                    {
                        if(vecMusico[i].idInstrumento == vecInstrumento[k].id && vecInstrumento[k].isEmpty == 0)
                        {
                            if(vecMusico[i].edad>=30)
                            {
                                mostrarUnMusico(vecMusico[i],vecOrquesta,tOrq,vecInstrumento,tInstru);
                                flag = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    if(flag == 0)
    {
        printf("\nNo hay musicos mayores a 30 anios.\n\n");
    }
}

void listarOrquestaLugarSeleccionado(eOrquesta vecOrquesta[],int tOrq,eTipoOrquesta vecTipoOrquesta[],int tamTipoOrq)
{
    char lugarABuscar[50];
    int index;

    imprimirOrquestas(vecOrquesta,tOrq,vecTipoOrquesta,tamTipoOrq);

    getNombreOApellido(lugarABuscar,"\nIngrese lugar a buscar: ","\nError.Reingrese",2,50,2);

    index = buscarOrquestaLugar(vecOrquesta,tOrq,lugarABuscar);

    if(index == -1)
    {
        printf("\nNo existen orquestas en ese lugar.\n");
    }
    else
    {
        printf("\n");
        printf("         ..::LAS ORQUESTAS SON::..\n\n");
        printf("  ID      NOMBRE       LUGAR           TIPO\n");
        printf("  --      ------       -----           ----\n\n");
        for(int i = 0; i<tOrq;i++)
        {
            if(strcmpi(vecOrquesta[i].lugar,lugarABuscar) == 0 && vecOrquesta[i].isEmpty == 0)
            {
                mostrarUnaOrquesta(vecOrquesta[i],vecTipoOrquesta,tamTipoOrq);
            }
        }
    }
}

int buscarOrquestaLugar(eOrquesta vecOrquesta[],int tOrq,char lugarABuscar[])
{
    int index = -1;

    for(int i = 0; i<tOrq;i++)
    {
        if(vecOrquesta[i].isEmpty==0 && strcmpi(vecOrquesta[i].lugar,lugarABuscar)== 0)
        {
            index = i;
            //Cuando encuentro el lugar, rompo el for.
            break;
        }
    }
    return index;
}

void listarOrquestasCompletas(eOrquesta vecOrquesta[],int tOrq,
                              eTipoOrquesta vecTipoOrquesta[],int tamTipoOrq,
                              eMusico vecMusico[],int tMusic,
                              eInstrumento vecInstrumento[],int tInstru,
                              eTipoInstru vecTipoInstru[],int tamTipoInstru)
{
    /***FUNCA MAS O MENOS**/
    int contadorCuerdas = 0;
    int contadorVientos = 0;
    int contadorPercusion = 0;

    for(int i = 0;i<tOrq;i++)
    {
        if(vecOrquesta[i].isEmpty == 0)
        {
            for(int j = 0;j<tMusic;j++)
            {
                if(vecMusico[j].idOrquesta == vecOrquesta[i].id && vecMusico[j].isEmpty == 0)
                {
                    for(int k = 0;k<tInstru;k++)
                    {
                        if(vecMusico[j].idInstrumento == vecInstrumento[k].id && vecInstrumento[k].isEmpty == 0)
                        {
                            if(vecInstrumento[k].tipo == 1)
                            {
                                contadorCuerdas++;
                            }
                            if(vecInstrumento[k].tipo == 2 || vecInstrumento[k].tipo == 3)
                            {
                                contadorVientos++;
                            }
                            if(vecInstrumento[k].tipo == 4)
                            {
                                contadorPercusion++;
                            }
                        }
                    }
                }
            }
        }

        if(contadorCuerdas>=5 && contadorVientos>=3 && contadorPercusion>=2)
        {
            mostrarUnaOrquesta(vecOrquesta[i],vecTipoOrquesta,tamTipoOrq);
        }
    }










}


void listarMusicosDeUnaOrquestaSeleccionada(eOrquesta vecOrquesta[],int tOrq,
                                           eTipoOrquesta vecTipoOrquesta[],int tamTipoOrq,
                                           eMusico vecMusico[],int tMusic,
                                           eInstrumento vecInstrumento[],int tInstru,
                                           eTipoInstru vecTipoInstrumento[],int tamTipoInstrru)
{
    int idABuscar;
    int index;
    int flag = 0;

    printf("\n**MUSICOS POR ORQUESTA SELECCIONADA**\n");

    imprimirOrquestas(vecOrquesta,tOrq,vecTipoOrquesta,tamTipoOrq);
    getInt(&idABuscar,"\nIngrese ID de la Orquesta: ","\nError. Reingrese un numero de id valido\n",1,10,2);

    index = buscarOrquestaId(vecOrquesta,tOrq,idABuscar);

    if(index == -1)
    {
        printf("\nNo existe una Orquesta con ese ID.\n");
    }
    else
    {
        printf("\n");
        printf("  ID      NOMBRE       APELLIDO    EDAD    ORQUESTA   INSTRUMENTO\n");
        printf("  --      ------       --------    ----    --------   -----------\n\n");

        //recorro los musicos
        for(int i = 0; i<tMusic;i++)
        {
            if(vecMusico[i].idOrquesta == idABuscar && vecMusico[i].isEmpty == 0)
            {
                mostrarUnMusico(vecMusico[i],vecOrquesta,tOrq,vecInstrumento,tInstru);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("\nEsta orquesta no tiene musicos.\n\n");
        }
    }
}

void orquestaConMasMusicos(eOrquesta vecOrquesta[],int tOrq,
                           eTipoOrquesta vecTipoOrquesta[],int tamTipoOrq,
                           eMusico vecMusico[],int tMusic,
                           eInstrumento vecInstrumento[],int tInstru,
                           eTipoInstru vecTipoInstrumento[],int tamTipoInstrru)
{

    int cantidadesOrquesta[tOrq];//EN ESTA VARIABLE RETORNA LA CANTIDAD
    int mayor;//SI ESTA TODO OK, LE ASIGNO LAS CANTIDADES AL MAYOR
    int flag = 0;

    //char descripcionOrquesta[50];//SE COPIA EL NOMBRE DE LA ORQUESTA ACA.

    for(int i = 0; i<tOrq;i++)
    {
        cantidadesOrquesta[i] = cantidadMusicosOrquesta(vecMusico,tMusic,vecOrquesta[i].id);
    }

    for(int i = 0; i<tOrq;i++)
    {
        if(mayor < cantidadesOrquesta[i] || flag == 0)
        {
            mayor = cantidadesOrquesta[i];
            flag = 1;
        }
    }

    for(int i = 0; i<tOrq;i++)
    {
        if(cantidadesOrquesta[i] == mayor)
        {
            //cargarNombreOrquesta(vecOrquesta,tOrq,vecOrquesta[i].id,descripcionOrquesta);

            printf("\n");
            printf("   ..::LAS ORQUESTA CON MAS MUSICOS ES::..\n\n");
            printf("  ID      NOMBRE       LUGAR           TIPO\n");
            printf("  --      ------       -----           ----\n\n");

            mostrarUnaOrquesta(vecOrquesta[i],vecTipoOrquesta,tamTipoOrq);

            printf("\n");
            printf("   ..::LA CANTIDAD DE MUSICOS ES DE::..\n\n");
            printf("\t            %d\n\n",mayor);
            //printf("\nOrquesta: %s\ncantidad: %d\n\n",descripcionOrquesta,mayor);
        }
    }
}

int cantidadMusicosOrquesta(eMusico vecMusico[], int tMusic,int idOrquesta)
{
    int cantidad = 0;

    for(int i= 0; i < tMusic; i++ )
    {
        //Si el vector de musico esta dado de alta y el vector de musico.idOrquesta es igual al vecOrquesta.id --> cantidad++
        if(vecMusico[i].isEmpty == 0 && vecMusico[i].idOrquesta == idOrquesta)
        {
            cantidad++;
        }
    }
    return cantidad;
}


void listarMusicosGuitarra(eMusico vecMusico[],int tMusic,
                           eOrquesta vecOrquesta[],int tOrq,
                           eInstrumento vecInstrumento[],int tInstru,
                           eTipoInstru vecTipoInstrumento[],int tamTipoInstru)
{

    char nombreTipoInstrumento[50];//EN ESTA VARIABLE CARGO EL NOMBRE DEL INSTRUMENTO
    int flag = 0;

    printf("\n");
    printf("  ID      NOMBRE       APELLIDO    EDAD    ORQUESTA   INSTRUMENTO\n");
    printf("  --      ------       --------    ----    --------   -----------\n\n");

    for(int i = 0; i<tMusic;i++)
    {
        if(vecMusico[i].isEmpty == 0)
        {
            for(int j = 0 ; j<tInstru;j++)
            {
                if(vecMusico[i].idInstrumento == vecInstrumento[j].id && vecInstrumento[j].isEmpty == 0)
                {
                    cargarDescripcionTipoInstrumento(vecTipoInstrumento,tamTipoInstru,vecInstrumento[j].tipo,nombreTipoInstrumento);

                    if(strcmpi(nombreTipoInstrumento,"cuerdas")==0)
                    {
                        ordenarGuitarristasPorApellidoOApellidoYNombre(vecMusico,tMusic);
                        mostrarUnMusico(vecMusico[i],vecOrquesta,tOrq,vecInstrumento,tInstru);
                        flag = 1;
                    }
                }
            }
        }
    }
    if(flag == 0)
    {
        printf("\nNo hay musicos que toquen el instrumentos de cuerdas.\n\n");
    }
}


void ordenarGuitarristasPorApellidoOApellidoYNombre(eMusico vecMusico[],int tMusic)
{
    eMusico auxMusico;

    for(int i = 0; i<tMusic-1;i++)
    {
        for(int j = i+1;j<tMusic;j++)
        {
            if(strcmpi(vecMusico[i].apellido,vecMusico[j].apellido)>0)
            {
                auxMusico = vecMusico[i];
                vecMusico[i] = vecMusico[j];
                vecMusico[j] = auxMusico;
            }
        }
    }
}


void imprimirPromedioDeMusicosPorOrquesta(eMusico vecMusico[], int tMusic, eOrquesta vecOrquesta[], int tOrq)
{
    int contador = 0;
    int acumulador = 0;
    float resultado;

    for(int i = 0; i<tMusic;i++)
    {
        if(vecMusico[i].isEmpty == 0)
        {
            acumulador++;//musicos
        }
    }

    for(int i = 0; i<tOrq;i++)
    {
        if(vecOrquesta[i].isEmpty == 0)
        {
            contador++;//orquestas
        }
    }

    resultado = (float) acumulador/contador;

    printf("\n        ...::DATOS::..\n");
    printf("\nEl total de musicos es de : %d\n\n",acumulador);
    printf("\nEl total de orquestas es de : %d\n\n",contador);

    printf("\nEl promedio de musicos por orquesta es : %.2f\n\n",resultado);

}






