/**
 * @file timeANDrand.h
 * 
 * @author houhx
 *
 * @data Oct 19th 2017
 */
#include <iostream>
#include <ctime>

using namespace std;


int main(){
	
	/**
	  *@ time_t,  it is generally implemented as an integral value representing 
	  *  the number of seconds elapsed since 00:00 hours, Jan 1, 1970 UTC
	  */
	time_t rowtime1, rowtime2;
	
	/**
	 * @time_t time (time_t* timer);
	 *  返回从00:00 hours, Jan 1, 1970 UTC到此刻的秒数
	 *  若参数不是NULL空指针，则也将该参数设为返回值 
	 */
	rowtime2=time(&rowtime1);
	cout << rowtime1  << endl << rowtime2 << endl;
	
	/**
	 * @char* ctime (const time_t * timer);
	 *  return a localtime's c string
	 */
	cout << ctime(&rowtime1) << endl; 
	
	/**
	 * @tm, 一个和时间相关的结构体
	 *  它的数据成员是一些和时间相关的，秒，分，时…… 
	 */
	struct tm *localtimeinfo, *utctimeinfo;
	
	/**
	 * @struct tm * localtime (const time_t * timer);
	 *  根据timer指向的秒数，返回一个关于本地时间的tm结构体指针 
	 */
	localtimeinfo=localtime(&rowtime1);
	
	/**
	 * @struct tm * gmtime (const time_t * timer);
	 *  return a tm struct about UTC(协调世界时) time
	 */
	utctimeinfo=gmtime(&rowtime1);
	
	/**
	 * @char* asctime (const struct tm * timeptr);
	 *  根据timeptr指向的时间结构体中的内容返回一个时间C串 
	 */ 
	cout << asctime(localtimeinfo) << endl;
	cout << asctime(utctimeinfo) << endl; 
	
	/**
	 * @int rand (void)
	 *  return the pseudo-random integral between 0 and RAND_MAX
	 *  if you don't set the seed or set the same seed each time
	 *  then you'll get the same pseudo-random sequence each time   
	 */
	cout << RAND_MAX << endl;
	for(int i=0; i<20; i++) cout << rand()%20 << " ";//每次运行都产生相同的序列，因为seed没变 
	
	cout << endl;
	srand(time(NULL));
	for(int i=0; i<20 ;i++) cout << rand()%20 << "  ";//每次运行产生不同序列，因为seed变了 
	
	cout << endl;
	for(int i=0; i<20 ;i++) cout << (double)(1+rand()%100)/100 << "  "; //小数 
	
}
