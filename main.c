#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn_validar.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int opcion = 0;
    int bandera = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
            utn_getUnsignedInt("Menu trabajo practico numero 3\n"
"Seleccione 1- Para cargar los datos de los empleados en modo texo\n"
"Seleccione 2- Para cargar los datos de los empleados en modo binario\n"
"Seleccione 3- Para dar de alta un empleado\n"
"Seleccione 4- Para modificar los datos de un empleado\n"
"Seleccione 5- Para dar de baja un empleado\n"
"Seleccione 6- Para imprimir la lista de empleados\n"
"Seleccione 7- Para ordenar la lista de empleados\n"
"Seleccione 8- Para guardar los datos de los empleados en modo texto\n"
"Seleccione 9- Para guardar los datos de los empleados en modo binario\n"
"Seleccione 10- Para salir del programa\n"
"Opcion elegida: ","Error\n",0,sizeof(int),1,sizeof(opcion),2,&opcion);
        switch(opcion)
        {
            case 1:
                system("cls");
                if (bandera == 1){
                    printf ("\n\nSolo se puede cargar una vez\n\n");
                }else{
                    controller_loadFromText("data.csv",listaEmpleados);
                }
                bandera = 1;
                break;
            case 2:
                system("cls");
                if (bandera == 1){
                    printf ("\n\nSolo se puede cargar una vez\n\n");
                }else{
                    controller_loadFromBinary("data.bin",listaEmpleados);
                }
                bandera = 1;

                break;
            case 3:
                if (bandera == 1){
                system("cls");
                controller_addEmployee(listaEmpleados);
                }
                break;
            case 4:
                if (bandera == 1){
                system("cls");
                controller_editEmployee(listaEmpleados);
                }
                break;
            case 5:
                if (bandera == 1){
                system("cls");
                controller_removeEmployee(listaEmpleados);
                }
                break;
            case 6:
                if (bandera == 1){
                system("cls");
                controller_ListEmployee(listaEmpleados);
                system("pause");
                system("cls");
                }
                break;
            case 7:
                system("cls");
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                system("cls");
                controller_saveAsText("data.csv",listaEmpleados);
                break;
            case 9:
                system("cls");
                controller_saveAsBinary("data.bin",listaEmpleados);
                break;
            case 10:
                break;
        }
    }while(opcion != 10);
    return 0;
}
