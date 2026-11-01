#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char infix[] = "A+B*(C-D)/E";
    char postfix[100];
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if (isalnum(ch))
            postfix[j++] = ch;

        else if (ch == '(')
            push(ch);

        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();

            pop();
        }
        else
        {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[j++] = pop();

            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix Expression: %s", postfix);

    return 0;
}