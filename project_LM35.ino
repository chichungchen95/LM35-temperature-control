float Temp=0.0, Humi=0.0,Temp_set=0.0,C=0.0;  //宣告變數
int fan_Cool = 13,fan_small = 14;
unsigned int ADC_Value = 0;
const int analogInPin = A0;  // ESP8266 Analog Pin ADC0 = A0
char Request[] = {0xFF,0x01,0x86,0x00,0x00,0x00,0x00,0x00,0x79};
char Response[10] = {};
int value = 0;

//========== 初始設定部分 ============
void setup() 
{ //設定串列埠
  Serial.begin(9600); //啟用串列埠(連接序列埠監控視窗)
  delay(10);           //稍候10ms 
  pinMode(fan_Cool,OUTPUT);
  pinMode(fan_small,OUTPUT);
}

//========== 主程式部分 ============
void loop() 
{ //
    ADC_Value = analogRead(analogInPin);   // turn the LED on (HIGH is the voltage level)
//    Serial.print(s);         //在序列埠監控視窗上顯示訊息

//    Serial.print("sensor = ")
    float temp = ADC_Value/11.1;

    Serial.println(temp);
    if(ADC_Value>210){
         digitalWrite(fan_Cool, HIGH);//設定RY1之初始狀態
         delay(100);         
    }
    if(ADC_Value<209){
        digitalWrite(fan_Cool, LOW);//設定RY1之初始狀態
        digitalWrite(fan_small,HIGH);//設定RY1之初始狀態
        delay(10);
    }
//    digitalWrite(fan_Cool, HIGH);//設定RY1之初始狀態
//    digitalWrite(fan_small,HIGH);//設定RY1之初始狀態
//    delay(1000);
    digitalWrite(fan_small,LOW);//設定RY1之初始狀態
    delay(1000);
}
