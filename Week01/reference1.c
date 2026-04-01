#if 0

#include "mylib.h"
#define SIZE(a) (sizeof(a)/sizeof(a[0]))

typedef enum {
    eEXEC_ARR_LOAD_DATA = 0,
    eEXEC_ARR_PRINT_DATA,
    eEXEC_ARR_GET_MIN,
    eEXEC_ARR_GET_MAX,
    eEXEC_ARR_GET_SUM,
    eEXEC_ARR_GET_AVG,
    eEXEC_ARR_GET_SORT,
    eEXEC_ARR_MAX
} eEXEC_ARR;


typedef struct {
    char* exec_name;
    int (*exec_handle)(int*, int);
} stEXEC_TABLE;

stEXEC_TABLE exec_table[eEXEC_ARR_MAX] = {
    [eEXEC_ARR_LOAD_DATA] = { "Load Data",    scanf_ary },
    [eEXEC_ARR_PRINT_DATA] = { "Print Data",    print_ary },
    [eEXEC_ARR_GET_MIN] = { "Get Min",        findmin_ary },
    [eEXEC_ARR_GET_MAX] = { "Get Max",        findmax_ary },
    [eEXEC_ARR_GET_SUM] = { "Get Sum",        sum_ary },
    [eEXEC_ARR_GET_AVG] = { "Get Avg",        avg_ary },
    [eEXEC_ARR_GET_SORT] = { "Sort Data",    sort_ary }
};

int main(void) {
    int ary[5] = { 0 };
    int exec_input = 0;

    while (1) {
        printf("-------------------------------------\n");
        printf("# Select EXEC Type\n");
        printf("-------------------------------------\n");

        for (size_t iAry = 0; iAry < eEXEC_ARR_MAX; iAry++) {
            printf("\t%zu: - %s\n", iAry + 1, exec_table[iAry].exec_name);
        }
        printf("\t%d: - %s\n", 0, "EXIT");
        printf("-------------------------------------\n");
        printf("Select Menu> ");

        scanf("%d", &exec_input);
        printf("-------------------------------------\n");

        if (exec_input == 0) {
            printf("Exit\n");
            return 0;
        }
        if (exec_input > eEXEC_ARR_MAX || exec_input < 0) {
            fprintf(stderr, "Wrong EXEC NUM");
            return 1;
        }

        printf("# EXEC RESULT:\n\t%d\n", exec_table[exec_input - 1].exec_handle(ary, SIZE(ary)));
        printf("-------------------------------------\n");
    }

    return 0;
}

#endif