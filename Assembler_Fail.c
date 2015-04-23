// Mark Soderblom
// CPTR 131-01
// 23 April 2015
// Lab 2 - Assembler

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	
	// Read the main file name
	char main_file_name[64];
	
	printf("Please enter the main file name: ");
	scanf("%s", main_file_name);
	printf("Checking for file --> %s\n", main_file_name);
	
	// Create file names for the assembly input file, the listing file, and the object file
	
	FILE *assembly;
	FILE *listing;
	FILE *object;
	
	// Open the input file if it exists, else give an error message and quit
	
	assembly = fopen("test.asm", "r");
		if (assembly == NULL){
			printf("Error opening file!!!\n");
			return (-1);
			exit(0);
	}
	
	listing = fopen("test.lst", "w+");
	object = fopen("test.obj", "w+");
	
	printf("Mem\tOpcode\tSource\n");
	fputs("Mem\tOpcode\tSource\n", listing);
	
	// Set address to 0
	
	int address = 00;
	
	// While there are lines to read
	
	char str[120];
		
	while (fgets(str, 120, assembly) != NULL){
		if (1 == 0){
			printf("%x\t\t%s",address, str);
			fputs(("%x\t\t%s", address, str), listing);
		}
		else{
			
			// Get Four Tokens!
			
			char *token1 = strtok(str, " ,\t");
			char *token2 = strtok(NULL," ,\t");
			char *token3 = strtok(NULL," ,\t");
			char *token4 = strtok(NULL," ,\t");
			
			int opcode1 = 0;
			int opcode2 = 2;
			int opcode3 = 3;
			int opcode4 = 4;
			
			// Convert to OpCode
			
			int get_opcode(char *command){
				if(strcmp(command, "NOP") == 0){
					opcode1 = 0;
				}
				if(strcmp(command, "LDD") == 0){
					opcode1 = 1;
				}
				if(strcmp(command, "LDI") == 0){
					opcode1 = 2;
				}
				if(strcmp(command, "STO") == 0){
					opcode1 = 3;
				}
				if(strcmp(command, "MOV") == 0){
					opcode1 = 4;
				}
				if(strcmp(command, "ADI") == 0){
					opcode1 = 5;
				}
				if(strcmp(command, "ADF") == 0){
					opcode1 = 6;
				}
				if(strcmp(command, "OR") == 0){
					opcode1 = 7;
				}
				if(strcmp(command, "AND") == 0){
					opcode1 = 8;
				}
				if(strcmp(command, "XOR") == 0){
					opcode1 = 9;
				}
				if(strcmp(command, "ROR") == 0){
					opcode1 = 10;
				}
				if(strcmp(command, "JMP") == 0){
					opcode1 = 11;
				}
				if(strcmp(command, "HLT") == 0){
					opcode1 = 12;
				}
				if(strcmp(command, "LDX") == 0){
					opcode1 = 13;
				}
				if(strcmp(command, "STX") == 0){
					opcode1 = 14;
				}
			}
			
			address += 2;
			
			get_opcode(token1);
			
			
			printf("%x\t%x%c %c%c\t%s\n", address, opcode1, opcode2, opcode3, opcode4, str);
			fputs(("%x\t%x\t%s", address, opcode1, str), listing);
			//fputs(opcode1, object);
		}
	}
	
	fclose(listing);
	fclose(object);
	fclose(assembly);
}