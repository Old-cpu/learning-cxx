#include "../exercise.h"

// READ: 数组向指针退化 <https://zh.cppreference.com/w/cpp/language/array#%E6%95%B0%E7%BB%84%E5%88%B0%E6%8C%87%E9%92%88%E7%9A%84%E9%80%80%E5%8C%96>
bool is_fibonacci(int *ptr, int len, int stride) {
    ASSERT(len >= 3, "`len` should be at least 3");
    int *start_ptr = ptr; // 初始指向数组的起始位置

    // 找到斐波那契数列的起始点，即第一个非零元素
    while (start_ptr > ptr && *start_ptr == 0) {
        start_ptr--;
    }

    // 检查是否找到了斐波那契数列的起始点
    if (start_ptr == ptr) {
        return false; // 如果整个数组都是0，那么它不是一个斐波那契数列
    }

    // 从找到的起始点开始检查斐波那契数列
    for (int i = 0; i < len - 2; i++) {
        int actual_index_i = start_ptr - ptr + i * stride;
        int actual_index_i_plus_1 = start_ptr - ptr + (i + 1) * stride;
        int actual_index_i_plus_2 = start_ptr - ptr + (i + 2) * stride;

        if (ptr[actual_index_i_plus_2] != ptr[actual_index_i] + ptr[actual_index_i_plus_1]) {
            return false;
        }
    }
    return true;
}

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    int arr0[]{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55},
        arr1[]{0, 1, 2, 3, 4, 5, 6},
        arr2[]{99, 98, 4, 1, 7, 2, 11, 3, 18, 5, 29, 8, 47, 13, 76, 21, 123, 34, 199, 55, 322, 0, 0};
    // clang-format off
    ASSERT( is_fibonacci(arr0    , sizeof(arr0) / sizeof(*arr0)    , 1),         "arr0 is Fibonacci"    );
    ASSERT( is_fibonacci(arr0 + 2, sizeof(arr0) / sizeof(*arr0) - 4, 1), "part of arr0 is Fibonacci"    );
    ASSERT(!is_fibonacci(arr1    , sizeof(arr1) / sizeof(*arr1)    , 1),         "arr1 is not Fibonacci");
    ASSERT( is_fibonacci(arr1 + 1,  3                              , 1), "part of arr1 is Fibonacci"    );
    ASSERT(!is_fibonacci(arr2    , sizeof(arr2) / sizeof(*arr2)    , 1),         "arr2 is not Fibonacci");
    ASSERT( is_fibonacci(arr2 + 2, 10                              , 2), "part of arr2 is Fibonacci"    );
    ASSERT( is_fibonacci(arr2 + 3,  9                              , 2), "part of arr2 is Fibonacci"    );
    
    ASSERT(!is_fibonacci(arr2 + 3, 10                              , 2), "guard check"                  );
    ASSERT(!is_fibonacci(arr2 + 1, 10                              , 2), "guard check"                  );
    // clang-format on
    return 0;
}
