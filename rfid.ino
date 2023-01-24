#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

#define RST_PIN         9
#define SS_PIN          10
#define GREEN_LED       8
#define RED_LED         1


MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);        
  SPI.begin();                                                  
  mfrc522.PCD_Init();                                           
  lcd.begin(16, 2);
  lcd.clear();
  lcd.write("Passar cartao:");
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

}

void loop() {


  MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;


  byte block;
  byte len;
  MFRC522::StatusCode status;


  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  delay(2000);
  lcd.clear();
  lcd.print("Sucesso");
  delay(2000);



  mfrc522.PICC_DumpDetailsToSerial(&(mfrc522.uid));



  byte buffer1[18];

  block = 4;
  len = 18;

  //------------------------------------------- NOME

  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 4, &key, &(mfrc522.uid)); //line 834 of MFRC522.cpp file
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Autenticação Falhada: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  status = mfrc522.MIFARE_Read(block, buffer1, &len);
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Leitura Falhada: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }


  lcd.clear();
  lcd.print("Nome");

  for (uint8_t i = 0; i < 16; i++)
  {
    if (buffer1[i] != 32)
    {
      lcd.write(buffer1[i]);
    }
  }

  delay(5000);

  //---------------------------------------- TURMA

  byte buffer2[18];
  block = 1;

  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 1, &key, &(mfrc522.uid)); //line 834
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Autenticação Falhada: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  status = mfrc522.MIFARE_Read(block, buffer2, &len);
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Leitura Falhada: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  String test;

  lcd.clear();
  lcd.print("Turma");
  
  for (uint8_t i = 0; i < 16; i++) {
      lcd.write(buffer2[i]);
    test += String((char)buffer2[i]);
  }

 delay(5000);

  //---------------------------------------- ANO

  byte buffer3[18];
  block = 6;

  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 6, &key, &(mfrc522.uid)); //line 834
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Autenticação Falhada: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  status = mfrc522.MIFARE_Read(block, buffer3, &len);
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Leitura Falhada: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }


  lcd.clear();
  lcd.print("Ano");
  
  for (uint8_t i = 0; i < 16; i++) {
      lcd.write(buffer3[i]);
  }


  delay(5000);

  //--------------------------------------------- PROCURAR CARTAO/LIGAR LEDS

  test.trim();

  if (test == "TETO") {
    lcd.clear();
    lcd.println("TETO Aceite");
    digitalWrite(GREEN_LED, HIGH);
    delay(5000);
    digitalWrite(GREEN_LED, LOW);
         delay(1000);
         lcd.clear();
         lcd.println("A abrir horario ");
         delay(1000);         
  } else if (test == "TGEIO") {
    lcd.clear();
    lcd.println("TGEIO Aceite");
    digitalWrite(GREEN_LED, HIGH);
    delay(5000);
    digitalWrite(GREEN_LED, LOW);
         delay(1000);
         lcd.clear();
         lcd.println("A abrir horario ");
         delay(5000);       
  } else {
    lcd.println("Negado");
    digitalWrite(RED_LED, HIGH);
    delay(5000);
    digitalWrite(RED_LED, LOW);

  }

  lcd.clear();
  lcd.print("Tirar cartao 15s");
  delay(15000);


  lcd.clear();
  lcd.print("Passar cartao:");


  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
}
