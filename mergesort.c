#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intercala(int inicio, int meio, int fim, int v[], int *loop){
   int i, j, *w;

   // aloca memória para o array temporário w
   w = malloc ((fim-inicio) * sizeof (int));

   for (i = inicio; i < meio; ++i){
        w[i-inicio] = v[i];
        (*loop)++;
   }
   for (j = meio; j < fim; ++j){
        w[fim-inicio+meio-j-1] = v[j];
        (*loop)++;
   }

   i = 0;
   j = fim-inicio-1;

   // intercala os elementos de w de volta em v
   for (int k = inicio; k < fim; ++k){
        if (w[i] <= w[j]) v[k] = w[i++];
        else v[k] = w[j--];
        (*loop)++;
   }

   free(w);
}

void mergesort (int inicio, int fim, int v[], int *loop){
   if (inicio < fim-1) {                 
      int meio = (inicio + fim)/2;  
      mergesort (inicio, meio, v, loop);
      mergesort (meio, fim, v, loop);
      intercala (inicio, meio, fim, v, loop);
   }
}

int main(){

    //mude o tamanho da amostra para o número de números em cada arquivo tipo 100, 200, 300, etc...
    int amostratam = 100;

    int *v = malloc(10* sizeof(int));

    int looptotal = 0;
    double tempototal = 0;

    for(int w = 0;w < 10;w++){
        for(size_t i = 0; i <= amostratam;i++){
        scanf("%d", &v[i]);
        }

        clock_t antes, depois;
        int loop = 0;

        antes = clock();
        mergesort(0, amostratam, v, &loop);
        depois = clock();
        double mediaseg = (double)(depois - antes)/ CLOCKS_PER_SEC;
        double mediasegg = mediaseg*1000;

        //se for fazer testes só desfazer esse comentario para ver os números que estão sendo lidos pelo código
        /* 
        for(size_t i = 0; i <= 100;i++){
            printf("%i\n", v[i]);
        }
        

        printf("Número de loops: %d\n", loop);
        printf("Tempo: %f segundos\n", mediasegg);
        */

        looptotal = looptotal + loop;
        tempototal = tempototal + mediasegg;
    }

    printf("Número total de loops: %d\n", looptotal);
    printf("Tempo total: %f segundos\n", tempototal);

}
