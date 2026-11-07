#include <stdio.h>
#include <stdlib.h>

int main(void){
    // Punto A
    // Variabili
    
    // numero geni
    int N; 
    // numero mutazioni
    int M;
    // seed 
    int seed;


    printf("Inserisci N, M, seed :  ");
    
    if(scanf("%d %d %d", &N, &M, &seed) != 3){
        printf("Errore : parametri di input non validi!\n");
        return 1;
    }
    

    // controllo sulla validità dei parametri
    if (!(N >= 1 && N <= 200 && M >= 0 && M <= 500 && seed >= 0)){
        printf("Errore : parametri genetici non validi!\n");
        return 1;
    }


    // Punto B
    // array
    int geni[200];

    // andiamo a leggere gli N valori iniziali dei geni
    for(int i = 0; i < N; i++){
        printf("Inserisci gli N livelli iniziali : ");
        if(scanf("%d", &geni[i]) != 1){
            printf("Errore : parametro di input non valido.\n");
            return 1;
        }
        // controlliamo la validità degli input
        if (!(geni[i] >= 0 && geni[i] <= 1000)){
            printf("Errore : livello genetico fuori intervallo.\n");
            return 1;
        }
    }

    // Punto C
    // stampiamo la sequenza iniziale
    printf("Sequenza iniziale : ");
    for(int i = 0; i < N; i++){
        printf("%d ", geni[i]);
    }

    printf("\n");

    srand(seed);
    int mutIncremento = 0;
    int mutDecremento = 0;
    int mutNulle = 0;

    // appllichiamo le mutazioni ai geni
    for(int i = 0; i < M; i++){
        int idx = rand() % N;
        int dt = (rand() % 11) - 5;

        geni[idx] += dt;
        if(geni[idx] < 0){
            geni[idx] = geni[i];
        }

        // verifichiamo se ci sono mutazioni nulle, che incrementano e che decrementano
        if(dt == 0){
            mutNulle++;
        } else if(dt > 0) {
            mutIncremento++;
        } else {
            mutDecremento++;
        }
    }

    // Punto D
    printf("Sequenza mutata : ");
    for(int i = 0; i < N; i++){
        printf("%d ", geni[i]);
    }

    printf("\n");

    printf("Mutazioni: incremento = %d, decremento = %d, nulle = %d\n", mutIncremento, mutDecremento, mutNulle);

    // conserviamo gli indici della run e della lunghezza iniziale
    int indRunIniziale = 0;
    int indLungIniziale = 1; 

    // ci servono anche quelli della run e della lunghezza migliore
    // inizialmente sono uguali a quelli iniziali
    // verranno confrontanti e aggiornati successivamente
    int indRunMigliore = 0;
    int indLungMax = 1;

    for(int i = 0; i < N; i++){
        if(geni[i] > geni[i - 1]){
            indLungIniziale++;
        } else {
            indRunIniziale = i;
            indLungIniziale = 1;
        }

        if(indLungIniziale > indLungMax){
            indLungMax = indLungIniziale;
            indRunMigliore = indRunIniziale;
        }


    }

    int fineRunMigliore = (indRunMigliore + indLungMax) - 1;
    printf("Run migliore: indice iniziale = %d, indice finale = %d\n", indRunMigliore, fineRunMigliore);
    printf("Lunghezza massima Lmax = %d\n", indLungMax);

    // Punto E
    // calcolare sulla run migliore quindi sulla sottosequenza ---> media, min e max
    double media = 0;
    // ci salviamo l'indice iniziale e finale della sottosequenza in due variabili separate
    int inizio = indRunMigliore;
    int fine = fineRunMigliore;
    int min = inizio, max = inizio;

    // scorriamo l'array partendo dall'elemento i-esimo della sottosequenza
    for(int i = inizio; i <= fine; i++){
        // eseguiamo il controllo per max e min
        if(geni[i] > max){
            max = geni[i];
        }
        if(geni[i] < min){
            min = geni[i];
        }

        media += geni[i];
    }


    printf("Run crescente migliore - media : %.2f , max : %d , min : %d\n", media, max, min);

    return 0;

}

