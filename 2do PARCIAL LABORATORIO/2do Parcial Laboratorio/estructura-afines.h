
typedef struct
{
    int idPiloto;
    char nombrePiloto[21];
}sPilotos;

typedef struct
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[21];
    char destino[21];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
}sVuelo;

//-----------------------CONSTRUCTORES-----------------------------

sVuelo* generico_new();

sPilotos* generico_new2();

sVuelo* generico_newParametros(int* integro,int* integro2,int* integro3,char* cadena, char* cadena2,int* integro4,int* integro5,int* integro6);

sPilotos* generico_newParametros2(int integro,char cadena[]);

//----------------------------------------------------------------------


//---------------------------SETTERS Y GETTERS-------------------------------------
int generico_setIdVuelo(sVuelo* Generico,int integro);

int generico_getIdVuelo(sVuelo* Generico,int* integro);

int generico_setIdAvion(sVuelo* Generico,int integro);

int generico_getIdAvion(sVuelo* Generico,int* integro);

int generico_setIdPiloto(sVuelo* Generico,int integro);

int generico_getIdPiloto(sVuelo* Generico,int* integro);

int generico_setFecha(sVuelo* Generico,char* cadena);

int generico_getFecha(sVuelo* Generico,char* cadena);

int generico_setDestino(sVuelo* Generico,char* cadena);

int generico_getDestino(sVuelo* Generico,char* cadena);

int generico_setCantPasajeros(sVuelo* Generico,int integro);

int generico_getCantPasajeros(sVuelo* Generico,int* integro);

int generico_setHoraDespegue(sVuelo* Generico,int integro);

int generico_getHoraDespegue(sVuelo* Generico,int* integro);

int generico_getHoraLlegada(sVuelo* Generico,int* integro);

int generico_setHoraLlegada(sVuelo* Generico,int integro);

int generico_setNombrePiloto_sPilotos(sPilotos* Generico,char* cadena);

int generico_getNombrePiloto_sPilotos(sPilotos* Generico,char* cadena);

int generico_setIdPiloto_sPilotos(sPilotos* Generico,int integro);

int generico_getIdPiloto_sPilotos(sPilotos* Generico,int* integro);

//----------------------------------------------------------------------------------------


//-------------------FUNCIONES CRITERIO-------------------------------

int generico_CompareById(void* e1, void* e2);

int generico_CompareByName(void* e1, void* e2);

int generico_countTotales(void* e1);

int generico_countEspecifico(void* e1);

int generico_filtroMenorATres(void*e1);

int generico_filtroAUnLugar(void* e1);

int generico_filtroPorNombre(void* e1);

int generico_filtroPorNombreElegido(void* e1,char* cadena);

//--------------------------------------------------------------------------
