cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(lcd-lib C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(PICO_NO_FLASH 1)
add_definitions(-O0)

# Initialize the SDK
pico_sdk_init()

if (TARGET tinyusb_device)
	add_executable(hello_cw
			hello_usb.c
			machikania.c
		)

	# Pull in our pico_stdlib which aggregates commonly used features
	target_link_libraries(hello_cw pico_stdlib)

	# enable usb output, disable uart output
	pico_enable_stdio_usb(hello_cw 0)
	pico_enable_stdio_uart(hello_cw 0)

	# create map/bin/hex/uf2 file etc.
	pico_add_extra_outputs(hello_cw)

	# use user linker script
	pico_set_linker_script(hello_cw ${CMAKE_CURRENT_SOURCE_DIR}/memmap_no_flash.ld)

elseif(PICO_ON_DEVICE)
	message(WARNING "not building hello_cw because TinyUSB submodule is not initialized in the SDK")
endif()
