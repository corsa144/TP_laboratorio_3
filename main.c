#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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
        opcion = menu();
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
                    controller_loadFromBinary("bin.dat",listaEmpleados);
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
                controller_saveAsText("data.csv", listaEmpleados);
                break;
            case 9:
                system("cls");
                controller_saveAsBinary("bin.dat",listaEmpleados);
                break;
        }
    }while(opcion != 10);

    return 0;
}
