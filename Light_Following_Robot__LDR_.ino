// ==================== Pin Definitions ====================
#define LeftLDR 8
#define CenterLDR 7
#define RightLDR 9

#define IN1 10 // Left Motor (+)
#define IN2 11 // Left Motor (-)
#define IN3 12 // Right Motor (+)
#define IN4 13 // Right Motor (-)

// ==================== Sensor Active Level ====================
#define LIGHT_ACTIVE_STATE LOW // Change to HIGH if needed

// ==================== Setup ====================
void setup() {
  Serial.begin(9600);

  pinMode(LeftLDR, INPUT);
  pinMode(CenterLDR, INPUT);
  pinMode(RightLDR, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  motorStop();
  delay(1000);

  Serial.println("Robot Ready - Test each sensor with torch");
}

// ==================== Motor Control Functions ====================
void motorForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("CMD: FORWARD");
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("CMD: TURN LEFT");
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("CMD: TURN RIGHT");
}

void motorStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("CMD: STOP");
}

// ==================== Debug Function ====================
void printSensorStatus() {
  static unsigned long lastPrint = 0;

  if (millis() - lastPrint > 300) {
    int l = digitalRead(LeftLDR);
    int c = digitalRead(CenterLDR);
    int r = digitalRead(RightLDR);

    Serial.print("LDR: L=");
    Serial.print(l);
    Serial.print(" C=");
    Serial.print(c);
    Serial.print(" R=");
    Serial.print(r);
    Serial.print(" | Active Level = ");
    Serial.println(LIGHT_ACTIVE_STATE);

    lastPrint = millis();
  }
}

// ==================== Main Loop ====================
void loop() {
  bool leftActive = (digitalRead(LeftLDR) == LIGHT_ACTIVE_STATE);
  bool centerActive = (digitalRead(CenterLDR) == LIGHT_ACTIVE_STATE);
  bool rightActive = (digitalRead(RightLDR) == LIGHT_ACTIVE_STATE);

  printSensorStatus();

  if (centerActive) {
    motorForward();
  }
  else if (leftActive) {
    turnLeft();
  }
  else if (rightActive) {
    turnRight();
  }
  else {
    motorStop();
  }

  delay(50);
}