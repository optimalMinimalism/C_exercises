Testo esercizio

Scrivere una funzione

int somme(int a[], int n, int range)

che dato un array a[] di n interi e un parametro range calcola e restituisce la somma s nel seguente modo:

    Se range è uguale a zero, s è la somma di tutti gli elementi dell'array a[]

    altrimenti, se range>0, s è la somma dei primi range elementi dell'array a[] oppure la somma di tutti gli elementi di a[] se range è maggiore della lunghezza di a[]

    altrimenti, se range<0, s è la somma degli ultimi -range elementi di a[] (si noti che -range è positivo), oppure la somma di tutti gli elementi di a[] se -range è maggiore della lunghezza di a[].

Si scriva poi un programma main che

    verifica che sia argc>2
    legge, con fscanf gli interi contenuti nel file di nome argv[1] e li memorizza in un array a[] allocato dinamicamente
    calcola il massimo m dei valori argv[2], argv[3], ..., argv[argc-1] convertiti in interi con la funzione atoi()
    invoca la funzione somme sull'array a[] e passando il valore m come parametro range

Il valore restituito da somme deve essere stampato su stdout. Dopo la stampa il programma deve deallocare tutta la memoria utilizzata e chiudure tutti i file e terminare. Non stampate altre informazioni su stdout, stampate eventuali messaggi informativi di debug su stderr.
Esempi

Si supponga che file contenga 1 2 3 4 5 6 7 8 9 10, allora

main file1 -5 2 0

deve restituire 3 in quanto il massimo è 2 quindi deve essere stampata la somma dei primi 2 elementi.

main file1 -5 -3 -10

deve restituire 27 in quanto il massimo è -3 quindi deve essere stampata la somma degli ultimi 3 elementi.

main file1 -5 -2 0

deve restituire 55 in quanto il massimo è 0 quindi deve essere stampata la somma di tutti elementi.

main file1 -5 20 4

deve restituire 55 in quanto il massimo è 20 che è maggiore della lunghezza dell'array quindi deve essere stampata la somma di tutti elementi.

main file1 -50 -11 -44

deve restituire 55 in quanto il massimo è -11, dato che 11 è maggiore della lunghezza dell'array quindi deve essere stampata la somma di tutti elementi.
Istruzioni

    Usate il tasto Run una volta sola per far partire una shell all'interno della Console

    Scrivete il vostro programma in main.c

    Se necessario consultate le pagine man online

    Il programma deve essere compilato senza errori con il comando make e generare un eseguibile di nome main (usate il makefile allegato)

    Dopo aver corretto tutti gli errori di compilazione e i warning verificare la correttezza dell'output dal terminale con gli esempi riportati sopra; utilizzare anche vagrind per verificare l'uso corretto della memoria e la completa deallocazione della stessa

    Quando tutto funziona, eseguite i test allegati all'esercizio (trovate l'opzione sotto il pulsante tools): se non vengono passati tutti l'esercizio non è considerato risolto (ricordate di compilare prima di eseguire i test).

    Prima della scadenza del tempo è necessario eseguire Submit su replit e consegnare il file main.c su moodle. Dopo la consegna non modificate più il programma.
