
wolfssl_VERSION = 3.12.2
wolfssl_THIRDPARTY_ROOT = $(wolfssl_ROOT)wolfssl-$(wolfssl_VERSION)

INC_DIRS += $(wolfssl_ROOT) $(wolfssl_THIRDPARTY_ROOT)

wolfssl_INC_DIR = $(wolfssl_THIRDPARTY_ROOT)
# wolfssl_SRC_DIR = $(wolfssl_THIRDPARTY_ROOT)/src $(wolfssl_THIRDPARTY_ROOT)/wolfcrypt/src
# this dedicated assignment reduces flash footprint by 8672 bytes for led example
# also set #define NO_MD5 and #define NO_SHA in user_settings.h
WC = $(wolfssl_THIRDPARTY_ROOT)/wolfcrypt/src
wolfssl_SRC_FILES = $(WC)/chacha.c \
                    $(WC)/chacha20_poly1305.c \
                    $(WC)/curve25519.c \
                    $(WC)/ed25519.c \
                    $(WC)/fe_operations.c \
                    $(WC)/ge_operations.c \
                    $(WC)/hash.c \
                    $(WC)/hmac.c \
                    $(WC)/integer.c \
                    $(WC)/misc.c \
                    $(WC)/poly1305.c \
                    $(WC)/random.c \
                    $(WC)/sha256.c \
                    $(WC)/sha512.c \
                    $(WC)/srp.c

EXTRA_CFLAGS += -DWOLFSSL_USER_SETTINGS

$(eval $(call component_compile_rules,wolfssl))

