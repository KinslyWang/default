#include "main.h"
/*发送传感器Modbus命令*/
BOOL_t Modbus_Send_Cmd(Sensor_Handle_t * hs)
{
	return TRUE;
}
/*接收传感器Modbus响应*/
BOOL_t Modbus_Receive_Resp(Sensor_Handle_t * hs)
{	
	return TRUE;
}

//
BOOL_t Modbus_Data_Proc(Sensor_Handle_t * hs, void * result)
{
	return TRUE;
}

/*解析传感器数据，以指针形式返回解析结果*/
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
