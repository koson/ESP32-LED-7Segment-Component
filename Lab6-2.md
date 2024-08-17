# Lab 6-2

## 1 สร้าง idf component ใหม่ 

1.1 สร้าง idf component ใหม่ โดยตั้งชื่อ `SevenSegment` 

1.2 เรียกเมนู View -> command palette...

1.3  พิมพ์ component แล้วเลือก `ESP-IDF: Create New ESP-IDF Component` 

![alt text](./Slide/image01.png)

1.4 พิมพ์ `SevenSegment` แล้วกด  enter

![alt text](./Slide/image02.png)

จะได้ source code ของ component มาเป็น folder

![alt text](./Slide/image03.png)

1.5 แก้ไข component  ให้เป็นภาษา C++

![alt text](./Slide/image04.png)

1.6 ทดสอบ build โปรแกรม ควรจะ  build ผ่าน


## 2 สร้าง คลาสสำหรับ 7 segment  

2.1 เพิ่มการประกาศคลาสในไฟล์ `SevenSegment.h`
```cpp
#include "LED.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
class SevenSegment
{
    int common_pin;
    LED seg_a = LED(16);
    LED seg_b = LED(17);
    LED seg_c = LED(5);
    LED seg_d = LED(18);
    LED seg_e = LED(19);
    LED seg_f = LED(21);
    LED seg_g = LED(22);
    LED common = LED(common_pin);
public:
    SevenSegment(int pin)
    {
        common_pin = pin;
        common = LED(common_pin);
    } 
    void HardwareTest();
    void DisplayBlank();
};
```

2.2 เพิ่ม function ใน `SevenSegment.cpp`

```cpp
#include <stdio.h>
#include "SevenSegment.h"

void SevenSegment::HardwareTest()
{
    common.ON();
    seg_a.ON();
    vTaskDelay(500/portTICK_PERIOD_MS);
    seg_b.ON();
    vTaskDelay(500/portTICK_PERIOD_MS);
    seg_c.ON();
    vTaskDelay(500/portTICK_PERIOD_MS);
    seg_d.ON();
    vTaskDelay(500/portTICK_PERIOD_MS);
    seg_e.ON();
    vTaskDelay(500/portTICK_PERIOD_MS);
    seg_f.ON();
    vTaskDelay(500/portTICK_PERIOD_MS);
    seg_g.ON();
    vTaskDelay(500/portTICK_PERIOD_MS);
}

void SevenSegment::DisplayBlank()
{
    common.ON();
    seg_a.OFF();
    seg_b.OFF();
    seg_c.OFF();
    seg_d.OFF();
    seg_e.OFF();
    seg_f.OFF();
    seg_g.OFF();
}
```

## 3. ทดสอบโปรแกรมใน main.cpp

3.1 แก้ไข  code  ใน main.cpp

```cpp
#include <stdio.h>
#include "SevenSegment.h"

SevenSegment s1(0) ;
SevenSegment s2(4) ;

extern "C" void app_main(void)
{
    while(1)
    {
        s1.HardwareTest();
        vTaskDelay(500/portTICK_PERIOD_MS);
        s1.DisplayBlank();
        vTaskDelay(500/portTICK_PERIOD_MS);
    } 
}
```

สังเกตุและบันทึกผลการทดลอง (ส่ง link วิดิโอ)

SevenSegment ของ s1 ติด แค่ อันเดียวเพราะในโค้ดเป็นการ สั่งให้ s1 ติดแค่อันเดียว และ มีการติดครบวงจร  และ และติดครบ ลูป โดยติดเป็นเวลาครึ่งวินาที   SevenSegment s2 ไม่ติดเพราะโค้ดไม่ได้มีคำสั่งให้ติด

รูปภาพ

![image](https://github.com/user-attachments/assets/d409ea77-d96a-4966-9c60-d7697818013a)
![image](https://github.com/user-attachments/assets/de7c0c99-3d86-4736-9620-7cfbe94cf074)

วิดิโอ

https://vt.tiktok.com/ZS2FxBRty/

![image](https://github.com/user-attachments/assets/ebc2aadc-d50f-43c7-8698-d55c15955d19)




3.2 แก้ไข  code  ใน main.cpp

```cpp
#include <stdio.h>
#include "SevenSegment.h"

SevenSegment s1(0) ;
SevenSegment s2(4) ;

extern "C" void app_main(void)
{
    while(1)
    {
        s2.HardwareTest();
        vTaskDelay(500/portTICK_PERIOD_MS);
        s2.DisplayBlank();
        vTaskDelay(500/portTICK_PERIOD_MS);
    } 
}
```

สังเกตุและบันทึกผลการทดลอง (ส่ง link วิดิโอ)

SevenSegment ของ s2 ติด แค่ อันเดียวเพราะในโค้ดเป็นการ สั่งให้ s2 ติดแค่อันเดียว และ และติดครบ ลูป โดยติดเป็นเวลาครึ่งวินาที  SevenSegment s1 ไม่ติดเพราะโค้ดไม่ได้มีคำสั่งให้ติด

รูปภาพ

![image](https://github.com/user-attachments/assets/7c3a0119-fe22-4fc8-b7bb-9f9072ac3dfd)

![image](https://github.com/user-attachments/assets/3df85198-38b1-4869-974e-74b014da633e)



วิดิโอ
https://vt.tiktok.com/ZS2FxuYq7/

![image](https://github.com/user-attachments/assets/2f043ac0-a1ae-47b7-b147-173aa62ed36a)


3.3 แก้ไข  code  ใน main.cpp

```cpp
#include <stdio.h>
#include "SevenSegment.h"

SevenSegment s1(0) ;
SevenSegment s2(4) ;

extern "C" void app_main(void)
{
    while(1)
    {
        s1.HardwareTest();
        vTaskDelay(500/portTICK_PERIOD_MS);
        s1.DisplayBlank();
        vTaskDelay(500/portTICK_PERIOD_MS);
        s2.HardwareTest();
        vTaskDelay(500/portTICK_PERIOD_MS);
        s2.DisplayBlank();
        vTaskDelay(500/portTICK_PERIOD_MS);
    } 
}
```

สังเกตุและบันทึกผลการทดลอง (ส่ง link วิดิโอ)

SevenSegment ของ s1 ติด กับ SevenSegment ของ s2 ติด เพราะมีคำสั่งในโค้ดให้ SevenSegment ของ s1 และ s2 ติด
จะเห็นว่า SevenSegment ติดอยู่ 2 อัน และติดครบ ลูป โดยติดเป็นเวลาครึ่งวินาที

รูปภาพ

![image](https://github.com/user-attachments/assets/c8bf32b6-ecd9-4018-8fd3-a01f769d0738)

![image](https://github.com/user-attachments/assets/6480d251-a7d0-48c4-a469-3c444cc20db7)
![image](https://github.com/user-attachments/assets/f5581050-a23e-462f-99c6-100dfed9ca1a)

![image](https://github.com/user-attachments/assets/4c4efca9-c544-490f-80f5-b0914de4e6df)

วิดิโอ

https://vt.tiktok.com/ZS2FxEWT3/

![image](https://github.com/user-attachments/assets/0838d25b-4668-4054-bc90-a1142a656d50)

   
ลิงค์งานบน GIT HUB

https://github.com/AnchisaPhetnoi/LAB__6.git








