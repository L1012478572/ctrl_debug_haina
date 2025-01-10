#ifndef PARAM_STRUCT_H
#define PARAM_STRUCT_H

#include <stdint.h>

// 编码器计数存储类型
typedef enum
{
  encoder_timerBits_16 = 0,
  encoder_timerBits_32 = 1
} encoder_timerBits_type;

// 编码器计数存储
typedef struct encoderCount
{
  // 溢出计数
  int64_t overflowCount;
  // 编码器计数
  uint32_t count;
  // 定时器位数
  encoder_timerBits_type timerBits;
} encoderCount_t;

// GPIO 电平有效性
typedef enum gpioLevel
{
  // 低电平有效
  GPIO_LEVEL_LOW = 0,
  // 高电平有效
  GPIO_LEVEL_HIGH = 1
} gpioLevel;

// 输入引脚物理地址枚举 1-30
typedef enum inputPin
{
  // 输入引脚 1
  INPUT_PIN_1 = 1,
  // 输入引脚 2
  INPUT_PIN_2 = 2,
  // 输入引脚 3
  INPUT_PIN_3 = 3,
  // 输入引脚 4
  INPUT_PIN_4 = 4,
  // 输入引脚 5
  INPUT_PIN_5 = 5,
  // 输入引脚 6
  INPUT_PIN_6 = 6,
  // 输入引脚 7
  INPUT_PIN_7 = 7,
  // 输入引脚 8
  INPUT_PIN_8 = 8,
  // 输入引脚 9
  INPUT_PIN_9 = 9,
  // 输入引脚 10
  INPUT_PIN_10 = 10,
  // 输入引脚 11
  INPUT_PIN_11 = 11,
  // 输入引脚 12
  INPUT_PIN_12 = 12,
  // 输入引脚 13
  INPUT_PIN_13 = 13,
  // 输入引脚 14
  INPUT_PIN_14 = 14,
  // 输入引脚 15
  INPUT_PIN_15 = 15,
  // 输入引脚 16
  INPUT_PIN_16 = 16,
  // 输入引脚 17
  INPUT_PIN_17 = 17,
  // 输入引脚 18
  INPUT_PIN_18 = 18,
  // 输入引脚 19
  INPUT_PIN_19 = 19,
  // 输入引脚 20
  INPUT_PIN_20 = 20,
  // 输入引脚 21
  INPUT_PIN_21 = 21,
  // 输入引脚 22
  INPUT_PIN_22 = 22,
  // 输入引脚 23
  INPUT_PIN_23 = 23,
  // 输入引脚 24
  INPUT_PIN_24 = 24,
  // 输入引脚 25
  INPUT_PIN_25 = 25,
  // 输入引脚 26
  INPUT_PIN_26 = 26,
  // 输入引脚 27
  INPUT_PIN_27 = 27,
  // 输入引脚 28
  INPUT_PIN_28 = 28,
  // 输入引脚 29
  INPUT_PIN_29 = 29,
  // 输入引脚 30
  INPUT_PIN_30 = 30
} inputPin;

// 输出引脚物理地址枚举 1-30
typedef enum outputPin
{
  // 输出引脚 1
  OUTPUT_PIN_1 = 1,
  // 输出引脚 2
  OUTPUT_PIN_2 = 2,
  // 输出引脚 3
  OUTPUT_PIN_3 = 3,
  // 输出引脚 4
  OUTPUT_PIN_4 = 4,
  // 输出引脚 5
  OUTPUT_PIN_5 = 5,
  // 输出引脚 6
  OUTPUT_PIN_6 = 6,
  // 输出引脚 7
  OUTPUT_PIN_7 = 7,
  // 输出引脚 8
  OUTPUT_PIN_8 = 8,
  // 输出引脚 9
  OUTPUT_PIN_9 = 9,
  // 输出引脚 10
  OUTPUT_PIN_10 = 10,
  // 输出引脚 11
  OUTPUT_PIN_11 = 11,
  // 输出引脚 12
  OUTPUT_PIN_12 = 12,
  // 输出引脚 13
  OUTPUT_PIN_13 = 13,
  // 输出引脚 14
  OUTPUT_PIN_14 = 14,
  // 输出引脚 15
  OUTPUT_PIN_15 = 15,
  // 输出引脚 16
  OUTPUT_PIN_16 = 16,
  // 输出引脚 17
  OUTPUT_PIN_17 = 17,
  // 输出引脚 18
  OUTPUT_PIN_18 = 18,
  // 输出引脚 19
  OUTPUT_PIN_19 = 19,
  // 输出引脚 20
  OUTPUT_PIN_20 = 20,
  // 输出引脚 21
  OUTPUT_PIN_21 = 21,
  // 输出引脚 22
  OUTPUT_PIN_22 = 22,
  // 输出引脚 23
  OUTPUT_PIN_23 = 23,
  // 输出引脚 24
  OUTPUT_PIN_24 = 24,
  // 输出引脚 25
  OUTPUT_PIN_25 = 25,
  // 输出引脚 26
  OUTPUT_PIN_26 = 26,
  // 输出引脚 27
  OUTPUT_PIN_27 = 27,
  // 输出引脚 28
  OUTPUT_PIN_28 = 28,
  // 输出引脚 29
  OUTPUT_PIN_29 = 29,
  // 输出引脚 30
  OUTPUT_PIN_30 = 30
} outputPin;

