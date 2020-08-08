#include <LiquidCrystal.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define servo_main_Gate 5
#define servo_second_Gate_1 6
#define servo_second_Gate_2 7
#define servo_second_Gate_3 3
#define servo_second_Gate_4 4


#define SS_PIN 9
#define RST_PIN 8
MFRC522 rfid(SS_PIN, RST_PIN);   // Create MFRC522 instance.
MFRC522::MIFARE_Key key;


Servo servo_main_G;
Servo servo_secon_1;
Servo servo_secon_2;
Servo servo_secon_3;
Servo servo_secon_4;


LiquidCrystal lcd(48, 49, 46, 44, 42, 40); //Parameters: (rs, enable, d4, d5, d6, d7)

void setup() {
Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  rfid.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
        servo_main_G.attach(servo_main_Gate);
        servo_secon_1.attach(servo_second_Gate_1);
        servo_secon_2.attach(servo_second_Gate_2);
        servo_secon_3.attach(servo_second_Gate_3);
        servo_secon_4.attach(servo_second_Gate_4);
          servo_main_G.write(0);
  servo_secon_1.write(0);
  servo_secon_2.write(0);
  servo_secon_3.write(0);
  servo_secon_4.write(0);
  pinMode(32,OUTPUT);
pinMode(33,OUTPUT);
pinMode(34,OUTPUT);
pinMode(35,OUTPUT);


  lcd.begin(16, 2);   // LCD screen
  // Prints the initial message
  lcd.print("-No Master Tag!-");
  lcd.setCursor(0, 0);
  lcd.clear();
  lcd.print("SMART STADIUM");21 
}

void loop() {
    MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
    // Look for new cards
  if ( ! rfid.PICC_IsNewCardPresent())
  {
    return;
  }
  // Select one of the cards
  if ( ! rfid.PICC_ReadCardSerial())
  {
    return;
  }

   Serial.print("UID tag :");
  String content = "";
  byte letter;
  for (byte i = 0; i < rfid.uid.size; i++)
  {
    Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(rfid.uid.uidByte[i], HEX);
    content.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(rfid.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  //first user
  if (content.substring(1)=="BC F3 57 D3") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
        lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Authorized access");
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Kamal Magdy");
    delay(3000);
    lcd.setCursor(0, 2);
    lcd.print("AB     D120   G1");
    servo_main_G.write(90);
    delay(3000);
    servo_main_G.write(0);
         delay(3000);
digitalWrite(32,HIGH);  
delay(250);
     
    servo_secon_1.write(90);
    delay(3000);
    servo_secon_1.write(0);
    digitalWrite(32,LOW);
    delay(250); 
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("  Scanning...");
    }
    else if (content.substring(1) == "57 10 22 12") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
        lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Authorized access");
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("AbdelRahman Ayman");
     delay(3000);
    lcd.setCursor(0, 2);
    lcd.print("A+     A100   G2");
    servo_main_G.write(90);
    delay(3000);
    servo_main_G.write(0);
         delay(3000);
digitalWrite(33,HIGH);  
delay(250);
    servo_secon_2.write(90);
    delay(3000);
    servo_secon_2.write(0);
digitalWrite(33,LOW);
delay(250);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("  Scanning...");
    }
    else if (content.substring(1) == "67 F5 42 08") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
        lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Authorized access");
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Diaa EL-Din ");
    delay(3000);
    lcd.setCursor(0, 2);
    lcd.print("B+     A122   G3");
    servo_main_G.write(90);
    delay(3000);
    servo_main_G.write(0);
         delay(3000);
   digitalWrite(34,HIGH);  
delay(250);
    servo_secon_3.write(90);
    delay(3000);
    servo_secon_3.write(0);
  digitalWrite(34,LOW);
delay(250);

    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("  Scanning...");
    }
     else if (content.substring(1) == "57 3D 4A 08") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
        lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Authorized access");
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Ahmed Mohamed");
     delay(3000);
    lcd.setCursor(0, 2);
    lcd.print("A-     A74   G4");
    servo_main_G.write(90);
    delay(3000);
    servo_main_G.write(0);
     delay(3000);
     digitalWrite(35,HIGH);  
delay(250);
    servo_secon_4.write(90);
    delay(3000);
    servo_secon_4.write(0);
    digitalWrite(35,LOW);
delay(250);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("  Scanning...");
    }
    else if (content.substring(1) == "87 F1 46 08") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
        lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Authorized access");
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Ahmed Hesham");
     delay(3000);
    lcd.setCursor(0, 2);
    lcd.print("AB+     A20   G4");
    servo_main_G.write(90);
    delay(3000);
    servo_main_G.write(0);
     delay(3000);
     digitalWrite(35,HIGH);  
delay(250);
    servo_secon_4.write(90);
    delay(3000);
    servo_secon_4.write(0);
    digitalWrite(35,LOW);
delay(250);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("  Scanning...");
    }

    else if (content.substring(1) == "77 C7 46 08") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Authorized access");
    Serial.println();
        lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Authorized access");
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Dr.Sara Fouad");
     delay(3000);
    lcd.setCursor(0, 2);
    lcd.print("A+,Private Chair,G1");
    servo_main_G.write(90);
    delay(3000);
    servo_main_G.write(0);
     delay(3000);
     digitalWrite(35,HIGH);  
delay(250);
    servo_secon_1.write(90);
    delay(3000);
    servo_secon_1.write(0);
    digitalWrite(35,LOW);
delay(250);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("  Scanning...");
    }
     else   {
    Serial.println(" Access denied");
    servo_main_G.write(0);
    delay(3000);
  }
  }
