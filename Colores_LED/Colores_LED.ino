#define LR 6
#define LG 5
#define LB 3
#define BU 2

void turn_on(double r, double g, double b, double brightness){
  r=r*brightness;
  g=g*brightness;
  b=b*brightness;
  analogWrite(LR, r);
  analogWrite(LG, g);
  analogWrite(LB, b);
  delay(1000);
}
int state=0;
void setup() {
  pinMode(LR, OUTPUT);
  pinMode(LG, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(BU, INPUT);
}
void loop() {
  switch(state){
    case 0: turn_on(255,50,200,1); break;
    case 1: turn_on(255,20,100,1); break;
    case 2: turn_on(255,0,50,1); break;
    case 3: turn_on(255,0,0,1); break;
    case 4: turn_on(0,255,0,1); break;
    case 5: turn_on(0,0,255,1); break;
    case 6: turn_on(255,255,255,1); break;
  }
  if(digitalRead(BU)){
    state++;
    state=state%7;
  }
}