// 模拟量输入引脚物理地址枚举 1-6
typedef enum analogInputPin
{
  // 模拟量输入引脚 1
  ANALOG_INPUT_PIN_1 = 1,
  // 模拟量输入引脚 2
  ANALOG_INPUT_PIN_2 = 2,
  // 模拟量输入引脚 3
  ANALOG_INPUT_PIN_3 = 3,
  // 模拟量输入引脚 4
  ANALOG_INPUT_PIN_4 = 4,
  // 模拟量输入引脚 5
  ANALOG_INPUT_PIN_5 = 5,
  // 模拟量输入引脚 6
  ANALOG_INPUT_PIN_6 = 6
} analogInputPin;

// Modbus RTU Slave 参数
typedef struct modbusRtuSlaveParam
{
  // 从机地址
  uint8_t address;
  // 数据位
  uint8_t dataBits;
  // 停止位
  uint8_t stopBits;
  // 校验位
  uint8_t parity;
  // 波特率
  uint32_t baudRate;
} modbusRtuSlaveParam;

// DI 映射表
typedef struct diMap
{
  // 主泵1启停输入引脚
  inputPin mainPump1StartStop;
  // 主泵1启停信号电平有效性
  gpioLevel mainPump1StartStopLevel;
  // 开门+出包输入引脚
  inputPin openDoorPlusOutPackage;
  // 开门+出包信号电平有效性
  gpioLevel openDoorPlusOutPackageLevel;
  // 自动输入引脚
  inputPin automatic;
  // 自动信号电平有效性
  gpioLevel automaticLevel;
  // 半自动输入引脚
  inputPin semiAutomatic;
  // 半自动信号电平有效性
  gpioLevel semiAutomaticLevel;
  // 原点位置信号输入引脚
  inputPin originPosition;
  // 原点位置信号电平有效性
  gpioLevel originPositionLevel;
  // 开门限位输入引脚
  inputPin openDoorLimit;
  // 开门限位信号电平有效性
  gpioLevel openDoorLimitLevel;
  // 关门限位输入引脚
  inputPin closeDoorLimit;
  // 关门限位信号电平有效性
  gpioLevel closeDoorLimitLevel;
  // 急停输入引脚
  inputPin emergencyStop;
  // 急停信号电平有效性
  gpioLevel emergencyStopLevel;
  // 主泵1热保护
  inputPin mainPump1ThermalProtection;
  // 主泵1热保护信号电平有效性
  gpioLevel mainPump1ThermalProtectionLevel;
  // 关门+后退
  inputPin closeDoorPlusBack;
  // 关门+后退信号电平有效性
  gpioLevel closeDoorPlusBackLevel;
  // 料位信号输入引脚
  inputPin levelSignal;
  // 料位信号电平有效性
  gpioLevel levelSignalLevel;
  // 料满信号
  inputPin fullMaterialSignal;
  // 料满信号电平有效性
  gpioLevel fullMaterialSignalLevel;
  // 输送带手动
  inputPin conveyorManual;
  // 输送带手动信号电平有效性
  gpioLevel conveyorManualLevel;
  // 输送带自动
  inputPin conveyorAutomatic;
  // 输送带自动信号电平有效性
  gpioLevel conveyorAutomaticLevel;
  // 出包到位
  inputPin outPackageInPlace;
  // 出包到位信号电平有效性
  gpioLevel outPackageInPlaceLevel;
  // 前进按钮（遥控）
  inputPin forwardButton;
  // 前进按钮（遥控）信号电平有效性
  gpioLevel forwardButtonLevel;
  // 后退按钮（遥控）
  inputPin backButton;
  // 后退按钮（遥控）信号电平有效性
  gpioLevel backButtonLevel;
  // 提门按钮（遥控）
  inputPin liftDoorButton;
  // 提门按钮（遥控）信号电平有效性
  gpioLevel liftDoorButtonLevel;
  // 关门按钮（遥控）
  inputPin closeDoorButton;
  // 关门按钮（遥控）信号电平有效性
  gpioLevel closeDoorButtonLevel;
  // 主泵2启停（遥控）
  inputPin mainPump2StartStop;
  // 主泵2启停（遥控）信号电平有效性
  gpioLevel mainPump2StartStopLevel;
  // 遥控停止信号
  inputPin remoteStopSignal;
  // 遥控停止信号电平有效性
  gpioLevel remoteStopSignalLevel;
} diMap;

