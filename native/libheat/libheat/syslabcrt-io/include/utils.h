#ifndef UTILS_H
#define UTILS_H

#define MAX_FILEPATH_LEN 1024
#define MAX_LEN 1024
#define READ_LEN 40

// 工具宏
#define LLT_ALLOC(n) malloc(n)
#define LLT_REALLOC(p, n) realloc((p), (n))
#define LLT_FREE(x) free(x)

void sleep_ms(int ms);

#endif
