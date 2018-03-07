// When Uploading the code you should use the ATTiny 85 @ 1MHZ option
// If you want to use the display as a wand instead then hookup a tilt switch to the RESET on pin 1.  You will need to connect a 4.7K resistor between RESET (pin1) 
// on the ATTiny85 and VCC.  Connect the tilt switch between RESET on pin 1 and ground.
// Depending which orinationation of the tilt switch, as you wave the wand DOWN the display will turn ON and display the text.  As you wave the wand UP the display will turn off because you are restting the ATTiny85.
// This way you will not be distracted with the text showing both forward and backward characters.

// Use These Timers for ".hello.." - Business Card
// To edit the message can be found at the bottom of the code.
int delayTime = 1; //sub-char delay time
int charBreak = .37; //char delay time default is 5 (this is the space between letters)

int LED1 = 3;   // 
int LED2 = 4;   // 
int LED3 = 2;  // 
int LED4 = 1;  //if you use my circuit design than use the pinouts as shown
int LED5 = 0;  //
// int TiltSwitchState = 0; // Using Rest pin so not required


void setup()
{
  pinMode(LED1, OUTPUT); 
  pinMode(LED2, OUTPUT); 
  pinMode(LED3, OUTPUT); 
  pinMode(LED4, OUTPUT); 
  pinMode(LED5, OUTPUT); 
// pinMode(5, INPUT); // Tilt Switch on PB5 which is Pin 1 use 4.7K pull up resistor to VCC USE THIS SHOULD YOU DECIDE NOT TO USE A RESET PIN (for different microcontrollers)

}
//I include a mirror image of all characters just incase you wire up the LED's in the incorrect order.  ie LED 1 to 5 or LED 5 to 1
int xx[] = {31, 4, 4, 4, 31}; // this is 4
// int a[] = {1, 6, 26, 6, 1}; // This is "A"
   int a[] = {1, 6, 26, 6, 1};
// int a[] = {10, 0, 17, 10, 4}; // This is a Smiley Face
// int a[] = {16, 31, 1, 31, 16}; // This is a squarewave use multiple a's and use delay times 2 and 0
// int b[] = {31, 21, 21, 10, 0};
 int b[] = {0, 10, 21, 21, 31};
// int c2[] = {14, 17, 17, 10, 0};
 int c2[] = {0, 10, 17, 17, 14};
// int d[] = {31, 17, 17, 14, 0};
 int d[] = {0, 14, 17, 17, 31};
// int e[] = {31, 21, 21, 17, 0};
int e[] = {0, 17, 21, 21, 31};
// int f[] = {31, 20, 20, 16, 0}; 
int f[] = {0, 16, 20, 20, 31};   
// int g[] = {14, 17, 19, 10, 0};
int g[] = {0, 10, 19, 17, 14};
// int h[] = {31, 4, 4, 4, 31};
int h[] = {31, 4, 4, 4, 31};
// int i[] = {0, 17, 31, 17, 0};
int i[] = {0, 17, 31, 17, 0};
// int j[] = {0, 17, 30, 16, 0};
int j[] = {0,16, 30, 17, 0};
// int k[] = {31, 4, 10, 17, 0};
int k[] = {0, 17, 10, 4, 31};
// int l[] = {31, 1, 1, 1, 0};
int l[] = {0, 1, 1, 1, 31};
// int m[] = {31, 12, 3, 12, 31};
int m[] = {31,12, 3, 12, 31};
// int n[] = {31, 12, 3, 31, 0};
int n[] = {0, 31, 3, 12, 31};
// int o[] = {14, 17, 17, 14, 0};
int o[] = {0, 14, 17, 17, 14};
// int p[] = {31, 20, 20, 8, 0};
int p[] = {0, 8, 20, 20, 31};
// int q[] = {14, 17, 19, 14, 2};
int q[] = {2, 14, 19, 17, 14};
// int r[] = {31, 20, 22, 9, 0};
int r[] = {0, 9, 22, 20, 31};
// int s[] = {8, 21, 21, 2, 0};
int s[] = {0, 2, 21, 21, 8};
// int t[] = {16, 16, 31, 16, 16};
int t[] = {16, 16, 31, 16, 16};
// int u[] = {30, 1, 1, 30, 0};
int u[] = {0, 30, 1, 1,30};
// int v[] = {24, 6, 1, 6, 24};
int v[] = {24, 6, 1, 6, 24};
// int w[] = {28, 3, 12, 3, 28};
int w[] = {28, 3, 12, 3, 28};
// int x[] = {17, 10, 4, 10, 17};
int x[] = {17, 10, 4, 10, 17};
// int y[] = {17, 10, 4, 8, 16};
int y[] = {16, 8, 4, 10, 17};
// int z[] = {19, 21, 21, 25, 0};
int z[] = {0, 25, 21, 21, 19};
// int int eos[] = {0, 1, 0, 0, 0};
int eos[] = {0, 0, 0, 1, 0};
// int excl[] = {0, 29, 0, 0, 0};
int excl[] = {0, 0, 0, 29, 0};
// int ques[] = {8, 19, 20, 8, 0};
int ques[] = {0, 8, 20, 19, 8};

