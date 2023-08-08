/*
 * @author: Ahmed Mohammed Bakr
 * Linkedin: https://www.linkedin.com/in/ahmed-mohammed-bakr/
 */

int enLeft = 7;
int enRight = 8;
int right_motor1 = 5;
int right_motor2 = 6;
int left_motor1 = 9;
int left_motor2 = 10;
int right_signal = 11;
int left_signal = 2;
int trig = 3;
int echo = 4;
int duration;
int distance;

void setup() {
    pinMode(right_motor1, OUTPUT);
    pinMode(left_motor1, OUTPUT);
    pinMode(right_motor2, OUTPUT);
    pinMode(left_motor2, OUTPUT);
    pinMode(enLeft, OUTPUT);
    pinMode(enRight, OUTPUT);
    pinMode(right_signal, INPUT);
    pinMode(left_signal, INPUT);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(enLeft, HIGH);
    digitalWrite(enRight, HIGH);
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH);
    distance = duration * 0.034 / 2;
    Serial.print("Distance: ");
    Serial.println(distance);

    if (distance <= 9) {
        analogWrite(right_motor1, 100);
        digitalWrite(left_motor1, LOW);
        digitalWrite(right_motor2, LOW);
        digitalWrite(left_motor2, LOW);
        delay(800);

        digitalWrite(right_motor1, LOW);
        analogWrite(left_motor1, 100);
        digitalWrite(right_motor2, LOW);
        digitalWrite(left_motor2, LOW);
        delay(800);

        analogWrite(right_motor1, 100);
        analogWrite(left_motor1, 100);
        digitalWrite(right_motor2, LOW);
        digitalWrite(left_motor2, LOW);
        delay(700);

        digitalWrite(right_motor1, LOW);
        analogWrite(left_motor1, 100);
        digitalWrite(right_motor2, LOW);
        digitalWrite(left_motor2, LOW);
        delay(800);

        analogWrite(right_motor1, 100);
        digitalWrite(left_motor1, LOW);
        digitalWrite(right_motor2, LOW);
        digitalWrite(left_motor2, LOW);
        delay(800);
    } else {
        if (digitalRead(right_signal) == HIGH && digitalRead(left_signal) == LOW) {
            analogWrite(left_motor1, 0);
            analogWrite(right_motor1, 80);
            digitalWrite(right_motor2, LOW);
            digitalWrite(left_motor2, LOW);
            Serial.println("Right");
        } else if (digitalRead(left_signal) == HIGH && digitalRead(right_signal) == LOW) {
            analogWrite(left_motor1, 80);
            analogWrite(right_motor1, 0);
            digitalWrite(right_motor2, LOW);
            digitalWrite(left_motor2, LOW);
            Serial.println("Left");
        } else {
            analogWrite(right_motor1, 100);
            analogWrite(left_motor1, 100);
            digitalWrite(right_motor2, LOW);
            digitalWrite(left_motor2, LOW);
            Serial.println("forward");
        }
    }
}
