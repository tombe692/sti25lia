#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX_BOX_SIZE 6
#define PADDING 2

void print_line(int idx);
void print_heder(int *ipt);
void print_num_row(int row_num, int *ipt);
void print_tabel(int *ipt);

int main(void){
    int ipt;
    printf("how many lines is the table?\nWrite here: ");
    scanf("%d", &ipt);
	assert(ipt > 0 && "ERR: bad input (Input below 0)");
    print_tabel(&ipt);
    return 0;
}

void print_line(int idx){
	char dashes[MAX_BOX_SIZE + 1];
    memset(dashes, '-', MAX_BOX_SIZE);
    dashes[MAX_BOX_SIZE] = '\0';

	printf("\n%-*s", MAX_BOX_SIZE, dashes);
	for(; idx>0; idx--){
		printf("%*s", MAX_BOX_SIZE, dashes);
	}
	printf("\n");
}

void print_heder(int *ipt){
    int idx=0;
    // Top row
    printf("%*c%*c", MAX_BOX_SIZE-PADDING, 'X', PADDING, '|');
    for(; idx<*ipt; idx++){
       printf("%*d%*c", MAX_BOX_SIZE-PADDING, idx+1, PADDING, '|');
    }
	// Seperation line
	print_line(idx);
}

void print_num_row(int row_num, int *ipt){
	printf("%*d%*c", MAX_BOX_SIZE-PADDING, row_num, PADDING, '|');
	for(int i=1; i<=*ipt; i++){
		printf("%*d%*c", MAX_BOX_SIZE-PADDING, i*row_num, PADDING, '|');
	}
}

void print_tabel(int *ipt){
	print_heder(ipt);
	for(int i=1; i<=*ipt; i++){
		print_num_row(i, ipt);
		if(i<*ipt){
			printf("\n");
		}
	}
	print_line(*ipt);
}
