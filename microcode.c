#include <stdio.h>
#include <math.h>

#define TOTAL_OPS 32

#define OAM_MAR_CL  		(int) pow(2, 0)
#define OAM_EN 				(int) pow(2, 1)
#define OAM_MAR_INC 		(int) pow(2, 2)
#define X_L					(int) pow(2, 3)
#define X_COUNTER_L			(int) pow(2, 4)
#define Y_L 				(int) pow(2, 5)
#define Y_COUNTER_L 		(int) pow(2, 6)
#define W_L 				(int) pow(2, 7)
#define W_COUNTER_L			(int) pow(2, 8)
#define H_L					(int) pow(2, 9)
#define H_COUNTER_L 		(int) pow(2, 10)
#define VMAR_L				(int) pow(2, 11) 
#define VRAM_EN				(int) pow(2, 12) 
#define VGA_BUFFER_L		(int) pow(2, 13) 
#define W_COUNTER_DEC		(int) pow(2, 14) 
#define X_COUNTER_INC 		(int) pow(2, 15) 
#define VMAR_INC			(int) pow(2, 16) 
#define H_COUNTER_DEC		(int) pow(2, 17) 
#define Y_COUNTER_INC		(int) pow(2, 18) 
#define W_EN				(int) pow(2, 19) 
#define H_EN				(int) pow(2, 20) 
#define X_EN				(int) pow(2, 21) 
#define Y_EN				(int) pow(2, 22) 
#define JNZ_W				(int) pow(2, 23) 
#define JZ_OAM				(int) pow(2, 24) 
#define JZ_H				(int) pow(2, 25) 
#define JMP					(int) pow(2, 26) 

#define JUMP_ADDRESS_OFFSET 27



int microcode[TOTAL_OPS];


void init_microcode() {

	for (int i = 0; i < TOTAL_OPS; i++) {
		switch (i) {
			case 0: microcode[i] = OAM_MAR_CL | OAM_EN; break;
			case 1: microcode[i] = JMP | 1 << JUMP_ADDRESS_OFFSET; break;
			default: microcode[i] = 0xffff; break;
		}		
	}
}


int main () {

	init_microcode();

	FILE *f = fopen ("microcode.txt", "w");
	fwrite(microcode, 1, sizeof(microcode), f);
	fclose(f);

	return 0;
}
