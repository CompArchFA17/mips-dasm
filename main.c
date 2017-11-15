#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "mips_dasm.h"

int main(int argc, char **argv) {

    while (!feof(stdin)) {
        int line_no = 0;
        char line[32];
        line[0] = 0;
        fscanf(stdin, "%s", line);
        
        if(line[0]) {
            uint32_t number = 0;
            mips_instruction_t* instruction = calloc(1, sizeof(mips_instruction_t));
            line_no += 1;
    
            sscanf(line, "%x", &number);
            
            //printf("%d", line_no);
    
            if(mips_disassemble(instruction, number)) {
                //printf(" (%c-type) ", instruction->type);
                //printf("[%10u:0x%08x] ", number, number);
                printf("%s %s\n", instruction->name, instruction->arguments);
            } else {
                printf("[0x%08x]\n", number);
                //printf("Invalid instruction");
            }
    
            free(instruction);
    	fflush(stdout);
        }
    }
    return 0;
}
