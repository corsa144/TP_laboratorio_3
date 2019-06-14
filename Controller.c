#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"
#include "controller.h"

int menu(void){
int option;
printf("Menu trabajo practico numero 3\n");
printf("Seleccione 1- Para cargar los datos de los empleados en modo texo\n");
printf("Seleccione 2- Para cargar los datos de los empleados en modo binario\n");
printf("Seleccione 3- Para dar de alta un empleado\n");
printf("Seleccione 4- Para modificar los datos de un empleado\n");
printf("Seleccione 5- Para dar de baja un empleado\n");
printf("Seleccione 6- Para imprimir la lista de empleados\n");
printf("Seleccione 7- Para ordenar la lista de empleados\n");
printf("Seleccione 8- Para guardar los datos de los empleados en modo texto\n");
printf("Seleccione 9- Para guardar los datos de los empleados en modo binario\n");
printf("Seleccione 10- Para salir del programa\n");
printf("Opcion elegida: ");
scanf("%d",&option);
return option;
}





/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param ruta char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* ruta, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    pArchivo = fopen(ruta,"r+");
    if(pArchivo == NULL){
        printf("Error al leer el archivo");
    }
    else{
        parser_EmployeeFromText(pArchivo,pArrayListEmployee);
        printf("\n\nDatos cargados con Exito!\n\n");
    }
    fclose(pArchivo);
    return 0;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param ruta char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_loadFromBinary(char* ruta , LinkedList* pArrayListEmployee)
{
FILE* pArchivo;
    if((pArchivo = fopen(ruta,"r+b")) == NULL){
        printf("Error al abrir el archivo");
    }
    else{
    parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
    printf("\n\nDatos cargados con Exito!\n\n");
    }
    fclose(pArchivo);
return 0;
}


