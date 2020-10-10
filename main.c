#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(void) 
{
   //entrada 01
  //int matriz[9][9]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9};
  // entrada 02
 // int matriz[9][9]={4, 0, 0, 0, 0, 0, 8, 0, 5,0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0,0, 2, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 8, 0, 4, 0, 0,0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 6, 0, 3, 0, 7, 0,5, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 4, 0, 0, 0, 0, 0, 5};
  //entrada 03
 //int matriz[9][9]={4, 1, 7, 3, 6, 9, 8, 2, 5, 6, 3, 2, 1, 5, 8, 9, 4, 7, 9, 5, 8, 7, 2, 4, 3, 1, 6, 8, 2, 5, 4, 3, 7, 1, 6, 9, 7, 9, 1, 5, 8, 6, 4, 3, 2, 3, 4, 6, 9, 1, 2, 7, 5, 8, 2, 8, 9, 6, 4, 3, 5, 7, 1, 5, 7, 3, 2, 9, 1, 6, 8, 4, 1, 6, 4, 8, 7, 5, 2, 9, 3};
  int matriz[9][9];
  void LeMatriz(int   M[9][9]);
   LeMatriz(matriz);
  int  Verifica_linhas(int matriz[9][9]);
  Verifica_linhas(matriz);
  int Verifica_coluna(int matriz[9][9]);
  Verifica_coluna(matriz);
  int Preenche_Quadrante(int matriz[9][9]);
   Preenche_Quadrante(matriz);

    if(Verifica_linhas(matriz)&& Verifica_coluna(matriz)&& Preenche_Quadrante(matriz))
      {
        printf("SIM\n");
      }
      else
      {
        printf("NAO\n");
      }
  return 0;
}

int repetidos_no_quadrante(int quadrante[3][3])
{
	int repetidos=0;
	for(int numero=0;numero<=9;numero++)
	{
		        for(int i = 0; i < 3; i=i+1)
	        	{	
			            for(int j = 0; j < 3; j++)
			            {
                    if(quadrante[i][j]!=0)
                     {
				                 if(quadrante[i][j] == numero)
			                  	{
				                   	repetidos=repetidos+1;
			    	              }
                     }
		            	}
		      	if(repetidos > 1)
		      	{
				       return 0;
		      	}
	        	}
		repetidos=0;
	}
	return 1;
}
int Preenche_Quadrante(int matriz[9][9])
{
	int quadrante [3][3];
	
	 for(int i = 0; i < 9; i =i+3) // percorre a linha da matriz
	 {
		      for(int j = 0; j < 9; j = j+ 3)// percorre coluna da matriz
	      	{
		          	 for(int k = 0; k < 3;k=k+1)// percorre a linha  dos quadrantes
			           {
			                	for(int l = 0; l < 3; l=l+1) // percorre a coluna  dos quadrantes
			                	{
				                     quadrante[k][l] = matriz[k+i][l+j];
			                	}
			    
			
			           }
	      	if(!repetidos_no_quadrante(quadrante))
			    {
				      return 0;
			    }
		      }
	}
	return 1;
}

 int Verifica_coluna(int matriz[9][9])
{
  int valido=1;
        for(int j=0;j<9 && valido;j=j+1)

        {
                for(int i=0;i<9 && valido;i=i+1)
                {
                        for(int k=0;k<9 && valido;k=k+1)
                        {
                            if((matriz[i][j]!=0)&&(i != k) && (matriz[i][j] == matriz[k][j]))
                            {
                              valido=0;
                            }
                        }
                }
        }
        return valido;
}


 int Verifica_linhas(int matriz[9][9])
{
  int valido=1;
        for(int i=0;i<9 && valido;i=i+1)

        {
                for(int j=0;j<9 && valido;j=j+1)
                {
                        for(int k=0;k<9 && valido;k=k+1)
                        {
                            if((matriz[i][j]!=0)&&(j != k) && (matriz[i][j] == matriz[i][k]))
                            {
                              valido=0;
                            }
                        }
                }
        }
        return valido;
}
 void LeMatriz(int   M[9][9])
  {
     
         for(int i=0;i<9;i=i+1)
          {
                for (int j=0;j<9;j=j+1)
                {
                     
                 scanf("%d", &M[i][j]);
                  
                }
          }
  	
	}
