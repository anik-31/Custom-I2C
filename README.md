# Custom I2C Communication

This repository demonstrates the implementation of a **Custom I2C Communication Protocol** between an **STM32 (Master)** and an **ESP32 (Slave)**. It includes driver-level coding to handle I2C communication, showcasing skills in embedded systems development and protocol handling.

---

## Features

- **Custom I2C Master-Slave Communication**:
  - STM32 acts as the Master device to send data.
  - ESP32 acts as the Slave device, responding to Master requests.

- **Driver Development**:
  - Implements low-level I2C communication routines for both Master and Slave.

- **Bidirectional Data Exchange**:
  - Demonstrates sending commands and receiving responses using the I2C protocol.

---

## Installation

### Prerequisites

1. **Hardware**:
   - STM32 (e.g., STM32F407)
   - ESP32 (e.g., ESP32 WROVER-IB)
   - Pull-up resistors (4.7kΩ) for the I2C lines (SDA, SCL)

2. **Software**:
   - STM32CubeIDE (for STM32 code)
   - PlatformIO (for ESP32 code)

3. **Wiring**:
   - Connect SDA and SCL lines between STM32 and ESP32.
   - Ensure pull-up resistors are connected to SDA and SCL.

### Setting Up

1. Clone the repository:
   ```bash
   git clone https://github.com/anik-31/Custom-I2C.git
   cd Custom-I2C
   ```

2. Upload the Slave code:
   - Navigate to the `ESP32_Slave/` folder.
   - Use PlatformIO or Arduino IDE to upload the code to the ESP32.

3. Upload the Master code:
   - Navigate to the `STM32_Master/` folder.
   - Open the project in STM32CubeIDE and upload it to the STM32.

---

## Usage

1. Power up the STM32 and ESP32.
2. Monitor communication using the Serial Monitor in PlatformIO or STM32CubeIDE.
3. Observe the commands sent by the Master and the responses from the Slave.

---

## Project Structure

```
Custom-I2C/
├── STM32_Master/            # Master device code (STM32)
├── ESP32_Slave/             # Slave device code (ESP32)
├── README.md                # Project documentation
└── LICENSE                  # License information
```

---

## Results

- Successful implementation of custom I2C communication.
- Robust data exchange between STM32 (Master) and ESP32 (Slave).

---

## Technologies Used

- **Hardware**: STM32, ESP32
- **Programming Languages**: Embedded C
- **Tools**: STM32CubeIDE, PlatformIO

---

## Future Work

- Expand to support multi-master and multi-slave configurations.
- Add error handling for scenarios like bus contention or data corruption.
- Include examples of sensor data transmission.

---

## Contributing

Contributions are welcome! Fork the repository, make your changes, and submit a pull request.

---

---

## Contact

For questions or suggestions, please contact **anik-31** via [GitHub Issues](https://github.com/anik-31/Custom-I2C/issues).
