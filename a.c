/* project P: handler.c */

#include <unistd.h>

ssize_t net_read_line(int fd, char *buf, size_t max);

size_t copy_line_safely(char *dst, size_t dst_cap,
                        const char *src, size_t src_cap);

int handle_request(int fd) {
    char recv_buf[512];
    char user_msg[128];

    /* [1] 从网络读入一行数据 —— 明确的 taint source */
    ssize_t n = net_read_line(fd, recv_buf, sizeof(recv_buf) - 1);
    if (n <= 0) return -1;
    recv_buf[n] = '\0';

    /* [2] 把外部数据安全拷贝到 user_msg 中 */
    copy_line_safely(user_msg, sizeof(user_msg), recv_buf, (size_t)n);

    /* 后续只对 user_msg 做业务逻辑使用 */
    // ...

    return 0;
}
/* project P: handler.c */

#include <unistd.h>

ssize_t net_read_line(int fd, char *buf, size_t max);

size_t copy_line_safely(char *dst, size_t dst_cap,
                        const char *src, size_t src_cap);

int handle_request(int fd) {
    char recv_buf[512];
    char user_msg[128];

    /* [1] 从网络读入一行数据 —— 明确的 taint source */
    ssize_t n = net_read_line(fd, recv_buf, sizeof(recv_buf) - 1);
    if (n <= 0) return -1;
    recv_buf[n] = '\0';

    /* [2] 把外部数据安全拷贝到 user_msg 中 */
    copy_line_safely(user_msg, sizeof(user_msg), recv_buf, (size_t)n);

    /* 后续只对 user_msg 做业务逻辑使用 */
    // ...

    return 0;
}
/* project P: handler.c */

#include <unistd.h>

ssize_t net_read_line(int fd, char *buf, size_t max);

size_t copy_line_safely(char *dst, size_t dst_cap,
                        const char *src, size_t src_cap);

int handle_request(int fd) {
    char recv_buf[512];
    char user_msg[128];

    /* [1] 从网络读入一行数据 —— 明确的 taint source */
    ssize_t n = net_read_line(fd, recv_buf, sizeof(recv_buf) - 1);
    if (n <= 0) return -1;
    recv_buf[n] = '\0';

    /* [2] 把外部数据安全拷贝到 user_msg 中 */
    copy_line_safely(user_msg, sizeof(user_msg), recv_buf, (size_t)n);

    /* 后续只对 user_msg 做业务逻辑使用 */
    // ...

    return 0;
}
/* project P: handler.c */

#include <unistd.h>

ssize_t net_read_line(int fd, char *buf, size_t max);

size_t copy_line_safely(char *dst, size_t dst_cap,
                        const char *src, size_t src_cap);

int handle_request(int fd) {
    char recv_buf[512];
    char user_msg[128];

    /* [1] 从网络读入一行数据 —— 明确的 taint source */
    ssize_t n = net_read_line(fd, recv_buf, sizeof(recv_buf) - 1);
    if (n <= 0) return -1;
    recv_buf[n] = '\0';

    /* [2] 把外部数据安全拷贝到 user_msg 中 */
    copy_line_safely(user_msg, sizeof(user_msg), recv_buf, (size_t)n);

    /* 后续只对 user_msg 做业务逻辑使用 */
    // ...

    return 0;
}
/* project P: handler.c */

#include <unistd.h>

ssize_t net_read_line(int fd, char *buf, size_t max);

size_t copy_line_safely(char *dst, size_t dst_cap,
                        const char *src, size_t src_cap);

int handle_request(int fd) {
    char recv_buf[512];
    char user_msg[128];

    /* [1] 从网络读入一行数据 —— 明确的 taint source */
    ssize_t n = net_read_line(fd, recv_buf, sizeof(recv_buf) - 1);
    if (n <= 0) return -1;
    recv_buf[n] = '\0';

    /* [2] 把外部数据安全拷贝到 user_msg 中 */
    copy_line_safely(user_msg, sizeof(user_msg), recv_buf, (size_t)n);

    /* 后续只对 user_msg 做业务逻辑使用 */
    // ...

    return 0;
}
/* project P: handler.c */

#include <unistd.h>

ssize_t net_read_line(int fd, char *buf, size_t max);

size_t copy_line_safely(char *dst, size_t dst_cap,
                        const char *src, size_t src_cap);

int handle_request(int fd) {
    char recv_buf[512];
    char user_msg[128];

    /* [1] 从网络读入一行数据 —— 明确的 taint source */
    ssize_t n = net_read_line(fd, recv_buf, sizeof(recv_buf) - 1);
    if (n <= 0) return -1;
    recv_buf[n] = '\0';

    /* [2] 把外部数据安全拷贝到 user_msg 中 */
    copy_line_safely(user_msg, sizeof(user_msg), recv_buf, (size_t)n);

    /* 后续只对 user_msg 做业务逻辑使用 */
    // ...

    return 0;
}
/* project P: handler.c */

#include <unistd.h>

ssize_t net_read_line(int fd, char *buf, size_t max);

size_t copy_line_safely(char *dst, size_t dst_cap,
                        const char *src, size_t src_cap);

int handle_request(int fd) {
    char recv_buf[512];
    char user_msg[128];

    /* [1] 从网络读入一行数据 —— 明确的 taint source */
    ssize_t n = net_read_line(fd, recv_buf, sizeof(recv_buf) - 1);
    if (n <= 0) return -1;
    recv_buf[n] = '\0';

    /* [2] 把外部数据安全拷贝到 user_msg 中 */
    copy_line_safely(user_msg, sizeof(user_msg), recv_buf, (size_t)n);

    /* 后续只对 user_msg 做业务逻辑使用 */
    // ...

    return 0;
}



size_t copy_line_safely(char *dst, size_t dst_cap,
                        const char *src, size_t src_cap) {
    size_t n = src_cap;
    if (n > dst_cap - 1) {
        n = dst_cap - 1;
    }
    memcpy(dst, src, n);
    dst[n] = '\0';
    return n;
}

int get_client_limit(app_ctx_t *app) {
    if (!app->prefs.initialized) {
        if (load_client_prefs(app) != 0) {
            return 32;
        }
    }
    int limit = app->prefs.max_items;
    if (limit <= 0) {
        limit = 1;
    } else if (limit > 100000) {
        limit = 100000;
    }
    return limit;
}

