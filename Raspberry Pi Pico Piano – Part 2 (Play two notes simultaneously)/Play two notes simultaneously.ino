#define BUZZER1 12
#define BUZZER2 15

#define TEMPO 3500
#define PAUSE 100     // length of pause between notes

const int c = 11;
const int cs = 10;
const int d = 9;
const int ds = 8;
const int e = 7;
const int f = 6;
const int fs = 5;
const int g = 4;
const int gs = 3;
const int a = 2;
const int as = 1;
const int b = 0;

int beats1[] = {10};
void setup() { 
  pinMode(BUZZER1, OUTPUT);
  pinMode(BUZZER2, OUTPUT);

  pinMode(c, INPUT);
  digitalWrite(c,HIGH);

  pinMode(cs, INPUT);
  digitalWrite(cs,HIGH);
  
  pinMode(d, INPUT);
  digitalWrite(d,HIGH);

  pinMode(ds, INPUT);
  digitalWrite(ds,HIGH);

  pinMode(e, INPUT);
  digitalWrite(e,HIGH);
  
  pinMode(f, INPUT);
  digitalWrite(f,HIGH);

  pinMode(fs, INPUT);
  digitalWrite(fs,HIGH);
  
  pinMode(g, INPUT);
  digitalWrite(g,HIGH);

  pinMode(gs, INPUT);
  digitalWrite(gs,HIGH);
  
  pinMode(a, INPUT);
  digitalWrite(a,HIGH);

  pinMode(as, INPUT);
  digitalWrite(as,HIGH);
  
  pinMode(b, INPUT);
  digitalWrite(b,HIGH);
}


void play2Tones(long tone1, long tone2, long duration) {
  byte s1, s2;    // state of the buzzers
  long sum1, sum2, cur, next, n1, n2;
  cur = next = sum1 = sum2 = 0;

  // Init buzzers
  s1 = s2 = LOW;
  digitalWrite(BUZZER1, s1);
  digitalWrite(BUZZER2, s2);

  if (tone1 > 0 && tone2 > 0) { 
    duration -= PAUSE;
    tone1 = tone1 << 1
    tone2 = tone2 << 1
    while (cur < duration) {
      next = min(min(sum1 + tone1, sum2 + tone2), duration);
      delayMicroseconds(next-cur);
      if(sum1 + tone1 == next) {
        //s1 = s1==HIGH ? LOW : HIGH;
        if(s1 == HIGH){
            s1 = LOW;
        }else{
          s1 = HIGH;  
        }
        digitalWrite(BUZZER1, s1);
        Serial.println(s1);
        sum1 += tone1;
      }
      if(sum2 + tone2 == next) {
        //s2 = s2==HIGH ? LOW : HIGH;
        if(s2 == HIGH){
            s2 = LOW;
        }else{
          s2 = HIGH;  
        }
        digitalWrite(BUZZER2, s2);
        Serial.println(s2);
        sum2 += tone2;
      }
      cur = next;
    } 
    delayMicroseconds(PAUSE);
  }
}

