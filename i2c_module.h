#ifndef I2C_MODULE_H
#define I2C_MODULE_H


class i2c_module
{
    public:
        i2c_module();
        virtual ~i2c_module();
        int Getaddress() { return m_address; }
        //char * Geti2c_file() { return m_i2c_file; }
        //void Seti2c_file(char * val) { m_i2c_file = val; }
        unsigned char Geti2c_rx_buffer(void) { return this->m_i2c_rx_buffer[60]; }
        //void Seti2c_rx_buffer[60](unsigned char val) { m_i2c_rx_buffer[60] = val; }
        unsigned int Getlength() { return m_length; }
        void Setlength(unsigned int val) { m_length = val; }
        char Setaddress(int addr);

        char open_i2c(char mode, int addr);
        char read_i2c(char * data,  int len);
        char write_i2c(char * data,  int len);
        char write_then_read_i2c(char *wdata,  int wlen, char * rdata,  int rlen);
        char close_i2c(i2c_module * );
    protected:
    private:
        int m_address, m_file_i2c_st;
        char * m_i2c_file;
        unsigned char m_i2c_rx_buffer[60];
        unsigned int m_length;

};

#endif // I2C_MODULE_H
