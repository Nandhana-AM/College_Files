#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

class stack
{
    struct node
    {
        char data;
        struct node *next;
    };

public:
    struct node *top;
    stack()
    {
        top = NULL;
    }
    void push(char);
    char pop();
    void display(); // didnt check
    int isempty();
    char* convert(char*,char []);
    int precedence(char);
    void evaluate(char*);
};

// Method to push an element into the stack
void stack::push(char c)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (top == NULL)
    {
        newnode->data = c;
        newnode->next = NULL;
        top = newnode;
    }
    else
    {
        newnode->data = c;
        newnode->next = top;
        top = newnode;
    }
}

// Method to pop an element from the stack
char stack::pop()
{
    if (top == NULL)
    {
        return '\0'; // leave as zero?
    }
    else
    {
        char p = top->data;
        top = top->next;
        return p;
    }
}

// Method to display the stack
void stack::display()
{
    printf("\nThe evaluated value of the postfix expression is: ");
    struct node *temp = top;
    int count = 0;
    while (temp != NULL)
    {
        count += 1;
        temp = temp->next;
    }
    int arr[count];
    temp = top;
    for (int i = 0; i < count; i++)
    {
        arr[i] = temp->data;
        temp = temp->next;
    }
    for (int i = (count - 1); i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
}

// Method to check if stack is empty
int stack::isempty()
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Method to convert infix to postfix
char* stack::convert(char *exp,char postfix[])
{
    int b=strlen(exp);
    char c=*exp;

    int cnt = 0;
    for (int i = 0; i < b; i++)
    {
        c=*(exp+i);
        if (isdigit(c))
        {
            postfix[cnt] = c;
            cnt++;
        }
        else if (c == '=' || c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
        {
            if (isempty())
            {
                push(c);
            }
            else
            {
                int p = precedence(c);
                int q = precedence(top->data);
                if (p > q)
                {
                    push(c);
                }
                else if (p < q || (p == q && c != '='))
                {
                    while ((p < q || (p == q && c != '=') ) && top!=NULL)
                    {
                        char o = pop();
                        postfix[cnt] = o;
                        cnt++;
                        if (top==NULL)
                        {
                            break;
                        }
                        else
                        {
                            q = precedence(top->data);
                        } 
                    }
                    push(c);
                }
                else if (p == q && c == '=')
                {
                    push(c);
                }
            }
        }
    }
    while (isempty()!=1)
    {
        char o = pop();
        postfix[cnt] = o;
        cnt++;
    }
    postfix[cnt] = '\0'; // Null-terminate the postfix expression
    char *ptr=&postfix[0];
    return ptr;

}

//Method to evaluate postfix expression
void stack::evaluate(char* postfix)
{
    int b=strlen(postfix);
    char c;
    for (int i = 0; i<b ; i++)
    {
         c=*(postfix+i);

        if (isdigit(c))
        {
            push(char(int(c)-48));
        }
        else if (c == '=' || c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
        {
            int op1 = int(pop());
            int op2 = int(pop());
            switch(c)
            {
                case '+': 
                    push(char(op1+op2));
                    break;
                case '-': 
                    push(char(op2-op1));
                    break;
                case '*': 
                    push(char(op1*op2));
                    break;
                case '/': 
                    push(char(int(op2/op1)));
                    break;
                case '=':
                    op2=op1;
                    push(op2);
                    break;
                case '%':
                    push(char(int(op2%op1)));
                    break;
                default:
                    printf("Character cannot be calculated");  

            }
            
        }
    }
    display();
}

// Method to check precedence
int stack::precedence(char a)
{
    if (a == '*' || a == '/' || a == '%')
    {
        return 2;
    }
    else if (a == '+' || a == '-')
    {
        return 1;
    }
    else if (a == '=')
    {
        return 0;
    }
}