// DO 映射表
typedef struct doMap
{
  // 1YA高压
  outputPin highPressure;
  // 1YA高压信号电平有效性
  gpioLevel highPressureLevel;
  // 2YA低/高压
  outputPin lowHighPressure;
  // 2YA低/高压信号电平有效性
  gpioLevel lowHighPressureLevel;
  // 开门
  outputPin openDoor;
  // 开门信号电平有效性
  gpioLevel openDoorLevel;
  // 关门
  outputPin closeDoor;
  // 关门信号电平有效性
  gpioLevel closeDoorLevel;
  // 前进
  outputPin forward;
  // 前进信号电平有效性
  gpioLevel forwardLevel;
  // 后退
  outputPin back;
  // 后退信号电平有效性
  gpioLevel backLevel;
  // 输送带
  outputPin conveyor;
  // 输送带信号电平有效性
  gpioLevel conveyorLevel;
  // 主泵1
  outputPin mainPump1;
  // 主泵1信号电平有效性
  gpioLevel mainPump1Level;
  // 后退回油
  outputPin backOil;
  // 后退回油信号电平有效性
  gpioLevel backOilLevel;
  // 辅助回油
  outputPin auxiliaryBackOil;
  // 辅助回油信号电平有效性
  gpioLevel auxiliaryBackOilLevel;
  // 前进回油
  outputPin forwardBackOil;
  // 前进回油信号电平有效性
  gpioLevel forwardBackOilLevel;
  // 小溢流阀 SC-11中压
  outputPin smallOverflowValve;
  // 小溢流阀 SC-11中压信号电平有效性
  gpioLevel smallOverflowValveLevel;
  // 捆报
  outputPin bale;
  // 捆报信号电平有效性
  gpioLevel baleLevel;
  // 主泵2
  outputPin mainPump2;
  // 主泵2信号电平有效性
  gpioLevel mainPump2Level;
  // 油温
  outputPin oilTemperature;
  // 油温信号电平有效性
  gpioLevel oilTemperatureLevel;
} doMap;

// 模拟量输入映射表
typedef struct aiMap
{
  // 油泵压力输入引脚
  analogInputPin oilPumpPressure;
  // 温度输入引脚
  analogInputPin temperature;
  // 电压输入引脚
  analogInputPin voltage;
  // 电流输入引脚
  analogInputPin current;
} aiMap;

// 编码器映射表
typedef struct encoderMap
{
  // 编码器通道
  uint8_t main_channel;
  // 编码器方向
  uint8_t main_direction;
} encoderMap;

// 系统参数
typedef struct systemParam
{
  // DI 映射表
  diMap diMap;
  // DO 映射表
  doMap doMap;
  // AI 映射表
  aiMap aiMap;
  // 编码器映射表
  encoderMap encoderMap;
  // Modbus RTU Slave 参数
  modbusRtuSlaveParam modbusRtuSlaveParam;

} systemParam;

// 系统参数读写结构体
typedef struct systemParamRW
{
  /* data */
  systemParam systemParam;
  uint16_t crc;
} systemParamRW;

// Modbus RTU Slave 特殊线圈地址标注
// 系统重启线圈
#define MODBUS_RTU_COIL_SYSTEM_REBOOT 84
// 系统恢复出厂设置线圈
#define MODBUS_RTU_COIL_SYSTEM_RESTORE_FACTORY_SETTINGS 92
// 系统参数保存线圈
#define MODBUS_RTU_COIL_SYSTEM_SAVE_PARAM 85
// 系统连接状态线圈
#define MODBUS_RTU_COIL_SYSTEM_CONNECT_STATUS 80

// Modbus RTU Slave 特殊寄存器地址标注
// 编码器1计数寄存器 按照32位寄存器计数
#define MODBUS_RTU_REG_ENCODER1_COUNT 2
// 编码器2计数寄存器 按照32位寄存器计数
#define MODBUS_RTU_REG_ENCODER2_COUNT 4
// 编码器3计数寄存器 按照32位寄存器计数
#define MODBUS_RTU_REG_ENCODER3_COUNT 6
// 温度寄存器

