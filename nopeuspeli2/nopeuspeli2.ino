int randNum; 
short int points,j;
int Delay = 600;
bool k = true;                       

void setup(){
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

void start_routine(){
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

void loop(){
  start_routine();                 
  while(k){                       //Starting game sequence
    randNum = random(3,7);
    digitalWrite(randNum,HIGH);
    delay(Delay);           
    digitalWrite(randNum,LOW);
    delay(150);
    j++;
    Delay = Delay - 5;
    if(j!=points){
      k=false;
    }  
  }
  Serial.println(points);          //Printing score in the serial monitor at the end of game
  while(1);
}

void point_count(){              //Couting point when interrupt encounters
  digitalWrite(randNum,LOW);
  points++;
}

