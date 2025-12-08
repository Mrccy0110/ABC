

/* project P: buffer_utils.c —— 全新的内部 API */

#include <string.h>

/* 读取数据后，根据目标缓冲区大小安全拷贝 */
size_t copy_line_safely(char *dst, size_t dst_cap,
                        const char *src, size_t src_cap) {
    size_t n = src_cap;

    /* 再次裁剪，保证不超过 dst_cap */
    if (n > dst_cap - 1) {
        n = dst_cap - 1;
    }

    memcpy(dst, src, n);   // 形态上：tainted length + memcpy
    dst[n] = '\0';

    return n;
}
