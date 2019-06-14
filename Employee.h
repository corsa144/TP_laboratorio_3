#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();

void employee_delete();

void employee_setId(Employee* this,int id);
int employee_getId(Employee* this);

void employee_setNombre(Employee* this,char* nombre);
char* employee_getNombre(Employee* this);

void employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this);

void employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this);

Employee* employee_nuevosParametros(char *var1, char *var2, char *var3, char *var4);

#endif // employee_H_INCLUDED
