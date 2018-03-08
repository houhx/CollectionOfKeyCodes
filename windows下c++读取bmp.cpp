#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <map>
#include <windows.h>
using namespace std;

BITMAPFILEHEADER bmpfileheader; //文件头
BITMAPINFOHEADER bmpinfoheader; //信息头
unsigned char* pBmpbuf; //指向bmp图像的像素数据部分
map<unsigned char, string> encodetable; //huffman编码表  

bool readBmp(const char* bmpName){
	FILE* in = fopen(bmpName,"rb");  //以二进制的方式读取文件
	if(in==nullptr) return 0;      //读取失败 
	/**BITMAPFILEHEADER bmpfileheader; //文件头 
	fread(&bmpfileheader, sizeof(BITMAPFILEHEADER), 1, in);
	cout << bmpfileheader.bfType << endl       //WORD，2字节  文件类型标识符 
	     << bmpfileheader.bfSize << endl       //DWORD, 4字节  文件大小（byte） 
	     << bmpfileheader.bfReserved1 << endl  //WORD          保留部分 
	     << bmpfileheader.bfReserved2 << endl  //WORD          供以后扩展使用 
	     << bmpfileheader.bfOffBits << endl   //DWORD          位图像素数据位置的地址偏移，即开始位置 
	     << sizeof(BITMAPFILEHEADER) << endl;**/
	
	//将当前的读取位置定位到文件头的后面     
	//fseek(in,sizeof(BITMAPFILEHEADER),SEEK_SET); //SEEK_SET代表文件开始位置 
	fread(&bmpfileheader, sizeof(BITMAPFILEHEADER), 1, in);
	fread(&bmpinfoheader,sizeof(BITMAPINFOHEADER),1,in);
	/*cout << infoheader.biSize << endl            //DWORD 4byte 说明该结构体的大小 
	     << infoheader.biWidth << endl           //LONG 4byte  位图的宽度（以像素个数表示） 
		 << infoheader.biHeight << endl          //LONG 4byte  位图的高度 
		 << infoheader.biPlanes << endl          //WORD 2byte  所用彩色位面的个数，1，不常用 
		 << infoheader.biBitCount << endl        //WORD 2byte  每个像素的位数1,4,8（灰阶）,24（彩色） 
		 << infoheader.biCompression << endl     //DWORD 4byte 定义所用的压缩算法，0（BI_RGB）表示没有压缩 
		 << infoheader.biSizeImage << endl       //DWORD 4byte 图像大小，即像素数据部分大小 
		 << infoheader.biXPelsPerMeter << endl   //LONG 4byte 水平分辨率 
		 << infoheader.biYPelsPerMeter << endl   //LONG 4byte 垂直分辨率 
		 << infoheader.biClrUsed << endl         //DWORD 4byte 所用颜色数目 
		 << infoheader.biClrImportant << endl    //DWORD 4byte 重要颜色数目 
	     << sizeof(BITMAPINFOHEADER) << endl; */
	
	pBmpbuf = new unsigned char[bmpinfoheader.biSizeImage];
	fread(pBmpbuf, 1, bmpinfoheader.biSizeImage, in); //读取像素数据部分 
	
	fclose(in);  
	return 1;
}

bool writeBmp(const char* bmpName){
	FILE* out =  fopen(bmpName, "wb");
	if(out == nullptr) return 0;
	fwrite(&bmpfileheader, sizeof(BITMAPFILEHEADER), 1, out);
	fwrite(&bmpinfoheader, sizeof(BITMAPINFOHEADER), 1, out);
	//fwrite(pBmpbuf, bmpinfoheader.biSizeImage, 1, out);
	
	for(int i=bmpinfoheader.biSizeImage-3;  i>=0; i-=3){
		fwrite(pBmpbuf+i,3,1,out);
	}
	
	fclose(out);
	return 1;
} 
