#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
void employee_delete();

void employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

void employee_setNombre(Employee* this,char* nombre);
char* employee_getNombre(Employee* this,char* nombre);

void employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

void employee_setSueldo(Employee* this,int sueldo);
float employee_getSueldo(Employee* this,float sueldo);

int ordenarSueldo(Employee* empleadoUno,Employee* empleadoDos);

#endif // employee_H_INCLUDED
