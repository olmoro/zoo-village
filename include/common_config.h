#ifndef _COMMON_CONFIG_H_
#define _COMMON_CONFIG_H_


// Номер выводов периферии, версия платы 023
// Светодиоды
#define CONFIG_GPIO_SYSTEM_LED    12    // ???

#define CONFIG_GPIO_LED_BLUE       4    // Синий, катод на GND
#define CONFIG_GPIO_LED_RED       15    // Красный, катод на GND
#define CONFIG_GPIO_IR_X1         14    // Выход на ИК светодиод, подключен к X1, катод на GND 
#define CONFIG_GPIO_IR_X2          5    // Выход на ИК светодиод, подключен к X2, катод на GND

// Входы
#define CONFIG_GPIO_IR            21    // Вход ИК датчика
#define CONFIG_GPIO_X5            26    // Вход X5
#define CONFIG_GPIO_X4            27    // Вход X4
#define CONFIG_GPIO_LINE_X6       32    // Вход контроля напряжения на X6
#define CONFIG_GPIO_LINE_X7       33    // Вход контроля напряжения на X7

// Датчики температуры, все DS18B20
#define CONFIG_GPIO_TEMP_X1       25    // Датчик температуры, подключен к X1
#define CONFIG_GPIO_TEMP_X2       16    // Датчик температуры, подключен к X2
#define CONFIG_GPIO_TEMP_X3       17    // Датчик температуры, подключен к X3

// Выходы
#define CONFIG_GPIO_RELAY_K1      19    // Выход на силовое реле K1 (X6)
#define CONFIG_GPIO_RELAY_K2      18    // Выход на силовое реле K2 (X7)
#define CONFIG_GPIO_RELAY_K3      22    // Выход на реле аварии K3 (X8)
#define CONFIG_GPIO_RELAY_K4      23    // Выход на реле аварии K4 (X9)

// ------------------------------------------------------------------------
//                            Общие параметры 
// ------------------------------------------------------------------------
// Перезапустить устройство при ошибках выделения памяти
#define CONFIG_HEAP_ALLOC_FAILED_RESTART 0
#define CONFIG_HEAP_ALLOC_FAILED_RETRY 0

/* Silent mode (no sounds, no blinks) */
// Разрешить "тихий" режим. Тихий режим - это период времени суток, когда блокируются вспышки светодиодов и звуки.
#define CONFIG_SILENT_MODE_ENABLE 1
#define CONFIG_SILENT_MODE_EXTENDED 0
// Интервал в формате H1M1H2M2. То есть интервал 21:00 -> 06:00 это 21000600
#define CONFIG_SILENT_MODE_INTERVAL 22000600UL

// ------------------------------------------------------------------------
// --------------------------------------------- RU - Контроль температуры -----------------------------------------------
// ------------------------------------------------------------------------
// Здесь можно указать вообще любые параметры, связанные с прикладной задачей устройства

// Интервал чтения данных с сенсоров в миллисекундах
#define CONFIG_SENSORS_TASK_CYCLE 30000
/* Использовать статическое выделение памяти под задачу и очередь. 
     Должен быть включен параметр CONFIG_FREERTOS_SUPPORT_STATIC_ALLOCATION! */
#define CONFIG_SENSORS_STATIC_ALLOCATION 1
// Размер стека для главной задачи
#define CONFIG_SENSORS_TASK_STACK_SIZE 4*1024

// Разрешить публикацию необработанных RAW-данных (без коррекции и фильтрации):
// 0 - только обработанное значение, 
// 1 - всегда оба значения, 
// 2 - только когда есть обработка
#define CONFIG_SENSOR_RAW_ENABLE 1
// Разрешить публикацию форматированных данных в виде строки
#define CONFIG_SENSOR_STRING_ENABLE 0
// Разрешить публикацию отметки времени чтения данных с сенсора
#define CONFIG_SENSOR_TIMESTAMP_ENABLE 1
// Разрешить публикацию форматированных данных в виде "значение + время"
#define CONFIG_SENSOR_TIMESTRING_ENABLE 1
// // Разрешить вычисление и публикацию точки росы
// #define CONFIG_SENSOR_DEWPOINT_ENABLE 0
// Разрешить публикацию смешанного значения, например "температура + влажность"
#define CONFIG_SENSOR_DISPLAY_ENABLED 0
// Разрешить публикацию абсолютного минимума и максимума
#define CONFIG_SENSOR_EXTREMUMS_ENTIRELY_ENABLE 1
// Разрешить публикацию ежедневного минимума и максимума
#define CONFIG_SENSOR_EXTREMUMS_DAILY_ENABLE 1
// Разрешить публикацию еженедельного минимума и максимума
#define CONFIG_SENSOR_EXTREMUMS_WEEKLY_ENABLE 1
// Публиковать экстеремумы только при их изменении
#define CONFIG_SENSOR_EXTREMUMS_OPTIMIZED 1


// ------------------------------------------------------------------------
//                               WiFi сети 
// ------------------------------------------------------------------------
/* 
 *  Режим для одной сети
 * --------------------
 * Раскомментируйте CONFIG_WIFI_SSID и CONFIG_WIFI_PASS, чтобы отключить 
 * автоматическое переключение между wifi-сетями
 * */
#define CONFIG_WIFI_SSID "HUAWEI-a6mB"
#define CONFIG_WIFI_PASS "rmbDHxYK"

/** 
 * Режим для нескольких сетей
 * --------------------
 * Вы можете определенить от одной до пяти сетей. При невозможности 
 * подключиться к одной из сетей, ESP попытается поключиться к следующей. 
 * Номер успешного подключения запоминается и используется в дальнейшем
 *  (до следущего сбоя). 
 * Это позволяет переносить устройство из одного здания в другое, не 
 * перепрошивая и перенастраивая его. 
 * Просто заранее определите все возможные сети.
 * */
// #define CONFIG_WIFI_1_SSID "WIFI1"
// #define CONFIG_WIFI_1_PASS "000000000"
// #define CONFIG_WIFI_2_SSID "WIFI2"
// #define CONFIG_WIFI_2_PASS "111111111"
// #define CONFIG_WIFI_3_SSID "WIFI3"
// #define CONFIG_WIFI_3_PASS "222222222"
// #define CONFIG_WIFI_4_SSID "WIFI4"
// #define CONFIG_WIFI_4_PASS "333333333"
// #define CONFIG_WIFI_5_SSID "WIFI5"
// #define CONFIG_WIFI_5_PASS "444444444"

/* Параметры WiFi подключения. Если закомментировать эти строки, будут 
    использованы параметры по умолчанию ESP-IDF */
// #define CONFIG_WIFI_STORAGE   WIFI_STORAGE_RAM
// #define CONFIG_WIFI_BANDWIDTH WIFI_BW_HT20

/* Перезапустить устройство, если нет подключения к WiFi более указанного
    времени в минутах. 
   Закомментируйте строку, если не нужно перезапускать устройство при длительном 
   отсутствии подключения к сети */
#define CONFIG_WIFI_TIMER_RESTART_DEVICE 60*24

/* Разрешить периодическую проверку доступности сети интернет с помошью пинга. 
    Иногда доступ в сеть может пропасть, но подключение к WiFi при этом работает. 
    В этом случае устройство приостановит все сетевые процессы. */
#define CONFIG_PINGER_ENABLE 1

/* Отключить иникацию сетевых ошибок (wifi, inetnet, openmon, tg...), так как 
    устройство не всегда подключено к сети */
#define CONFIG_OFFLINE_MODE 0





#endif // _COMMON_CONFIG_H_
