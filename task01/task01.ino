#define PIN_1 3
#define PIN_2 5
#define PIN_3 6
#define PIN_4 9
#define PIN_5 10

unsigned long interval_1 = 533;
unsigned long interval_2 = 133;
unsigned long interval_3 = 13;
unsigned long interval_4 = 266;
unsigned long interval_5 = 133;

unsigned long previousMillis_1 = 0;
unsigned long previousMillis_2 = 0;
unsigned long previousMillis_3 = 0;
unsigned long previousMicros_4 = 0;
unsigned long previousMicros_5 = 0;

int pinState_1 = LOW;
int pinState_2 = LOW;
int pinState_3 = LOW;
int pinState_4 = LOW;
int pinState_5 = LOW;

unsigned long currentMicros = 0;
unsigned long currentMillis = 0;

void setup() {
  pinMode(PIN_1, OUTPUT);
  pinMode(PIN_2, OUTPUT);
  pinMode(PIN_3, OUTPUT);
  pinMode(PIN_4, OUTPUT);
  pinMode(PIN_5, OUTPUT);
}

void blinkMicros(int pin, int &pinState, int interval, unsigned long currentMicros, unsigned long &previousMicros){
  
  if (currentMicros - previousMicros >= interval) {
    previousMicros = currentMicros;
    
    if (pinState == LOW) {
      pinState = HIGH;
    } else {
      pinState = LOW;
    }

    digitalWrite(pin, pinState);
  }
}

void blinkMillis(int pin, int &pinState, int interval, unsigned long currentMillis, unsigned long &previousMillis){
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    if (pinState == LOW) {
      pinState = HIGH;
    } else {
      pinState = LOW;
    }
    digitalWrite(pin, pinState);
  }
}

void loop() {
  currentMicros = micros();
  currentMillis = millis();
  
  blinkMillis(PIN_1, pinState_1, interval_1, currentMillis, previousMillis_1);
  blinkMillis(PIN_2, pinState_2, interval_2, currentMillis, previousMillis_2);   
  blinkMillis(PIN_3, pinState_3, interval_3, currentMillis, previousMillis_3);  
  blinkMicros(PIN_4, pinState_4, interval_4, currentMicros, previousMicros_4);
  blinkMicros(PIN_5, pinState_5, interval_5, currentMicros, previousMicros_5); 
}
