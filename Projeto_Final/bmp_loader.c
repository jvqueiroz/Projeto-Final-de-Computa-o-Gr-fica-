#include <stdio.h>
#include<stdlib.h>

#define HEADER_SIZE 54
#define COMPRESSION_OFFSET 0x1e
#define	BPP_OFFSET 0x1c
#define	IMAGE_START_OFFSET 0x0a
#define	IMAGE_SIZE_OFFSET 0x22
#define	IMAGE_WIDTH_OFFSET 0x12
#define	IMAGE_HEIGHT_OFFSET 0x16


int get_int(char *header, unsigned int offset){
	return (header[offset + 3] << 24) +
			(header[offset + 2] << 16) +
			(header[offset + 1] << 8) +
			(header[offset + 0]);
}

unsigned char *
load_bmp(char *filename, int *width, int *height){
	unsigned char *data = NULL;
	int image_size, data_offset;
	FILE *fp = fopen(filename, "rb");
	if(!fp)
		return NULL;
	printf("File sucessfully opened!\n");

	char header[HEADER_SIZE];

	if(fread(header, HEADER_SIZE, 1, fp) != 1){
		printf("error\n");
		goto out;
	}

	printf("Header sucessfully loaded\n");

	if(header[0] != 'B' || header[1] != 'M'){
		printf("unrecognized BMP header.\n");
		goto out;
	}

	printf("BMP header recognized!\n");

	if(get_int(header, COMPRESSION_OFFSET) != 0 ||
		get_int(header, BPP_OFFSET) != 24){
			printf("NOT AN UNCOMPRESSED 24bpp bitmap!\n");
			goto out;
	}

	printf("BMP file right format!\n");

	data_offset = get_int(header, IMAGE_START_OFFSET);
	image_size = get_int(header ,IMAGE_SIZE_OFFSET);
		*width = get_int(header, IMAGE_WIDTH_OFFSET);
		*height = get_int(header, IMAGE_HEIGHT_OFFSET);

		printf("image dimensions: %dx%d\n", *width, *height);

		if(image_size == 0)
			image_size = (*width)*(*height)*3;
		if(data_offset==0)
			data_offset = HEADER_SIZE;

		data = malloc(image_size);

		if(fread(data, image_size, 1, fp)!= 1){
			printf("!Error loading image data. \n");
			goto out;
		}

		printf("Image sucessfully loaded!\n");
		int i;
		for (i=0; i<image_size; i+= 3){
             unsigned  char aux= data[i+2];
                    data[i+2]= data[i];
                    data[i]= aux;
		}
out:
	fclose(fp);
	return (unsigned char*)data;

}
