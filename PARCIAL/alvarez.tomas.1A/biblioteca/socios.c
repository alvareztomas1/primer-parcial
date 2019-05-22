#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#ifndef socios_H_INCLUDED
#define socios_H_INCLUDED
#include "socios.h"
#endif // socios_H_INCLUDED

#ifndef funciones_H_INCLUDED
#define funciones_H_INCLUDED
#include "funciones.h"
#endif // funciones_H_INCLUDED

#ifndef libros_H_INCLUDED
#define libros_H_INCLUDED
#include "libros.h"
#endif // libros_H_INCLUDED

#ifndef autores_H_INCLUDED
#define autores_H_INCLUDED
#include "autores.h"
#endif // autores_H_INCLUDED

#ifndef prestamos_H_INCLUDED
#define prestamos_H_INCLUDED
#include "prestamos.h"
#endif // prestamos_H_INCLUDED

#ifndef input_H_INCLUDED
#define input_H_INCLUDED
#include "input.h"
#endif // input_H_INCLUDED

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int menu()
{
    int opcion;

    printf("----------ABM----------\n\n");
    printf("1-Alta socio\n");
    printf("2-Modificar socio\n");
    printf("3-Baja socio\n");
    printf("4-Listar socio\n");
    printf("5-Listar libros \n");
    printf("6-Listar autores\n");
    printf("7-Alta prestamo\n");
    printf("8-Listar prestamos\n");
    printf("9-Informes\n");
    printf("10-Salir\n");

    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int subMenu()
{
    int opcion;

    printf("1-Libro menos prestado\n");
    printf("2-Socio que mas solicito\n");
    printf("3-Prestamos de socio con fecha determinada\n");
    printf("4-Prestamo de libros con fecha determinada\n");
    printf("5-Listado socios por libro determinado\n");
    printf("6-Libros libro por socio determinado\n");
    printf("7-Listar libros ordenados\n");
    printf("8-Listar socios ordenados\n");

    getInt(&opcion, "Ingrese opcion: ", "No entra en el rango. Reinrese", 1, 8);

    return opcion;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void inicializarSocios (eSocio soc[], int tamSoc)
{
    for (int i=0;i<tamSoc;i++)
    {
        soc[i].itsEmpty=1;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void hardcode (eSocio soc[], int tamSoc, eAutor aut[], int tamAut, eLibros lib[], int tamLib, ePrestamo pres[], int tamPres)
{
    inicializarSocios(soc, tamSoc);
    inicializarAutores(aut, tamAut);
    inicializarLibros(lib, tamLib);
    inicializarPrestamo(pres, tamPres);

    /*eSocio lista[]=
    {
        {0, "Alvarez", "Tomas", 'm', "1140515642","tomasalvarez1@hotmail.com", {10,12,2011},0},
        {1, "Caballero", "Julian", 'm', "1198724643","juliancaballero2@hotmail.com", {04,07,2013}, 0},
        {2, "Cortes", "Florencia", 'f', "1103965201","cortesflorencia@hotmail.com", {21,03,2005}, 0},
        {3, "Abila", "Ramon", 'm', "1133906453","abilaramon@hotmail.com", {17,03,2009}, 0},
        {4, "Cortes", "Julieta", 'f', "1155402310", "julietacortes@hotmail.com", {12,10,2010}, 0},
    };

    for (int i=0;i<5;i++)
    {
        soc[i]=lista[i];
    }
*/
    eAutor autores[]=
    {
        {100, "Cortazar", "Julio", 0},
        {101, "Orwell", "George", 0},
        {102, "Saint-Exupery", "Antoine", 0},
        {103, "Garcia Marquez", "Gabriel", 0},
        {104, "Shelley", "Mary", 0},
    };

    for (int i=0;i<5;i++)
    {
        aut[i]=autores[i];
    }

    eLibros libros[]=
    {
        {1000, "Rayuela", 100, 0},
        {1001, "Casa tomada", 100, 0},
        {1002, "Bestiario", 100, 0},
        {1003, "Revelion en la granja", 101, 0},
        {1004, "1984", 101, 0},
        {1005, "El principito", 102, 0},
        {1006, "El naufrago", 103, 0},
        {1007, "Frankenstein", 104, 0},
    };

    for (int i=0;i<8;i++)
    {
        lib[i]=libros[i];
    }

  /* ePrestamo prestamos[]=
    {
        {0, 1003, 2, {10,07,2018}, 0},
        {1, 1003, 2, {10,07,2018}, 0},
        {2, 1004, 3, {06,01,2019}, 0},
        {3, 1003, 1, {13,10,2018}, 0},
        {4, 1003, 1, {07,9,2018}, 0},

    };

    for (int i=0;i<5;i++)
    {
        pres[i]=prestamos[i];
    }
    */

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int buscarLibre (eSocio soc[], int tamSoc)
{
    int indiceLibre=-2;

    for (int i=0;i<tamSoc;i++)
    {
        if (soc[i].itsEmpty==1)
        {
            indiceLibre=i;
            break;
        }
    }

    return indiceLibre;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int buscarLegajo (eSocio soc[], int tamSoc, int legajo)
{
    int indiceLegajo=-2;

    for (int i=0;i<tamSoc;i++)
    {
        if (soc[i].itsEmpty==0 && soc[i].legajo==legajo)
        {
            indiceLegajo=i;
            break;
        }
    }

    return indiceLegajo;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void altaSocio (eSocio soc[], int tamSoc, int contador)
{
    int espacioLibre;
    espacioLibre=buscarLibre(soc, tamSoc);

    if (espacioLibre==-2)
    {
        printf("\nNo hay espacio en el sistema\n\n");
    }
    else
    {
        getString(soc[espacioLibre].apellido, "Ingrese apellido: ", "Supero los caracteres. Reingrese: ", 0, 51);
        getString(soc[espacioLibre].nombre, "Ingrese nombre: ", "Supero los caracteres. Reingrese: ", 0, 51);
        validarDosChar(&soc[espacioLibre].sexo, "Ingrese sexo: ", "Solo m o f. Reingrese: ", 'f', 'm');
        getString(soc[espacioLibre].telefono, "Ingrese telefono: ", "No entra en el rango. Reingrese: ", 0, 16);
        getInt(&soc[espacioLibre].fechaDeIngreso.dia, "Ingrese dia: ", "No entra en el rango. Reingrese: ", 0, 16);
        getInt(&soc[espacioLibre].fechaDeIngreso.mes, "Ingrese dia: ", "No entra en el rango. Reingrese: ", 1, 12);
        getInt(&soc[espacioLibre].fechaDeIngreso.anio, "Ingrese dia: ", "No entra en el rango. Reingrese: ", 1900, 2019);
        getString(soc[espacioLibre].eMail, "Ingrese email: ", "No entra en el rango. Reingrese: ", 0, 31);


        soc[espacioLibre].legajo=0;
        soc[espacioLibre].legajo+=contador;
        soc[espacioLibre].itsEmpty=0;

        printf("\nAlta empleado exitosa!!\n\n");
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void bajaSocio (eSocio soc[], int tamSoc)
{
    int legajo;
    int busquedaLegajo;
    char respuesta;
    int sinSocio=0;

    for (int i=0;i<tamSoc;i++)
    {
        if (soc[i].itsEmpty==0)
        {
            sinSocio++;
            printf("Ingrese legajo: ");
            scanf("%d", &legajo);

            busquedaLegajo=buscarLegajo(soc, tamSoc, legajo);

            if (busquedaLegajo==-2)
            {
                printf("\nLegajo inexistente!!\n\n");
            }
            else
            {
                printf("\nLegajo nro %d-%s, %s\n\n", soc[busquedaLegajo].legajo, soc[busquedaLegajo].apellido, soc[busquedaLegajo].nombre);

                validarDosChar(&respuesta, "Desea continuar? Ingrese s/n: ", "Solo 's' o 'n'. Reingrese: ", 'n', 's');

                if (respuesta=='s')
                {
                    soc[legajo].itsEmpty=-1;
                    printf("\nOperacion exitosa!!\n\n");
                }
                else
                {
                    printf("\nOperacion cancelada!!\n\n");
                }
            }
        }
    }
    if(sinSocio==0)
    {
        printf("\nNo hay socios para dar de baja!!\n\n");
    }


}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarSocio (eSocio soc)
{
    printf("%04d        %-15s  %-15s %c     %-8s   %-13s  %02d/%02d/%4d\n",soc.legajo,  soc.apellido, soc.nombre, soc.sexo, soc.telefono, soc.eMail, soc.fechaDeIngreso.dia ,soc.fechaDeIngreso.mes, soc.fechaDeIngreso.anio);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mostrarSocios (eSocio soc[], int tamSoc)
{
    int contador=0;

    printf ("LEGAJO    APELLIDO           NOMBRE         SEXO   TELEFONO            EMAIL              FECHA\n");

    for (int i=0;i<tamSoc;i++)
    {
        if (soc[i].itsEmpty==0)
        {
            mostrarSocio(soc[i]);
            contador++;
        }
    }
    if (contador==0)
    {
        printf("\nNo hay empleados que listar!!\n\n");
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ordenarSocios (eSocio soc[], int tamSoc)
{
    eSocio aux;

    for (int i=0;i<tamSoc-1;i++)
    {
        for (int j=i+1;j<tamSoc;j++)
        {
            if (strcmp(soc[i].apellido, soc[j].apellido)>0)
            {
                aux=soc[i];
                soc[i]=soc[j];
                soc[j]=aux;
            }
            else if (strcmp(soc[i].apellido, soc[j].apellido)>0 && strcmp(soc[i].nombre, soc[j].nombre)>0)
            {
                aux=soc[i];
                soc[i]=soc[j];
                soc[j]=aux;
            }

        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void modificarSocio (eSocio soc[], int tamSoc)
{
    int legajo;
    int busquedaLegajo;
    char respuesta;
    int opcionM;
    int sinSocio=0;

    for (int i=0;i<tamSoc;i++)
    {
        if (soc[i].itsEmpty==0)
        {
            sinSocio++;
            printf("Ingrese legajo: ");
            scanf("%d", &legajo);

            busquedaLegajo=buscarLegajo(soc, tamSoc, legajo);

            if (busquedaLegajo==-2)
            {
                printf("\nLegajo inexistente en el sistema.\n\n");
            }
            else
            {
                printf("\nLegajo nro %d-%s, %s\n\n", soc[busquedaLegajo].legajo, soc[busquedaLegajo].apellido, soc[busquedaLegajo].nombre);
                validarDosChar(&respuesta, "Desea continuar? Ingrese s/n: ", "Solo 's' o 'n'. Reingrese: ", 'n', 's');

                if  (respuesta=='s')
                {
                    printf("1-Apellido\n");
                    printf("2-Nombre\n");
                    printf("3-Sexo\n");
                    printf("4-Telefono\n");
                    printf("5-eMail\n");
                    printf("6-Salir\n\n");

                    printf("Ingrese opcion: ");
                    scanf("%d", &opcionM);


                    switch(opcionM)
                    {
                        case 1:
                            getString(soc[busquedaLegajo].apellido, "Ingrese apellido: ", "Supero los caracteres. Reingrese: ", 0, 51);
                            printf("\nOperacion exitosa!!\n\n");
                            break;

                        case 2:
                            getString(soc[busquedaLegajo].nombre, "Ingrese nombre: ", "Supero los caracteres. Reingrese: ", 0, 51);
                            printf("\nOperacion exitosa!!\n\n");
                            break;

                        case 3:
                            validarDosChar(&soc[busquedaLegajo].sexo, "Ingrese sexo: ", "Solo m o f. Reingrese: ", 'f', 'm');
                            printf("\nOperacion exitosa!!\n\n");
                            break;

                        case 4:
                            getString(soc[busquedaLegajo].telefono, "Ingrese telefono: ", "No entra en el rango. Reingrese: ", 0, 16);
                            printf("\nOperacion exitosa!!\n\n");
                            break;

                        case 5:
                            getString(soc[busquedaLegajo].eMail, "Ingrese email: ", "No entra en el rango. Reingrese: ", 1, 31);
                            printf("\nOperacion exitosa!!\n\n");
                            break;
                        case 6:
                            break;

                        default:
                            system("cls");
                            printf("\nOperacion invalida!!\n\n");
                            break;

                    }

                }
                else
                {
                    printf("\nOperacion cancelada!!\n\n");
                }
            }
        }
    }
    if (sinSocio==0)
    {
        printf("\nNo hay socios para modificar!!\n\n");
    }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void E_informarLibroMenosPrestado (eLibros lib[],int tamLib, ePrestamo pres[], int tamPres)
{
    int contador;
    int min;
    int idMin=0;
    int flag=0;

    for (int i=0;i<tamLib;i++)
     {
         contador=0;

         for (int j=0;j<tamPres;j++)
         {
             if (pres[j].idLibro==lib[i].idLibro && pres[j].itsEmpty==0 && lib[i].itsEmpty==0)
             {
                 contador++;
                 if (contador<min || flag==0)
                 {
                     min=contador;
                     idMin=pres[j].idLibro;
                     flag++;


                 }
            }
        }

    }

    if(idMin>0)
    {

        printf("\nEl libro menos prestado es el %d con %d veces\n\n", idMin, min);


    }
    else
    {
        printf("\nNo hay nada que mostrar!!\n\n");
    }



}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void F_informarSocioMasSolicito (eSocio soc[], int tamSoc, eLibros lib[],int tamLib, ePrestamo pres[], int tamPres)
{
    int contador;
    int max=0;
    char apellido[31];
    char nombre[31];
    int flag=0;
    int legajo=-1;

    for (int i=0;i<tamLib;i++)
    {
        contador=0;
        for (int j=0;j<tamPres;j++)
        {
            if (pres[j].idLibro==lib[i].idLibro)
            {

                for (int k=0;k<tamSoc;k++)
                {

                    if (soc[k].legajo==pres[j].legajoEmpleado  && soc[k].itsEmpty==0  && pres[j].itsEmpty==0  && lib[i].itsEmpty==0)
                    {
                         contador++;
                         if (contador>max || flag==0)
                         {
                             max=contador;
                             strcpy(apellido, soc[k].apellido);
                             strcpy(nombre, soc[k].nombre);
                             legajo=soc[k].legajo;
                             flag++;

                         }
                    }
                }
            }
        }
    }

    if (legajo==-1)
    {
        printf("\nNo hay nada que listar!!\n\n");
    }
   else
    {

        printf("El socio es %d-%s %s\n", legajo, apellido, nombre);

    }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void H_informarPrestamoSocioConFechaDeterminada (eAutor aut[],int tamAut,ePrestamo pres[], int tamPres, eSocio soc[], int tamSoc)
{
    int contador=0;
    int legajo;
    int indice;
    int dia, mes, anio;


    getInt (&dia, "Ingrese dia: ", "No entra en el rango. Reingrese: ", 1, 31);
    getInt (&mes, "Ingrese mes: ", "No entra en el rango. Reingrese: ", 1, 12);
    getInt (&anio, "Ingrese anio: ", "No entra en el rango. Reingrese: ", 2018, 2019);


    for (int i=0;i<tamSoc;i++)
    {
        for (int j=0;j<tamPres;j++)
        {
            if (pres[j].fechaDePrestamo.dia==dia && pres[j].fechaDePrestamo.mes==mes && pres[j].fechaDePrestamo.anio && soc[i].legajo==pres[j].legajoEmpleado)
            {
                printf("\n ID  PRESTAMO  LEGAJO  APELLIDO  NOMBRE  ID LIBRO  FECHA \n");
                printf("    %04d       %04d     %s  %s     %d   %02d/%02d/%4d\n\n", pres[j].idPrestamo, pres[j].legajoEmpleado, soc[i].apellido, soc[i].nombre,  pres[j].idLibro, pres[j].fechaDePrestamo.dia, pres[j].fechaDePrestamo.mes, pres[j].fechaDePrestamo.anio);
                contador++;
            }
        }
    }

    if (contador==0)
    {
        printf("\nNo hay nada que listar!!\n\n");
    }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void G_informarPrestamoLibrosConFechaDeterminada (eAutor aut[],int tamAut,ePrestamo pres[], int tamPres, eLibros lib[], int tamLib)
{
    int contador=0;
    int legajo;
    int indice;
    int dia, mes, anio;


    getInt (&dia, "Ingrese dia: ", "No entra en el rango. Reingrese: ", 1, 31);
    getInt (&mes, "Ingrese mes: ", "No entra en el rango. Reingrese: ", 1, 12);
    getInt (&anio, "Ingrese anio: ", "No entra en el rango. Reingrese: ", 2018, 2019);


    for (int i=0;i<tamLib;i++)
    {
        for (int j=0;j<tamPres;j++)
        {
            if (pres[j].fechaDePrestamo.dia==dia && pres[j].fechaDePrestamo.mes==mes && pres[j].fechaDePrestamo.anio==anio && lib[i].itsEmpty==0 && lib[i].idLibro==pres[j].idLibro)
            {
                printf("\n Codigo libro   Titulo    Fecha\n");
                printf("    %04d  %s %02d/%02d/%4d\n\n", pres[j].idLibro, lib[i].titulo, pres[j].fechaDePrestamo.dia, pres[j].fechaDePrestamo.mes, pres[j].fechaDePrestamo.anio);
                contador++;
            }
        }
    }

    if (contador==0)
    {
        printf("\nNo hay nada que listar!!\n\n");
    }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void C_informarLibrosDeterminados (eLibros lib[],int tamLib,eAutor aut[],int tamAut,ePrestamo pres[], int tamPres, eSocio soc[], int tamSoc)
{
    int contador = 0;
    int legajo;
    int indice;
    int opcion;

    mostrarLibros(lib, tamLib);
    getInt(&opcion, "Ingrese libro: ", "No entra en el rango. Reingrese: ", 1000, 1007);

    {
        printf("\n IDPRESTAMO  LEGAJO   APELLIDO  NOMBRE  ID LIBRO  FECHA \n");

        for (int j=0;j<tamSoc;j++)
        {
            for(int i=0;i<tamPres;i++)
            {
                if(pres[i].itsEmpty==0 && pres[i].idLibro==opcion && soc[j].itsEmpty==0 && soc[j].legajo==pres[i].legajoEmpleado)
                {
                    printf("%    04d           %d      %s  %s  %d   %02d/%02d/%4d\n\n", pres[i].idPrestamo, pres[i].legajoEmpleado, soc[j].apellido, soc[j].nombre, pres[i].idLibro, pres[i].fechaDePrestamo.dia, pres[i].fechaDePrestamo.mes, pres[i].fechaDePrestamo.anio);
                    contador++;
                }
            }
        }


    }

    if(contador==0)
    {
        printf("\nEste libro no tiene prestamos");
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void D_informarSocioDeterminado (eLibros lib[],int tamLib,eAutor aut[],int tamAut,ePrestamo pres[], int tamPres, eSocio soc[], int tamSoc)
{
    int contador = 0;
    int legajo;
    int indice;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice=buscarLegajo(soc, tamSoc, legajo);

    if(indice==-2)
    {
        printf("\nNo se encuentra su legajo!!\n\n");
    }
    else
    {
        printf("\n PRESTAMO  LEGAJO  TITULO    ID LIBRO      FECHA \n");

        for (int i=0;i<tamLib;i++)
        {
             for(int j=0;j<tamPres;j++)
            {
                if(pres[j].itsEmpty==0 && pres[j].legajoEmpleado==legajo && lib[i].idLibro==pres[j].idLibro)
                {
                    printf("    %d       %d      %s   %d      %02d/%02d/%4d\n\n", pres[j].idPrestamo, pres[j].legajoEmpleado, lib[i].titulo, pres[j].idLibro, pres[j].fechaDePrestamo.dia, pres[j].fechaDePrestamo.mes, pres[j].fechaDePrestamo.anio);
                    contador++;
                }

            }
        }
    }

    if(contador==0)
    {
        printf("\nEste socio no tiene prestamos\n");
    }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void I_librosOrdenados (eLibros lib[], int tamLib)
{
    eLibros aux;
    int noEstaOrdenado=1;


    while(noEstaOrdenado==1)
    {
        noEstaOrdenado=0;
        for (int i=0;i<tamLib-1;i++)
        {
            for (int j=i+1;j<tamLib;j++)
            {
                if (stricmp(lib[i].titulo, lib[j].titulo)<0)
                {
                    aux=lib[i];
                    lib[i]=lib[j];
                    lib[j]=aux;
                    noEstaOrdenado=1;
                }
            }
        }
    }
    mostrarLibros(lib, tamLib);

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void J_sociosOrdenados (eSocio soc[], int tamSoc)
{
    eSocio aux;
    int j;

    for (int i=1;i<tamSoc;i++)
    {
        aux=soc[i];
        j=i-1;

        while (j>=0 && stricmp(aux.apellido, soc[j].apellido)<0)
        {
            soc[j+1] = soc[j];
            j--;
        }
        soc[j+1]=aux;
    }
    mostrarSocios(soc, tamSoc);
}
