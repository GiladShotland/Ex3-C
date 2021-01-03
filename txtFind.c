#include <stdio.h>
#include <string.h>
#define WORD 30
#define LINE 256
int getLine(char s[]);
int getword(char w[]);
int similar(char *s, char *t, int n);
int substring(char *str1, char *str2);
void print_similar_words(char *str);
void print_lines(char *str);

int getword(char w[])
{
    char letter = getchar();
    int currentSize = 0;
    while (currentSize < WORD && letter != '\t' && letter != '\n' && letter != ' ' && letter != EOF && letter != '\r')
    {
        w[currentSize] = letter;
        currentSize++;
        letter = getchar();
    }
    w[currentSize] = '\0';
    return currentSize;
}
// check if s similiar to t(if we delete n letters from s we'll get t)
int similar(char *s, char *t, int n)
{
    int x = strlen(s);
    int y = strlen(t);
    if (x != y + n)
    {
        return 0;
    }
    int i = 0;
    int j = 0;
    int mistakes = 0;
    while (*(s + i) != '\0' && *(s + i) != '\r' && *(s + i) != '\n')
    {
        if (*(s + i) == *(t + j))
        {
            i++;
            j++;
        }
        else
        {
            mistakes++;
            i++;
            if (mistakes > n)
            {
                return 0;
            }
        }
    }
    return 1;
}

int getLine(char s[])
{
    char letter = getchar();
    int currentSize = 0;
    while (letter == '\n')
    {
        letter = getchar();
    }
    if (letter == EOF)
    {
        return 0;
    }
    while (currentSize < LINE && letter != '\n' && letter != '\r' && letter != EOF)
    {
        s[currentSize] = letter;
        currentSize++;
        letter = getchar();
    }
    s[currentSize] = '\0';
    return currentSize;
}

//fix it
//check if str1 conatins str2
int substring(char *str1, char *str2)
{
    int i = 0;

    while (*str1 != '\0' && *str1 != '\n' && *str1 != '\r')
    {
        if (*str1 == *(str2 + i))
        {
            i++;

            if (i == strlen(str2))
            {
                return 1;
            }
        }
        else
        {
            i = 0;
        }
        str1++;
    }
    return 0;
}
void print_similar_words(char *str)
{
    char s[WORD];
    int i = getword(s);
    while (i != 0)
    {
        if (similar(s, str, 1) == 1)
        {
            printf("%s\n", s);
        }
        i = getword(s);
    }
}
void print_lines(char *str)
{
    char s[LINE];
    int length = getLine(s);
    while (length != 0)
    {
        if (substring(s, str) == 1)
        {
            printf("%s\n", s);
        }
        length = getLine(s);
    }
}
int main()
{
    char firstword[WORD];
    getword(firstword);
    char choice;
    scanf("%c\n", &choice);

    if (choice == 'a')
    {
        print_lines(firstword);
    }
    else
    {
        if (choice == 'b')
        {
            print_similar_words(firstword);
        }
    }
}
