/*Memory Game v1
by JX Pan
email 736107120@qq.com
contact me before spreading thecode for any purpose
*/


//-----------------
//SETTINGS:
const int inPutWaitTime= 10000; //in ms, how long to wait for your input until ruled losing
const int PinLED1=4;
const int PinLED2=5;
const int PinBUT1=12;
const int PinBUT2=13;
const int difficulty= 600;
const int buttonReactTime= 400

//-----------------
//CODE:
int arrange [100];
int i;

void setup() {
  Serial.begin(9600);
  pinMode(PinLED1,OUTPUT);
  pinMode(PinLED2,OUTPUT);
  pinMode(PinBUT1,INPUT);
  pinMode(PinBUT2,INPUT);
}

void loop() {

  randomSeed(analogRead(0)*analogRead(1)/analogRead(2)*analogRead(3));
  arrange[i] = random(1,3);


  for(int n=0;arrange[n]>0;n++){
    digitalWrite(3+arrange[n],HIGH);
    digitalWrite(6-arrange[n],LOW);
    delay(difficulty);
    digitalWrite(3+arrange[n],LOW);
    delay(difficulty*0.8);
  }
  int answerN = 0;
  for (int n = 0; n<inPutWaitTime;n++){

    if(digitalRead(PinBUT1)==HIGH){
      if(arrange[answerN] ==1){
        flash(PinLED1,PinLED2,400);
        answerN ++;
        n=0;
      }
      else{
        loseRoutine();
        break;
      }
    }
    if(digitalRead(PinBUT2)==HIGH){
      if(arrange[answerN] ==2){
        flash(PinLED2,PinLED1,buttonReactTime);
        answerN ++;
        n=0;
      }
      else{
        loseRoutine();
        break;
      }
    }
    if (arrange[answerN]==0){
      break;
    }
    if(n==inPutWaitTime-1){
      loseRoutine();
      break;
    }

    delay(1);
  }



  i++;
  if(i == 100){
    digitalWrite(PinLED1,HIGH);
    digitalWrite(PinLED2,HIGH);
    delay(1000);
    digitalWrite(PinLED1,LOW);
    digitalWrite(PinLED2,LOW);
    delay(1000);
    digitalWrite(PinLED1,HIGH);
    digitalWrite(PinLED2,HIGH);
    delay(1000);
    digitalWrite(PinLED1,LOW);
    digitalWrite(PinLED2,LOW);
    delay(1000);
    digitalWrite(PinLED1,HIGH);
    digitalWrite(PinLED2,HIGH);
    delay(5000);
    digitalWrite(PinLED1,LOW);
    digitalWrite(PinLED2,LOW);
    delay(2000);
  }
}


void flash(int pin, int pinToClose, int time ){
  digitalWrite(pinToClose,LOW);
  digitalWrite(pin,HIGH);
  delay(time);
  digitalWrite(pin,LOW);
  delay(time/10);
}

void loseRoutine(){
  digitalWrite(PinLED1,HIGH);
  digitalWrite(PinLED2,HIGH);
  delay(2000);
  digitalWrite(PinLED1,LOW);
  digitalWrite(PinLED2,LOW);
  delay(2000);
  digitalWrite(PinLED2,HIGH);
  digitalWrite(PinLED1,HIGH);
  delay(2000);
  digitalWrite(PinLED1,LOW);
  digitalWrite(PinLED2,LOW);
  delay(1500);
  i = -1;
  for(int times= 0; times<100;times++){
    arrange [times]=0;
  }
}


//this code was uploaded to https://github.com/p99410/MemoryGameArduino/blob/master／

