#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pArchivo , LinkedList* pArrayListEmployee)
{
    int r,i=0;
    if (pArchivo == NULL){
        printf ("Error al leer el archivo txt");
    }
    else{
        char var1[50],var3[50],var2[50],var4[50];

        do{
            r = fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
            if(r==4){
                Employee* p = employee_nuevosParametros(var1, var2, var3, var4);
                i++;
                ll_add(pArrayListEmployee,p);
            }
            else{
                break;
            }
        }while( !feof(pArchivo));
    }
    return i;
}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pArchivo , LinkedList* pArrayListEmployee)
{
    int r,i;
    Employee* pBinario;
    if (pArchivo == NULL){
        printf ("Error al leer el archivo bin");
    }
    else{
        char var1[50],var3[50],var2[50],var4[50];
        do{
            r = fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
            if(r==4){
                pBinario = employee_nuevosParametros(var1, var2, var3, var4);
                i++;
                ll_add(pArrayListEmployee,pBinario);
            }
            else{
                break;
            }
        }while( !feof(pArchivo));
    }
    return i;
}