void loop() { 
  //C
  if(digitalRead(c) == HIGH && digitalRead(cs) == LOW && digitalRead(d) == LOW 
    && digitalRead(ds) == LOW && digitalRead(e) == LOW && digitalRead(f) == LOW 
    && digitalRead(fs) == LOW && digitalRead(g) == LOW  && digitalRead(gs) == LOW  
    && digitalRead(a) == LOW  && digitalRead(as) == LOW && digitalRead(b) == LOW)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NC4,NC4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(c) == HIGH && digitalRead(cs) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NC4,NCS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(c) == HIGH && digitalRead(d) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NC4,ND4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(c) == HIGH && digitalRead(ds) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NC4,NDS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(c) == HIGH && digitalRead(e) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NC4,NE4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(c) == HIGH && digitalRead(f) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NC4,NF4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(c) == HIGH && digitalRead(fs) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NC4,NFS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(c) == HIGH && digitalRead(g) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NC4,NG4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(c) == HIGH && digitalRead(gs) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NC4,NGS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(c) == HIGH && digitalRead(a) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NC4,NA4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(c) == HIGH && digitalRead(as) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NC4,NAS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(c) == HIGH && digitalRead(b) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NC4,NB4, beats1[i] * 4 * TEMPO);
    }
  }

  //Note D
  if(digitalRead(d) == HIGH && digitalRead(c) == LOW && digitalRead(cs) == LOW 
    && digitalRead(ds) == LOW && digitalRead(e) == LOW && digitalRead(f) == LOW 
    && digitalRead(fs) == LOW && digitalRead(g) == LOW  && digitalRead(gs) == LOW  
    && digitalRead(a) == LOW  && digitalRead(as) == LOW && digitalRead(b) == LOW)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(ND4,ND4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(d) == HIGH && digitalRead(cs) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(ND4,NCS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(d) == HIGH && digitalRead(ds) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(ND4,NDS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(d) == HIGH && digitalRead(e) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(ND4,NE4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(d) == HIGH && digitalRead(f) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(ND4,NF4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(d) == HIGH && digitalRead(fs) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(ND4,NFS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(d) == HIGH && digitalRead(g) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(ND4,NG4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(d) == HIGH && digitalRead(gs) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(ND4,NGS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(d) == HIGH && digitalRead(a) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(ND4,NA4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(d) == HIGH && digitalRead(as) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(ND4,NAS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(d) == HIGH && digitalRead(b) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(ND4,NB4, beats1[i] * 4 * TEMPO);
    }
  }

  //Note E
  if(digitalRead(e) == HIGH && digitalRead(c) == LOW && digitalRead(cs) == LOW 
    && digitalRead(d) == LOW && digitalRead(ds) == LOW && digitalRead(f) == LOW 
    && digitalRead(fs) == LOW && digitalRead(g) == LOW  && digitalRead(gs) == LOW  
    && digitalRead(a) == LOW  && digitalRead(as) == LOW && digitalRead(b) == LOW)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NE4,NE4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(e) == HIGH && digitalRead(cs) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NE4,NCS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(e) == HIGH && digitalRead(ds) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NE4,NDS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(e) == HIGH && digitalRead(f) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NE4,NF4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(e) == HIGH && digitalRead(fs) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NE4,NFS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(e) == HIGH && digitalRead(g) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NE4,NG4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(e) == HIGH && digitalRead(gs) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NE4,NGS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(e) == HIGH && digitalRead(a) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NE4,NA4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(e) == HIGH && digitalRead(as) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NE4,NAS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(e) == HIGH && digitalRead(b) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NE4,NB4, beats1[i] * 4 * TEMPO);
    }
  }

  //Note F
  if(digitalRead(f) == HIGH && digitalRead(c) == LOW && digitalRead(cs) == LOW 
    && digitalRead(d) == LOW && digitalRead(ds) == LOW && digitalRead(e) == LOW 
    && digitalRead(fs) == LOW && digitalRead(g) == LOW  && digitalRead(gs) == LOW  
    && digitalRead(a) == LOW  && digitalRead(as) == LOW && digitalRead(b) == LOW)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NF4,NF4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(f) == HIGH && digitalRead(cs) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NE4,NCS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(f) == HIGH && digitalRead(ds) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NF4,NDS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(f) == HIGH && digitalRead(fs) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NF4,NFS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(f) == HIGH && digitalRead(g) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NF4,NG4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(f) == HIGH && digitalRead(gs) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NF4,NGS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(f) == HIGH && digitalRead(a) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NF4,NA4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(f) == HIGH && digitalRead(as) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NF4,NAS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(f) == HIGH && digitalRead(b) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NF4,NB4, beats1[i] * 4 * TEMPO);
    }
  }

  //Note G
  if(digitalRead(g) == HIGH && digitalRead(c) == LOW && digitalRead(cs) == LOW 
    && digitalRead(d) == LOW && digitalRead(ds) == LOW && digitalRead(e) == LOW 
    && digitalRead(f) == LOW && digitalRead(fs) == LOW  && digitalRead(gs) == LOW  
    && digitalRead(a) == LOW  && digitalRead(as) == LOW && digitalRead(b) == LOW)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NG4,NG4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(g) == HIGH && digitalRead(cs) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NG4,NCS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(g) == HIGH && digitalRead(ds) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NG4,NDS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(g) == HIGH && digitalRead(fs) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NG4,NFS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(g) == HIGH && digitalRead(gs) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NG4,NGS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(g) == HIGH && digitalRead(a) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NG4,NA4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(g) == HIGH && digitalRead(as) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NG4,NAS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(g) == HIGH && digitalRead(b) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NG4,NB4, beats1[i] * 4 * TEMPO);
    }
  }

  //Note A
  if(digitalRead(a) == HIGH && digitalRead(c) == LOW && digitalRead(cs) == LOW 
    && digitalRead(d) == LOW && digitalRead(ds) == LOW && digitalRead(e) == LOW 
    && digitalRead(f) == LOW && digitalRead(fs) == LOW  && digitalRead(g) == LOW  
    && digitalRead(gs) == LOW  && digitalRead(as) == LOW && digitalRead(b) == LOW)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NA4,NA4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(a) == HIGH && digitalRead(cs) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NA4,NCS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(a) == HIGH && digitalRead(ds) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NA4,NDS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(a) == HIGH && digitalRead(fs) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NA4,NFS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(a) == HIGH && digitalRead(gs) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NA4,NGS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(a) == HIGH && digitalRead(as) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NA4,NAS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(a) == HIGH && digitalRead(b) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NA4,NB4, beats1[i] * 4 * TEMPO);
    }
  }

  //Note B
  if(digitalRead(b) == HIGH && digitalRead(c) == LOW && digitalRead(cs) == LOW 
    && digitalRead(d) == LOW && digitalRead(ds) == LOW && digitalRead(e) == LOW 
    && digitalRead(f) == LOW && digitalRead(fs) == LOW  && digitalRead(g) == LOW  
    && digitalRead(gs) == LOW  && digitalRead(a) == LOW && digitalRead(as) == LOW)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NB4,NB4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(b) == HIGH && digitalRead(cs) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NB4,NCS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(b) == HIGH && digitalRead(ds) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NB4,NDS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(b) == HIGH && digitalRead(fs) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NB4,NFS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(b) == HIGH && digitalRead(gs) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NB4,NGS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(b) == HIGH && digitalRead(a) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NB4,NA4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(b) == HIGH && digitalRead(as) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NB4,NAS4, beats1[i] * 4 * TEMPO);
    }
  }

  //Note CS
  if(digitalRead(cs) == HIGH && digitalRead(c) == LOW  && digitalRead(d) == LOW 
    && digitalRead(ds) == LOW && digitalRead(e) == LOW && digitalRead(f) == LOW 
    && digitalRead(fs) == LOW  && digitalRead(g) == LOW && digitalRead(gs) == LOW  
    && digitalRead(a) == LOW && digitalRead(as) == LOW && digitalRead(b) == LOW)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NCS4,NCS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(cs) == HIGH && digitalRead(ds) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NCS4,NDS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(cs) == HIGH && digitalRead(fs) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NCS4,NFS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(cs) == HIGH && digitalRead(gs) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NCS4,NGS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(cs) == HIGH && digitalRead(as) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NCS4,NAS4, beats1[i] * 4 * TEMPO);
    }
  }

  //Note DS
  if(digitalRead(ds) == HIGH && digitalRead(c) == LOW  && digitalRead(cs) == LOW 
    && digitalRead(d) == LOW && digitalRead(e) == LOW && digitalRead(f) == LOW 
    && digitalRead(fs) == LOW  && digitalRead(g) == LOW && digitalRead(gs) == LOW  
    && digitalRead(a) == LOW && digitalRead(as) == LOW && digitalRead(b) == LOW)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NDS4,NDS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(ds) == HIGH && digitalRead(fs) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NDS4,NFS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(ds) == HIGH && digitalRead(gs) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NDS4,NGS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(ds) == HIGH && digitalRead(as) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NDS4,NAS4, beats1[i] * 4 * TEMPO);
    }
  }

  //Note FS
  if(digitalRead(fs) == HIGH && digitalRead(c) == LOW  && digitalRead(cs) == LOW 
    && digitalRead(d) == LOW && digitalRead(ds) == LOW && digitalRead(e) == LOW 
    && digitalRead(f) == LOW  && digitalRead(g) == LOW && digitalRead(gs) == LOW  
    && digitalRead(a) == LOW && digitalRead(as) == LOW && digitalRead(b) == LOW)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NFS4,NFS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(fs) == HIGH && digitalRead(gs) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NFS4,NGS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(fs) == HIGH && digitalRead(as) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NFS4,NAS4, beats1[i] * 4 * TEMPO);
    }
  }

  //Note GS
  if(digitalRead(gs) == HIGH && digitalRead(c) == LOW  && digitalRead(cs) == LOW 
    && digitalRead(d) == LOW && digitalRead(ds) == LOW && digitalRead(e) == LOW 
    && digitalRead(f) == LOW  && digitalRead(fs) == LOW && digitalRead(g) == LOW  
    && digitalRead(a) == LOW && digitalRead(as) == LOW && digitalRead(b) == LOW)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NGS4,NGS4, beats1[i] * 4 * TEMPO);
    }
  }
  if(digitalRead(gs) == HIGH && digitalRead(as) == HIGH)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NGS4,NAS4, beats1[i] * 4 * TEMPO);
    }
  }

  //Note AS
  if(digitalRead(as) == HIGH && digitalRead(c) == LOW  && digitalRead(cs) == LOW 
    && digitalRead(d) == LOW && digitalRead(ds) == LOW && digitalRead(e) == LOW 
    && digitalRead(f) == LOW  && digitalRead(fs) == LOW && digitalRead(g) == LOW  
    && digitalRead(gs) == LOW && digitalRead(a) == LOW && digitalRead(b) == LOW)
  {
    int n = sizeof(beats1) / 2;
    for (int i=0; i<n; i++) {
      play2Tones(NAS4,NAS4, beats1[i] * 4 * TEMPO);
    }
  }
}
