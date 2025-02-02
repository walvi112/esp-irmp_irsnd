idf_component_register(SRCS "irmp.c" "irsnd.c"
                    INCLUDE_DIRS "include"
                    REQUIRES "driver" "esp_driver_ledc")
