#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include <locale.h>
#include <windows.h>
/*fonte https://www.clubedohardware.com.br/forums/topic/1290480-campo-minado-em-c/*/

void gotoxy(int x,int y)//Fun��o para for�ar uma posi��o para impress�o de texto
{
    COORD c; //Variavel de coordenada, lib windows https://learn.microsoft.com/pt-br/windows/console/coord-str
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);//transporta o prompt para a posi��o da coord.
}
int main(){
    setlocale(LC_ALL,""); //M�todo para evitar setar o locale de acordo com o locale do ambiente.
    srand(time(NULL)); //fun��o que previne o rand de repetir a seed.
    char campominado[5][5],cminado[5][5];
    int linha,coluna,i,j,k,flag=50,minas=5,nivel,jogada;
    for(i=0;i<5;i++)/*//cria��o do tabuleiro que aparece na tela*/
        for(j=0;j<5;j++)
            campominado[i][j]=0;

    for(linha=0;linha<minas;linha++)
        campominado[rand()%5][rand()%5] = '*'; /*https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm*/


    system("cls");
    printf("\n\n                  Colunas\n             0   1   2   3   4\n");
    printf("Linha 0 ->     |   |   |   |   \n");
    printf("            ---+---+---+---+---\n");
    printf("Linha 1 ->     |   |   |   |   \n");
    printf("            ---+---+---+---+---\n");
    printf("Linha 2 ->     |   |   |   |   \n");
    printf("            ---+---+---+---+---\n");
    printf("Linha 3 ->     |   |   |   |   \n");
    printf("            ---+---+---+---+---\n");
    printf("Linha 4 ->     |   |   |   |   \n");
    for(jogada=1;jogada<4;jogada++){/* la�o para controlar o n� de jogadas */
        do{
            gotoxy(5,15);
            printf("                                            \n");
            printf("                                              ");
            gotoxy(5,15);
            printf("Informa a linha que voce quer jogar: ");
            scanf("%d",&linha);
            printf("     Informe a coluna que voce quer jogar: ");
            scanf("%d",&coluna);
        }while((linha<0||linha>4) || (coluna<0||coluna>4));
        if(campominado[linha][coluna]=='*'){/* condi��o se marcar o espa�o que est� a mina, o jogo acaba */
            printf("\n\nVoce pisou na mina, buuummmm!");
            printf("\n\n       GAME OVER");
            flag=1;
            break;
        }
         else{
         campominado[linha][coluna]='X';/* condi��o se marcar um espa�o sem mina, vai aparecer o X no tabuleiro */
        }
        for(i=0;i<5;i++){                /* quantidade de linhas */
            k=13;                        /* primeira posi��o */
            for(j=0;j<5;j++){            /* quantidade de colunas */
                if(campominado[i][j] !='*')/* verifica se nessa posi��o n�o eh mina */
                {
                    gotoxy(k,i*2+4);      /* coloca o cursor nessa posi��o */
                    printf("%c",campominado[i][j]);/* imprime o que est� nessa posi��o */
                }
                k+=4;                     /* vai para a proxima posi��o no desenho na tela */
            }
        }
    }
    gotoxy(0,22);
    if(flag==0)printf("    Parab�ns,  Voc� Venceu . . . !\n");
    printf("\n          Finalizar . . . !\n\n");
    getch();
    return 0;
}
