#include <stdio.h>
#include <ctype.h>

int stack[100];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char exp[] = "5 3 2 * + 4 -";
    int i, a, b;

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (isdigit(exp[i]))
            push(exp[i] - '0');

        else if (exp[i] == ' ')
            continue;

        else
        {
            b = pop();
            a = pop();

            switch (exp[i])
            {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }

    printf("Result = %d", pop());

    return 0;
}