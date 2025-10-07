/*

// C++ code
//

 int a = 6,
  	 b = 7,
	 c = 8,
  	 d = 9,
  	 e = 10,
  	 f = 11,
  	 g = 12; 
       
int dp = 13;


// Number functions
void num0(void){
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  // g remains off
}

void num1(void){
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
}

void num2(void){
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(g,HIGH);
}

void num3(void){
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(g,HIGH);
}

void num4(void){
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}

void num5(void){
  digitalWrite(a,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}

void num6(void){
  digitalWrite(a,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}

void num7(void){
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
}

void num8(void){
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}

void num9(void){
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}



void clear(void){
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  digitalWrite(dp,LOW);
}

void setup()
{
 
  int i;
  for(i=6;i<=13;i++)  
  pinMode(i,OUTPUT);
  
}




void loop()
{

  
  
  clear();
  delay(500);
  num0();
  delay(1000);
  clear();
  
  num1();
  delay(1000);
  clear();
  
  num2();
  delay(1000);
  clear();
  
  
  num3();
  delay(1000);
  clear();
  
  
  num4();
  delay(1000);
  clear();
  
  
  num5();
  delay(1000);
  clear();
  
  
  num6();
  delay(1000);
  clear();
  
  
  num7();
  delay(1000);
  clear();
  
  
  num8();
  delay(1000);
  clear();
  
  num9();
  delay(1000);
  clear();
  
}










*/