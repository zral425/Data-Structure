#include <stdio.h>
#define MAX 100

typedef struct {
    char data[MAX];
    int  length;
} String;

void StrAssign(String *s, const char *str)
{
    int i = 0;
    while (str[i] != '\0' && i < MAX) {
        s->data[i] = str[i];
        i++;
    }
    s->length = i;
}

void StrPrint(const String *s)
{
    for (int i = 0; i < s->length; i++)
        putchar(s->data[i]);
    printf("%d\n", s->length);
}

int BF(const String *s, const String *t, long *cmp)
{
    int i = 0, j = 0;   
    long cnt = 0;

    while (i < s->length && j < t->length) {
        cnt++;
        if (s->data[i] == t->data[j]) { 
            i++;
            j++;
        } else {                        
            i = i - j + 1;               
            j = 0;                   
        }
    }

    if (cmp != NULL)
        *cmp = cnt;

    if (j >= t->length)
        return i - t->length + 1;        
    return 0;                           
}

int main(void)
{
    String s, t;
    long cmp = 0;
    int pos;

    StrAssign(&s, "acabaabcaabaabcac");
    StrAssign(&t, "abaabcac");

    StrPrint(&s);
    StrPrint(&t);

    pos = BF(&s, &t, &cmp);

    if (pos != 0) {
        printf("匹配成功：T 在 S 中首次出现于第 %d 个字符（下标 %d）\n", pos, pos - 1);
    } else {
        printf("匹配失败：S 中不存在 T\n");
    }
    printf("BF 字符比较次数 = %ld\n", cmp);
    return 0;
}
