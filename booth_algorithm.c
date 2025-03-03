#include <stdio.h>
#include <stdlib.h>

void boothAlgorithm(int multiplicand, int multiplier) {
    int A = multiplicand;
    int Q = multiplier;
    int Q1 = 0;
    int M = multiplicand;
    int count = sizeof(int) * 8;
    
    while (count > 0) {
        int Q0 = Q & 1;
        
        if (Q0 == 1 && Q1 == 0) {
            A = A - M;
        } else if (Q0 == 0 && Q1 == 1) {
            A = A + M;
        }
        
        int temp = A & (1 << (sizeof(int) * 8 - 1));
        A = (A >> 1) & ~(1 << (sizeof(int) * 8 - 1));
        Q = Q >> 1;
        if (temp) {
            Q = Q | (1 << (sizeof(int) * 8 - 1));
        }
        Q1 = Q0;
        count--;
    }
    
    printf("Result: %d\n", A);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <multiplicand> <multiplier>\n", argv[0]);
        return 1;
    }
    
    int multiplicand = atoi(argv[1]);
    int multiplier = atoi(argv[2]);
    
    boothAlgorithm(multiplicand, multiplier);
    
    return 0;
}
