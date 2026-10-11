/*
 * EBAZ4205 - Liet ke file tren the SD (CHI DOC, khong ghi / format / mkfs)
 *
 * Yeu cau:
 *  - PS7 trong Vivado bat SD 0 (MIO 40..45), export lai XSA
 *  - BSP: them thu vien xilffs (fs_interface = 1 / SD)
 *  - Nen dat trong xilffs: read_only = true, use_mkfs = false,
 *    use_lfn = 1 (de thay ten file dai)
 */

#include <stdio.h>
#include <string.h>
#include "xparameters.h"
#include "xil_printf.h"
#include "ff.h"

#define MAX_PATH_LEN   256
#define MAX_DEPTH      4        /* so cap thu muc toi da khi duyet de quy */

static FATFS fatfs;

static void print_indent(int depth)
{
	for (int i = 0; i < depth; i++) {
		xil_printf("    ");
	}
}

/* Duyet de quy thu muc, chi dung f_opendir / f_readdir */
static FRESULT list_dir(char *path, int depth)
{
	DIR dir;
	FILINFO fno;
	FRESULT res;
	size_t len = strlen(path);

	res = f_opendir(&dir, path);
	if (res != FR_OK) {
		print_indent(depth);
		xil_printf("[loi f_opendir '%s': %d]\r\n", path, (int)res);
		return res;
	}

	for (;;) {
		res = f_readdir(&dir, &fno);
		if (res != FR_OK || fno.fname[0] == 0) {
			break;      /* loi hoac het muc */
		}

		print_indent(depth);

		if (fno.fattrib & AM_DIR) {
			xil_printf("[DIR ] %s\r\n", fno.fname);

			/* de quy vao thu muc con */
			if (depth + 1 < MAX_DEPTH &&
			    len + strlen(fno.fname) + 2 < MAX_PATH_LEN) {
				path[len] = '/';
				strcpy(&path[len + 1], fno.fname);
				list_dir(path, depth + 1);
				path[len] = '\0';
			}
		} else {
			xil_printf("[FILE] %s  (%u bytes, %04d-%02d-%02d)\r\n",
				   fno.fname,
				   (unsigned int)fno.fsize,
				   1980 + (fno.fdate >> 9),
				   (fno.fdate >> 5) & 0x0F,
				   fno.fdate & 0x1F);
		}
	}

	f_closedir(&dir);
	return res;
}

int main(void)
{
	FRESULT res;
	char path[MAX_PATH_LEN] = "0:/";

	xil_printf("\r\n---- SD card: liet ke file (read-only) ----\r\n");

	/*
	 * opt = 0: dang ky volume trong RAM (lazy), chua truy cap the.
	 * The chi duoc doc o lan f_opendir dau tien, khong co thao tac ghi.
	 */
	res = f_mount(&fatfs, "0:/", 0);
	if (res != FR_OK) {
		xil_printf("f_mount that bai: %d\r\n", (int)res);
		return -1;
	}

	res = list_dir(path, 0);
	if (res != FR_OK) {
		xil_printf("Khong doc duoc the (ma loi %d). Kiem tra: the da cam, "
			   "SD0 da bat trong PS7, partition dau la FAT.\r\n", (int)res);
		return -1;
	}

	xil_printf("---- Xong ----\r\n");

	/* Huy dang ky volume (khong ghi gi len the) */
	f_mount(NULL, "0:/", 0);

	return 0;
}
