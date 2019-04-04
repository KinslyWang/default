#ifndef __SENSOR_H
#define __SENSOR_H
#define MODBUS_TIMEOUT 100 //ModBus等待响应超时时间（ms），即发出ModBus命令后，等待接收方响应的时间，超出此时间认为失去响应
typedef enum
{
	SEN_TEMP_HUMI = 0,	//土壤温湿度传感器
	SEN_ILLUM_T_H,			//光照温湿度传感器
	SEN_CO2_T_H,				//CO2温湿度传感器
	SEN_COND_SALT			//电导率盐分传感器
}SensorType_t;//传感器类型
typedef struct
{
	uint8_t rs485addr;	//485总线地址
	uint8_t funcode;		//modbus功能码
	uint16_t regaddr;		//modbus寄存器首地址
	uint16_t regcount;	//modbus寄存器数量
	uint8_t crcl;				//CRC校验低字节
	uint8_t crch;				//CRC校验高字节
}ModBus_Cmd_t;//ModBus命令格式
typedef struct
{
	uint8_t rs485addr;	//485总线地址
	uint8_t funcode;		//modbus功能码
	uint8_t datasize;		//其后的数据长度（不包括CRC校验码）
	uint16_t regaddr;		//modbus寄存器首地址
	uint16_t regcount;	//modbus寄存器数量
	uint8_t crcl;				//CRC校验低字节
	uint8_t crch;				//CRC校验高字节
}ModBus_Cmd_Ext_t;//ModBus命令扩展格式（非正规的）
typedef union
{
	uint8_t cmdbytes[9];
	ModBus_Cmd_t cmd;
	ModBus_Cmd_Ext_t cmd_ext;
}ModBus_Cmd_Union_t;
typedef struct
{
	uint8_t rs485addr;	//485总线地址
	uint8_t funcode;		//modbus功能码
	uint8_t datasize;		//其后的数据长度（不包括CRC校验码）
	uint16_t humidity;		//湿度
	int16_t temperature;	//温度
	uint32_t illuminance;	//光照度
	uint8_t crcl;				//CRC校验低字节
	uint8_t crch;				//CRC校验高字节
}ModBus_Resp_IHT_t;//光照温湿度传感器响应数据结构
typedef struct
{
	uint8_t rs485addr;	//485总线地址
	uint8_t funcode;		//modbus功能码
	uint8_t datasize;		//其后的数据长度（不包括CRC校验码）
	uint16_t humidity;		//湿度
	int16_t temperature;	//温度
	uint16_t co2;					//二氧化碳浓度
	uint8_t crcl;				//CRC校验低字节
	uint8_t crch;				//CRC校验高字节
}ModBus_Resp_CO2HT_t;//二氧化碳浓度温湿度传感器响应数据结构
typedef struct
{
	uint8_t rs485addr;	//485总线地址
	uint8_t funcode;		//modbus功能码
	uint8_t datasize;		//其后的数据长度（不包括CRC校验码）
	uint16_t humidity;		//湿度
	int16_t temperature;	//温度
	uint8_t crcl;				//CRC校验低字节
	uint8_t crch;				//CRC校验高字节
}ModBus_Resp_HT_t;//土壤水分温度传感器响应数据结构
typedef struct
{
	uint8_t rs485addr;	//485总线地址
	uint8_t funcode;		//modbus功能码
	uint8_t datasize;		//其后的数据长度（不包括CRC校验码）
	uint16_t cond;			//电导率
	int16_t salt;				//盐分
	uint8_t crcl;				//CRC校验低字节
	uint8_t crch;				//CRC校验高字节
}ModBus_Resp_CS_t;//土壤电导率盐分传感器响应数据结构
typedef union
{
	uint8_t respbytes[13];
	ModBus_Resp_IHT_t resp_iht;
	ModBus_Resp_CO2HT_t resp_co2ht;
	ModBus_Resp_HT_t resp_ht;
	ModBus_Resp_CS_t resp_cs;
}ModBus_Resp_Union_t;
typedef struct
{
	SensorType_t type;	//传感器类型
	ModBus_Cmd_Union_t *modbus_cmd;//modbus命令指针
	uint8_t mb_cmdsize;	//modbus命令长度
	ModBus_Resp_Union_t * modbus_resp;//modbus响应数据指针
	uint8_t mb_respsize;	//modbus响应数据长度
}Sensor_Handle_t;
/*发送传感器Modbus命令*/
BOOL_t Modbus_Send_Cmd(Sensor_Handle_t * hs);
/*接收传感器Modbus响应*/
BOOL_t Modbus_Receive_Resp(Sensor_Handle_t * hs);
/*解析传感器数据*/
BOOL_t Sens_Data_Proc(Sensor_Handle_t * hs);
/*传感器巡检*/
void Sensors_Polling(PtrQue_TypeDef * pq);
#endif
