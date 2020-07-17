#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (){
    //Definimos el numero de hilo a utilizar
    char cad[1000];
    char encriptado[1000]="";
    printf("********ENCRIPTACION CESAR********");
    printf("\nIntroduzca su nombre: " );
    fgets (cad, 100, stdin);
    int m =strlen(cad);
    int i;
    char a;
    omp_set_num_threads(6);
    #pragma omp parallel shared(m), private(i)
    {
        #pragma omp for
    
            for(int i=0;i<m;i++){
                a=cad[i]+3;
                if ((a>=65&& a<=90)||(a>=97 && a<=122)|| (a>=164 && a<=165)){
                    encriptado[i]=a;
                }else if(a>90||a>122){
                    a=a-26;
                    encriptado[i]=a;
                }else if((a-3)==32){
                        encriptado[i]=32;
                    }

            }
            
        } 
        printf("El nombre encriptado es:\n\t%s\n",encriptado);
    return 0;
}