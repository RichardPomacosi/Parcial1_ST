#include <stdio.h>
#include <stdlib.h>
# include <math.h>
#include<omp.h>
void llenar(double M[500][500], int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
                printf("Posicion(%d,%d)=",i,j);
                scanf("%lf",&M[i][j]);
        }
    }
}

void mostrar(double M[500][500], int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          printf("%*.3lf",12,M[i][j]);
        }
        printf("\n");
    }
}
void mostrar2(double M[500][500], int m, int n){
    for(int j=0;j<n;j++){
          printf("%*s%d   -->%*.3lf",8,"X",(j+1),8,M[m-1][j]);
        printf("\n");
    }
}
int main(){
    int n;
    //Matris Ax=b
    double A[500][500];
    printf("********************************\n");
    printf("*     PROGRAMACIÓN CON OMP     *\n");
    printf("*        METODO DE JACOBI      *\n");
    printf("*              Ax=b            *\n");
    printf("********************************\n");
    double B[500][500];
    printf("Numero de variables: ");
    scanf("%d",&n);
    printf("Ingrese Matriz A\n");
    llenar(A,n,n);
    printf("Ingrese Matriz b\n");
    llenar(B,n,1);
    //Matriz a prima
    double AP[500][500];
    double BP[500][500];
    double R[50][500];
    printf("MATRIZ A\n");
    mostrar(A,n,n);
    printf("Matriz B\n");
   mostrar(B,n,1);
#pragma omp parallel
{
    int i,j;
#pragma omp for private (i,j)
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i!=j)
                AP[i][j]=-A[i][j]/A[i][i];
        }
    }
    
#pragma omp for private (i,j)
    for(i=0;i<n;i++){
       BP[i][0]=B[i][0]/A[i][i];
    }
    
#pragma omp for private (i,j)  
   for(i=0;i<n;i++){
       R[0][i]=0;
   }
    for(int i=1;i<50;i++){
        for(int k=0;k<n;k++){
            double s=0;
            for(int l=0;l<n;l++){
                s=s+AP[k][l]*R[i-1][l];
            }
            s=s+BP[k][0];
            R[i][k]=s;
        }
    }
}
    printf("Iteraciones:\n");
    mostrar(R,50,n);
    printf("Resultado:\n");
    mostrar2(R,50,n);

    return 0;
}
