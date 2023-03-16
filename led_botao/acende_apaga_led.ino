// Acender e apagar um led usando dois botões

//Atribuindo os pinos a variáveis


int LED = 13; //LED está no pino 13
int BT = 12;  // Botão que liga está no pino 12
int BT2 = 8;  // Botão que desliga está no pino 8

void setup()
{
pinMode(LED, OUTPUT);
pinMode(BT, INPUT_PULLUP);
pinMode(BT2, INPUT_PULLUP);
}

int estado = 0; 


void loop()
{
int valorBotao = digitalRead(BT);
int valorBotao2 = digitalRead(BT2);
 

//--------------------------------------------------
  //Apertar os botões modifica o valor do "estado"
  
	if(valorBotao == LOW){     
    estado = 1; 		   
    delay(1000);           
      					
	}  
	
  	if(valorBotao2 == LOW){ 
    estado = 0; 			
    delay(1000); 			
      						
    }
  
//-------------------------------------------------- 
  // O valor do estado é usado pra ligar o led ou desligar
  
 	if(estado == 0){
      digitalWrite(LED, LOW); 
    }
  
    else{ 
      digitalWrite(LED, HIGH); 
    }
    	
}

