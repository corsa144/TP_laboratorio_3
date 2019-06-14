#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(char* ruta , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* ruta , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* ruta , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* ruta , LinkedList* pArrayListEmployee);
int menu(void);


#endif // CONTROLLER_H_INCLUDED


