
int photoPin = A7;
// ms_counts do not directly correlate to actual ms
// due to clock differences between stock and 3rd party nano
// 1 s on clock = 4 s irl
const int BACKGROUND_COUNT = 250; 
// int vals[BACKGROUND_COUNT];
unsigned long background_sum = 0;
unsigned long background_avg;
int reading;
int corrected_reading;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(photoPin, INPUT);

  for(int i = 0; i < BACKGROUND_COUNT; i++){
    // vals[i] = analogRead(photoPin);
    background_sum += analogRead(photoPin);
  }
  background_avg = background_sum / BACKGROUND_COUNT;
}

void loop() {
  // put your main code here, to run repeatedly:

  reading = analogRead(photoPin); //- background_avg;
  corrected_reading = max(reading, 0);
  Serial.println(corrected_reading, DEC);
  delay(100);
}