/** \brief Alta de empleados
 *
 * \param ruta char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
   Employee* pB;
   int resp,cant;
   char var1[50],var3[50],var2[50],var4[50];
   resp = 1;
   while (resp == 1){
        cant = ll_len(pArrayListEmployee);
        sprintf(var1,"%d",cant);
        printf("\nIngrese el nombre del empleado: ");
        fflush(stdin);
        getString(var2);
        printf("\nIngrese las horas trabajadas del empleado: ");
        fflush(stdin);
        getString(var3);
        printf("\nIngrese el sueldo del empleado: ");
        fflush(stdin);
        getString(var4);
        pB = employee_nuevosParametros(var1,var2,var3,var4);
        ll_add(pArrayListEmployee,pB);
        printf("\nPara continuar ingresando datos ingrese 1 : ");
        getInt(&resp);
        system("cls");
   }
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param ruta char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int codigo,resp;
    char auxNombre[51];
    int auxSueldo,auxHoras;
    Employee* puntero;
    printf ("\nDesea imprimir la lista? Ingrese 1 para imprimir: ");
        getInt(&resp);
        if (resp == 1){
            controller_ListEmployee(pArrayListEmployee);
        }
    printf ("\nIngrese el codigo del empleado a modificar: ");
    getInt(&codigo);
    if (pArrayListEmployee != NULL){
        puntero = ll_get(pArrayListEmployee,codigo);
        printf("1-Para modificar el Nombre\t 2-Para el Sueldo\t 3-Para las Horas Trabajadas");
        getInt(&resp);
        switch(resp){
            case 1:
                printf("\nIngrese el nombre a asignar");
                getString(auxNombre);
                employee_setNombre(puntero,auxNombre);
                break;
            case 2:
                printf("\nIngrese el sueldo a asignar");
                getInt(&auxSueldo);
                employee_setSueldo(puntero,auxSueldo);
                break;
            case 3:
                printf("\nIngrese las horas trabajadas a asignar");
                getInt(&auxHoras);
                employee_setHorasTrabajadas(puntero,auxHoras);
                break;
            case 4:
                printf("\n\nIngrese el nombre a asignar");
                getString(auxNombre);
                employee_setNombre(puntero,auxNombre);
                printf("\n\nIngrese el sueldo a asignar");
                getInt(&auxSueldo);
                employee_setSueldo(puntero,auxSueldo);
                printf("\nIngrese las horas trabajadas a asignar");
                getInt(&auxHoras);
                employee_setHorasTrabajadas(puntero,auxHoras);
                break;
        }
    }


    return 1;
}

/** \brief Baja de empleado
 *
 * \param ruta char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int cant,codigo,resp;
    Employee* puntero;
    printf ("\nDesea imprimir la lista? Ingrese 1 para imprimir: ");
        getInt(&resp);
        if (resp == 1){
            controller_ListEmployee(pArrayListEmployee);
        }
    printf ("\nIngrese el codigo del empleado a borrar: ");
    getInt(&codigo);
    if (pArrayListEmployee != NULL){
        cant = ll_len(pArrayListEmployee);
        if (codigo >0 && codigo <= cant){
            puntero = ll_get(pArrayListEmployee,codigo);
            free(puntero);
            ll_remove(pArrayListEmployee,codigo);
            printf ("\nSe elimino correctamente\n");
            system("pause");
            system("cls");
        }
        else{
            printf("\nEl codigo debe estar entre 1 y %d\n\n",cant);
            system("pause");
            system("cls");
        }
    }
    else{
        printf("\n\nError al eliminar el registro \n\n");
    }
    return 1;
}

/** \brief Listar empleados
 *
 * \param ruta char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i,cant;
    cant = ll_len(pArrayListEmployee);
    Employee* lista;
    for (i=1;i<cant;i++){
        lista = (Employee*)ll_get(pArrayListEmployee,i);
        printf("%d\t %s\t %d\t %d\n",employee_getId(lista),employee_getNombre(lista),employee_getHorasTrabajadas(lista),employee_getSueldo(lista));
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param ruta char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int i,j,len;
    Employee* actualEmpleado;
    Employee* empSiguiente;
    Employee* auxiliar;
    len = ll_len(pArrayListEmployee);
    for (i=1;i<len;i++){
        actualEmpleado = ll_get(pArrayListEmployee,i);
        for(j=i+1;j<len;j++){
            empSiguiente = ll_get(pArrayListEmployee,j);
            if (employee_getSueldo(actualEmpleado) > employee_getSueldo(empSiguiente)){
                auxiliar = actualEmpleado;
                actualEmpleado = empSiguiente;
                empSiguiente = auxiliar;
            }
        }
    }
    return 1;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param ruta char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int controller_saveAsText(char* ruta , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int len,i;
    int total= 0;
    Employee* auxEmpleado;
    len = ll_len(pArrayListEmployee);
    pArchivo = fopen(ruta,"r+");
    if (pArchivo == NULL){
        pArchivo = fopen(ruta,"w+");
    }
    if (len>0){
        for (i=0;i<len;i++){
        auxEmpleado = ll_get(pArrayListEmployee,i);
        fprintf(pArchivo,"%d,%s,%d,%d\n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
        total++;
        }
    printf("\nSe escribieron %d caracteres\n\n", total);
    }
    fclose(pArchivo);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param ruta char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* ruta , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int len,i;
    int total= 0;
    Employee* auxEmpleado;
    len = ll_len(pArrayListEmployee);
    pArchivo = fopen(ruta,"r+b");
    if (pArchivo == NULL){
        pArchivo = fopen(ruta,"w+b");
    }
    if (len>0){
        for (i=0;i<len;i++){
        auxEmpleado = ll_get(pArrayListEmployee,i);
        fprintf(pArchivo,"%d,%s,%d,%d\n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
        total++;
        }
    printf("\nSe escribieron %d caracteres\n\n", total);
    }
    fclose(pArchivo);
    return 1;
}
