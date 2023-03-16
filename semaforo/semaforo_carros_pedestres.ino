int vermelho = 6; // led vermelho carro
int amarelo = 5;  // led amarelo
int verde = 4;    // led verde carro
int vermelhop = 3; // led vermelho pedestre
int verdep = 2;     // led verde pedestre
int btliga = 7;   // Botão ligar
int btdesliga = 8; // Botão desligar


void setup()
{
  pinMode(vermelho, OUTPUT); // Pino 6 como saída
  pinMode(amarelo, OUTPUT); // Pino 5 como saída
  pinMode(verde, OUTPUT); // Pino 4 como saída
  pinMode(vermelhop, OUTPUT); // Pino 3 como saída
  pinMode(verdep, OUTPUT); // Pino 2 como saída

  /*Botões de Pullup:
  - quando eu aperto o nivel lógico é LOW (0)
  - sem apertar, seu nivel lógico é HIGH (1)
  */  
  pinMode(btliga, INPUT_PULLUP); //Botão que liga o led entrada
  pinMode(btdesliga, INPUT_PULLUP);//Botão que desliga o led entrada
}

int estado = 0;
int x = 0;
// Serve pra registrar se um botão foi apertado
/* estado = 0 implica em manter o led desligado
 estado = 1 implica em manter o led ligado */
void verificabotao()
{
  int valorBotao = digitalRead(btliga); //Valor que o botão de ligar me dá
  int valorBotao2 = digitalRead(btdesliga);// valor que o botão desligar me dá

  // nivel lógico alto: não pressionado
  // nivel lógico baixo: pressionado
  //--------------------------------------------------
  //Apertar os botões modifica o valor do "estado"

  if(valorBotao == LOW){  // Botão que liga o led apertado   
    estado = 1; 		    //manter led ligado
    x = 1;
    delay(1000);            /*coloquei por medo 
                              de atropelar na execulção*/
  }  

  if(valorBotao2 == LOW){ // Botão que desliga o led apertado 

    estado = 0; 			// manter led desligado    
    x = 0;

    delay(1000); 			/* coloquei por medo
                              de atropelar na execulção*/
  }

  //-------------------------------------------------- 
  // O valor do estado é usado pra ligar o ledo ou desligar
}
void desligar()
{
  if (estado == 0)
  {
    digitalWrite(vermelho, LOW); //Desligue se for 0
    digitalWrite(amarelo, LOW); //Desligue se for 0
    digitalWrite(verde, LOW); //Desligue se for 0
    digitalWrite(vermelhop, LOW); //Desligue se for 0
    digitalWrite(verdep, LOW); //Desligue se for 0
    delay(1000);
    x = 1;
  }
}

void etapa1()
{
  digitalWrite(vermelho, HIGH); //Ligue se for 1
  digitalWrite(amarelo, LOW); //Desligue se for 0
  digitalWrite(verde, LOW); //Desligue se for 0
  digitalWrite(vermelhop, LOW); //Desligue se for 0
  digitalWrite(verdep, HIGH); //Desligue se for 0         
}

void etapa2()
{     
  digitalWrite(vermelho, LOW); //Desligue se for 0
  digitalWrite(amarelo, HIGH); //Ligue se for 1
  digitalWrite(verde, LOW); //Desligue se for 0
  digitalWrite(vermelhop, LOW); //Desligue se for 0
  digitalWrite(verdep, HIGH); //Desligue se for 0    
}
void etapa3()
{
  digitalWrite(vermelho, LOW); //Desligue se for 0
  digitalWrite(amarelo, LOW); //Desligue se for 0
  digitalWrite(verde, HIGH); //Ligue se for 1
  digitalWrite(vermelhop, HIGH); //Desligue se for 0
  digitalWrite(verdep, LOW); //Desligue se for 0
}


void ligadesligafarol()
{
    if(estado == 0)
  {
    verificabotao();
    desligar();
  }

  else
  {
    verificabotao();
    etapa1();
    desligar();
    delay(2000);
    verificabotao();

    if(estado == 0)
    {
      desligar();
    }
    else
    {
      etapa2();
      desligar();
      verificabotao();
      delay(2000);
      verificabotao();
      if(estado == 0)
      {
        desligar();
      }
      else
      {
        etapa3();
        desligar();
        verificabotao();
        delay(2000);
        verificabotao();
      }
    } 
  }
//   if(estado == 0)
 // {
 //   verificabotao();
  //  desligar();
  //}
}

void loop()
{
  verificabotao();
  ligadesligafarol();
}

