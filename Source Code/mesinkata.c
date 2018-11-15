#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"


/* State Mesin Kata */
boolean EndKata;
Kata CKata;

void IgnoreBlank(){
    while ((CC== BLANK || CC == '\n') && CC != MARK){
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA(char* filename){
    START(filename);
    IgnoreBlank();
    if (CC == MARK)
        EndKata = true;
    else{
        EndKata = false;
        SalinKata();
    }
}
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA(){
    IgnoreBlank();
    if (CC == MARK){
        EndKata = true;}
    else{
        SalinKata();
        IgnoreBlank();
    }
}

/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata(){
    int i;
    i =0;
    for(;;){
        CKata.TabKata[i] = CC;
        ADV();
        if ( CC== MARK || CC == BLANK || CC == '\n' )
            break;
        else
            i ++;

    }
    CKata.Length = i;
/*
    int i;
    i=1;
    while ((CC!=MARK) && ((CC!= BLANK)&&(CC!= '\n'))){
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }*/
}
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
