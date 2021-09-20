#include <SPI.h>
#include <SD.h>

File myFile;
int i;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(8,INPUT_PULLUP);  
  pinMode(9,INPUT_PULLUP);  
  delay(1000);

  if (!SD.begin(10)) {
    Serial.println(" SD card Gagal!  ");
    delay(2000);
    while(1);
  }
  Serial.println("SD card Berhasil ");
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(8)==LOW){
      Serial.println("Tulis Data...");
      i++;
      writeSD();
      delay(500);
  }
  else if(digitalRead(9)==LOW){
      Serial.println("Baca Data...");
      readSD();
      delay(500); 
  }
}

void writeSD(){
  //===================Simpan data ke sd Card
      myFile = SD.open("data1.txt", FILE_WRITE);
      if (myFile) {
          Serial.println("  Simpan data");
          Serial.println("file->data1.txt");
          myFile.print("Data ke-");   
          myFile.println(i);
          myFile.close();
          delay(2000);
          Serial.println("  Berhasil...  ");
      } 
      else {
          Serial.println("error buka file");
          Serial.println("   data1.txt");
      }
      delay(1000);
}

void readSD(){
  //====================baca isi file data1.txt  
  myFile = SD.open("data1.txt");
  if (myFile){
    Serial.println("Isi File data1.txt:");
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close();
  }  
  else{
    Serial.println("buka file data1.txt Error!!");
  }  
}
