#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>

typedef struct Question{
    int num1;
    int num2;
} Question;

typedef Question *Q_ptr; 

Q_ptr create_question(void){
    Q_ptr q = (Q_ptr)malloc(sizeof(Question));
    assert(q != NULL);
    q->num1 = rand() % 100; 
    q->num2 = rand() % 100; 
    return q;
}

int answer_question(Q_ptr q){
    int sum = q->num1 + q->num2, answer = 0;
    while(1){
        printf("What is the sum of %d + %d?\nYour answer: ", q->num1, q->num2);
        scanf("%d", &answer);
        if(answer == sum){
            printf("You got it right\n%d + %d = %d\n\n", q->num1, q->num2, sum);
            break;
        }
        else{
            printf("Wrong answer, try again\n\n");
        }
    }
    free(q);
    return 1;
}

int main(void){
    srand(time(0));
    printf("Hello\n");
    char ipt;
    while(1){
        Q_ptr q = create_question();
        answer_question(q);
        printf("Do you want to stop playing? (y/n)\n");
        while(1){
            scanf(" %c", &ipt);
            // printf("dbg: %s\n", ipt);
            if(tolower(ipt) == 'y'){ return 0; }
            else if(tolower(ipt) == 'n'){ break; }
            else{ printf("Write y or n\n"); }
        }
        printf("\n");
    }
    return 0;
}