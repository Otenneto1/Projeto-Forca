#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//Função de impressão
void imprimirGame(int state){

if (state == 0) {
    printf("\n|---------------|");
    printf("\n|                ");
    printf("\n|                ");
    printf("\n|                ");
    printf("\n|                ");
    printf("\n|                ");
    printf("\n|                ");
    printf("\n-                ");
    }

if (state == 1) {
    printf("\n|---------------|");
    printf("\n|               O");
    printf("\n|                ");
    printf("\n|                ");
    printf("\n|                ");
    printf("\n|                ");
    printf("\n|                ");
    printf("\n-                ");
    }

if (state == 2) {
    printf("\n|---------------|");
    printf("\n|               O");
    printf("\n|               |");
    printf("\n|                ");
    printf("\n|                ");
    printf("\n|                ");
    printf("\n|                ");
    printf("\n-                ");
    }

if (state == 3) {
    printf("\n|---------------|");
    printf("\n|               O");
    printf("\n|              /|");
    printf("\n|                ");
    printf("\n|                ");
    printf("\n|                ");
    printf("\n|                ");
    printf("\n-                ");
    }

if (state == 4) {
    printf("\n|---------------|");
    printf("\n|               O");
    printf("\n|              /|\\");
    printf("\n|                ");
    printf("\n|                ");
    printf("\n|                ");
    printf("\n|                ");
    printf("\n-                ");
    }

if (state == 5) {
    printf("\n|---------------|");
    printf("\n|               O");
    printf("\n|              /|\\");
    printf("\n|              / ");
    printf("\n|                ");
    printf("\n|                ");
    printf("\n|                ");
    printf("\n-                ");
    }

if (state == 6) {
    printf("\n|---------------|");
    printf("\n|               O");
    printf("\n|              /|\\");
    printf("\n|              / \\");
    printf("\n|                ");
    printf("\n|                ");
    printf("\n|                ");
    printf("\n-                ");
    }
}

int main()
{

 int statusJogo = 0;
 srand(time(NULL));
 int num_sorte = rand() % 4;

 //Palavras para a forca

 char palavrasecreta[10][20];

    strcpy(palavrasecreta[0], "tartaruga");
    strcpy(palavrasecreta[1], "pinguim");
    strcpy(palavrasecreta[2], "macaco");
    strcpy(palavrasecreta[3], "cachorro");
    strcpy(palavrasecreta[4], "serpente");
    strcpy(palavrasecreta[5], "cavalo");
    strcpy(palavrasecreta[6], "gato");
    strcpy(palavrasecreta[7], "peixe");
    strcpy(palavrasecreta[8], "elefante");
    strcpy(palavrasecreta[9], "girafa");

 char underscore[20];
 char palavraGame[20];
 char letra;


 printf("A palavra sorteada tem %lu letras", strlen(palavrasecreta[num_sorte]));
 strcpy(underscore, palavrasecreta[num_sorte]);
 strcpy(palavraGame, underscore);

  for(int u=0;u < strlen(underscore);u++)
    underscore[u]= '_';


 while(1){

 //Imprimir a Forca
 imprimirGame(statusJogo);

 //Imprimir os traços para palavra
 for(int u=0;u < strlen(underscore);u++)
    printf("%c ", underscore[u]);

 //Receber a letra do jogador
 printf("\nLetra: ");
 scanf(" %c", &letra);

 //Se a letra está correta e atualização da tela do game
  int flag = 1;
  for(int u=0;u < strlen(underscore);u++){
    if (letra == palavraGame[u]){
        underscore[u] = letra;
        flag = 0;
    }
   }

 //Se não, incrementa erro
   if (flag == 1){
     statusJogo++;
   }
 //Verificar o andamento do jogo

 if (strcmp(palavraGame, underscore)==0){
   imprimirGame(statusJogo);
    printf("\nAcertou: %s", palavraGame);
    printf("\nYou Win!");
    break;
 }

 if (statusJogo==6){
   imprimirGame(statusJogo);
   printf("\nYou Lose!");
   break;
   }
 }

return 0;
}
