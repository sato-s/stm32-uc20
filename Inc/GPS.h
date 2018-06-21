#ifndef GPS_H
#define GPS_H

class GPS {
	string lat;
	string lon;
	string i1;
	string i2;
	string i3;
	public:
		int ToString();
		int ToMsgpack();
}
