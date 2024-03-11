
#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa/numero exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // confronto/copia/etc di stringhe
#include <errno.h>

// stampa un messaggio d'errore e termina il programma
void termina(char *messaggio)
{
  if(errno!=0) perror(messaggio);
  else fprintf(stderr,"%s\n", messaggio);
  exit(1);
}

// legge array di interi da file f usando scanf
// restituisce numero di elementi dell'array per riferimento 
int *leggi_array_int(FILE *f, int *n) {
    int *a = NULL;
    int count = 0;
    int e; // Declare e to store the result of fscanf

    while (fscanf(f, "%d", &e) == 1) {
        a = realloc(a, (count + 1) * sizeof(int)); // Reallocate memory
        if (a == NULL) {
            termina("Errore di allocazione di memoria");
        }
        a[count] = e;
        count++;
    }

    if (count < 1) {
        termina("Numero elemento array non valido");
    }

    fseek(f, 0, SEEK_SET);  // Resets the file pointer to the beginning of the file

    *n = count;
    return a;
}

//FUNZIONE SOMMA
int somme(int a[], int n, int range) {
    int s = 0; // Inizializziamo la somma a zero

    if (range == 0) {
        // Somma di tutti gli elementi dell'array a[]
        for (int i = 0; i < n; i++) {
            s += a[i];
        }
    } else if (range > 0) {
        // Somma dei primi range elementi o di tutti se range è maggiore di n
        int count = (range < n) ? range : n;
        for (int i = 0; i < count; i++) {
            s += a[i];
        }
    } else if (range < 0) {
        // Somma degli ultimi -range elementi o di tutti se -range è maggiore di n
        int count = (-range < n) ? -range : n;
        for (int i = n - count; i < n; i++) {
            s += a[i];
        }
    }

    return s; // Restituiamo il risultato
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        termina("Uso: main nomefile i1 [i2 i3 ...]");
    }

    //apro il file
    FILE* file = fopen(argv[1],"r"); //there's our file at argv[1]
    if (file == NULL) {
        termina("File opening error!");
    }

    //dichiaro una variabile che misura la lunghezza
    int n;
    //dichiaro un array allocato dinamicamente
    int *a = leggi_array_int(file, &n);
    fclose(file); //file chiuso dopo l'uso

    /*
    calcola il massimo m dei valori argv[2], argv[3], ..., argv[argc-1] convertiti in interi con la funzione atoi()
    */
    int m = atoi(argv[2]);
    for (int j = 3; j < argc; j++) {
        int input = atoi(argv[j]);
        if (input > m) {
            m = input;
        }
    }

    //"invoca la funzione somme sull'array a[] e passando il valore m come parametro range"
    int resultato = somme(a, n, m);
    fprintf(stdout, "%d", resultato);

    free(a);
    return 0;
}
