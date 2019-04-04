typedef enum
{
	SEN_TEMP_HUMI = 0,	//土壤温湿度传感器
	SEN_ILLUM_T_H,			//光照温湿度传感器
	SEN_CO2_T_H,				//CO2温湿度传感器
	SEN_COND_SALT			//电导率盐分传感器
}SensorType_t;//传感器类型
typedef struct
{
	SensorType_t type;	//传感器类型
	uint8_t rs485addr;	//485总线地址
	uint8_t funcode;		//modbus功能码
	uint16_t regaddr;		//modbus寄存器首地址
	uint16_t regcount;	//modbus寄存器数量
	uint8_t * modbus_cmd;//modbus命令指针
	uint8_t mb_cmdsize;	//modbus命令长度
	uint8_t * modbus_resp;//modbus响应数据指针
	uint8_t mb_respsize;	//modbus响应数据长度
}Sensor_Handle_t;