#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

Employee* employee_new(){
    Employee* persona = malloc(sizeof(Employee));
    return persona;
}

Employee* employee_nuevosParametros(char *var1, char *var2, char *var3, char *var4)
{
    int idAux,sueldoAux, horasAux;
    Employee* p = employee_new();
    idAux = atoi(var1);
    horasAux = atoi(var3);
    sueldoAux = atof(var4);
    employee_setId(p, idAux);
    employee_setNombre(p, var2);
    employee_setSueldo(p, sueldoAux);
    employee_setHorasTrabajadas(p, horasAux);
    return p;
}

/********FUNCIONES SET***********/

void employee_setId(Employee* this, int id)
{
    if(id > 0){
        this->id = id;
    }
}

void employee_setNombre(Employee* this, char* nombre)
{
    if(nombre[0] != '\0'){
    strncpy(this->nombre, nombre, sizeof(this->nombre));
    }
}

void employee_setSueldo(Employee* this, int sueldo)
{
    if(sueldo > 0){
        this->sueldo = sueldo;
    }
}

void employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    if(horasTrabajadas > 0){
        this->horasTrabajadas = horasTrabajadas;
    }
}

/*********FUNCIONES GET**********/

int employee_getId(Employee* this, int* id)
{
    if (this != NULL){
        return this->id;
    }
}

char * employee_getNombre(Employee* this, char* nombre)
{
    if(this != NULL){
        return this->nombre;
    }
}

float employee_getSueldo(Employee* this, float sueldo)
{
    if(this != NULL){
        return this->sueldo;
    }
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    if(this != NULL){
        return this->horasTrabajadas;
    }
}

int ordenarSueldo(Employee* empleadoUno,Employee* empleadoDos)
{
    if(empleadoUno->sueldo > empleadoDos->sueldo)
    {
       return 1;
    }
    else if( empleadoUno->sueldo < empleadoDos->sueldo)
    {
        return -1;
    }
    else
    {
        return 0;
    }

}
