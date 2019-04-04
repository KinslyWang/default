typedef enum
{
	SEN_TEMP_HUMI = 0,	//������ʪ�ȴ�����
	SEN_ILLUM_T_H,			//������ʪ�ȴ�����
	SEN_CO2_T_H,				//CO2��ʪ�ȴ�����
	SEN_COND_SALT			//�絼���ηִ�����
}SensorType_t;//����������
typedef struct
{
	SensorType_t type;	//����������
	uint8_t rs485addr;	//485���ߵ�ַ
	uint8_t funcode;		//modbus������
	uint16_t regaddr;		//modbus�Ĵ����׵�ַ
	uint16_t regcount;	//modbus�Ĵ�������
	uint8_t * modbus_cmd;//modbus����ָ��
	uint8_t mb_cmdsize;	//modbus�����
	uint8_t * modbus_resp;//modbus��Ӧ����ָ��
	uint8_t mb_respsize;	//modbus��Ӧ���ݳ���
}Sensor_Handle_t;