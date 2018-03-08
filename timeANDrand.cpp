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
	 *  ���ش�00:00 hours, Jan 1, 1970 UTC���˿̵�����
	 *  ����������NULL��ָ�룬��Ҳ���ò�����Ϊ����ֵ 
	 */
	rowtime2=time(&rowtime1);
	cout << rowtime1  << endl << rowtime2 << endl;
	
	/**
	 * @char* ctime (const time_t * timer);
	 *  return a localtime's c string
	 */
	cout << ctime(&rowtime1) << endl; 
	
	/**
	 * @tm, һ����ʱ����صĽṹ��
	 *  �������ݳ�Ա��һЩ��ʱ����صģ��룬�֣�ʱ���� 
	 */
	struct tm *localtimeinfo, *utctimeinfo;
	
	/**
	 * @struct tm * localtime (const time_t * timer);
	 *  ����timerָ�������������һ�����ڱ���ʱ���tm�ṹ��ָ�� 
	 */
	localtimeinfo=localtime(&rowtime1);
	
	/**
	 * @struct tm * gmtime (const time_t * timer);
	 *  return a tm struct about UTC(Э������ʱ) time
	 */
	utctimeinfo=gmtime(&rowtime1);
	
	/**
	 * @char* asctime (const struct tm * timeptr);
	 *  ����timeptrָ���ʱ��ṹ���е����ݷ���һ��ʱ��C�� 
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
	for(int i=0; i<20; i++) cout << rand()%20 << " ";//ÿ�����ж�������ͬ�����У���Ϊseedû�� 
	
	cout << endl;
	srand(time(NULL));
	for(int i=0; i<20 ;i++) cout << rand()%20 << "  ";//ÿ�����в�����ͬ���У���Ϊseed���� 
	
	cout << endl;
	for(int i=0; i<20 ;i++) cout << (double)(1+rand()%100)/100 << "  "; //С�� 
	
}
