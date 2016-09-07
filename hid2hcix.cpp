/*
 * hid2hcix : cross platform hid2hci based on hidapi
 *            just wake up HCI from HID
 *
 *  Copyright (C) 2016-2016  cho45 <cho45@lowreal.net>
 *
 * hid2hci : switch the radio on devices that support
 *           it from HID to HCI and back
 *
 *  Copyright (C) 2003-2010  Marcel Holtmann <marcel@holtmann.org>
 *  Copyright (C) 2008-2009  Mario Limonciello <mario_limonciello@dell.com>
 *  Copyright (C) 2009-2011  Kay Sievers <kay.sievers@vrfy.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "hidapi.h"

// Just for CSR dongle
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

	uint8_t report[] = {
		/* report id */
		0x01,
		/* feeature report */
		0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};
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
