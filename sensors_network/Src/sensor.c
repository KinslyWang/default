#include "main.h"
/*���ʹ�����Modbus����*/
BOOL_t Modbus_Send_Cmd(Sensor_Handle_t * hs)
{
	return TRUE;
}
/*���մ�����Modbus��Ӧ*/
BOOL_t Modbus_Receive_Resp(Sensor_Handle_t * hs)
{	
	return TRUE;
}

//
BOOL_t Modbus_Data_Proc(Sensor_Handle_t * hs, void * result)
{
	return TRUE;
}

/*�������������ݣ���ָ����ʽ���ؽ������*/
BOOL_t Sens_Data_Proc(Sensor_Handle_t * hs)
{
	return TRUE;
}

void Sensors_Polling(PtrQue_TypeDef * sq)
{
	int i;
	Sensor_Handle_t * hs;
	for (i = 0; i < __PTRQUE_COUNT(sq); i++)
	{
		if (PtrQue_Query(sq, (void **)&hs))
		{
			Modbus_Send_Cmd(hs);
			HAL_Delay(MODBUS_TIMEOUT);
			if (Modbus_Receive_Resp(hs)) {
				
			}
		}
	}
}
