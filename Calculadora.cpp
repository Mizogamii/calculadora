#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void opcao1(), opcao2(), opcao3(), opcao4(), opcao5(), opcao6(), imprimirMenu(), decimalBin(int dec), decimalHex(int dec);
int binarioDec(char num[]), hexadecimalDec(char hexadecimal[]);

int main(){

	setlocale(LC_ALL, "Portuguese");

	int opcao, retorno = -1;

	while(opcao != 0){
		imprimirMenu();
		printf("Escolha a opção desejada: ");
		retorno = scanf("%d", &opcao);
		fflush(stdin);
		if(retorno == 0){
			system("cls");
			printf("ERRO!\nDigite apenas números de 0 a 6");
		}else{
			system("cls");
			printf("\n");
			switch (opcao){
				case 1: //De binário para decimal
					printf("----------------------------------------------\n");
					printf("\t     BINÁRIO PARA DECIMAL\n");
					printf("----------------------------------------------\n");
					opcao1();
					break;
				case 2: //De binário para hexadecimal	
					printf("----------------------------------------------\n");
					printf("\t   BINÁRIO PARA HEXADECIMAL\n");
					printf("----------------------------------------------\n");
					opcao2();
					break;
					
				case 3: //Decimal para binário
					printf("\n----------------------------------------------\n");
					printf("\t    DECIMAL PARA BINÁRIO\n");
					printf("----------------------------------------------\n");
					opcao3();
					break;
					
				case 4: //Decimal para hexadecimal
					printf("----------------------------------------------\n");
					printf("\t   DECIMAL PARA HEXADECIMAL\n");
					printf("----------------------------------------------\n");
					opcao4();
					break;
					
				case 5: // Hexadecimal pra binário
					printf("----------------------------------------------\n");
					printf("\t   HEXADECIMAL PARA DECIMAL\n");
					printf("----------------------------------------------\n");
					opcao5();
					break;
					
				case 6: //Hexadecimal para decimal
					printf("----------------------------------------------\n");
					printf("\t    HEXADECIMAL PARA BINÁRIO\n");
					printf("----------------------------------------------\n");
					opcao6();
					break;
					
				case 0:
					printf("Encerrando...");
					abort();
					break;
					
				default:
					printf("ERRO!\nDigite apenas números de 0 a 6!");
					break;
			}
		}
		printf("\n");
		system("pause");
		system("cls");
	}
}

void opcao1(){ //Binário para decimal
	
	char numero[50];
	int decimal; 

	printf("Digite o número binário: ");
	scanf("%s", &numero);
	fflush(stdin);
	
	decimal = binarioDec(numero);
	if(decimal != NULL){
		printf("\nDecimal: %d", decimal);	
	}

	printf("\n----------------------------------------------\n");			
}

void opcao2(){ //Binário para hexadecimal 

	char numero[50]; 
	int decimal;
	
	printf("Digite o número binário: ");
	scanf("%s", &numero);
	fflush(stdin);
	
	decimal = binarioDec(numero);
	if(decimal != NULL){
		decimalHex(decimal);
	}
	
	printf("\n----------------------------------------------\n");	
}

void opcao3(){ //Decimal para binário
	
	int decimal, retorno = -1;
	
	printf("Digite um número decimal: ");
	retorno = scanf("%d", &decimal);
	fflush(stdin);
	
	if(retorno == 0){
		printf("\nAtenção! Digite apenas números!\nTente novamente!");
	}else{
		printf("\nDecimal: %d", decimal);
		
		if(decimal == 0){
			printf("\nBinário: 0");
		}else{
			decimalBin(decimal);		
		}
	}

	printf("\n----------------------------------------------\n");
}

void opcao4(){ //Decimal para hexadecimal
	
	int decimal, retorno = -1; 
	
	printf("Digite um número decimal: ");
	retorno = scanf("%d", &decimal);
	fflush(stdin);
	
	if(retorno == 0){
		printf("\nAtenção! Digite apenas números!\nTente novamente!");
	}else{
		printf("\nDecimal: %d", decimal);
		
		if(decimal == 0){
			printf("\nHexadecimal: 0");
		}else{
			decimalHex(decimal);
		}
	}
	
	printf("\n----------------------------------------------\n");	
}

void opcao5(){ // Hexadecimal para binário
	
	char hexadecimal[50];
	int decimal;
	
	printf("Digite um número hexadecimal: ");
	scanf("%s", &hexadecimal);	
	
	decimal = hexadecimalDec(hexadecimal);
	
	if(decimal != NULL){
		printf("\nDecimal: %d", decimal);
	}
	
	printf("\n----------------------------------------------\n");
}

