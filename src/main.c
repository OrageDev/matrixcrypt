#include <stdlib.h>
#include <stdio.h>
#include <math.h>


//int** CalculMatriceCle(char **av,int **matrix, int length, int lengthMatrix, int counter, int Argu);
//int** CalculMatriceMessage(char **av,int **matrix,  int length, int lengthMatrixmessage,int  lengthMatrixColumn, int counter, int Argu);
int my_strlen(char *text);

int my_strlen(char *text){

  int i = 0;

  while(text[++i]);

  return i;
}



void CalculMatriceMessage(char **av,int **matrix,  int lengthmessage, int lengthMatrixcle,int lengthMatrixmessage, int counter, int Argu){

  counter = 0;

  for(int j = 0; j < lengthMatrixmessage; j++){

    matrix[j] = malloc(sizeof(int)*lengthMatrixcle);

    for(int k = 0; k < lengthMatrixcle; k++){

      if(counter < lengthmessage){

	matrix[j][k] = av[Argu][counter];
	counter ++;
	printf("%i\t",matrix[j][k]);

      }else{

	matrix[j][k] = 0;
	printf("%i\t",matrix[j][k]);

      }
    }
    printf("\n");
  }
}



void CalculMatriceCle(char **av,int **matrix,  int length, int lengthMatrix, int counter, int Argu){

  counter = 0;

  for(int j = 0; j < lengthMatrix; j++){

    matrix[j] = malloc(sizeof(int)*lengthMatrix);

    for(int k = 0; k <lengthMatrix; k++){

      if(counter < length){

	matrix[j][k] = av[Argu][counter];
	counter ++;
	printf("%i\t",matrix[j][k]);

      }else{

	matrix[j][k] = 0;
	printf("%i\t",matrix[j][k]);

      }
    }
    printf("\n");
  }
}


void MultiplyMatrix(int **matrixmessage, int **matrixmultiply,int **matrixcle, int nblignem, int nbcolonnem, int nblignec, int nbcolonnec){

	int **matrixX;
	int **matrixY;


	for(int i = i; i < 1; i ++){
		printf("colonnes : \n");
		matrixY[i] = malloc(sizeof(int)*nbcolonnec);

		for(int j = 0; j < nbcolonnec; j++){

			matrixY[j][i] = matrixcle[j][i];
			printf("%i\n",matrixY[j][i]);
		}
	}

	for(int i = i; i < 1; i++){
		printf("Ligne : \n");
		matrixX[i] = malloc(sizeof(int)*nblignem);
		for(int j = 0; j < nblignem; j++){

			matrixX[i][j] = matrixmessage[i][j];
			printf("%i\n",matrixX[i][j]);
		}
	}
}



int  main(int ac, char **av){

  int **matrixcle;
  int **matrixmessage;
  int **matrixmultiply;


  if(ac!=3){


  }else {

    int counter = 0;

    int lengthmessage = my_strlen(av[1]);
    int lengthcle =  my_strlen(av[2]);

    int lengthMatrixcle =  ceil(sqrt(lengthcle));
    int lengthMatrixmessage =  ceil((float)lengthmessage/(float)lengthMatrixcle);

    //int lengthMatrixColumn = ceil(lengthmessage/lengthMatrixcle);

    printf("Nombre de matrice cle %i \n",lengthMatrixcle);
    printf("Nombre de matrice message %i \n",lengthMatrixmessage);
   //int rows = ceil(lengthmessage/lengthcle);
   //printf("Nombre de Rows %i \n",rows);

    matrixcle = malloc(sizeof(int*)*lengthMatrixcle);
    matrixmessage = malloc(sizeof(int*)*lengthMatrixmessage);

    printf("Matrice du message : \n");
    CalculMatriceMessage(av, matrixmessage, lengthmessage, lengthMatrixcle,lengthMatrixmessage, counter,1);

    printf("Matrice de la cle : \n");
    CalculMatriceCle(av, matrixcle, lengthcle, lengthMatrixcle, counter,2);

    MultiplyMatrix(matrixmessage,matrixmultiply,matrixcle, lengthMatrixmessage, lengthMatrixcle, lengthMatrixcle,lengthMatrixcle);
    // printf("test Ligne matrice :  [%i]\t[%i]\t[%i]\t[%i]\n",matrixmessage[0][0],matrixmessage[0][1],matrixmessage[0][2],matrixmessage[0][3]);
    // printf("test column matrice :\n [%i]\n[%i]\n[%i]\n[%i]",matrixmessage[0][0],matrixmessage[1][0],matrixmessage[2][0],matrixmessage[3][0]);

  }
  return (0);
}