void displayLine(int line)
{
  int myline;
 myline = line;
  if (myline>=16) {digitalWrite(LED1, HIGH); myline-=16;} else {digitalWrite(LED1, LOW);}
  if (myline>=8)  {digitalWrite(LED2, HIGH); myline-=8;}  else {digitalWrite(LED2, LOW);}
  if (myline>=4)  {digitalWrite(LED3, HIGH); myline-=4;}  else {digitalWrite(LED3, LOW);}
  if (myline>=2)  {digitalWrite(LED4, HIGH); myline-=2;}  else {digitalWrite(LED4, LOW);}
  if (myline>=1)  {digitalWrite(LED5, HIGH); myline-=1;}  else {digitalWrite(LED5, LOW);} 
 }

void displayChar(char c)
{
 if (c == 'xx'){for (int i = 0; i <5; i++){displayLine(a[i]);delay(delayTime);}displayLine(0);}
 if (c == 'a'){for (int i = 0; i <5; i++){displayLine(a[i]);delay(delayTime);}displayLine(0);}
 if (c == 'b'){for (int i = 0; i <5; i++){displayLine(b[i]);delay(delayTime);}displayLine(0);}
 if (c == 'c'){for (int i = 0; i <5; i++){displayLine(c2[i]);delay(delayTime);}displayLine(0);}
 if (c == 'd'){for (int i = 0; i <5; i++){displayLine(d[i]);delay(delayTime);}displayLine(0);}
 if (c == 'e'){for (int i = 0; i <5; i++){displayLine(e[i]);delay(delayTime);}displayLine(0);}
 if (c == 'f'){for (int i = 0; i <5; i++){displayLine(f[i]);delay(delayTime);}displayLine(0);}
 if (c == 'g'){for (int i = 0; i <5; i++){displayLine(g[i]);delay(delayTime);}displayLine(0);}
 if (c == 'h'){for (int i = 0; i <5; i++){displayLine(h[i]);delay(delayTime);}displayLine(0);} 
 if (c == 'i'){for (int it = 0; it <5; it++){displayLine(i[it]);delay(delayTime);}displayLine(0);}
 if (c == 'j'){for (int i = 0; i <5; i++){displayLine(j[i]);delay(delayTime);}displayLine(0);}
 if (c == 'k'){for (int i = 0; i <5; i++){displayLine(k[i]);delay(delayTime);}displayLine(0);}
 if (c == 'l'){for (int i = 0; i <5; i++){displayLine(l[i]);delay(delayTime);}displayLine(0);}
 if (c == 'm'){for (int i = 0; i <5; i++){displayLine(m[i]);delay(delayTime);}displayLine(0);}
 if (c == 'n'){for (int i = 0; i <5; i++){displayLine(n[i]);delay(delayTime);}displayLine(0);}
 if (c == 'o'){for (int i = 0; i <5; i++){displayLine(o[i]);delay(delayTime);}displayLine(0);}
 if (c == 'p'){for (int i = 0; i <5; i++){displayLine(p[i]);delay(delayTime);}displayLine(0);}
 if (c == 'q'){for (int i = 0; i <5; i++){displayLine(q[i]);delay(delayTime);}displayLine(0);}
 if (c == 'r'){for (int i = 0; i <5; i++){displayLine(r[i]);delay(delayTime);}displayLine(0);}
 if (c == 's'){for (int i = 0; i <5; i++){displayLine(s[i]);delay(delayTime);}displayLine(0);}
 if (c == 't'){for (int i = 0; i <5; i++){displayLine(t[i]);delay(delayTime);}displayLine(0);}
 if (c == 'u'){for (int i = 0; i <5; i++){displayLine(u[i]);delay(delayTime);}displayLine(0);}
 if (c == 'v'){for (int i = 0; i <5; i++){displayLine(v[i]);delay(delayTime);}displayLine(0);}
 if (c == 'w'){for (int i = 0; i <5; i++){displayLine(w[i]);delay(delayTime);}displayLine(0);}
 if (c == 'x'){for (int i = 0; i <5; i++){displayLine(x[i]);delay(delayTime);}displayLine(0);}
 if (c == 'y'){for (int i = 0; i <5; i++){displayLine(y[i]);delay(delayTime);}displayLine(0);}
 if (c == 'z'){for (int i = 0; i <5; i++){displayLine(z[i]);delay(delayTime);}displayLine(0);}
 if (c == '!'){for (int i = 0; i <5; i++){displayLine(excl[i]);delay(delayTime);}displayLine(0);}
 if (c == '?'){for (int i = 0; i <5; i++){displayLine(ques[i]);delay(delayTime);}displayLine(0);}
 if (c == '.'){for (int i = 0; i <5; i++){displayLine(eos[i]);delay(delayTime);}displayLine(0);}
  delay(charBreak);
}

void displayString(char* s)
{
//   TiltSwitchState = digitalRead(5);  // Not Required using reset pin
//   if (TiltSwitchState == 0) {        // Not Required using reset pin
  for (int i = strlen(s); i>=0; i--)
  {
    displayChar(s[i]);
    }
//    }  // Not required using reset pin
  }

void loop()
{   
  displayString(".hello.."); // enter only lower case characters
  }