void opcao6(){ //Hexadecimal para decimal
	
	char hexadecimal[50];
	int decimal;

	printf("Digite um número hexadecimal: ");
	scanf("%s", &hexadecimal);	
	
	decimal = hexadecimalDec(hexadecimal);

	if(decimal != NULL){
		decimalBin(decimal);
	}
	
	printf("\n----------------------------------------------\n");
    
}

void imprimirMenu(){
	
	printf("----------------------------------------------\n");
	printf("                     MENU                     \n");
	printf("----------------------------------------------\n");
	printf("1 - Binário para decimal\n");
	printf("2 - Binário para hexadecimal\n");
	printf("3 - Decimal para binário\n");
	printf("4 - Decimal para hexadecimal\n");
	printf("5 - Hexadecimal para decimal\n");
	printf("6 - Hexadecimal pra binário\n");
	printf("0 - Sair\n");
	printf("----------------------------------------------\n");
}

int binarioDec(char num[]){
	
	int binario[100];
	int qtd, i = 0, j = 0, decimal = 0;
	bool errou = false;
	
	qtd = strlen(num);
		
	for(i = 0; i < qtd; i++){
		if(num[i] != '0' && num[i] != '1'){
			errou = true;
		}
	}
	
	if(!errou){
		printf("\nBinário: ");
		for(i = 0; i < qtd; i++){
			printf("%c", num[i]);
		}
	}
	
	for(i = 0; i < qtd; i++){
		if(num[i] == 48){
			num[i] = 0;
		}else if(num[i] == 49){
			num[i] = 1;
		}
	}

	if(errou == true){
		printf("\nNúmero binário é composto de 0 e 1!\nTente novamente!");
	}else{	
		for(i = qtd - 1; i >= 0; i--){	
			binario[i] = pow(2, j);
			if(num[i] == 1){
				decimal = decimal + binario[i];
			}
		j++;
		}
	}
	return decimal;
}

void decimalBin(int dec){
	
	int contador = 0, i = 0, binario[50];
	
	while(dec > 0){
			contador++;
			binario[i] = dec % 2;
			dec = dec / 2;
			i++;
	}
	
		
	printf("\nBinário: ");
	for(i = contador - 1; i >= 0; i--){
		printf("%d", binario[i]);
	}
}

void decimalHex(int dec){
	
	char hexadecimal[50];
	int i = 0, contador = 0;
	
	while(dec > 0){
		contador++;
		hexadecimal[i] = dec % 16;
		dec = dec / 16;
		i++;
	}
			
	printf("\nHexadecimal: ");	
	for(i = contador - 1; i >= 0; i--){
		if(hexadecimal[i] < 10){
			hexadecimal[i] = hexadecimal[i] + '0';
		}else{
			hexadecimal[i] = hexadecimal[i] + 'A' - 10; 
		}
		printf("%c", hexadecimal[i]);
	}	
}

int hexadecimalDec(char hexadecimal[]){
	
	int decimal = 0, i = 0, j = 0, qtd, resp, numero;
	bool errou = false;
	
	qtd = strlen(hexadecimal);

	for(i = 0; i < qtd; i++){
		hexadecimal[i] = toupper(hexadecimal[i]);
	}
	
	for(i = 0; i <= qtd - 1; i++){
		if(hexadecimal[i] == 'A'){
			resp = 10 * (pow(16, qtd - 1 - i));
			decimal += resp;
			
		}else if(hexadecimal[i] == 'B'){
			resp = 11 * (pow(16, qtd - 1 - i));
			decimal += resp;
			
		}else if(hexadecimal[i] == 'C'){
			resp = 12 * (pow(16, qtd - 1 - i));
			decimal += resp;
			
		}else if(hexadecimal[i] == 'D'){
			resp = 13 * (pow(16, qtd - 1 - i));
			decimal += resp;	
			
		}else if(hexadecimal[i] == 'E'){
			resp = 14 * (pow(16, qtd - 1 - i));
			decimal += resp;		
			
		}else if(hexadecimal[i] == 'F'){
			resp = 15 * (pow(16, qtd - 1 - i));
			decimal += resp;		
			
		}else if(hexadecimal[i] > 47 and hexadecimal[i] < 58){
			numero = hexadecimal[i] - 48;
			resp = numero * pow(16, qtd - 1 - i);
			decimal += resp;
		}else{
			errou = true;
		}
	}
	
	if(errou){
		printf("\nDigite números de 1 a 9 e letras de A até F!\nTente novamente!!");
		decimal = NULL;
	}else{
		printf("\nHexadecimal: %s", hexadecimal);
	}
		return decimal;
}
