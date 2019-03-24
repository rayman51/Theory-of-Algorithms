# include <stdio.h>
# include <stdint.h>

union msgblock{
    uint8_t  e[64];
    uint32_t t[16];
    uint64_t s[8];
};// msgblock

int main(int argc, char *argv[]){

    union msgblock M;

    uint64_t nobits = 0;
    uint64_t nobytes;

    FILE* f;
    f = fopen(argv[1],"r");

    while (!feof(f)){
        nobytes = fread(M.e, 1, 64, f); 
        nobits = nobits + (nobytes * 8);

        if (nobytes < 56){
            printf("I've found a block with less than 55 bytes!\n");
            M.e[nobytes] = 0x80;

            while(nobytes < 56){
                nobytes = nobytes + 1;
                M.e[nobytes] = 0x00;
            }// while

            M.e[7] = nobits;
        }// if

    }// while

    fclose(f);

    for(int i = 0; i < 64; i++)
        printf("%x ", M.e[i]);
        printf("\n");
   
    return 0; 
}// main
