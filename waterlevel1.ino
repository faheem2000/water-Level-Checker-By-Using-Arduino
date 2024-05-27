/*Water level indicator project.
  created by SriTu Tech team.
  Read the code below and use it for any of your creation
*/

//define pins and water values
#define Trig A4
#define Echo A5
#define L1 4
#define L2 5
#define L3 6
#define L4 7
#define L5 8
#define L6 10
#define L7 13

int Wlevel;
int range;
int Range;

void setup() {
  Serial.begin(9600);//enable serial monitor
  pinMode(Trig, OUTPUT);//Ultrasonic Trig pin
  pinMode(Echo, INPUT);//Ultrasonic Trig pin
  pinMode(2, OUTPUT);//LED pin
  pinMode(3, OUTPUT);//LED pin
  pinMode(4, OUTPUT);//LED pin
  pinMode(5, OUTPUT);//LED pin
  pinMode(6, OUTPUT);//LED pin
  pinMode(11, OUTPUT);//LED pin
  pinMode(12, OUTPUT);//LED pin
}

void loop() {
  Range = levelrange();
  Serial.println(Range);

  //Bulb indicator
  if (Range == 1) {
    digitalWrite(2, LOW);
    analogWrite(3, 50);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
  } else if (Range == 2) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
  } else if (Range == 3) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
  } else if (Range == 4) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
  } else if (Range == 5) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
  } else if (Range == 6) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
  } else if (Range == 000) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
  } 
}
//check water level range
int levelrange() {
  Wlevel = level();
  //Serial.println(Wlevel);
  if (Wlevel < L7 && Wlevel > L6) {
    range = 1;
  } else if (Wlevel <= L6 && Wlevel > L5) {
    range = 2;
  } else if (Wlevel <= L5 && Wlevel > L4) {
    range = 3;
  } else if (Wlevel <= L4 && Wlevel > L3) {
    range = 4;
  } else if (Wlevel <= L3 && Wlevel > L2  ) {
    range = 5;
  } else if (Wlevel <= L2 && Wlevel > L1  ) {
    range = 6;
  } else if (Wlevel >= L7 ) {
    range = 000;
  } 
  return range;
}
//Ultrasonic readings
int level() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(4);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);


  long t = pulseIn(Echo, HIGH);//input pulse and save it veriable
  long cm = t / 29 / 2; //time convert distance
  return cm;
}
