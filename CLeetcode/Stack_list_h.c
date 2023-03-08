#include<stdio.h>
#include<stdbool.h>
#include<assert.h>

typedef struct listnode 
{
    char data;
    struct listnode *next;
} ListNode;

typedef struct stack
{
    ListNode *top;
} Stack;

void initStack(Stack *s);
bool stackFull(Stack *s);
bool stackEmpty(Stack *s);
void pushStack(Stack *s, char data);
char popStack(Stack *s); // 這邊改了型態, int => char

/*
  因為我們只是換成 link-list 的形式，
  其他都沒有動到，所以我把剛剛的括號平衡
  和對稱字串的主程式放到這邊執行也沒問題。
*/

/* 對稱字串 */
int main(void)
{
    char string[128];
    scanf("%s", string);
    
    int length = strlen(string);
    int half = length / 2;
    
    Stack stack;
    initStack(&stack);
    
    for (int i = 0; i < half; i++)
    {
        pushStack(&stack, string[i]);
    }
    for (int i = length - half; i < length; i++)
    {
        if (string[i] != popStack(&stack))
        {
            printf("not a palindrome\n");
            return 0;
        }
    }
    printf("palindrome\n");
}

/* initStack */
void initStack(Stack *s)
{
    s->top = NULL;
}

/* stackFull */
bool stackFull(Stack *s) // 因為不會有滿的問題，除非記憶體爆炸
{
    return(0);
}

/* stackEmpty */
bool stackEmpty(Stack *s)
{
    return(s->top == NULL);
}

/* pushStack */
void pushStack(Stack *s, char i)
{
    ListNode *current = (ListNode *)malloc(sizeof(ListNode));
    assert(current != NULL);
    current -> data = i;
    current -> next = s -> top;
    s -> top = current;
}

/* popStack */
char popStack(Stack *s)
{
    if (stackEmpty(s))
    {
        printf("stack is empty\n");
        return(-1);
    }
    ListNode *current = s->top;
    s->top = s->top->next;
    char c = current->data;
    free(current);
    return(c);
}
