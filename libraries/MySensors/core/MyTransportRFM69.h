/**
 * The MySensors Arduino library handles the wireless radio link and protocol
 * between your home built sensors/actuators and HA controller of choice.
 * The sensors forms a self healing radio network with optional repeaters. Each
 * repeater and gateway builds a routing tables in EEPROM which keeps track of the
 * network topology allowing messages to be routed to nodes.
 *
 * Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
 * Copyright (C) 2013-2015 Sensnology AB
 * Full contributor list: https://github.com/mysensors/Arduino/graphs/contributors
 *
 * Documentation: http://www.mysensors.org
 * Support Forum: http://forum.mysensors.org
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 */

#ifndef MyTransportRF69_h
#define MyTransportRF69_h

#include "MyConfig.h"
#include "MyTransport.h"
#include <stdint.h>
#include "drivers/RFM69/RFM69.h"
#include "drivers/SPI/SPI.h"


class MyTransportRFM69 : public MyTransport
{ 
public:
	MyTransportRFM69(uint8_t freqBand=MY_RFM69_FREQUENCY, uint8_t networkId=MY_RFM69_NETWORKID, uint8_t slaveSelectPin=MY_RF69_SPI_CS, uint8_t interruptPin=MY_RF69_IRQ_PIN, bool isRFM69HW=false, uint8_t interruptNum=MY_RF69_IRQ_NUM);
	bool init();
	void setAddress(uint8_t address);
	uint8_t getAddress();
	bool send(uint8_t to, const void* data, uint8_t len);
	bool available(uint8_t *to);
	uint8_t receive(void* data);
	void powerDown();
private:
	RFM69 radio;
	uint8_t _address;
	uint8_t _freqBand;
	uint8_t _networkId;
};

#endif