void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int turbidity = analogRead(A0);
  float vo = turbidity*(5.0/1024.0)*1.14;
  float ntu ;
  if(vo < 2.5){
      ntu = 3000;
    }else{
      ntu = -1120.4*square(vo)+5742.3*vo-4353.8; 
    }
  Serial.println(ntu);
  delay(1500);
}