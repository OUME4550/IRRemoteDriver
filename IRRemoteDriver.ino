#include "IRremote.h"
#define receiver 8 // Signal Pin of IR receiver to Arduino Digital Pin
IRrecv irrecv(receiver); // create instance of 'irrecv'
 // takes action based on IR code received
String translateIR(decode_results &results){
  switch(results.value){
    case 0xFFA25D: return String("POWER"); break;
    case 0xFFE21D: return String("VOL STOP"); break;
    case 0xFF629D: return String("MODE"); break;
    case 0xFF22DD: return String("PAUSE"); break;
    case 0xFF02FD: return String("FAST BACK"); break;
    case 0xFFC23D: return String("FAST FORWARD"); break;
    case 0xFFE01F: return String("EQ"); break;
    case 0xFFA857: return String("VOL-"); break;
    case 0xFF906F: return String("VOL+"); break;
    case 0xFF9867: return String("RETURN"); break;
    case 0xFFB04F: return String("USB SCAN"); break;
    case 0xFF6897: return String("0"); break;
    case 0xFF30CF: return String("1"); break;
    case 0xFF18E7: return String("2"); break;
    case 0xFF7A85: return String("3"); break;
    case 0xFF10EF: return String("4"); break;
    case 0xFF38C7: return String("5"); break;
    case 0xFF5AA5: return String("6"); break;
    case 0xFF42BD: return String("7"); break;
    case 0xFF4AB5: return String("8"); break;
    case 0xFF52AD: return String("9"); break;
    case 0xFFFFFFFF: return String(" REPEAT");break;
    default:
    return String(" UNKNOWN");
    }// End Case
  delay(500); // Do not get immediate repeat
} //END translateIR
void setup(){
  Serial.begin(115200);
  Serial.println("IR Receiver Button Decode");
  irrecv.enableIRIn(); // Start the receiver
}
void loop(){
  decode_results results; // create instance of 'decode_results'
  if (irrecv.decode(results)){
    Serial.println(translateIR(results));
    irrecv.resume(); // receive the next value
  }
}
