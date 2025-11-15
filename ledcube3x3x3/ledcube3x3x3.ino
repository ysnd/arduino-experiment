const int layerPin[3] = {11, 12, 13};     
const int columnPin[9] = {2, 3, 4, 5, 6, 7, 8, 9, 10};  

// Contoh pola cube: cube[z][y][x]
bool cube[3][3][3] = {
  { // Layer 0 (bawah)
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1}
  },
  { // Layer 1 (tengah)
    {0, 1, 0},
    {1, 0, 1},
    {0, 1, 0}
  },
  { // Layer 2 (atas)
    {1, 1, 1},
    {1, 0, 1},
    {1, 1, 1}
  }
};

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(layerPin[i], OUTPUT);
    digitalWrite(layerPin[i], HIGH);  
  }
  for (int i = 0; i < 9; i++) {
    pinMode(columnPin[i], OUTPUT);
    digitalWrite(columnPin[i], LOW);  
  }
}

void loop() {
  for (int z = 0; z < 3; z++) {
    activateLayer(z);
    for (int y = 0; y < 3; y++) {
      for (int x = 0; x < 3; x++) {
        int index = y * 3 + x; 
        if (cube[z][y][x]) {
          digitalWrite(columnPin[index], HIGH); 
        }
      }
    }
    delay(2);
    clearAll();
  }
}

// 🔧 Fungsi bantu
void activateLayer(int z) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(layerPin[i], HIGH); // Semua layer OFF dulu
  }
  digitalWrite(layerPin[z], LOW);    // Layer z ON (transistor aktif)
}

void clearAll() {
  for (int i = 0; i < 9; i++) {
    digitalWrite(columnPin[i], LOW); // Matikan kolom
  }
}
