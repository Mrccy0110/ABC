































































































































































































/* handler.c */

#include "app_ctx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define ITEM_SIZE 32

extern int g_backend_fd;

int handle_client(int sock_fd) {
    app_ctx_t app;
    app_ctx_init(&app, sock_fd);

    int limit = get_client_limit(&app);
    size_t total = (size_t)limit * ITEM_SIZE;
    
    char *buf = (char *)malloc(total);
    if (!buf) {
        const char *resp = "ERR no memory\n";
        (void)write(sock_fd, resp, strlen(resp));
        return -1;
    }
    size_t off = 0;
    for (int i = 0; i < limit; ++i) {
        ssize_t n = read(g_backend_fd, buf + off, ITEM_SIZE);
        if (n <= 0) {
            free(buf);
            return -1;
        }
        off += (size_t)ITEM_SIZE;
    }

    free(buf);
    return 0;
}









int handle_request(int fd) {
    char recv_buf[512];
    char user_msg[128];

    ssize_t n = net_read_line(fd, recv_buf, sizeof(recv_buf) - 1);
    if (n <= 0) return -1;
    recv_buf[n] = '\0';

    copy_line_safely(user_msg, sizeof(user_msg), recv_buf, (size_t)n);


    if (strcmp(user_msg, "PING") == 0) {
        const char *resp = "PONG\n";
        (void)write(fd, resp, strlen(resp));
    } else if (strncmp(user_msg, "ECHO ", 5) == 0) {
        const char *prefix = "ECHOED: ";
        char outbuf[256];
        int len = snprintf(outbuf, sizeof(outbuf), "%s%s\n",
                           prefix, user_msg + 5);
        if (len < 0) {
            return -1;
        }
        if ((size_t)len > sizeof(outbuf)) {
            len = (int)sizeof(outbuf);
        }
        (void)write(fd, outbuf, (size_t)len);
    } else {
        const char *resp = "OK\n";
        (void)write(fd, resp, strlen(resp));
    }
