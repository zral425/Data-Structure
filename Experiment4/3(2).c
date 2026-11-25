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

void GetNextval(const String *t, int nextval[])
{
    int i = 1, j = 0;
    nextval[1] = 0;
    while (i < t->length) {
        if (j == 0 || t->data[i - 1] == t->data[j - 1]) {
            i++;
            j++;
            if (t->data[i - 1] != t->data[j - 1])
                nextval[i] = j;          
            else
                nextval[i] = nextval[j];  
        } else {
            j = nextval[j];
        }
    }
}

int IndexKMP(const String *s, const String *t, const int nextval[], long *cmp)
{
    int i = 1, j = 1;
    long cnt = 0;
    while (i <= s->length && j <= t->length) {
        if (j == 0) {          
            i++;
            j = 1;
        } else {
            cnt++;            
            if (s->data[i - 1] == t->data[j - 1]) {
                i++;
                j++;
            } else {
                j = nextval[j]; 
            }
        }
    }
    if (cmp != NULL)
        *cmp = cnt;

    if (j > t->length)
        return i - t->length;  
    return 0;
}

int main(void)
{
    String s, t;
    int nextval[MAX + 1];
    long cmp = 0;
    int pos;

    StrAssign(&s, "acabaabcaabaabcac");
    StrAssign(&t, "abaabcac");

    GetNextval(&t, nextval);

    printf("主串 S   = ");
    for (int i = 0; i < s.length; i++)
        putchar(s.data[i]);
    printf("  (长度 %d)\n", s.length);

    printf("模式串 T = ");
    for (int i = 0; i < t.length; i++)
        putchar(t.data[i]);
    printf("  (长度 %d)\n\n", t.length);

    printf("      j :");
    for (int i = 1; i <= t.length; i++)
        printf("%3d", i);
    printf("\n");
    printf("   T[j] :");
    for (int i = 1; i <= t.length; i++)
        printf("%3c", t.data[i - 1]);
    printf("\n");
    printf("nextval :");
    for (int i = 1; i <= t.length; i++)
        printf("%3d", nextval[i]);
    printf("\n\n");

    pos = IndexKMP(&s, &t, nextval, &cmp);

    if (pos != 0) {
        printf("匹配成功：T 在 S 中首次出现于第 %d 个字符（下标 %d）\n", pos, pos - 1);
    } else {
        printf("匹配失败：S 中不存在 T\n");
    }
    printf("KMP 字符比较次数 = %ld\n", cmp);

    return 0;
}
