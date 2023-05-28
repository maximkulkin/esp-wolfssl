#ifndef wolfcrypt_user_settings_h
#define wolfcrypt_user_settings_h

#ifdef ESP_IDF

//#define WOLFSSL_ESPIDF

#if ESP_IDF_VERSION_MAJOR < 5

#include <esp_system.h>

static inline int hwrand_generate_block(uint8_t *buf, size_t len) {
    int i;
    for (i=0; i+4 < len; i+=4) {
        *((uint32_t*)buf) = esp_random();
        buf += 4;
    }
    if (i < len) {
        uint32_t r = esp_random();
        while (i < len) {
            *buf++ = r;
            r >>= 8;
            i++;
        }
    }

    return 0;
}

#else  // ESP_IDF_VERSION_MAJOR >= 5

#include <esp_random.h>

static inline int hwrand_generate_block(uint8_t *buf, size_t len) {
    esp_fill_random(buf, len);
    return 0;
}

#endif  // ESP_IDF_VERSION_MAJOR < 5

#else

#include <esp/hwrand.h>

static inline int hwrand_generate_block(uint8_t *buf, size_t len) {
    hwrand_fill(buf, len);
    return 0;
}

#define MP_LOW_MEM

#define FREERTOS
#define WC_NO_HARDEN
#define NO_WOLFSSL_DIR
#define SINGLE_THREADED
#define WOLFSSL_LWIP
#define NO_INLINE #define NO_WOLFSSL_MEMORY
#define NO_WOLFSSL_SMALL_STACK

#define CUSTOM_RAND_GENERATE_BLOCK hwrand_generate_block

#endif // ifndef ESP_IDF

#endif  // ifndef wolfcrypt_user_settings_h
