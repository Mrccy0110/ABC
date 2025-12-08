











































































































































































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
