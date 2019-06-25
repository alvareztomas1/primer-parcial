#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#ifndef socios_H_INCLUDED
#define socios_H_INCLUDED
#include "socios.h"
#endif // socios_H_INCLUDED

#ifndef input_H_INCLUDED
#define input_H_INCLUDED
#include "input.h"
#endif // input_H_INCLUDED



void E_informarLibroMenosPrestado (eLibros lib[],int tamLib, ePrestamo pres[], int tamPres)
{
    int min=0;
    int contador;
    int flag=0;
    int hayPrestamo=0;

    for (int i=0;i<tamLib;i++)
    {
        contador = 0;
        for (int j=0;j<tamPres;j++)
        {
            if (lib[i].idLibro==pres[j].idLibro && pres[j].itsEmpty==0 && lib[i].itsEmpty==0)
            {
                contador++;
            }
        }

        if (flag==0 && contador!=0)
        {
            min=contador;
            flag=1;
            hayPrestamo++;
        }
        else if (contador<=min && contador!=0)
        {
            min=contador;
        }

    }

    if (hayPrestamo!=0)
    {
        printf("Los libros menos prestados son:\n");
        printf("\n  ID AUTOR | ID LIBRO   |  TITULO\n");

        for (int i=0;i<tamLib;i++)
        {
            contador = 0;
            for ( int j=0;j<tamPres;j++)
            {
                if (lib[i].idLibro==pres[j].idLibro && pres[j].itsEmpty==0 && lib[i].itsEmpty==0)
                {
                    contador++;
                }
            }
            if (contador == min)
            {
                printf("%-10d | %-10d | %-10s \n", lib[i].idAutor, lib[i].idLibro, lib[i].titulo);
            }
        }

        printf("\n");
    }
    else
    {
        printf("\nNo hay prestamos dados de alta!!\n\n");
    }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void F_informarSocioMasSolicito (eSocio soc[], int tamSoc, ePrestamo pres[], int tamPres)
{
    int contador;
    int max=0;
    int flag=0;
    int hayPrestamo = 0;

    for (int i=0;i<tamSoc;i++)
    {
        contador=0;
        for (int j=0;j<tamPres;j++)
        {

            if (soc[i].legajo==pres[j].legajoEmpleado  && soc[i].itsEmpty==0  && pres[j].itsEmpty==0)
            {
                contador++;
            }

            if (flag==0 && contador!=0)
            {
                max=contador;
                hayPrestamo++;
                flag=1;
            }

            else if (contador>=max && contador!=0)
            {
                max=contador;

            }

        }
    }

    if(hayPrestamo!=0)
    {
        printf("Los socios con mas prestamos son:\n\n");
        printf("LEGAJO  APELLIDO    NOMBRE\n");
        for (int i=0;i<tamSoc;i++)
        {
            contador=0;
            for (int j=0;j<tamPres;j++)
            {
                if (soc[i].legajo==pres[j].legajoEmpleado  && soc[i].itsEmpty==0  && pres[j].itsEmpty==0)
                {
                    contador++;
                }
            }
            if (contador==max)
            {
                printf("%04d    %-10s  %-10s  \n", soc[i].legajo, soc[i].apellido, soc[i].nombre);
            }
        }

        printf("\n");
    }
    else
    {
        printf("\nNo hay prestamos dados de alta!!\n\n");
    }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void H_informarPrestamoSocioConFechaDeterminada (ePrestamo pres[], int tamPres, eSocio soc[], int tamSoc)
{
    int contador=0;
    int dia, mes, anio;
    char respuesta;

    for (int i=0;i<tamSoc;i++)
    {
        for (int j=0;j<tamPres;j++)
        {
            if (soc[i].legajo==pres[j].legajoEmpleado)
            {
                contador++;
            }
        }
    }

    if(contador!=0)
    {
        contador=0;
        getInt (&dia, "Ingrese dia de prestamo: ", "No entra en el rango. Reingrese: ", 1, 31);
        getInt (&mes, "Ingrese mes de prestamo: ", "No entra en el rango. Reingrese: ", 1, 12);
        getInt (&anio, "Ingrese anio de prestamo: ", "No entra en el rango. Reingrese un año entre 2018 y 2019: ", 2018, 2019);

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
        if(contador==0)
        {
            printf("\nNo hay prestamo!!\n\n");
        }
    }
    else
    {
        printf("\nNo hay nada que listar!!\n\n");
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void G_informarPrestamoLibrosConFechaDeterminada (ePrestamo pres[], int tamPres, eLibros lib[], int tamLib)
{
    int dia, mes, anio;
    char respuesta;
    int hayPrestamo=0;

    for (int i=0;i<tamLib;i++)
    {
        for (int j=0;j<tamPres;j++)
        {
            if (lib[i].itsEmpty==0 && lib[i].idLibro==pres[j].idLibro)
            {
                hayPrestamo++;
            }
        }
    }

    if(hayPrestamo!=0)
    {
        hayPrestamo=0;
        getInt (&dia, "Ingrese dia de prestamo: ", "No entra en el rango. Reingrese: ", 1, 31);
        getInt (&mes, "Ingrese mes de prestamo: ", "No entra en el rango. Reingrese: ", 1, 12);
        getInt (&anio, "Ingrese anio de prestamo: ", "No entra en el rango(2018-2019). Reingrese: ", 2018, 2019);


        for (int i=0;i<tamLib;i++)
        {
            for (int j=0;j<tamPres;j++)
            {
                if (pres[j].fechaDePrestamo.dia==dia && pres[j].fechaDePrestamo.mes==mes && pres[j].fechaDePrestamo.anio==anio && lib[i].itsEmpty==0 && lib[i].idLibro==pres[j].idLibro)
                {
                    printf("\n ID LIBRO   TITULO    FECHA\n");
                    printf("    %04d  %s %02d/%02d/%4d\n\n", pres[j].idLibro, lib[i].titulo, pres[j].fechaDePrestamo.dia, pres[j].fechaDePrestamo.mes, pres[j].fechaDePrestamo.anio);
                    hayPrestamo++;
                }
            }
        }
        if(hayPrestamo==0)
        {
            printf("\nNo hay prestamo!!\n\n");
        }
    }
    else
    {
        printf("\nNo hay nada que listar!!\n\n");
    }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void C_informarLibrosDeterminados (eLibros lib[],int tamLib,ePrestamo pres[], int tamPres, eSocio soc[], int tamSoc)
{
    int hayPrestamo = 0;
    int opcion;

     for (int j=0;j<tamSoc;j++)
        {
            for(int i=0;i<tamPres;i++)
            {
                if(pres[i].itsEmpty==0 &&  soc[j].itsEmpty==0 && soc[j].legajo==pres[i].legajoEmpleado)
                {
                    hayPrestamo++;
                }
            }
        }

    if(hayPrestamo!=0)
    {
        hayPrestamo=0;
        mostrarLibros(lib, tamLib);
        getInt(&opcion, "Ingrese libro: ", "No entra en el rango. Reingrese: ", 1000, 1007);


        printf("\n IDPRESTAMO  LEGAJO   APELLIDO  NOMBRE  ID LIBRO  FECHA \n");

        for (int j=0;j<tamSoc;j++)
        {
            for(int i=0;i<tamPres;i++)
            {
                if(pres[i].itsEmpty==0 && pres[i].idLibro==opcion && soc[j].itsEmpty==0 && soc[j].legajo==pres[i].legajoEmpleado)
                {
                    printf("%    04d           %d      %s  %s  %d   %02d/%02d/%4d\n\n", pres[i].idPrestamo, pres[i].legajoEmpleado, soc[j].apellido, soc[j].nombre, pres[i].idLibro, pres[i].fechaDePrestamo.dia, pres[i].fechaDePrestamo.mes, pres[i].fechaDePrestamo.anio);
                    hayPrestamo++;
                }
            }
        }
        if(hayPrestamo==0)
        {
            printf("\nNo tiene prestamos!!\n\n");
        }
    }
    else
    {
        printf("\nNo hay nada que listar!!\n\n");
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void D_informarSocioDeterminado (eLibros lib[],int tamLib, ePrestamo pres[], int tamPres, eSocio soc[], int tamSoc)
{
    int contador = 0;
    int legajo;
    int indice;

    mostrarSocios(soc, tamSoc);
    for (int i=0;i<tamLib;i++)
    {
        for(int j=0;j<tamPres;j++)
        {
            if(pres[j].itsEmpty==0 && lib[i].idLibro==pres[j].idLibro)
            {
                contador++;
            }

        }
    }
    if(contador!=0)
    {
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
            contador=0;
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
            if(contador==0)
            {
                printf("\nNo tiene prestamos!!\n\n");
            }
        }
    }
    else
    {
        printf("\nNo hay nada dado de alta!!\n\n");
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
        for (int i=1;i<tamLib;i++)
        {
            if (stricmp(lib[i].titulo, lib[i-1].titulo)<0)
            {
                aux=lib[i];
                lib[i]=lib[i-1];
                lib[i-1]=aux;
                noEstaOrdenado=1;
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void A_totalPromedio (eSocio soc[], int tamSoc, ePrestamo pres[], int tamPres)
{
    int contadorPrestamo=0;
    int contadorDiario=0;
    float promedioPorDia;

    promedioDiario(soc, tamSoc, pres, tamPres, &contadorPrestamo, &contadorDiario);
    promedioPorDia = (float)contadorPrestamo/(float)contadorDiario;

    if (contadorPrestamo==0)
    {
        printf("\nNo hay ningun prestamo de alta!!\n\n");
    }
    else
    {
        printf("\nEl total de prestamos es %d y el promedio diario es %.2f\n\n", contadorPrestamo, promedioPorDia);
    }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void B_diasQueNoSuperanPromedio (eSocio soc[], int tamSoc, ePrestamo pres[], int tamPres)
{
    int contadorPrestamos=0;
    int contadorDias=0;
    float contador=0;
    float promedio;

    promedioDiario(soc, tamSoc, pres, tamPres, &contadorPrestamos, &contadorDias);
    promedio=(float)contadorPrestamos/(float)contadorDias;
    contadorDias=0;

    for (int i=1;i<=12;i++)
    {
        for (int j=1;j<=31;j++)
        {
            contador=0;
            for (int k=0;k<tamPres;k++)
            {
                if (pres[k].fechaDePrestamo.dia==j && pres[k].fechaDePrestamo.mes==i && pres[k].itsEmpty==0)
                {
                    contador++;
                }
            }
            if (contador!=0 && contador<promedio)
            {
                contadorDias++;
            }
        }
    }

    //printf("Contador vale %d y contadorDias %d\n\n", contador, contadorDias);
    if(promedio>0)
    {
         printf("El promedio es %.2f. La cantidad de dias que no pasan el promedio son %d\n\n", promedio, contadorDias);
    }
    else
    {
        printf("\nNo hay prestamos!!\n\n");
    }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void promedioDiario (eSocio soc[], int tamSoc, ePrestamo pres[], int tamPres, int *contadorPrestamo, int *contadorDiario)
{
    int flag=0;

    for (int i=0;i<tamSoc;i++)
    {
        for (int j=0;j<tamPres;j++)
        {
            if (pres[j].legajoEmpleado==soc[i].legajo && pres[j].itsEmpty==0 && soc[i].itsEmpty==0)
            {
                *contadorPrestamo=*contadorPrestamo+1;

            }
        }
    }

    for (int i=1;i<=13;i++)
    {
        for (int j=1;j<=31;j++)
        {
            flag=0;
            for (int k=0;k<tamPres;k++)
            {
                if (pres[k].fechaDePrestamo.dia==j && pres[k].fechaDePrestamo.mes==i && pres[k].itsEmpty==0)
                {
                    flag++;
                }
            }
            if (flag != 0)
            {
                *contadorDiario=*contadorDiario+1;
            }
        }
    }


}

