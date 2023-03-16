// Piscar dois leds 

void setup()
{
 //inicialização de variáveis

 	pinMode (13, OUTPUT); //Led conectado na porta 13
 	pinMode (4, OUTPUT);
}
void loop()
{
 	digitalWrite(13, HIGH);
  	delay(1000);
 	digitalWrite(13, LOW); 
  	delay(1000);
  
   	digitalWrite(4, HIGH);
  	delay(1000);
 	digitalWrite(4, LOW); 
  	delay(1000); 	
}