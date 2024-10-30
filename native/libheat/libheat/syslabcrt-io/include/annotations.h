#ifndef ANNOTATIONS_H
#define ANNOTATIONS_H

// 不导出 symbol，通过 funclookup.hpp 来查找
#define IORT_EXPORT

#define ATTRIBUTE_ALIGN_PTRSIZE

#define DEBUG 0
// 启用新开发函数宏s
#define TEST_FUNC_ID IOS_DEFAULT_TEST

// 用于unittest.c文件中进行分类测试
enum
{
    IOS_NONE,
    IOS_DEFAULT_TEST,
    IOS_READ_TEST,
    IOS_READ_ALL_TEST,
    IOS_WRITE_TEST,
    IOS_FILE_TEST
};

#endif