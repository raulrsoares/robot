
/*
  Copyright © 2022 Tropa do Robo, Inc
  Programa para controle de robô via Bluetoth - Micontrolador ESP-32
*/



#include "BluetoothSerial.h"   //chama a biblioteca Bluetoth

//Configuração da Placa ESP-32                                                                                  Não precisa alterar
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT;
//                                                                                                              Não precisa alterar

//    Declarando variáveis
const int led =  2;  //Define Led

String message = "";
char incomingChar;

//PORTAS  MOTOR
int mtDF = 27;  //motor direita frente
int mtDT = 33;  //motor direita trás
int mtEF = 19;  //motor esquerda frente
int mtET = 4;   //motor esquerda trás


//                                                                                                              Inicio da configuração - Principal/Inicial
void setup() {


  //Configurando ESP-32
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pinMode(mtDF, OUTPUT);
  pinMode(mtDT, OUTPUT);//CONFIGURA MOTORES    garanta que os motores de fato respeite as configurações. inverta número das portas até o controle funcionar de forma adequada
  pinMode(mtEF, OUTPUT);
  pinMode(mtET, OUTPUT);
  SerialBT.begin("robozin"); //Nome do Bluetooth  senha:1234
}
//                                                                                                              Fim da configuração - Principal/Inicial


// Código de configuração aqui, para executar uma vez:
void loop() {

  MOVE(1, 0, 1, 0); // declarar MOVER, DF, DB, EF, EB

  if (SerialBT.available()) {

    char incomingChar = SerialBT.read();
    if (incomingChar != '\n')
      message += String(incomingChar);
  }


  //                                                                                                              Recebendo comando do aplicativo (F) - Inicio
  if (message == "F"); {

    digitalWrite(mtDF, HIGH);
    digitalWrite(mtDT, LOW);
    digitalWrite(mtEF, HIGH);
    digitalWrite(mtET, LOW);
    digitalWrite(led, HIGH);
  }

  //                                                                                                              Recebendo comando do aplicativo (F) - Fim

  //                                                                                                              Recebendo comando do aplicativo (L) - Inicio
  if (message == "L") {

    digitalWrite(mtDF, LOW);
    digitalWrite(mtDT, HIGH);
    digitalWrite(mtEF, HIGH);
    digitalWrite(mtET, LOW);
    digitalWrite(led, HIGH);
  }
  //                                                                                                              Recebendo comando do aplicativo (L) - Fim

  //                                                                                                              Recebendo comando do aplicativo (R) - Inicio
  if (message == "R") {

    digitalWrite(mtDF, HIGH);
    digitalWrite(mtDT, LOW);
    digitalWrite(mtEF, HIGH);
    digitalWrite(mtET, LOW);
    digitalWrite(led, HIGH);
  }
  //                                                                                                              Recebendo comando do aplicativo (R) - FIM

  //                                                                                                              Recebendo comando do aplicativo (B) - Inicio
  if (message == "B") {

    digitalWrite(mtDF, LOW);
    digitalWrite(mtDT, HIGH);
    digitalWrite(mtEF, LOW);
    digitalWrite(mtET, HIGH);
    digitalWrite(led, HIGH);
  }
  //                                                                                                              Recebendo comando do aplicativo (B) - Fim
  /*
    //                                                                                                              Recebendo comando do aplicativo (G) - Inicio
    if (message == "G") {

      digitalWrite(mtDF, LOW);
      digitalWrite(mtDT, HIGH);
      digitalWrite(mtEF, LOW);
      digitalWrite(mtET, HIGH);
      digitalWrite(led, HIGH);
    }
    //                                                                                                              Recebendo comando do aplicativo (G) - Fim
  */
  //                                                                                                              Recebendo comando do aplicativo (S) - Inicio
  else if (message == "S") {

    digitalWrite(mtDF, 0);
    digitalWrite(mtDT, LOW);
    digitalWrite(mtEF, 0);
    digitalWrite(mtET, LOW);
    digitalWrite(led, LOW);
  }
  //                                                                                                              Recebendo comando do aplicativo (S) - Fim

  //                                                                                                              Recebendo comando do aplicativo (X) - Inicio

  //Aplicativo conta com comando de voz, pré configurada palavra "robonáticos", se o aplicativo entender essa palavra ele irá enviar a letra X para o ESP que irá realizar os movimentos abaixo.
  else if (message == "X") {

    digitalWrite(led, 1);
    digitalWrite(mtDF, 1);
    digitalWrite(mtDT, m1t);
    digitalWrite(mtEF, m2);
    digitalWrite(mtET, m2t);
    delay(300);
    digitalWrite(led, 1);
    digitalWrite(mtDF, m1);
    digitalWrite(mtDT, m1t);
    digitalWrite(mtEF, 1);
    digitalWrite(mtET, m2t);
    delay(300);
    digitalWrite(mtDF, 1);
    digitalWrite(mtDT, m1t);
    digitalWrite(mtEF, m2);
    digitalWrite(mtET, m2t);
    delay(200);
    digitalWrite(led, 1);
    digitalWrite(mtDF, m1);
    digitalWrite(mtDT, m1t);
    digitalWrite(mtEF, 1);
    digitalWrite(mtET, m2t);
    delay(200);
    digitalWrite(mtDF, 1);
    digitalWrite(mtDT, m1t);
    digitalWrite(mtEF, m2);
    digitalWrite(mtET, m2t);
    delay(100);
    digitalWrite(led, 1);
    digitalWrite(mtDF, m1);
    digitalWrite(mtDT, m1t);
    digitalWrite(mtEF, 1);
    digitalWrite(mtET, m2t);
    delay(100);
    digitalWrite(led, 0);
    digitalWrite(mtDF, m1);
    digitalWrite(mtDT, m1t);
    digitalWrite(mtEF, m2);
    digitalWrite(mtET, m2t);
    delay(100);
    digitalWrite(mtDF, m1);
    digitalWrite(mtDT, m1t);
    digitalWrite(mtEF, m2);
    digitalWrite(mtET, m2t);
  }

  //                                                                                                              Recebendo comando do aplicativo (X) - Fim

  Serial.println(message);     //comando resposável em limpar a variavel "message"
  message = "";

}

void MOVE(byte m1, byte m1t, byte m2, byte m2t) {

digitalWrite(mtDF, m1);
    digitalWrite(mtDT, m1t);
    digitalWrite(mtEF, m2);
    digitalWrite(mtET, m2t);
    
}


/*
  Made with @raulrsoares © 2022  Tropa do Robo, Inc
*/
