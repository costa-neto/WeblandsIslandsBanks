//
//senha: algoritmos2

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <math.h>

char a;
static const char * unidades[]  = { "Zero", "Um", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove" };
static const char * dez_vinte[] = { "", "Onze", "Doze", "Treze", "Quatorze", "Quinze", "Dezesseis", "Dezessete", "Dezoito", "Dezenove" };
static const char * dezenas[]   = { "", "Dez", "Vinte", "Trinta", "Quarenta", "Cinquenta", "Sessenta", "Setenta", "Oitenta", "Noventa" };
static const char * centenas[]  = { "", "Cento", "Duzentos", "Trezentos", "Quatrocentos", "Quinhentos", "Seiscentos", "Setecentos", "Oitocentos", "Novecentos" };


void moveXY(int x, int y, char t[10])
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {x,y};
    SetConsoleCursorPosition(hStdout, position);
    printf("%s", t);
}

void SetColor(int ForgC) //cores
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

void senha()
{
    srand((unsigned int)(time(NULL)));
	int index = 0;

	char char1[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	char senhagerada[4];
	for(index = 0; index < 4; index++)
	{
        senhagerada[index] = char1[rand() % (sizeof char1 - 1)];
	}
	moveXY(40,14,"sua senha: ");
	for(index = 0; index < 4; index++)
    {
        printf("%c",senhagerada[index]);
    }
    getch();
    system("cls");
    int a=10;
    do{
    char str1[15];
    SetColor(15);
    moveXY(40,14,"insira sua senha: ");
    scanf("%s",str1);
    a = strcmp(str1, senhagerada);
    if (a!=0)
    {
        system("cls");
        SetColor(12);
        moveXY(40,14,"*****senha incorreta*****\n");
        Sleep(300);
        system("cls");
        SetColor(13);
        moveXY(40,14,"digite novamente: ");
    }
    }while (a!=0);
    system("cls");
    SetColor(13);
}

char * strcatb( char * dst, const char * src )
{
    size_t len = strlen(src);
    memmove( dst + len, dst, strlen(dst) + 1 );
    memcpy( dst, src, len );
    return dst;
}
void retiracedulas()
{
    double bits;
    moveXY(1, 14, "INSIRA A QUANTIA DESEJADA EM BITS: ");
    scanf("%lf",&bits);
    int cem, cinquenta, vinte, dez, cinco, dois;
    int um, cinquentac, vintecc, dezc, cincoc, umc;
    int valor;
    valor=floor(bits);
    bits-=valor;
    cem=(valor/100);
    cinquenta=((valor%100)/50);
    vinte=((valor%100)%50)/20;
    dez=(((valor%100)%50)%20)/10;
    cinco=((((valor%100)%50)%20)%10)/5;
    dois=(((((valor%100)%50)%20)%10)%5)/2;
    um=(((((valor%100)%50)%20)%10)%5)%2;
    double valorm;
    valorm=bits*100;
    valor=round(valorm);
    cinquentac=valor/50;
    vintecc=(valor%50)/25;
    dezc=(((valor%50)%25)/10);
    umc=((valor%50)%25)%10;

    printf("\n\n");
    SetColor(10);
    if (cem!=0)
    printf(" %d nota(s) de 100 Bits\n",cem);
    if (cinquenta!=0)
    printf(" %d nota(s) de 50 Bits\n",cinquenta);
    if (vinte!=0)
    printf(" %d nota(s) de 20 Bits\n",vinte);
    if (dez!=0)
    printf(" %d nota(s) de 10 Bits\n",dez);
    if (cinco!=0)
    printf(" %d nota(s) de 5 Bits\n",cinco);
    if (dois!=0)
    printf(" %d nota(s) de 2 Bits\n",dois);
    printf("\n");
    SetColor(14);
    if (um!=0)
    printf(" %d moeda(s) de 1 CentBits\n",um);
    if (cinquentac!=0)
    printf(" %d moeda(s) de 50 CentBits\n",cinquentac);
    if (vintecc!=0)
    printf(" %d moeda(s) de 25 CentBits\n",vintecc);
    if (dezc!=0)
    printf(" %d moeda(s) de 10 CentBits\n",dezc);
    if (umc!=0)
    printf(" %d moeda(s) de 1 CentBits\n",umc);

    SetColor(13);
    moveXY(74,29,"pressione qualquer tecla para voltar ao menu");
    getch();
    system("cls");
}

char * traduzir_numero( char * nome, int n )
{
    int c = n / 100;
    int d = n / 10 - c * 10;
    int u = n - (n / 10) * 10;
    int dv = d * 10 + u;
	

    strcpy( nome, unidades[ u ] );

    if( n < 10 )
        return nome;

    if ( (dv > 10) && (dv < 20) )
    {
        strcpy( nome, dez_vinte[ dv - 10 ] );
    }
    else
    {
        if( u == 0 )
        {
            strcpy( nome, dezenas[ d ] );
        }
        else
        {
        	if( d != 0 ){
	            strcatb( nome, " e " );
    	        strcatb( nome, dezenas[d] );
        	}
        	else
        		strcatb( nome, dezenas[d] );
		}
    }

    if( n < 100 )
        return nome;

    if( (d == 0) && ( u == 0 ) )
    {
        if( c == 1 )
            strcpy( nome, "Cem" );
        else
            strcpy( nome, centenas[c] );
    }
    else
    {
        strcatb( nome, " e " );
        strcatb( nome, centenas[c] );
    }
    return nome;
}

void preencheCheque(){
	double valorCheque, inteiro, decimal;
	char bits[ 100 ];
	char centbits[100];
	moveXY(1, 14, "INSIRA A QUANTIA DESEJADA EM BITS: ");
    scanf("%lf",&valorCheque);
    decimal = modf(valorCheque, &inteiro);
	traduzir_numero(bits, (int)inteiro);
    printf("\n %s bits e", bits);
    traduzir_numero(centbits, (decimal*100));
    printf(" %s centbits", centbits);
}

void navegmenu()
{
    short posX = 91, posY = 27;
    moveXY(91, 27, "->");
    do
    {
        menu();
        moveXY(posX, posY, "->");
        a = toupper(getch());

        switch(a)
        {
            case 'H':
                if (posY > 27)
                {
                    moveXY(91,posY, "  ");
                    posY-=1;
                    moveXY(91,posY, "->");
                }
            break;

            case 'P':
                if (posY < 29)
                {
                    moveXY(91,posY, "  ");
                    posY+=1;
                    moveXY(91,posY, "->");
                }
            break;

            case 13:  //pressionou enter
                if (posY == 27) //retirar cédulas
                {
                	system("cls");
                	retiracedulas();
                }
                if (posY == 28) //preenchimento de cheques
                {
                    system("cls");
                    preencheCheque();
                }
                if (posY == 29) //sair
                {
                    system("cls");
                    exit(0);
                }
            break;
        }

    }while(1);

    system("pause");
    return 0;
}

void menu()
{
	moveXY(98,25, "TRAB WEBLANDS");
    moveXY(93,27,"retirar cédulas");
    moveXY(93,28,"preenchimento de cheques");
    moveXY(93,29,"sair");
    //desenho quadrado
    int astY;
    for (astY=24; astY<=29 ; astY++)
    {
        moveXY(90,astY,"|");
    }
    for (astY=24; astY<=29 ; astY++)
    {
        moveXY(118,astY,"|");
    }
    int astX;
    for (astX=91; astX<=117 ; astX++)
    {
        moveXY(astX,26,"_");
    }
    for (astX=91; astX<=117 ; astX++)
    {
        moveXY(astX,23,"_");
    }
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	system("COLOR 0D");
	senha();
	navegmenu();
    system("pause");
    return 0;
}
