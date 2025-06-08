# 🛠️ STM32 I2C Master Communication with ESP32

This project demonstrates I2C communication between an STM32F4 microcontroller configured as the master and an ESP32 as the slave. The STM32 sends a predefined message to the ESP32 using I2C.

---

## 📂 Project Structure

.
├── Core
│ ├── Inc # Header files
│ ├── Src # Source files
│ │ └── main.c # Main application
│ └── Startup # Startup files
├── Drivers # HAL Drivers
├── .gitignore # Git ignore file
└── README.md # This file

---

## 📝 Features

- **I2C Communication:** STM32 acts as the I2C master and sends data to a slave device (ESP32).
- **Configurable I2C Settings:** User-defined slave address and clock speed.
- **Polling-Based Implementation:** Uses polling for simplicity.

---

## 🚀 How It Works

### 🛠️ System Configuration

#### I2C Configuration:
- **Peripheral:** I2C1
- **Master Address:** `0x10` (arbitrary; not used in communication).
- **Slave Address:** `0x28` (ESP32 address).
- **Clock Speed:** 100 kHz (standard mode).
- **GPIO Pins:**
  - **PB8:** SCL (Serial Clock Line)
  - **PB9:** SDA (Serial Data Line)

### 🔧 I2C Master Functions

#### `I2C_Master_Init()`
1. Configures GPIO pins for I2C (PB8 and PB9) in alternate function mode with pull-up resistors.
2. Enables the I2C1 peripheral clock.
3. Sets up I2C timing, rise time, and enables the I2C1 peripheral.

#### `I2C_Master_Write(uint8_t slave_addr, uint8_t *data, uint8_t length)`
1. Waits for the I2C bus to be free.
2. Generates a START condition.
3. Sends the slave address with the write bit.
4. Sends data bytes sequentially.
5. Generates a STOP condition after all data is transmitted.

---

## 💻 Code Walkthrough

### 🛠️ Key Functions

#### `I2C_Master_Init()`
- **GPIO Configuration:** PB8 and PB9 are set to open-drain, alternate function mode (AF4).
- **I2C Timing:** 
  - `CR2`: Configures the clock frequency for the I2C peripheral (APB1 clock = 16 MHz).
  - `CCR`: Configures the clock control for 100 kHz operation.
  - `TRISE`: Sets the maximum rise time.
- Enables the I2C peripheral by setting the `PE` bit in `CR1`.

#### `I2C_Master_Write()`
- **START Condition:** Initiates communication with the slave.
- **Address and Data Transmission:** Sends the slave address and writes the data bytes.
- **STOP Condition:** Ends the communication session.

---

## 📸 Usage Instructions

1. Clone the repository:
   ```bash
   git clone https://github.com/your-repo/stm32-i2c-master.git
2. Open the project in your STM32 IDE (e.g., STM32CubeIDE).
3. Connect the STM32 and ESP32 via I2C lines:
4. PB8 (SCL) ↔ ESP32 SCL
5. PB9 (SDA) ↔ ESP32 SDA
6. Connect appropriate pull-up resistors (4.7 kΩ) to both lines.
7. Flash the firmware onto your STM32 board.
8. Monitor the ESP32 for received data (e.g., using a serial terminal).

⚠️ Notes and Recommendations
Pull-Up Resistors: Ensure 4.7 kΩ pull-up resistors are connected to the I2C lines (SCL and SDA).

Clock Speed: The default I2C clock speed is 100 kHz; adjust as needed in I2C_Master_Init().

Error Handling: This example does not include error handling for simplicity.

ESP32 Configuration: Ensure the ESP32 is configured to act as an I2C slave and has the correct address.

| Icon | Description                       |
| ---- | --------------------------------- |
| 🛠️  | Code or functionality explanation |
| 🔧   | Configuration details             |
| 🚀   | How to run the project            |
| 📂   | File structure overview           |
