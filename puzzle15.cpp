// Nombre del programa: puzzle15.cpp
// Responsables: 
//          Profesor: Mti. Lourdes Aguilar López
//          Alumno: Sergio Enrique Vargas García 
// Fecha: 19-Enero-2015

//--------------------------------------------------------------------------------------- 
// INCLUDES 
//--------------------------------------------------------------------------------------- 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//--------------------------------------------------------------------------------------- 
// Localizacion
//--------------------------------------------------------------------------------------- 
void localizacion(int movido, int cuadro[4][4], int lugar[2])
{
	int horizontales, verticales;
	for (horizontales = 0; horizontales < 4; horizontales++)
	{
		for (verticales = 0; verticales<4; verticales++)
		{
			if (movido == cuadro[horizontales][verticales])
			{
				lugar[0] = horizontales;
				lugar[1] = verticales;
			}
		}
	}
}

//--------------------------------------------------------------------------------------- 
// Movimiento
//--------------------------------------------------------------------------------------- 
bool movimiento(int cuadro[4][4], int movido, int lugar[2])
{
	int lugar2[2], temp = 0;
	bool listo;
	localizacion(movido, cuadro, lugar);
	localizacion(0, cuadro, lugar2);

	if ((lugar[0] == lugar2[0] && lugar[1] == lugar2[1] - 1) || (lugar[0] == lugar2[0] && lugar[1] + 1) || (lugar[0] == lugar2[0] + 1 && lugar[1] == lugar2[1]) || (lugar[0] == lugar2[0] - 1 && lugar[1] == lugar2[1]))
	{
		temp = cuadro[lugar[0]][lugar[1]];
		cuadro[lugar[0]][lugar[1]] = cuadro[lugar2[0]][lugar2[1]];
		cuadro[lugar2[0]][lugar2[1]] = temp;
		listo = true;
	}
	else
	{
		listo = false;
	}

	return listo;
}

//--------------------------------------------------------------------------------------- 
// Revuelto
//--------------------------------------------------------------------------------------- 
void revuelto(int cuadro[4][4])
{
	int vector[16], acomodar=0, distintos=0, yaesta, pos, horizontales, verticales;

	while (distintos < 16)
	{
		acomodar = rand()%16;
		yaesta = 0;

		for (pos = 0; pos <= distintos; pos++)
		{
			if (vector[pos] == acomodar)
			{
				yaesta++;
			}
		}
		if (yaesta == 0)
		{
			vector[distintos] = acomodar;
			distintos++;
		}
	}

	distintos = 0;

	for (horizontales = 0; horizontales < 4; horizontales++)
	{
		for (verticales = 0; verticales < 4; verticales++)
		{
			cuadro[horizontales][verticales] = vector[distintos];
			distintos++;
		}
	}

	for (horizontales = 0; horizontales < 4; horizontales++)
	{
		printf("\n");

		for (verticales = 0; verticales < 4; verticales++)
		{
			printf("%d\t", cuadro[horizontales][verticales]);
		}
	}

}

void revuelto2(int cuadro[4][4])
{
	int horizontales, verticales=0, num = 1;

	for (horizontales = 0; horizontales < 4; verticales++)
	{
		cuadro[horizontales][verticales] = num;
		num++;
		cuadro[3][3] = 15;
		cuadro[3][2] = 0;
		printf("%d\t", cuadro[horizontales][verticales]);
	}
}

//--------------------------------------------------------------------------------------- 
// haGanado
//--------------------------------------------------------------------------------------- 
bool haGanado(int cuadro[4][4])
{
	int correcto = 1, verticales, horizontales;
	bool ganado = true;

	for (int horizontales = 0; horizontales < 4; horizontales++)
	{
		for (int verticales = 0; verticales < 4; verticales++)
		{
			if (cuadro[horizontales][verticales] != correcto && correcto != 16)
			{
				ganado = false;
				verticales = 4;
				horizontales = 4;
			}
			correcto++;
		}
	}

	return ganado;
}

//--------------------------------------------------------------------------------------- 
// Función main
//--------------------------------------------------------------------------------------- 
int main()
{
	cout << "\nReglas del juego:" << endl << endl;
	cout << "El juego termina cuando se hayan organizado los numeros del 1 al 15 de forma consecutiva." << endl;
	cout << "La forma en que se movera es de la siguiente manera:" << endl;
	cout << "El cero (0) es el espacio en blanco, para mover y poder ganar el juego tienes que poner el numero a donde quieres que se mueva el cero." << endl;
	cout << "Ejemplo: Si quieres que el cero vaya hacia arriba, fijate que numero esta arriba del cero, por decir en este ejemplo, es el numero 5, tecleas ese numero y le das enter, y asi hacia todos los lados que desees." << endl;
	
	int cuadro[4][4], movido, lugar[2];
	bool gano = false, sePudo;
	revuelto(cuadro);

	while (gano == false)
	{
		cout << endl << "Movimiento: " << endl;
		cin >> movido;

		sePudo = movimiento(cuadro, movido, lugar);

		if (sePudo)
		{
			for (int horizontales = 0; horizontales < 4; horizontales++)
			{
				printf("\n");

				for (int verticales = 0; verticales < 4; verticales++)
				{
					printf("%d\t", cuadro[horizontales][verticales]);
				}
			}
		}
		else
		{
			printf("\nError\n");
		}
	}

	gano = haGanado(cuadro);
	printf("\nFelicidades, completaste el rompecabezas!!!\n");
}