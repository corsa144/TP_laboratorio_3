#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn_validar.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* ruta , LinkedList* pArrayListEmployee)
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
 * \param path char*
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
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    char idAux[50];
    char nombreAux[50];
    char horasTrabajadasAux[50];
    char sueldoAux[50];
    Employee* pEmpleado;
    int resp=1;
    int cant;
        while (resp == 1){
        cant = ll_len(pArrayListEmployee);
        sprintf(idAux,"%d",cant);
        getString("Ingrese nombre del empleado:\n","Error",0,sizeof(nombreAux),2,nombreAux);
        getString("Ingrese horas trabajadas:\n","Error",0,sizeof(horasTrabajadasAux),2,horasTrabajadasAux);
        getString("Ingrese sueldo del empleado:\n","Error",0,sizeof(sueldoAux),2,sueldoAux);
        pEmpleado = employee_nuevosParametros(idAux,nombreAux,horasTrabajadasAux,sueldoAux);
        ll_add(pArrayListEmployee,pEmpleado);
        utn_getUnsignedInt("Para continuar cargando datos ingrese 1:\n","Error",0,sizeof(resp),0,sizeof(resp),2,&resp);
        system("cls");
   }

    return 0;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int codigo,resp;
    char auxNombre[51];
    float auxSueldo;
    int auxHoras;
    Employee* puntero;
    utn_getUnsignedInt("\nDesea imprimir la lista? Ingrese 1 para imprimir: ","\nNo se imprimio la lista",
                       0,sizeof(resp),1,sizeof(resp),2,&resp);
    if (resp == 1){
        controller_ListEmployee(pArrayListEmployee);
    }
    utn_getUnsignedInt("\nIngrese el codigo del empleado a modificar: ","\nCodigo incorrecto!",
                           0,sizeof(codigo),0,sizeof(codigo),2,&codigo);
    if (pArrayListEmployee != NULL)
    {
        puntero = ll_get(pArrayListEmployee,codigo);
    utn_getUnsignedInt("1-Para modificar el Nombre\t 2-Para el Sueldo\t 3-Para las Horas Trabajadas\t 4-Todos","Error",
                       0,sizeof(resp),0,sizeof(resp),2,&resp);
        switch(resp){
            case 1:
                getString("\nIngrese el nombre a asignar","Error",0,sizeof(auxNombre),2,&auxNombre);
                employee_setNombre(puntero,auxNombre);
                break;
            case 2:
                utn_getFloat("\nIngrese el sueldo a asignar","Error",0,sizeof(auxSueldo),
                             0,sizeof(auxSueldo),2,&auxSueldo);
                employee_setSueldo(puntero,auxSueldo);
                break;
            case 3:
                utn_getUnsignedInt("\nIngrese las horas trabajadas a asignar","Error",0,sizeof(auxHoras),
                                   0,sizeof(auxHoras),2,&auxHoras);
                employee_setHorasTrabajadas(puntero,auxHoras);
                break;
            case 4:
                getString("\nIngrese el nombre a asignar","Error",0,sizeof(auxNombre),2,&auxNombre);
                employee_setNombre(puntero,auxNombre);
                utn_getFloat("\nIngrese el sueldo a asignar","Error",0,sizeof(auxSueldo),
                             0,sizeof(auxSueldo),2,&auxSueldo);
                employee_setSueldo(puntero,auxSueldo);
                utn_getUnsignedInt("\nIngrese las horas trabajadas a asignar","Error",0,sizeof(auxHoras),
                                   0,sizeof(auxHoras),2,&auxHoras);
                employee_setHorasTrabajadas(puntero,auxHoras);
                break;
        }
    }


    return 0;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int cant,codigo,resp;
    Employee* puntero;
    utn_getUnsignedInt("\nDesea imprimir la lista? Ingrese 1 para imprimir: ","Error",
                       0,sizeof(resp),0,sizeof(resp),2,&resp);
        if (resp == 1){
            controller_ListEmployee(pArrayListEmployee);
        }
        utn_getUnsignedInt("\nIngrese el codigo del empleado a borrar: ","Error",
                           0,sizeof(codigo),0,sizeof(codigo),2,&codigo);
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
    return 0;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i,cant;
    int idAux[50];
    char nombreAux[50];
    int horasTrabajadasAux[50];
    float sueldoAux[50];
    cant = ll_len(pArrayListEmployee);
    Employee* lista;
    for (i=1;i<cant;i++){
        lista = (Employee*)ll_get(pArrayListEmployee,i);
        printf("%d\t %s\t %d\t %.2f\n",employee_getId(lista,idAux),employee_getNombre(lista, nombreAux),
               employee_getHorasTrabajadas(lista, horasTrabajadasAux),employee_getSueldo(lista, *sueldoAux));
    }
    return 0;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;
    ll_sort(pArrayListEmployee,ordenarSueldo,1);
    controller_ListEmployee(pArrayListEmployee);

    return 0;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
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
        fprintf(pArchivo,"%d,%s,%d,%.2f\n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
        total++;
        }
    printf("\nSe escribieron %d caracteres\n\n", total);
    }
    fclose(pArchivo);
    return 0;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
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
        fprintf(pArchivo,"%d,%s,%d,%.2f\n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
        total++;
        }
    printf("\nSe escribieron %d caracteres\n\n", total);
    }
    fclose(pArchivo);
    return 1;
}

