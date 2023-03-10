 #include <Wire.h>
 #include <Time.h>
 #include <DS1307RTC.h>
 #include <Servo.h>
 #include <EEPROM.h>
 #include <SPI.h>
 #include <MFRC522.h>

 
 #define SS_PIN 10
 #define RST_PIN 9

 
 #include <Servo myservo>;

 
 pinMode(match  ,INPUT);
 pinMode(programMode,INPUT);
 pinMode(replaceMaster,INPUT);
 
 
// making changes
 int lightSensor=0;
 int distanceSensor=1;
 int pos= 0;

 
 int successRead;

 
 byte storedCard[4];
 byte readCard[4];
 byte masterCard[4];

 
 MFRC522 mfrc522(SS_PIN , RST_PIN );

 
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 setSyncProvider( RTC.get);

 myservo.attach(9);

 Serial .begin(9600);
 SPI.begin();
 mfrc522.PCD_Init();
 if (EEPROM .read (1) !=143) {
  do{
    successRead= getID();
  }
  while(!successRead);

 
  for( int j = 0; j < 4; j++ ) {
   EEPROM.write( 2 + j,readCard[j] );
  }
} 

void loop() {
  // put your main code here, to run repeatedly:
  int valueFromLightSensor = analogRead(lightSensor);
  int valueFromDistanceSensor=analogRead(distanceSensor);
  int distance=4800/(valueFromLightSensor - 20);
  Serial.print(distance);

 do {
  successRead  = getID ();

 }
 if(programMode) {
   if ( isMaster (readCard ) ) {
      programMode  =  INPUT;
     return;
   }
   else {
     if(findID( readCard) ) {
      
     }
     
   }
   
 }

 
 else {
   if( isMaster (readCard)) {
     programMode = true;
          int count = EEPROM.read (0);
   }

   
   else  {
     if ( findID (readCard ) ) {
      
               if( hour()>=8)&&( hour()<=12 )){
                 if (distance>=20){
                     for(pos = 130; pos>=1; pos-=1)
                       {
                        myservo . write(pos);
                        delay (20);
                       }
                     for(pos = 50;  pos < 180; pos += 1)
                       {
                         myservo.write(pos );
                         delay (20);
                     }
                     
                 }
               delay (10000);
               }

               
     if ((hour()>=12)&&(hour()<=16 )){
                if(distance>=20){
                   for (pos pos = 130; pos >=1; pos -=1)
                     {
                      
                      myservo .write(pos );
                      delay (20);
                     }
                   for(pos = 50; pos< 180; pos += 1)
                     {
                       myservo .write (pos);
                       delay (20);
                   }

                 }
               delay (10000);
         }


   if ((hour()>=0) && (hour()<=8 )){
                   if (distance>=20){
                    
                       for (pos = 130; pos >=1; pos -=1)
                         {
                          myservo.write (pos );
                          delay  (20);
                         }
                       for (pos =50; pos < 180 ; pos += 1)
                         {
                            myservo.write(pos);
                            delay (20);
                        }
                        
                   }
                 delay(20000 );
           }


           
           if ((hour()>=16) && (hour()<=20)){
                    if (distance>=20){
                        Serial .println(distance);
                        for (pos  = 130; pos >=1; pos -=1)
                          {
                           myservo .write (pos);
                           delay (20);
                          }
                        for (pos  = 5050; pos  < 180; pos += 1)
                          {
   myservo.write(pos);
   delay(20);
     }

     
                    }
                  delay ( 10000);
            }

            
         }
            }
    }
   }

   
   int  val=digitalRead(Sensor_pin) {
    if ( !  mfrc522.PICC_IsNewCardPresent ()) {
      return  0;
    }
    if( ! mfrc522.PICC_ReadCardSerial()) {
      return 0;
    }
    Serial.println(F);
    for  (int i= 0; i < 4; i++) { 
      
      Serial .print (readCard[i] );
    }
    Serial.println ("");
    mfrc522 . PICC_HaltA();
    return 1;
   }

     for ( int k= 0; k < 4; k++ ) {
       if( a[k] != b[k] )
         match  = false;
      }
      if ( match ) {
        return  true;
      }
      else {
        return  false;
      }
     }

     
     int  findIDSLOT ( byte find [] ) {
      int  count  = EEPROM.read(0);
      for ( int i = 1;i <=  count; i++ ) {
        readID (i);
        if( checkTwo ( find, storedCard ) ) {
          return i;
          break ;
        }
      }
     } 

     
     boolean ( byte find[] ) {
      int  count  = EEPROM .read (0);

      for ( int i = 1; i <= count; i++ ) {
        readID (i);

      if( checkTwo( find, storedCard ) ) {
         return true;
     
        }
        
      }
      return  false;
     }

     
     boolean isMaster (  byte test[] ) {
      if( checkTwo ( test , masterCard  ) )
        return  true;
      else{

        return false;
      }
     }
