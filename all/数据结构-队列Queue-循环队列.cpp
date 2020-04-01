/*循环队列*/   //有一个元素空余座位是否满的判断 
#include<stdio.h>
#define MAXSIZE 10

typedef struct
{
   int front;
   int rear;
   int a[MAXSIZE];
   int size;
}SqQueue;

SqQueue q;

void InitQueue()
{
     q.front = 0;
     q.rear = 0;
     q.size=0;
}

int EnQueue(int x) //入队操作 
{
    if((q.rear+1)%MAXSIZE==q.front) //队满，函数返回0 
      return 0;
    else
	{
		q.a[q.rear]=x;
		q.rear=(q.rear+1)%MAXSIZE;
		return 1;
	} 
}

int QueueEmpty();

int DeQueue() //出队操作 
{
    if(QueueEmpty()) //队空，出队失败，返回0 
      return 0;
    else
    {
      q.front=(q.front+1)%MAXSIZE;	 
      return 1;
    }
}

int QueueLength()
{
    return (q.rear-q.front+MAXSIZE)%MAXSIZE;
}

int QueueEmpty() //队列空返回1，否则返回0 
{
	if(q.rear==q.front)
	  return 1;
	return 0;
}

int GetHead() //获取对头元素 
{
    if(QueueEmpty())
      return 0;
    return q.a[q.front];
}

int main()
{
    int arr[10] = {1,2,3,4,5,6};
    int i;
    //InitQueue();
    //printf("%d\n", QueueEmpty());
    for(i=0; i<6; i++)
      EnQueue(arr[i]);
    DeQueue();

    printf("%d\n", GetHead());
    printf("\n");
    return 0;
}
