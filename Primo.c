#include <stdio.h>
#include <math.h>
main(){
    int i, j, cont = 1, qnt = 100000;
    //int vetor[qnt];
    int* vetor = malloc(qnt * sizeof(int));
    vetor[0] = 2;
    for(i = 3;cont+2 <= qnt && i <= pow(2, 32)-1;i = i + 2){
        int k = 0;
        int f = 0;
        while (f < cont){
            float raiz = sqrt(i);
            int r = raiz;
            if(r != raiz){
                if(vetor[f] <= r){
                    if(i%vetor[f] == 0){
                        k++;
                        f = cont;
                    }
                }else{
                    f = cont;
                }
                f++;
            }else{
                k++;
                break;
            }
        }
        if(k == 0){
            if(cont+2 <= qnt){
                vetor[cont] = i;
                cont++;
            }
            else{
                cont++;
            }
        }
    }
}
