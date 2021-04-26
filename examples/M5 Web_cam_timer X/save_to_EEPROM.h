#define MAXCOUNT 100
struct  MyObject
{
  char a[256];
};
extern MyObject aaa, bbb, ccc;
////////////////////
void writeString(int add, char data[], int _size)
{
  //int _size = data.length();
  int i;
  for(i=0;i<_size;i++)
  {
    EEPROM.write(add+i,data[i]);
  }
  EEPROM.write(add +_size,'\0');   //Add termination null character for String Data
  EEPROM.commit();
}

//////////
int write_to_EEPROM(int adress, String my_name1, String my_name2) 
{  

 MyObject str;  //create structure str 
 String s1;
 s1.reserve(256); 
 s1 = "                                                           ";  //s1 is String type variable.
 int timeoutCount =0;
 int saved = 0;
 for (int k=0; k < sizeof(str.a); k++) str.a[k] = '\0';
 
 //you have to set it #define SERIAL_BUFFER_SIZE 256 in RingBuffer.h file, also
 //#define EPX_SIZE 256 // 64 for Full Speed, EPT size max is 1024 in USBAPI.h file
  while (!Serial && timeoutCount < MAXCOUNT) //wait until serial is available or timeout
  {
  timeoutCount++;
  delay(100);
  }

   if (timeoutCount<=MAXCOUNT)
   {
   Serial.println (my_name1); 
   Serial.setTimeout(30000); // set timeout of 30 seconds
   Serial.println("You have 30 seconds to press to type 'Y' or 'y': ");
   s1 = Serial.readStringUntil('\n'); //with timeout
        if (s1.indexOf('Y')>=0 || s1.indexOf('y')>=0)
           {
           // Process message when new line character is recieve                  
            s1 = ""; // clear string
            Serial.print("Yes received. ");                                
            while (Serial.available()) Serial.read();   //clean buffer
            Serial.setTimeout(50); // now set timeout of 0.1 seconds                    
            Serial.println (my_name2);
            while (!Serial.available()) delay (10); //wait for string            
              int i = 0;
              int k= Serial.available();
              char inchar ='\0';
              while ((k  > 0) && (k < 400)) //no more as 400 characters string
               {
                 inchar = Serial.read();  
                 str.a[i] = inchar;           
                 if (k < 3) delay (10); //gives possibility to collect more characters
                 k = Serial.available();
                 i++;
               }                          
              str.a[i]='\0'; //null termination
        
         if (i>1) 
         { 
         writeString(adress, str.a, i); 
         delay(100); 
         saved =1;             
         }
       else 
       {
       Serial.println("No Y received. Then proceeding with previous settings.");
       saved = 0;
       }   
   } //end if
  }
  Serial.print("This string is saved or extracted from EEPROM: ");   
  EEPROM.get(adress, str); 
  s1 = String(str.a);
  Serial.println(s1);
  return saved;
}

///////////////
 void EEPROM_setup()
{
 Serial.println("ENTERING SETUP - You have 30 seconds to press to type 'y' <ENTER>: ");
 String ss = Serial.readStringUntil('\n'); //with timeout
 char serverName[256];
 if (ss.indexOf('Y')>=0 || ss.indexOf('y')>=0)
  {
  
  write_to_EEPROM(0,   "Would you like to set network WIFI name?", "Now enter WIFI network name: "); //address = 0  
  write_to_EEPROM(100, "Would you like to set network WIFI password?", "Now enter WIFI network password: "); //address = 100    
  write_to_EEPROM(200, "Would you like to set network WEB password?", "Now enter WEB network password: "); //address = 200   
  }
}
////

void remove_End_of_Line(MyObject * bbb)
{
  int str_lenght = strlen(bbb->a);
  for (int k=0; k < str_lenght; k++)
  {
  char inByte = bbb->a[k];
  //find and remove /n character
  if (inByte == '\r' || inByte == '\n')  bbb->a[k]='\0'; //null termination
  }
}

/////////////////////////////////
  void show_EEPROM_setup()
  {
  EEPROM.get(0, bbb);                 //0 wifi name
  Serial.print("WIFI NAME is: ");
  Serial.print(bbb.a); 
  
  EEPROM.get(100, ccc);               // wifi password
  Serial.print("WIFI PASSWORD is: ");
  Serial.print(ccc.a);   
  
  EEPROM.get(200, aaa);               // WEB password
  Serial.print("WEB PASSWORD is: ");
  Serial.print(aaa.a);   
  
  remove_End_of_Line(&bbb);
  remove_End_of_Line(&ccc);
  remove_End_of_Line(&aaa);    
  }  
//////
