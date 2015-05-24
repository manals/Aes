#include <stdio.h>


int main(){

    
    char state[4][4];
    char key[4][4]={'f','x','r','w','3','5','d','s','g','h','c','s','w','q','s','l'};
    int i,j;

//============1. Read user text into matrix================= 

/* it is goint to be stored as hex internally
**refer to http://stackoverflow.com/questions/16519056/convert-ascii-char-to-hexadecimal-char-in-c 
**if convert is needed. 
*/

//Each letter is 1 byte, text should be <= 16 byte (128 bit). TextNofBits%128 =0 ?
//What if user entered less than 128 bits?

printf("Enter Plain Text:  ");
scanf("%s",state);

 
 printf("\n TEXT IN HEX \n");
  
//PRINT IN HEX
  
for(i=0;i<4;i++){
  for(j=0;j<4;j++){
 printf("%hhX.",state[i][j]);
//Q: Why 2,2 is 40 and 2,1 is 05 if nothing was entered!
}
printf("\n");
}

printf("\n KEY IN HEX \n");
  
  
for(i=0;i<4;i++){
  for(j=0;j<4;j++){
 printf("%hhX.",key[i][j]);

}
printf("\n");
}
 
//=================2. Add round key ================


for(i=0;i<4;i++){
  for(j=0;j<4;j++){
state[i][j]= state[i][j] ^ key[i][j];
}
}

printf("\n AFTER ADDING ROUND KEY \n");
  
for(i=0;i<4;i++){
  for(j=0;j<4;j++){
 printf("%hhX.",state[i][j]);
}
printf("\n");
}

}
