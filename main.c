#include "func.h"
int main(int argc, char** argv){
    if (argc == 1){
        printf("No arguments found\n");
        return 0;
    }
    int size; 
    for (int i = 1; i < argc; i++){
        if ((argv[i][0] == '-') && (!strchr("0123456789", argv[i][1]))){
            size = (i + 1)/3;
            break;
        }
        if (i == argc - 1){
            size = (i + 1)/3;
        }
    }
    int* results = malloc(sizeof(int) * size);
    if (!results){
        printf("Error with memory allocation\n");
        return -1;
    }
    int i = 1;
    for (int j = 0; j < size; j++){
        if (strspn(argv[i], "-0123456789") != strlen(argv[i])){
            printf("Error in first argument of expression %d\n", j + 1);
            free(results);
            return 0;
        }
        int arg0 = atoi(argv[i]);
        i++;
        if (strlen(argv[i]) != 1){
            printf("Error with operator in expression %d\n", j + 1);
            free(results);
            return 0;
        }
        char op = argv[i][0];
        i++;
        if (strspn(argv[i], "-0123456789") != strlen(argv[i])){
            printf("Error in second argument of expression %d\n", j + 1);
            free(results);
            return 0;
        }
        int arg1 = atoi(argv[i]);
        results[j] = get_ans(arg0, arg1, op);
        if (results[j] == INT_MIN){
            printf(" in expression %d\n", j + 1);
            free(results);
            return 0;
        }
        i++;
    }
    print_ans(results, size);
    if (i != argc){
        if (strcmp(argv[i], "-k") != 0){
            printf("ERROR: unknown flag\n");
            free(results);
            return 0;
        }
        i++;
        if (i == argc || (strspn(argv[i], "-0123456789") != strlen(argv[i]))){
            printf("ERROR: expected integer after '-k'\n");
            free(results);
            return 0;
        }
        print_ans_str(results, size, atoi(argv[i]));
    }else{
        printf("No flags found, end of programm\n");
    }
    free(results);
    return 0;
}