// 任务1 剩余堆栈大小
#define MODBUS_RTU_REG_TASK1_STACK_SIZE 4096
// 任务2 剩余堆栈大小
#define MODBUS_RTU_REG_TASK2_STACK_SIZE 4097
// 任务3 剩余堆栈大小
#define MODBUS_RTU_REG_TASK3_STACK_SIZE 4098
// 任务4 剩余堆栈大小
#define MODBUS_RTU_REG_TASK4_STACK_SIZE 4099
// 任务5 剩余堆栈大小
#define MODBUS_RTU_REG_TASK5_STACK_SIZE 4050
// 任务6 剩余堆栈大小
#define MODBUS_RTU_REG_TASK6_STACK_SIZE 4051
// 任务7 剩余堆栈大小
#define MODBUS_RTU_REG_TASK7_STACK_SIZE 4052
// 任务8 剩余堆栈大小
#define MODBUS_RTU_REG_TASK8_STACK_SIZE 4053
// 任务9 剩余堆栈大小
#define MODBUS_RTU_REG_TASK9_STACK_SIZE 4054
// 任务10 剩余堆栈大小
#define MODBUS_RTU_REG_TASK10_STACK_SIZE 4055

// 系统运行状态监控系列
// 系统启动状态
#define MODBUS_RTU_REG_SYSTEM_RUN_STATUS 4100
// modbus rtu 接收到的命令码
#define MODBUS_RTU_REG_SYSTEM_RECV_CMD 4101
// modbus rtu 接收到的寄存器地址
#define MODBUS_RTU_REG_SYSTEM_RECV_REGADDR 4102

// 系统参数监视寄存器起始地址
#define MODBUS_RTU_REG_SYSTEM_PARAM_START 5000

// 保持寄存器地址
#define MDBS_HD_MATERIAL_DELAY 0                       // 料位延时
#define MDBS_HD_GEAR_RATIO 2                           // 齿轮比 float
#define MDBS_HD_BOX_TOTAL_LEN 4                        // 包箱总长度
#define MDBS_HD_BOX_LEN 6                              // 打包长度
#define MDBS_HD_BACKWARD_LOW_PRESSURE_POS 12           // 后退低压位置设定
#define MDBS_HD_OUT_BOX_LEN 14                         // 出包长度设定
#define MDBS_HD_BACKWARD_CLOSE_DOOR_LEN 16             // 后退关门长度
#define MDBS_HD_FORWARD_WALK_LEN 18                    // 前进行走长度
#define MDBS_HD_TEMP_MAXLIMIT 34                       // 温度上限
#define MDBS_HD_TEMP_MINLIMIT 36                       // 温度下限
#define MDBS_HD_PRESSURE_FORWARD_PROTECT_TIME 50       // 前进压力保护计时
#define MDBS_HD_MATERIAL_FULL_DELAY 100                // 料满延时
#define MDBS_HD_RUNTIME_S 110                          // 运行时间 秒
#define MDBS_HD_RUNTIME_MIN 112                        // 运行时间 分
#define MDBS_HD_RUNTIME_H 114                          // 运行时间 时
#define MDBS_HD_RUNTIME_TOTAL_H 200                    // 运行时间计数 h
#define MDBS_HD_RUNTIME_ACTIVATE_H 210                 // 运行时间激活 h
#define MDBS_HD_RUNTIME_REMAIN_H 220                   // 剩余运行时间 h
#define MDBS_HD_PRESSURE_FASTORLOW 250                 // 快慢切换压力  float
#define MDBS_HD_FIRST_PRESSURE_COUNT 350               // 第一次预压次数
#define MDBS_HD_SECOND_PRESSURE_COUNT 360              // 第二次预压次数
#define MDBS_HD_PRESSURE_MAINCYLINDER_FORWARD 400      // 主缸前进压力设定 float
#define MDBS_HD_PRESSURE_MAXPROTECT_STOP 402           // 最高保护压力停止 float
#define MDBS_HD_PRESSURE_MAINCYLINDER_BACKWARD 404     // 主缸后退压力保护 float
#define MDBS_HD_PRESSURE_RELIEF_DELAY 600              // 泄压延时时间
#define MDBS_HD_MAINCYLINDER_BACKWARD_PROTECT_TIME 650 // 主缸后退计时

#define MDBS_HD_PRESSURE_WALK_LEN 8          // 预压行走长度设定
#define MDBS_HD_FIRST_PRESSURE_COUNT_SET 10  // 第一次预压次数设定
#define MDBS_HD_SECOND_PRESSURE_COUNT_SET 20 // 第二次预压次数设定
#define MDBS_HD_THIRD_PRESSURE_COUNT_SET 30  // 第三次预压次数设定

// HD寄存器地址偏移
#define MODBUS_RTU_HD_REG_OFFSET 41089
// D寄存器地址偏移
#define MODBUS_RTU_D_REG_OFFSET 1

#endif // PARAM_STRUCT_H
