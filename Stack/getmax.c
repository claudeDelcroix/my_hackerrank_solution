int* getMax(int operations_count, char** operations, int* result_count) {
    int* stack = malloc(operations_count * sizeof(int));
    int stack_size = 0;
    int* result = malloc(operations_count * sizeof(int));
    *result_count = 0;
    
    for (int i = 0; i < operations_count; i++) {
        if (strncmp(operations[i], "1 ", 2) == 0) {
            int val;
            sscanf(operations[i], "1 %d", &val);
            stack[stack_size++] = val;
        } else if (strncmp(operations[i], "2", 1) == 0) {
            if (stack_size > 0) stack_size--;
        } else if (strncmp(operations[i], "3", 1) == 0) {
            if (stack_size > 0) {
                result[*result_count] = stack[0];
                for (int j = 1; j < stack_size; j++) {
                    if (stack[j] > result[*result_count]) {
                        result[*result_count] = stack[j];
                    }
                }
                (*result_count)++;
            }
        }
    }

    free(stack);
    return realloc(result, *result_count * sizeof(int));
}
