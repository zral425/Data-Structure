#include <stdio.h>

#define MAX 100

/* 顺序结构存储的串 */
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

/*
 * 求模式串 t 的 next 数组（教材约定：下标从 1 开始，next[1] = 0）
 * next[j] = 满足 "t[1..k-1] == t[j-k+1..j-1]" 的最大 k，
 *           即 j 失配时模式串应重新对准的字符位置。
 */
void GetNext(const String *t, int next[])
{
    int i = 1, j = 0;

    next[1] = 0;
    while (i < t->length) {
        if (j == 0 || t->data[i - 1] == t->data[j - 1]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

/*
 * 求 nextval 数组：在 next 基础上，若 t[j] 与 t[next[j]] 相同，
 * 那么按 next 回退后仍需再次失配，故直接跳到 nextval[next[j]]，
 * 省掉这次必然失败的比较。
 */
void GetNextval(const String *t, int nextval[])
{
    int i = 1, j = 0;

    nextval[1] = 0;
    while (i < t->length) {
        if (j == 0 || t->data[i - 1] == t->data[j - 1]) {
            i++;
            j++;
            if (t->data[i - 1] != t->data[j - 1])
                nextval[i] = j;             /* 字符不同，保持 next 的值 */
            else
                nextval[i] = nextval[j];    /* 字符相同，继续向前跳 */
        } else {
            j = nextval[j];
        }
    }
}

int main(void)
{
    String t;
    int next[MAX + 1], nextval[MAX + 1];

    StrAssign(&t, "ababaabab");

    GetNext(&t, next);
    GetNextval(&t, nextval);

    printf("模式串 T = ");
    for (int i = 0; i < t.length; i++)
        putchar(t.data[i]);
    printf("  (长度 %d)\n\n", t.length);

    /* 按 1 起计的下标逐列打印，便于和教材表格对照 */
    printf("      j :");
    for (int i = 1; i <= t.length; i++)
        printf("%3d", i);
    printf("\n");

    printf("   T[j] :");
    for (int i = 1; i <= t.length; i++)
        printf("%3c", t.data[i - 1]);
    printf("\n");

    printf("   next :");
    for (int i = 1; i <= t.length; i++)
        printf("%3d", next[i]);
    printf("\n");

    printf("nextval :");
    for (int i = 1; i <= t.length; i++)
        printf("%3d", nextval[i]);
    printf("\n");

    return 0;
}
