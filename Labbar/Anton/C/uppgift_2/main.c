// #include <stdio.h>

// #define MAX_BOX_SIZE 4

// void print_heder(int *ipt){
//     int i=1;
//     printf(" X |");
//     for(; i<=*ipt; i++){
//         printf("%*d", MAX_BOX_SIZE, i);
//         // printf("%d\t", i);
//     }
//     printf("\n----");
//     for(; i>1; i--){
//         printf("%*c |", MAX_BOX_SIZE, '-');
//         // printf("0");
//     }
//     printf("\n");
// }

// int main(void){
//     int ipt;
//     printf("how many lines is the table?\nWrite here: ");
//     scanf("%d", &ipt);
//     print_heder(&ipt);
    
    
//     return 0;
// }

#include <stdio.h>
#include <string.h>

int main() {
  int column_width = 12;

  printf("%-*s | %-*s | %-*s\n", column_width, "Number", column_width,
         "Description", column_width, "Value");
  printf("%-*c | %-*c | %-*c\n", column_width, '-', column_width, '-',
         column_width, '-');

  printf("%-*d | %-*s | %*.*d\n", column_width, 123, column_width, "First",
         column_width, 2, 4567);
  printf("%-*d | %-*s | %*.*d\n", column_width, 456, column_width, "Second",
         column_width, 4, 789);
  printf("%-*d | %-*s | %*.*d\n", column_width, 7890, column_width, "Third",
         column_width, 1, 12345);

  return 0;
}

