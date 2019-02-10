#include <unistd.h>				//Needed for I2C port
#include <fcntl.h>				//Needed for I2C port
#include <sys/ioctl.h>			//Needed for I2C port
#include <linux/i2c-dev.h>		//Needed for I2C port
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "i2c_module.h"

i2c_module::i2c_module()
{
    //ctor
    memset(&this->m_i2c_rx_buffer, 0, sizeof(this->m_i2c_rx_buffer));
    this->m_length = 0;
    this->m_address = 0;
    this->m_file_i2c_st = 0;

}

i2c_module::~i2c_module()
{
    //dtor
    memset(&this->m_i2c_rx_buffer, 0, sizeof(this->m_i2c_rx_buffer));
    this->m_length = 0;
    this->m_address = 0;
    this->m_file_i2c_st = 0;
}

char i2c_module::open_i2c(char mode, int addr){
    std::cout << "Opening I2C!"<< std::endl;
    strcpy(this->m_i2c_file, "/dev/i2c-1");
    this->m_file_i2c_st = open(this->m_i2c_file, O_RDWR);
    if(this->m_file_i2c_st < 0){
        std::cout << "Error: Opening I2C!"<< std::endl;
        return (-1);
    }
    return 0;
}


char i2c_module::close_i2c(i2c_module * obj){
    std::cout << "Closing I2C!"<< std::endl;
    close(obj->m_file_i2c_st);
    return 0;
}

char i2c_module::Setaddress(int addr){

	if (ioctl(this->m_file_i2c_st, I2C_SLAVE, addr) < 0)
	{
		std::cout<<"Error: Failed to acquire bus access and/or talk to slave!"<<std::endl;
		//ERROR HANDLING; you can check errno to see what went wrong
		return (-1);
	}
	this->m_address = addr;
	return 0;
}

char i2c_module::read_i2c(char *data,  int len){

    if (read(this->m_file_i2c_st, data, len) != len)		//read() returns the number of bytes actually read, if it doesn't match then an error occurred (e.g. no response from the device)
	{
		//ERROR HANDLING: i2c transaction failed
		std::cout<<"Failed to read from the i2c bus!"<<std::endl;
		return(-1);
	}

	return 0;
}


char i2c_module::write_i2c(char *data, int len){

    if (write(this->m_file_i2c_st, data, len) != len)		//read() returns the number of bytes actually read, if it doesn't match then an error occurred (e.g. no response from the device)
	{
		//ERROR HANDLING: i2c transaction failed
		std::cout<<"Failed to read from the i2c bus!"<<std::endl;
		return(-1);
	}

	return 0;
}


char i2c_module::write_then_read_i2c(char *wdata,  int wlen, char * rdata,  int rlen){

    if (write(this->m_file_i2c_st, wdata, wlen) != wlen)		//read() returns the number of bytes actually read, if it doesn't match then an error occurred (e.g. no response from the device)
	{
		//ERROR HANDLING: i2c transaction failed
		std::cout<<"Failed to read from the i2c bus!"<<std::endl;
		return(-1);
	}

    if (read(this->m_file_i2c_st, rdata, rlen) != rlen)		//read() returns the number of bytes actually read, if it doesn't match then an error occurred (e.g. no response from the device)
	{
		//ERROR HANDLING: i2c transaction failed
		std::cout<<"Failed to read from the i2c bus!"<<std::endl;
		return(-1);
	}

	return 0;
}
