const int ledX = D0;
const int ledY = D1;
bool receiveStatus = true;

void setup(){
    Serial.begin(115200);
    pinMode(ledX, OUTPUT);
    pinMode(ledY, OUTPUT);
    digitalWrite(ledX, LOW);
    digitalWrite(ledY, LOW);
}

void loop(){
    if(Serial.available() > 0  && receiveStatus == true){
        int valX = map(byte(Serial.read()), 0, 640, 180, 0);
        analogWrite(ledX, valX);
        receiveStatus = false;
    }

    else if(Serial.available() > 0 && receiveStatus == false){
        int valY = map(byte(Serial.read()), 0, 480, 180, 0);
        analogWrite(ledY, valY);
        receiveStatus = true;
    }
    
}
