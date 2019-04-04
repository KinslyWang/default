#ifndef __UDS_H_
#define __UDS_H_
#define  QUESIZE 20
#define  PTRQUESIZE 7
//获取队列数据个数
#define __QUE_COUNT(PQUE) (((PQUE)->rear - (PQUE)->front + QUESIZE) % QUESIZE)
//获取传感器队列数据个数
#define __PTRQUE_COUNT(PQUE) (((PQUE)->rear - (PQUE)->front + PTRQUESIZE) % PTRQUESIZE)
typedef struct {
  uint8_t data[QUESIZE];
  uint8_t front;
  uint8_t rear;
}CircleQue_TypeDef;//支持查询队头的循环字节队列，队满时入队覆盖旧数据

void Que_Init(CircleQue_TypeDef * pq);
BOOL_t Que_In(CircleQue_TypeDef * pq, uint8_t c);
BOOL_t Que_Out(CircleQue_TypeDef * pq, uint8_t *c);
BOOL_t Que_Query(CircleQue_TypeDef * pq, uint8_t *c);

typedef struct {
  void * data[PTRQUESIZE];
  uint8_t front;//头指针
  uint8_t rear;//尾指针
	uint8_t current;//当前数据指针（用于查询操作）
}PtrQue_TypeDef;//支持遍历查询的循环指针队列，队满时不允许入队

void PtrQue_Init(PtrQue_TypeDef * pq);
BOOL_t PtrQue_In(PtrQue_TypeDef * pq, void * psh);
BOOL_t PtrQue_Out(PtrQue_TypeDef * pq, void ** ppsh);
BOOL_t PtrQue_Query(PtrQue_TypeDef * pq, void ** ppsh);

#endif
