
//-------------------------LECTURA--------------------------------------

int controller_Rivero_loadFromText(char* path, LinkedList* pArrayList);

int controller_Rivero_loadFromText_Pilotos(char* path, LinkedList* pArrayList);

int controller_Rivero_loadFromBinary(char* path, LinkedList* pArrayList);

//-----------------------------------------------------------------------

int controller_Rivero_ListGenerico(LinkedList* pArrayList, LinkedList* this);

int controller_Rivero_ListPilotos(LinkedList* this);

LinkedList* crear_hardCodeoPilotos();

int controller_Rivero_PasajerosTotales(LinkedList* this);

int controller_Rivero_PasajerosIrlanda(LinkedList* this);

int controller_Rivero_VuelosCortos(LinkedList* this);

int controller_Rivero_VuelosPortugal(LinkedList* this,LinkedList* this2 );

int controller_Rivero_FiltrarLifeson(LinkedList* this,LinkedList* this2);

int controller_Rivero_PasajerosTotales(LinkedList* this);

int controller_Rivero_FiltrarPorNombreElegido(LinkedList* this, LinkedList* this2);



//--------------------------GUARDADO----------------------------

int controller_Rivero_saveAsText(char* path , LinkedList* pArrayList);

int controller_Rivero_saveAsBinary(char* path , LinkedList* pArrayList);

//-----------------------------------------------------------------

