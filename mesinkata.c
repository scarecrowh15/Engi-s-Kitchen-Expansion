/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */


#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"

boolean EndKata;
Kata CKata;


void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
{
  while (CC == BLANK && CC!=MARK) {
    ADV();
  }
}
void STARTKATA()
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
  START();
  IgnoreBlank();

  if (CC==MARK) {
    EndKata = true;
  } else {
    EndKata = false;
    SalinKata();

  }


  }

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
  IgnoreBlank();

  if(CC==MARK) {
    EndKata = true;
  } else {
    EndKata = false;
    SalinKata();
    IgnoreBlank();
  }
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{

  //Kamus
  int i;
  //Algo
  i = 1;
  while ((CC!=MARK) && (i <= NMax) && (CC!= BLANK)) {
    CKata.TabKata[i] = CC;
    ADV();
    i++;
  }

if(i>NMax){
  while(CC!=MARK) {
    ADV();
  }
}

  CKata.Length = i-1;
}

void CopyKata (char *akhir, char *awal){
  /* KAMUS */
  int i;
  
  /* ALGORITMA */
  i = 0;
  
  while (awal[i] != '\0'){
      akhir[i] = awal[i]
      i++;
    }
  
}
