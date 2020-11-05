const byte MOTOR_L1 = 3;  //  назад
const byte MOTOR_L2 = 4;  //  вперед
const byte INPUT_L = 5;
const byte MOTOR_R1 = 7;  //  назад
const byte MOTOR_R2 = 8;  //  вперед
const byte INPUT_R = 6;
//const byte SPEED_L = 255;
//const byte SPEED_R = SPEED_L*(0.06/0.045);  
/* это соотношение применяется для разных моторов (конкретно у меня).
 * предполагаю, что один мотор RS445PA15200R, а другой RS445PD15205BR.
 * https://datasheetspdf.com/pdf/813147/MabuchiMotor/RS-445PA/1 сравнение.
 * сделал соотношение токов по току NO LOAD.
 */ 

void setup() 
{
  pinMode(MOTOR_L1, OUTPUT);
  pinMode(MOTOR_L2, OUTPUT);
  pinMode(INPUT_L, OUTPUT);
  pinMode(MOTOR_R1, OUTPUT);
  pinMode(MOTOR_R2, OUTPUT);
  pinMode(INPUT_R, OUTPUT);
  set_speed(0,0);
}

void loop() 
{
  set_speed(255, 255);
  forward();
  delay(1000);
  left();
  delay(500);
  right();
  delay(500);
  _stop();
  delay(500);
  backward();
  delay(800);
}

void set_speed(int leftSpeed, int rightSpeed)
{
  analogWrite(INPUT_L, leftSpeed);
  analogWrite(INPUT_R, rightSpeed);
}

void forward()
{
  digitalWrite(MOTOR_L1, LOW);
  digitalWrite(MOTOR_L2, HIGH);
  digitalWrite(MOTOR_R1, LOW);
  digitalWrite(MOTOR_R2, HIGH);
}

void left()
{
  digitalWrite(MOTOR_L1, LOW);
  digitalWrite(MOTOR_L2, HIGH);
  digitalWrite(MOTOR_R1, LOW);
  digitalWrite(MOTOR_R2, LOW);
}

void right()
{
  digitalWrite(MOTOR_L1, LOW);
  digitalWrite(MOTOR_L2, LOW);
  digitalWrite(MOTOR_R1, LOW);
  digitalWrite(MOTOR_R2, HIGH);
}

void backward()
{
  digitalWrite(MOTOR_L1, HIGH);
  digitalWrite(MOTOR_L2, LOW);
  digitalWrite(MOTOR_R1, HIGH);
  digitalWrite(MOTOR_R2, LOW);
}

void _stop()
{
  digitalWrite(MOTOR_L1, LOW);
  digitalWrite(MOTOR_L2, LOW);
  digitalWrite(MOTOR_R1, LOW);
  digitalWrite(MOTOR_R2, LOW);
}
