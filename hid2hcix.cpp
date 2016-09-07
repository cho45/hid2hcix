#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "hidapi.h"

// CSR Bluetooth Dongole as HID USB
const uint16_t VENDOR_ID = 0x0a12;
const uint16_t PRODUCT_ID = 0x100b;

const int8_t EXIT_CODE_HID_INIT_FAILED = -2;
const int8_t EXIT_CODE_HID_OPEN_FAILED = -3;
const int8_t EXIT_CODE_HID_SEND_FEATURE_FAILED = -4;

int main(void) {
	if (hid_init()) {
		printf("Failed: hid_init()\r\n");
		return EXIT_CODE_HID_INIT_FAILED;
	}

	hid_device* handle = hid_open(VENDOR_ID, PRODUCT_ID, NULL);
	if (!handle) {
		printf("Failed: hid_open()\r\n");
 		return EXIT_CODE_HID_OPEN_FAILED;
	}

	uint8_t report[] = { 0x01, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	int res = hid_send_feature_report(handle, report, sizeof(report));
	if (res < 0) {
		printf("Failed: hid_send_feature_report()\r\n");
		return EXIT_CODE_HID_SEND_FEATURE_FAILED;
	}

	hid_close(handle);

	hid_exit();
	printf("Done\r\n");

	return 0;
}
