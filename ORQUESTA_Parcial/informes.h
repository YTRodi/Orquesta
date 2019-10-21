
int menuInformes();

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

void listarMusicosCuerdas(eMusico vecMusico[],int tMusic,
                           eOrquesta vecOrquesta[],int tOrq,
                           eInstrumento vecInstrumento[],int tInstru,
                           eTipoInstru vecTipoInstrumento[],int tamTipoInstru);

void ordenarGuitarristasPorApellidoOApellidoYNombre(eMusico vecMusico[],int tMusic);

void imprimirPromedioDeMusicosPorOrquesta(eMusico vecMusico[], int tMusic, eOrquesta vecOrquesta[], int tOrq);
