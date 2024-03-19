#include <cstdint>
#include <linux/spi/spidev.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

int spifd;
static uint8_t mode =  SPI_MODE_3;
static uint8_t bits = 8;
static uint32_t speed = 200000000;

// the buffer looks like this because the logic analyzer that i use only goes up to 24MHz
uint8_t buf[] = {0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF};

int main(){

    //open SPI device 
    spifd = open("/dev/spidev0.0",O_RDWR);
    
    //set SPI mode 
    ioctl(spifd, SPI_IOC_WR_MODE, &mode);
    
    //set  wbat 
    ioctl(spifd, SPI_IOC_WR_BITS_PER_WORD, &bits);
    
    //set SPI speed 
    ioctl(spifd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);

    //
    int bytes_written = write(spifd, buf, (uint32_t)sizeof(buf));

}