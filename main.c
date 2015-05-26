/* itoa example */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "AES.h"


int main ()
{

  int i,j,k;

  unsigned char state[4][4] = {{0x32,0x88,0x31,0xE0},{0x43,0x5A,0x31,0x37},{0xF6,0x30,0x98,0x07},{0xa8,0x8D,0xA2,0x34}};
  unsigned char key[4][4]={{0x2B,0x28,0xAB,0x09},{0x7E,0xAE,0xF7,0xCF},{0x15,0xD2,0x15,0x4F},{0x16,0xA6,0x88,0x3C}};
  unsigned char expan_key[4][44];
  unsigned char temp[4][4];
  //============1. Read user text into matrix=================


  //Each letter is 1 byte, text should be <= 16 byte (128 bit). TextNofBits%128 =0 ?
  //What if user entered less than 128 bits?

  /*printf("Enter Plain Text:  ");
    scanf("%s",*state);

  //State length condition (16 letters only)
  printf("\n TEXT IN HEX \n");

  //PRINT IN HEX
  unsigned char state1[4][4]={{0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00}};
  for(i=0;i<4;i++){
  for(j=0;j<4;j++){
  state1[i][j]=state[i][j];
  }
  }
  */

  print(state);
  printf("\n KEY IN HEX \n");




  print(key);

  printf("\n");
  printf("\n");
  key_generate(key,expan_key);

  printf("\n");
  printf("\n");
  //=================2. Add round key Correct ================



  Add_key(state,key);

  printf("\n AFTER ADDING ROUND KEY \n");

  print(state);

  int start=4;
  int loop;
  unsigned char temp_key[4][4];
  //=================3. n round ================

  for(loop=1;loop<11;loop++)
  {
    printf("\n State %d \n",loop);

    print(state);




    for(i=0;i<4;i++)
    {
      for(j=0;j<4;j++)
      {
        temp_key[j][i]=expan_key[j][loop*start+i];
      }

    }


    printf("\n key %d \n",loop);


    print(temp_key);
    //=================3.a. SubByte ================


    subByte(state);

    printf("\n AFTER SubByte\n");

    print(state);

    printf("\n");


    //=================3.b. Shift raw Correct ================

    shiftRaw(state);


    printf("\n AFTER shift raw \n");

    print(state);

    printf("\n");


    //=================3.c. mix Column Correct ================
    if(loop!=10)
    {
      mixcolumn(state,temp);

      printf("\n AFTER MIX COLUMN \n");

      for(j=0;j<4;j++)
      {
        for (i=0;i<4;i++)
        {
          state[j][i]=temp[j][i];

        }
      }
    }

    print(state);

    //=================3.d. Add round key ================


    Add_key(state,temp_key);
    /*for(i=0;i<4;i++){
      for(j=0;j<4;j++){
      state[i][j]= state[i][j] ^ temp_key[i][j];
      }
      }
      */

    printf("\n AFTER ADDING ROUND KEY %d\n",loop);

    print(state);

    printf("\n");




  }

  return 0;



}
