#pragma once
#include <qobject.h>
#include <curl/curl.h>
#include <curlpp/cURLpp.hpp>
#include <iostream>
#include <sstream>
#ifndef ERRLOG(x)
#define ERRLOG(x) std::cout<<"[ERROR] "<<x<<std::endl;
#endif // !LOG(x)

class NETWorker : public QObject
{
	Q_OBJECT
private:
	struct weatherInfo
	{
		std::string maxTemp, minTemp, cloudCover;
	};
public:
	NETWorker(std::string cityName = "nairobi");
	~NETWorker();
	size_t netCallBack_impl(char* contents, size_t size, size_t numMemb);
	static size_t netCallback(char* contents, size_t size, size_t numMemb, void *user);
	void getWeather(std::string city);

public slots:
	//void updateGui();
private:
	std::string searchToken; 
	CURL* curl;
	CURLcode result;
	static weatherInfo nbm;
	const char zURL[45] = "http://www.meteo.go.ke/pages/fetch.php?town=";
};

