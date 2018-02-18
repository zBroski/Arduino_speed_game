int randNum; 
short int i,point,j;
bool k= true;                       

void setup() {
  randomSeed(analogRead(0));
  Serial.begin(9600);
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), point_count, RISING);      //Setting the external interrupt on pin 2 raising edge
}
void start_routine()                                      //Three blink routine to indicate the start of the game
{
/* for(i=0;i<=1;i++){
  digitalWrite(3,HIGH);
  delay(150);
  digitalWrite(3,LOW);
  delay(150);
  digitalWrite(3,HIGH);
  delay(150);
  digitalWrite(3,LOW);
  delay(150);
 }*/
 delay(2000);
 Serial.println("GO");
}
void loop() {
  start_routine();                 //Calling game start routine
    while(k){                       //Starting game sequence
      randNum = random(3,7);
      digitalWrite(randNum,HIGH);
      delay(600);
      digitalWrite(randNum,LOW);
      delay(150);
      j++;
      if(j!=point){
        k=false;
      }  
   }
   Serial.print(point);          //Printing score in the serial monitor at the end of game
   //Serial.println("/15 correct");
   while(1);
}

void point_count(){              //Couting point when interrupt encounters
  digitalWrite(randNum,LOW);
  point=point+1;
}

