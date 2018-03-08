#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <map>
#include <windows.h>
using namespace std;

BITMAPFILEHEADER bmpfileheader; //�ļ�ͷ
BITMAPINFOHEADER bmpinfoheader; //��Ϣͷ
unsigned char* pBmpbuf; //ָ��bmpͼ����������ݲ���
map<unsigned char, string> encodetable; //huffman�����  

bool readBmp(const char* bmpName){
	FILE* in = fopen(bmpName,"rb");  //�Զ����Ƶķ�ʽ��ȡ�ļ�
	if(in==nullptr) return 0;      //��ȡʧ�� 
	/**BITMAPFILEHEADER bmpfileheader; //�ļ�ͷ 
	fread(&bmpfileheader, sizeof(BITMAPFILEHEADER), 1, in);
	cout << bmpfileheader.bfType << endl       //WORD��2�ֽ�  �ļ����ͱ�ʶ�� 
	     << bmpfileheader.bfSize << endl       //DWORD, 4�ֽ�  �ļ���С��byte�� 
	     << bmpfileheader.bfReserved1 << endl  //WORD          �������� 
	     << bmpfileheader.bfReserved2 << endl  //WORD          ���Ժ���չʹ�� 
	     << bmpfileheader.bfOffBits << endl   //DWORD          λͼ��������λ�õĵ�ַƫ�ƣ�����ʼλ�� 
	     << sizeof(BITMAPFILEHEADER) << endl;**/
	
	//����ǰ�Ķ�ȡλ�ö�λ���ļ�ͷ�ĺ���     
	//fseek(in,sizeof(BITMAPFILEHEADER),SEEK_SET); //SEEK_SET�����ļ���ʼλ�� 
	fread(&bmpfileheader, sizeof(BITMAPFILEHEADER), 1, in);
	fread(&bmpinfoheader,sizeof(BITMAPINFOHEADER),1,in);
	/*cout << infoheader.biSize << endl            //DWORD 4byte ˵���ýṹ��Ĵ�С 
	     << infoheader.biWidth << endl           //LONG 4byte  λͼ�Ŀ�ȣ������ظ�����ʾ�� 
		 << infoheader.biHeight << endl          //LONG 4byte  λͼ�ĸ߶� 
		 << infoheader.biPlanes << endl          //WORD 2byte  ���ò�ɫλ��ĸ�����1�������� 
		 << infoheader.biBitCount << endl        //WORD 2byte  ÿ�����ص�λ��1,4,8���ҽף�,24����ɫ�� 
		 << infoheader.biCompression << endl     //DWORD 4byte �������õ�ѹ���㷨��0��BI_RGB����ʾû��ѹ�� 
		 << infoheader.biSizeImage << endl       //DWORD 4byte ͼ���С�����������ݲ��ִ�С 
		 << infoheader.biXPelsPerMeter << endl   //LONG 4byte ˮƽ�ֱ��� 
		 << infoheader.biYPelsPerMeter << endl   //LONG 4byte ��ֱ�ֱ��� 
		 << infoheader.biClrUsed << endl         //DWORD 4byte ������ɫ��Ŀ 
		 << infoheader.biClrImportant << endl    //DWORD 4byte ��Ҫ��ɫ��Ŀ 
	     << sizeof(BITMAPINFOHEADER) << endl; */
	
	pBmpbuf = new unsigned char[bmpinfoheader.biSizeImage];
	fread(pBmpbuf, 1, bmpinfoheader.biSizeImage, in); //��ȡ�������ݲ��� 
	
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
