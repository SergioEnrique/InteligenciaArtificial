// Nombre del programa: 3Raya.cpp
// Responsables: 
//          Profesor: Mti. Lourdes Aguilar López
//          Alumno: Sergio Enrique Vargas García 
// Fecha: 121-Enero-2015

//--------------------------------------------------------------------------------------- 
// INCLUDES 
//--------------------------------------------------------------------------------------- 
#include <stdio.h>
#include <stdlib.h>

//--------------------------------------------------------------------------------------- 
// Variables Globales
//--------------------------------------------------------------------------------------- 
char matriz[3][3];
char comprobar(void);
void inic_matriz(void);
void obt_mov_jugador(void);
void obt_mov_computadora(void);
void mostrar_matriz(void);

//--------------------------------------------------------------------------------------- 
// Función principal
//--------------------------------------------------------------------------------------- 
int main()
{
	char hecho;
	printf( "este es el juego de 3 en raya \n " );
	printf( "ud jugara contra la computadora \n " );
	hecho=' ';
	inic_matriz();
	do{
		mostrar_matriz();
		obt_mov_jugador();
		hecho=comprobar();
		if ( hecho != ' ') break;
		obt_mov_computadora();
		hecho=comprobar();
	} while ( hecho == ' ');
	if ( hecho == 'X') printf("ha ganado !!! \n");
	else printf ("Yo Gano !!!! \n");
	mostrar_matriz();

	return 0;
}

//--------------------------------------------------------------------------------------- 
// Iniciar matriz
//--------------------------------------------------------------------------------------- 
void inic_matriz(void){
	int j, i;
	for (i=0; i<3; i++)
		for (j=0; j<3; j++)
			matriz[i][j]=' ';
}

//--------------------------------------------------------------------------------------- 
// Obtener movimiento jugador
//--------------------------------------------------------------------------------------- 
void obt_mov_jugador(void){
	int x,y;
	printf("introduzca sus coordenadas de su X: ");
	scanf("%d%d",&x,&y);
	x--;
	y--;
	if(matriz[x][y]!=' '){
		printf("Movimiento invalido, pruebe de nuevo. \n");
		obt_mov_jugador();
	}
	else matriz[x][y]='X';
}

//--------------------------------------------------------------------------------------- 
// Obtener movimiento computadora 
//--------------------------------------------------------------------------------------- 
void obt_mov_computadora(void){
	int i,j;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++)
			if (matriz[i][j]==' ') break;
		if (matriz[i][j]==' ' )break;
	}
	if (i*j==9){
		printf ("tablas\n");
		exit(0);
	}
	else
		matriz[i][j]='O';
}

//--------------------------------------------------------------------------------------- 
// Mostrar matriz
//--------------------------------------------------------------------------------------- 
void mostrar_matriz(void){
	int t;
	for (t=0; t<3; t++){
		printf ("%c | %c| %c", matriz[t][0],matriz[t][1],matriz[t][2]);
		if(t!=2) printf("\n---|---|---\n");
	}
	printf("\n");
}

//--------------------------------------------------------------------------------------- 
// Comprobar
//--------------------------------------------------------------------------------------- 
char comprobar(void){
	int i;
	for (i=0; i<3;i++) 
		if(matriz[i][0]==matriz[i][1] && matriz[i][0]==matriz[i][2] )
			return (matriz[i][0]);
		for (i=0; i<3;i++)
			if(matriz[0][i]==matriz[1][i] && matriz[0][i]==matriz[2][i] )
				return (matriz[0][i]);
			if(matriz[0][0]==matriz[1][1] && matriz[1][1]==matriz[2][2] )
				return (matriz[0][0]);
			if(matriz[0][2]==matriz[1][1] && matriz[1][1]==matriz[2][0] )
				return (matriz[0][2]);
			return ' ';
}