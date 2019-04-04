#include "main.h"
//队列初始化
void Que_Init(CircleQue_TypeDef * pq)
{
  pq->front = pq->rear = 0;
}

//入队
BOOL_t Que_In(CircleQue_TypeDef * pq, uint8_t c)
{
  pq->data[pq->rear] = c;
  pq->rear = (pq->rear + 1) % QUESIZE;
  if (pq->front == pq->rear)
    pq->front = (pq->front + 1) % QUESIZE;
  return TRUE;
}

//出队
BOOL_t Que_Out(CircleQue_TypeDef * pq, uint8_t *c)
{
  if (pq->front == pq->rear) {
    return FALSE;
  }
  *c = pq->data[pq->front];
  pq->front = (pq->front + 1) % QUESIZE;
  return TRUE;
}

//查询队列：取出对头，但不删除
BOOL_t Que_Query(CircleQue_TypeDef * pq, uint8_t *c)
{
  if (pq->front == pq->rear) {
    return FALSE;
  }
  *c = pq->data[pq->front];
  return TRUE;
}

void PtrQue_Init(PtrQue_TypeDef * pq)
{
	pq->front = pq->rear = pq->current = 0;
}

BOOL_t PtrQue_In(PtrQue_TypeDef * pq, void * psh)
{
  if ((pq->rear + 1) % PTRQUESIZE == pq->front)
	{
		return FALSE;//que full
	}
  pq->data[pq->rear] = psh;
  pq->rear = (pq->rear + 1) % PTRQUESIZE;
  return TRUE;
}

BOOL_t PtrQue_Out(PtrQue_TypeDef * pq, void ** ppsh)
{
  if (pq->front == pq->rear) {
    return FALSE;
  }
  *ppsh = pq->data[pq->front];
  pq->front = (pq->front + 1) % PTRQUESIZE;
  return TRUE;
}

BOOL_t PtrQue_Query(PtrQue_TypeDef * pq, void ** ppsh)
{
  if (pq->front == pq->rear) {
    return FALSE;
  }
  *ppsh = pq->data[pq->current];
  pq->current = (pq->current + 1) % PTRQUESIZE;
	if (pq->current == pq->rear) {
		pq->current = pq->front;
	}
  return TRUE;
}
